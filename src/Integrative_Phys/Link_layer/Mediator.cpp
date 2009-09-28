/**************************************************************************************************
  Mediator.cpp
  Contributor(s):	E. Zeynep Erson
  Created on:		31-Jul-2007 1:50:07 PM
  Description:		Implementation of the Class Mediator. Mediator is responsible for the	integration of components, which
				 share information to represent a physiological process. Information flow among the components are handled
				 by the mediator. Following are the basic responsibilities of the mediator:
				 1. Compile the set of components to assign the input/output variables to the associated models using
					the semantic converter operations.
				 2.	Build a Directed Acyclic Graph to be used for topological sort
				 3.	Integrate with other mediators using the point of integration
					point of integration: 
**************************************************************************************************/

//FOR TEST PURPOSES ADD THESE LIBRARIES:
#include <iostream>
#include <assert.h>
#include <fstream>
#include "Link_layer.h"
#include "Semantic_Converter.h"



using namespace link_layer;

Mediator::Mediator(){
	DE_queue = new Phys_Container<Link_layer_Component>;
	ordered_components = new Phys_Container<Link_layer_Component>;
	vip_list = new Phys_Container<Link_layer_Component>;
	m_Director = new Director;
	integrators = new Phys_Container<Replacer_semantic_converter>;
	
}

Mediator::Mediator(char *name){
	DE_queue = new Phys_Container<Link_layer_Component>;
	component_list = new Phys_Container<Link_layer_Component>;
	ordered_components = new Phys_Container<Link_layer_Component>;
	m_Director = new Director;
	set_name(name);
}




Mediator::~Mediator(){

}

Phys_Container<Link_layer_Component>* Mediator::get_components(){
	component_list->reset_iterator();
	return component_list;
}


void Mediator::set_order(int ord){
	order = ord;
}

int Mediator::get_order(){
	return order;
}

Phys_Container<Link_layer_Component>* Mediator::get_ordered_components(){
	return ordered_components;
}

void Mediator::add_to_ordered_components(Link_layer_Component* item){
	ordered_components->add_front(item);
}




/*
This method creates and order of execution based on the components' models attached to the current mediator.
The order is determined by using directed acyclic graphs.
for feedback mechanisms, avoiding the cycles and finding the order for simulatin is very important.


1.	Insert Semantic Converters for each individual (or set of physiological variables)
	a. Go over the semantic converters list and apply the semantic conversion.
2.	Ask the user to connect the input/output models and introduce the semantic conversion process.
3.	Iterate over variables and place the variables which have the discrete event models in the discrete event queue in the director.
4.	Compose the  Directed Graph of physiological variables
	a.	Iterate over variables of nodes
	b.	Find the semantic converter
	c.	Put the directed edge between the variables based on the semantic converter
5.	Check for cycles: Apply a DFS, linear in number of vertices
	a.	If no cycles, it is “DAG”, go step 6
	b.	If there is a cycle:
		i.	Iterate over the models (of variables)
			1.	If that model is INITIAL_CONDITION model, then remove the incoming edge of the variable having this model.
			2.	Check if there is still a cycle 
		ii.	If there is still a cycle, (algebraic loop) ASK THE USER TO RESOLVE!!
6.	Run topological sort on DAG (O(|m| + |physiological_variables|)) and assign order to models based on the sort result
7.	Director tries to solve the time_step for the simulation:
	a.	Follow the rules explained above for heterogeneous/homogenous models

*/


void Mediator::compile_model(){
	//clear all the lists built during model compilation
	ordered_components->clear();
	Phys_Container<Link_layer_Component>* comps = get_runnable_components();
	while(comps->hasMoreVariables()){
		comps->getNextItem()->reset_order_info();
	}

	//Apply the integrator semantic converters first!
	Phys_Container<Replacer_semantic_converter>* replacers  = get_integrators();
	while(replacers->hasMoreVariables()){
		replacers->getNextItem()->apply_semantic_operation();
	}
	
	//Apply semantic operations to set the inputs/outputs of the models.
	Phys_Container<Semantic_Converter>* semantic_converters = new Phys_Container<Semantic_Converter>(get_semantic_converters());

	while(semantic_converters->hasMoreVariables()){
		semantic_converters->getNextItem()->apply_semantic_operation();
	}

	//todo: think about the discrete events, do we need seperate implementation for them?
	//Compose the discrete event list
	/*Link_layer_Component *temp;
	comps->reset_iterator();
	while(comps->hasMoreVariables()){
		temp = comps->getNextItem();
		if(temp->is_DE_component()){
			DE_queue->addItem(temp);
		}
	}*/
	component_list->reset_iterator();

	//Build the directed acyclic graph
	build_DAG();

	//Run the topological sort on DAG
	comps->reset_iterator();
	while(comps->hasMoreVariables()){
		comps->getNextItem()->set_color(WHITE);
	}
	topological_sort(comps);
	Phys_Container<Link_layer_Component>* temp_list = new Phys_Container<Link_layer_Component>;
	temp_list->addList(vip_list);
	get_ordered_components()->prependList(temp_list);

}

//In the final graph only components which have a runnable model are included!!
void Mediator::build_DAG(){
	//first build the directed graph
	build_DG();

	//set every component to "NOT VISITED"
	Phys_Container<Link_layer_Component> *temp_list  = new Phys_Container<Link_layer_Component>(get_runnable_components());
	while(temp_list->hasMoreVariables()){
		temp_list->getNextItem()->set_color(WHITE);
	}

	temp_list->reset_iterator();
	set_order(0);
	
	while(temp_list->hasMoreVariables()){
		resolve_cycles((Component*)temp_list->getNextItem(),NULL);
	}


}

/*
1. Check for a cycle
2. if the back edge is found
3. try to resolve the cycle here by removing the back edge
4. check if the succ is an initial value variable
5. if so, remove the back edge feeding into it
6. if not, carry the cycle information to the all the nodes on the cycle
	and try to find the initial value variable
7. if no initial value variable can be found, 
	throw an exception indicating that there is an algebraic loop
---
TODO: check the ordering mechanism, there is a bug!
TODO: throw an exception
*/
bool Mediator::resolve_cycles(Component *component, Component *predecessor){
	bool isOncycle = false;

		if (component->get_color()==WHITE){
		component->set_color(GRAY);
		set_order(get_order()+1);
		Phys_Container<Link_layer_Component> *successors = 
			new Phys_Container<Link_layer_Component> (component->get_successor_components());
		Component *succ;
		while(successors->hasMoreVariables()){
			succ = (Component*)successors->getNextItem();

			if(succ->get_color()==WHITE){
				bool test = resolve_cycles(succ,component);
				isOncycle = (isOncycle || test);
			}
			//THERE IS A CYCLE!!
			//found the back edge
			//try to resolve the cycle here by removing the back edge
			else if(succ->get_color()==GRAY){												
				//check if the succ is an initial value variable
				//if so, remove the back edge feeding into it
				//add the source of the removed back edge to the top of the ordered component list
				//this resolves the cycle
				if(*(succ->get_value())!=EMPTY_INITIAL_VALUE){					

					succ->get_predecessor_components()->deleteItem(component);
					component->get_successor_components()->deleteItem(succ);

				}
				//todo: think about this, do we still need this color scheme?
				//red indicates that a cycle is found and resolved with that node
				else{
					isOncycle = true;
				}
				//if not, carry the cycle information to the all the nodes on the cycle
				//and try to find the initial value variable
				//if no initial value variable can be found, 
				//throw an exception indicating that there is an algebraic loop
			}
		}
		if(!isOncycle){
			component->set_color(BLACK);
		}
		//a cycle is found on the successor nodes, but none of the nodes on the cycle were initial value,
		//so check if the current node is an initial value variable
		//if so, set its color Red
		//and remove the back edge feeding into this node 
		//add the source of the removed back edge to the top of the ordered component list
		//this resolves the cycle

		else if(isOncycle){
			if(*(component->get_value())!=EMPTY_INITIAL_VALUE && predecessor!=NULL){														

				component->set_color(WHITE);
				predecessor->get_successor_components()->deleteItem(component);
				component->get_predecessor_components()->deleteItem(predecessor);
				isOncycle = false;
			}
			else{
				//TODO: THINK ABOUT THIS, WHAT IF BLACK
				//component->set_color(RED);

			}
		}
		component->set_order(get_order());		
	}
	return isOncycle;
}



//UPDATE::NEED TO RESET THE PREDECCESSOR/SUCCESSOR LIST EVERY TIME WE BUILD DG!!!
void Mediator::build_DG(){

	Phys_Container<Semantic_Converter>* sems = new Phys_Container<Semantic_Converter>(get_semantic_converters());
	sems->reset_iterator();

	while(sems->hasMoreVariables()){
		Semantic_Converter *sem = sems->getNextItem();
		Phys_Container<Link_layer_Component>* temp_outputs = new Phys_Container<Link_layer_Component>(sem->get_outputs());
		Phys_Container<Link_layer_Component>* temp_inputs = new Phys_Container<Link_layer_Component>(sem->get_inputs());	
		Phys_Container<double>* ins = new Phys_Container<double>;
		Link_layer_Component* var_input;
		Component *temp_component;

		

		temp_outputs->reset_iterator();
		//Simply adds every variable in the input port of the semantic converter as an input parameter to every variable
		//at the output port of the semantic converter.
		while(temp_outputs->hasMoreVariables())
		{
			temp_component = (Component*)temp_outputs->getNextItem();
			
			//if the output component is an initial value model, do not put any predecessors to it
			//if(*(temp_component->get_value())== EMPTY_INITIAL_VALUE){				
				temp_inputs->reset_iterator();
				while(temp_inputs->hasMoreVariables())
				{
					var_input = temp_inputs->getNextItem();	
					//adding a component as a successor to a compoent, implicity maintains the predecessor list of 
					//the successor component.			
					var_input->add_successor_component(temp_component);

				}
		}//WHILE FOR OUTPUTS
	}//WHILE FOR SEMANTIC CONVERTERS

}


void Mediator::topological_sort(Phys_Container<Link_layer_Component>* dag)
{
	Component *component;

	dag->reset_iterator();
	while(dag->hasMoreVariables()){
		component = (Component*)dag->getNextItem();
		visit_DFS(component);
	}

}

//todo:if a cycle is detected, throw and exception and report to the user
void Mediator::visit_DFS(link_layer::Link_layer_Component *component){
	


	if (component->get_color()==WHITE){
		component->set_color(GRAY);
		set_order(get_order()+1);
		Phys_Container<Link_layer_Component> *successors = 
			new Phys_Container<Link_layer_Component> (component->get_successor_components());
		Component *succ;
		while(successors->hasMoreVariables()){
			succ = (Component*)successors->getNextItem();
			if(succ->get_color()==WHITE){
				visit_DFS(succ);
			}
		}
		component->set_color(BLACK);
		
			add_to_ordered_components(component);

					if(strcmp(component->get_name(),"Nbr")==0 || 
						strcmp(component->get_name(),"Nbr_derivative")==0||
						strcmp(component->get_name(),"Nbr_t")==0||
						strcmp(component->get_name(),"Nbr_t_derivative")==0){
							int i=6;
					}

			component->set_order(get_order());		
	}

}

void Mediator::build_DE_queue(){

}

void Mediator::check_DE_queue(int global_time){

}

void Mediator::add_to_integrators(Replacer_semantic_converter *replacer){
	integrators->addItem(replacer);
}

Phys_Container<Replacer_semantic_converter>* Mediator::get_integrators(){
	integrators->reset_iterator();
	return integrators;
}
void Mediator::resolve_cycles(){
	Phys_Container<Link_layer_Component>* test_cycle = new Phys_Container<Link_layer_Component>(get_ordered_components());
	Link_layer_Component *cycle;
	while(test_cycle->hasMoreVariables()){
		cycle = test_cycle->getNextItem();
		if(cycle->get_color()==RED){
			get_ordered_components()->deleteItem(cycle);
			get_ordered_components()->add_front(cycle);
		}
	}

}


void Mediator::run_components(double current_time, bool major){
	Phys_Container<Component>* components = new Phys_Container<Component>( (Phys_Container<Component> *)get_ordered_components());
	Component *next_component;
	while(components->hasMoreVariables()){
		next_component = components->getNextItem();
		
		if(next_component->get_variable()->get_Model()!=NULL && (strcmp(next_component->get_name(),"t")!=0)){
			
			
			double *test = next_component->get_value();
			
			next_component->update_variable(current_time);

			
		}
		
	}

	Phys_Container<Memory_Component>* memory_components = new Phys_Container<Memory_Component>(get_memory_components());
	Memory_Component* mem_comp;
	memory_components->reset_iterator();
	while(memory_components->hasMoreVariables()){
		mem_comp = memory_components->getNextItem();
		mem_comp->update_variable(current_time);
	}
}
void Mediator::run_components(double current_time, Phys_Container<Component> *list){
	Phys_Container<Component>* components = list;
	Component *next_component;
	while(components->hasMoreVariables()){
		next_component = components->getNextItem();
		
		if(next_component->get_variable()->get_Model()!=NULL && (strcmp(next_component->get_name(),"t")!=0)){
			double *test = next_component->get_value();
			next_component->update_variable(current_time);			
		}
		
	}

	Phys_Container<Memory_Component>* memory_components = new Phys_Container<Memory_Component>(get_memory_components());
	Memory_Component* mem_comp;
	memory_components->reset_iterator();
	while(memory_components->hasMoreVariables()){
		mem_comp = memory_components->getNextItem();
		mem_comp->update_variable(current_time);
	}
}
void Mediator::run_minor_step_components(double current_time){
	Phys_Container<Component>* components = new Phys_Container<Component>((Phys_Container<Component> *)vip_list);
	Component *next_component;
	components->reset_iterator();
	while(components->hasMoreVariables()){
		next_component = components->getNextItem();
	
		if(next_component->get_variable()->get_Model()!=NULL && (strcmp(next_component->get_name(),"t")!=0)){
			double *test = next_component->get_value();
			
				std::cout<<"*********"<<next_component->get_name()<<"*********"<<std::endl;
			
				if(!((*(next_component->get_value())!=EMPTY_INITIAL_VALUE) && (current_time-0.0<EPSILON))){
					next_component->update_variable(current_time);			
				}			
		}		
	}

	Phys_Container<Memory_Component>* memory_components = new Phys_Container<Memory_Component>(get_memory_components());
	Memory_Component* mem_comp;
	memory_components->reset_iterator();
	while(memory_components->hasMoreVariables()){
		mem_comp = memory_components->getNextItem();
		mem_comp->update_variable(current_time);
	}
}

/*Name of the target component's name, which is the component to be replaced in the current mediator is given.
The mediator, in which the candidate source components are searched to replace the target component.
User guidance is required to find the correct source component
Based on the user selection, the replacer semantic converter is created and returned.
*/
Replacer_semantic_converter* Mediator::define_horizontal_integration_point (char *name, link_layer::Mediator *mediator){
		
	int var_index;
	Phys_Container<link_layer::Replacer_semantic_converter>* replacers = new Phys_Container<link_layer::Replacer_semantic_converter>;
	//first integration point(target to be replaced) is "iv_q"

	//target component
	link_layer::Component *target = get_ModelComponent_by_name(name);

	//source mediator-mediator
	//to find the integration points, pass the target component to the source mediator and ask that mediator the questions:
	//first list all the variables that has the same anatomical structure
	//then list all the variables which is the same as the arterial supply/venous drainage of iv_q
	//then list all the variables which contain iv_q as a part
	//todo:...better define the search criteria...for replacement, for vertical, for horizontal...


	Phys_Container<link_layer::Component>* proposed_list = mediator->find_components_by_AS(target);
	proposed_list->addList(mediator->find_components_by_arterial_supply(target));
	proposed_list->addList(mediator->find_components_by_venous_drainage(target));
	proposed_list->addList(mediator->find_components_by_part(target));

	cout<<"Suggested variables for replacing "<<target->get_name()<<endl;
	proposed_list->reset_iterator();
	for(int i=0;proposed_list->hasMoreVariables();i++){
		cout<<i<<":"<<proposed_list->getNextItem()->get_name()<<endl;
	}

	cout<<"Select one variable"<<endl;
	std::cin>>var_index;
	
	proposed_list->reset_iterator();
	link_layer::Component *source  = proposed_list->getItemAt(var_index);

			
	link_layer::Replacer_semantic_converter* replacer_1 = link_layer::Replacer_semantic_converter::
		create_replacer_semantic_converter(target->get_name(),this,source->get_name(),mediator);
	return replacer_1;

}


Replacer_semantic_converter* Mediator::define_vertical_integration_point (char *name, link_layer::Mediator *mediator){
		
	int var_index;
	Phys_Container<link_layer::Replacer_semantic_converter>* replacers = new Phys_Container<link_layer::Replacer_semantic_converter>;
	//first integration point(target to be replaced) is "iv_q"

	//target component
	link_layer::Component *target = get_ModelComponent_by_name(name);

	//source mediator-mediator
	//to find the integration points, pass the target component to the source mediator and ask that mediator the questions:
	//then list all the variables which contain iv_q as a part

	Phys_Container<link_layer::Component>* proposed_list = mediator->find_components_by_part(target);

	cout<<"Suggested variables for replacing "<<target->get_name()<<endl;
	proposed_list->reset_iterator();
	for(int i=0;proposed_list->hasMoreVariables();i++){
		cout<<i<<":"<<proposed_list->getNextItem()->get_name()<<endl;
	}

	cout<<"Select one variable"<<endl;
	std::cin>>var_index;
	
	proposed_list->reset_iterator();
	link_layer::Component *source  = proposed_list->getItemAt(var_index);

			
	link_layer::Replacer_semantic_converter* replacer_1 = link_layer::Replacer_semantic_converter::
		create_replacer_semantic_converter(target->get_name(),this,source->get_name(),mediator);
	return replacer_1;

}

/*
This method integrates/merges two mediators (source mediator, which is the mediator to be integrated to another mediator and 
target mediator, which is the mediator to receive the mediator to be merged)
Integration is (can be) performed over the points of merge. 
If one or more of component(s) are semantically same components, then the source component should replace the variable
and model of the target component. Once the merging of the components are complete, rest of the link layer components 
of the source mediator can be simply added to the target mediator.

source component list: This component list is the ordered component list whose variables will replace the variables 
						of the components in the target component list;					
target component: This component list is the ordered component list whose variables will be replaced by the variables 
						of the components in source component list.

Since the idea is to merge two mediators over one/or more components, the steps to follow during this merging is as follows:
	1. Replace the target component's variable with the source component's variable.
	2. Update the semantic converter(s) which has the target component as the output.
		NOTE: WHAT IF THE SEMANTIC CONVERSION IDEA IS DESIRED TO BE KEPT, but only the model needs to be replaced?
			  THINK OF ANOTHER APPROACH?
	3. Add the semantic converters in the source mediator, to the target mediator.
	4. Add all the Link layer components in the source mediator to the target mediator.
	5. Compile the new model to determine the DAG and orders among models

*/
void Mediator::integrate_Mediators(Phys_Container<Component> *target_components, 
								   Phys_Container<Component> *source_components, 
								   Mediator *source_mediator)
{
	/*
	Assertions:
	*/	
	assert(target_components->size() == source_components->size());

	/*
	Local variables:
	*/
	Component *target, *source;
	Phys_Container<Link_layer_Component>* sources; 
	Phys_Container<Semantic_Converter>* sem_converters;
	Semantic_Converter *sem;


	/*
	1.copy the variables of the source components to the variables of the target components
	*/	
	while(target_components->hasMoreVariables()){
		target = target_components->getNextItem();
		source = source_components->getNextItem();
		replace_component(target,source,source_mediator);
		
		
	}

	/*
	2. Find the semantic converter which has the target component at its output list and remove it from the output list
		2.1 If the semantic converter does not have any other outputs, then it can be deleted as well.\
		2.2 If there are more outputs but if some of the inputs are only related to the deleted output, 
			then these itputs can be removed from the inout list as well.
	*/


	
	/*
	3. merge the source_mediator
		3.1 add the components
		3.2 add the semantic converters
	*/

	sources = new Phys_Container<Link_layer_Component>(source_mediator->get_components());
	Link_layer_Component *temp;
	while(sources->hasMoreVariables()){
		temp = sources->getNextItem();
		add_component(temp);

			
	}
	sem_converters = new Phys_Container<Semantic_Converter>(source_mediator->get_semantic_converters());
	while(sem_converters->hasMoreVariables()){
		sem = sem_converters->getNextItem();
		add_semantic_converter(sem);
	}

	/*
	4. Compile the new model
	*/
	compile_model();
}

/*
This method aims to replace a component in the current mediator with another component in the source mediator.
This method would be useful when the source component and target component have the same physiological variable
but they implement different processes.
When the source component replaces the target component, the model attached to the target component will not
be valid anymore.
Therefore, semantic converters attached to the target component should be modified!
*/
void Mediator::replace_component(link_layer::Component *target, link_layer::Component *source, link_layer::Mediator *source_mediator){
	/*	1.	Remove the target component from the output list of the semantic converter(s), 
			which serves as an input semantic converter.(Since the target component's model is no longer valid, 
			this output of the semantic converter should left as empty/null)
		2.	set the target component pointer point to the source component
		3.	
	*/

	Phys_Container<Semantic_Converter>* in_list = target->get_input_semantic_converters();
	Semantic_Converter *sem;
	while(in_list->hasMoreVariables()){
		sem = in_list->getNextItem();
		sem->get_outputs()->deleteItem(target);
		target->get_input_semantic_converters()->deleteItem(sem);
	}

	Phys_Container<Semantic_Converter>*out_list = target->get_output_semantic_converters();
	while(out_list->hasMoreVariables()){
		sem = out_list->getNextItem();
		sem->get_inputs()->deleteItem(target);
		sem->get_inputs()->addItem(source);
		target->get_output_semantic_converters()->deleteItem(sem);
	}
	//copy the semantic converters which has target at input port to the source mediator
	remove_component(target);
	target = source;
}

void Mediator::remove_component(link_layer::Link_layer_Component *component){
	component_list->deleteItem(component);
	ordered_components->deleteItem(component);
}


