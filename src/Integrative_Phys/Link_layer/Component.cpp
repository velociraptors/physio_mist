/*************************************************************************************************
  Link_Layer_Component. cpp
  Contributor(s):	E. Zeynep Erson
  Created on:		August, 2007
  Description:		Link_Layer_Component is the smallest unit in the Link_Layer. It serves as a node in the graph.
					It is connected to the other Link_Layer_Component instances through semantic converters.
				Link_Layer_Component is the parent to the following classes:
				1. Component
				2. SubModel_Component
				3. Director
  Members:
	1. predecessor_components: List of Link_Layer_Components that should be executed before,
	2. successor_components:List of Link_Layer_Components that should be executed after
	3. input_semantic_converters: List of semantic converters which provide input to the current Link_Layer_Component
	4. output_semantic_converters:List of semantic converters which use the current Link_Layer_Component as an input
	5. color: Used to identify if this L_L_C causes a cycle in the model that it is contained in.
	6. order: Integer value assigned after the model that contains this L_L_C is compiled

*************************************************************************************************/
#include "Link_layer.h"
#include "Semantic_Converter.h"

using namespace link_layer;

Link_layer_Component::Link_layer_Component(){
	predecessor_components = new Phys_Container<Link_layer_Component>;
	successor_components = new Phys_Container<Link_layer_Component>;
	input_semantic_converters = new Phys_Container<Semantic_Converter>;
	output_semantic_converters = new Phys_Container<Semantic_Converter>;
	color = WHITE;
	slave = NULL;
	

}
Link_layer_Component::~Link_layer_Component(){
}

int Link_layer_Component::get_color(){
	return color;
}

void Link_layer_Component::set_color(int _color){
	color = _color;
}


int Link_layer_Component::get_order(){
	return order;
}

void Link_layer_Component::set_order(int ord){
	order = ord;
}

void Link_layer_Component::reset_order_info(){
	set_order(0);
	set_color(WHITE);
	predecessor_components->clear();
	successor_components->clear();
}

Phys_Container<Link_layer_Component>* Link_layer_Component::get_predecessor_components(){
	return predecessor_components;
}
Derivative_Component* Link_layer_Component::get_slave(){
	return slave;
}
void Link_layer_Component::set_slave(Derivative_Component *der){
	der->set_master((Component*)this);
	slave = der;
}
Phys_Container<Link_layer_Component>* Link_layer_Component::get_successor_components(){
	return successor_components;
}
void Link_layer_Component::deleteSuccessor(link_layer::Link_layer_Component *succ){

	get_successor_components()->SAFE_deleteItem(succ);
	//	get_successor_components()->deleteItem(succ);
	if(get_slave()!=NULL){
		get_successor_components()->SAFE_deleteItem(succ->get_slave());
	}
	
	/*succ->get_predecessor_components()->deleteItem(this);
	succ->get_slave()->get_predecessor_components()->deleteItem(this);*/
	succ->deletePredecessor(this);

}

void Link_layer_Component::deletePredecessor(link_layer::Link_layer_Component *pre){
	get_predecessor_components()->SAFE_deleteItem(this);
	if(get_slave()!=NULL){
		get_slave()->get_predecessor_components()->SAFE_deleteItem(this);
	}
}
void Link_layer_Component::add_successor_component(Link_layer_Component *successor){
	if(!successor_components->contains(successor)){
		successor_components->addItem(successor);
		if(successor->get_slave()!=NULL){
			if(!successor_components->contains(successor->get_slave())){
				successor_components->addItem(successor->get_slave());
			}			
		}
	}

	successor->add_predecessor_component(this);
	
}

void Link_layer_Component::add_predecessor_component(Link_layer_Component *predecessor){
	if(!predecessor_components->contains(predecessor)){
		predecessor_components->addItem(predecessor);
	}
		

	
}

void Link_layer_Component::add_input_semantic_converter(Semantic_Converter *sem_conv){				
	input_semantic_converters->addItem(sem_conv);
	
}

Phys_Container<Semantic_Converter>* Link_layer_Component::get_input_semantic_converters(){
	return input_semantic_converters;
}

void Link_layer_Component::add_output_semantic_converter(Semantic_Converter *sem_conv){	
		output_semantic_converters->addItem(sem_conv);
	
}


Phys_Container<Semantic_Converter>* Link_layer_Component::get_output_semantic_converters(){
	return output_semantic_converters;
}

double Link_layer_Component::determine_fixed_update_rate(){
	return 0.;

}

Phys_Container<double>* Link_layer_Component::determine_variable_update_rates(){
	return NULL;
}

Phys_Container<Link_layer_Component>* Link_layer_Component::get_runnable_components(){
	Phys_Container<Link_layer_Component> *list = new Phys_Container<Link_layer_Component>;		
	list->addItem(this);		
	return list;
}

Phys_Container<Semantic_Converter>* Link_layer_Component::get_semantic_converters(){
	return NULL;
}

/*TODO: COMPLETE THE IMPLEMENTATION*/
bool Link_layer_Component::operator==(link_layer::Link_layer_Component component){

	if (strcmp(component.get_name(),this->get_name())==0){
		return true;
	}
	else{
		return false;
	}
}

/*
	Component.cpp
	Contributor(s): E. Zeynep Erson
	Description: Implementation of the Component class.
				Component encapsulates anatomical structure in addition to physiological variables.

*/
Component::Component(){
	anatomical_structure = NULL;
	arterial_supply = new Phys_Container<FMAID>;
	venous_drainage = new Phys_Container<FMAID>;
	nerve_supply = new Phys_Container<FMAID>;	
}
Component::Component(physiological_layer::Physiological_Variable *var){
	anatomical_structure = NULL;
	arterial_supply = new Phys_Container<FMAID>;
	venous_drainage = new Phys_Container<FMAID>;
	nerve_supply = new Phys_Container<FMAID>;
	set_variable(var);
}


Component::~Component(){

}

double Component::determine_fixed_update_rate(){
	return get_variable()->get_sample_time();

}

Phys_Container<double>* Component::determine_variable_update_rates(){
	Phys_Container<double>* rates= new Phys_Container<double>;
	double *sample_time = new double;
	*sample_time = get_variable()->get_sample_time();
	if(*sample_time!=0.0){
		rates->addItem(sample_time);
	}
	
	return rates;
}
void Component::set_variable(physiological_layer::Physiological_Variable *variable){
	m_Physiological_Variable = variable;

}

void Component::set_anatomical_structure(Anatomical_structure *str){
	anatomical_structure = str;
	
}


void Component::update_variable(double current_time){
	this->get_variable()->update_variable(current_time);	
}

double* Component::get_value(){
	return get_variable()->get_value();
}


/*
Current component is replaced with the source component:
	1. if the target has a slave, it means that there is a derivative component in the models, 
		1.1 check if the source has a slave,
			if so, replace the slave of the target with the slave of source as well.
			if not, just add target's slave to the source as slave.
	2. Remove all the components that are input to the semantic converter which has the target as the output
	3. Remove all the components that are output to the semantic converter which has the target as the input
	   Add the source as an input to these semantic converters

*/
void Component::replace_with(Component *source,Replacer_semantic_converter *replacer){


	//if the target has a slave, it means that there is a derivative component in the integrated model, 
	//check if the source has a slave,
	//if so, replace the slave of the target with the slave of source as well.
	//if not, just add target's slave to the source as slave.
	if(get_slave()!=NULL){
		if(source->get_slave()==NULL){
			source->set_slave(get_slave());						
		}
		else{
			source->set_slave(get_slave());
			get_slave()->replace_with(source->get_slave(),replacer);
		}
	}

	
	//Remove all the components that are input to the semantic converter which has the target as the output
	Phys_Container<Semantic_Converter>* in_list = get_input_semantic_converters();
	Semantic_Converter *sem;
	while(in_list->hasMoreVariables()){
		sem = in_list->getNextItem();
		if(sem!=(Semantic_Converter*)replacer){	
			sem->get_outputs()->deleteItem(this);
			get_input_semantic_converters()->SAFE_deleteItem(sem);

		}
	}
	
	//Remove all the components that are output to the semantic converter which has the target as the input
	//Instead add the source as an input to these semantic converters
	Phys_Container<Semantic_Converter>* out_list = get_output_semantic_converters();

	while(out_list->hasMoreVariables()){
		sem = out_list->getNextItem();
		if(sem!= (Semantic_Converter*)replacer){
			sem->get_inputs()->replaceItem(this,source);
			source->add_output_semantic_converter(sem);
			get_output_semantic_converters()->SAFE_deleteItem(sem);					
		}			
	}

}

bool Component::is_DE_component(){
	physiological_layer::Physiological_Variable *test;
	test = get_variable();
	if(test->get_Model()==NULL)
	{
		return false;
	}

	return get_variable()->get_Model()->get_Computation_Model()->get_is_DE();
}





physiological_layer::Physiological_Variable* Component::get_variable(){
	return m_Physiological_Variable;
}

Anatomical_structure* Component::get_anatomical_structure(){
	return anatomical_structure;
}

Phys_Container<FMAID>* Component::get_arterial_supply(){
	return arterial_supply;
}

Phys_Container<FMAID>* Component::get_nerve_supply(){
	return nerve_supply;
}

Phys_Container<FMAID>* Component::get_venous_drainage(){
	return venous_drainage;
}
/*TODO: COMPLETE THE IMPLEMENTATION*/
bool Component::operator==(link_layer::Component component){
	if(get_variable()==component.get_variable()){
		return true;
	}
	return false;
}

/*
	SubModel_Component.cpp
	Contributor(s): E. Zeynep Erson
	Description:Implementation of the SubModel_Component class.
	
	This class serves as a submodel container as well as a Link_Layer_Component. 
	Every SubModel_Component is a container of components and semantic converters representing a sub_model
	for a physiological process. SubModel_Components can be integrated at the level of Mediator to compose
	more complicated models; or s single SubModel_Component can be added to a Mediator to simulate the single
	model represented within.
*/


SubModel_Component::SubModel_Component(){
	component_list = new Phys_Container<Link_layer_Component>;
	memory_component_list = new Phys_Container<Memory_Component>;
	semantic_converter_list = new Phys_Container<Semantic_Converter>;
}
SubModel_Component::SubModel_Component(char *_name){
	name = _name;
	component_list = new Phys_Container<Link_layer_Component>;
	memory_component_list = new Phys_Container<Memory_Component>;
	semantic_converter_list = new Phys_Container<Semantic_Converter>;
}
SubModel_Component::~SubModel_Component(){
}
Phys_Container<Link_layer_Component>* SubModel_Component::get_components(){
	return component_list;
}

Phys_Container<Memory_Component>* SubModel_Component::get_memory_components(){
	return memory_component_list;
}
void SubModel_Component::add_semantic_converter(Semantic_Converter *sem_converter){
	semantic_converter_list->addItem(sem_converter);
}

void SubModel_Component::add_to_integrators(Semantic_Converter *sem_converter){
	semantic_converter_list->add_front(sem_converter);
}

Phys_Container<Semantic_Converter>* SubModel_Component::get_semantic_converters(){
	Phys_Container<Semantic_Converter> *sem_list = new Phys_Container<Semantic_Converter>;
	Phys_Container<Link_layer_Component> *comp_list = new Phys_Container<Link_layer_Component>(get_components());
	while(comp_list->hasMoreVariables()){
		Link_layer_Component *tmp = comp_list->getNextItem();
		sem_list->addList(tmp->get_semantic_converters());
		//sem_list->prependList(tmp->get_semantic_converters());
	}
	semantic_converter_list->reset_iterator();
	//sem_list->prependList(semantic_converter_list);
	sem_list->addList(semantic_converter_list);
	return sem_list;
}

void SubModel_Component:: add_component(Link_layer_Component* component){

	component_list->addItem(component);
	//This method adds the components of the component to the mediator.
	//ex:If the component is a Mediator itself, it will have some components owned by itself.
	//These components should be in the component list of this Mediator as well.
	//THINK ABOUT THIS CONSTRUCTION, INSTEAD OF ADDIND THESE TO THE COMPONENT LIST,
	//THEY CAN BE ADDED AT THE TIME OF ORDER CONFIGURATION (RECURSIVELY MAY BE???)
//	component->update_meditor();


}

void SubModel_Component:: add_memory_component(Memory_Component *mem_comp){
	memory_component_list->addItem(mem_comp);
}
Phys_Container<Link_layer_Component>* SubModel_Component::get_runnable_components(){
	Phys_Container<Link_layer_Component> *list = new Phys_Container<Link_layer_Component>;
	Phys_Container<Link_layer_Component> *comp_list = new Phys_Container<Link_layer_Component>(get_components());
	while(comp_list->hasMoreVariables()){
		list->addList(comp_list->getNextItem()->get_runnable_components());
	}
	return list;
}

/*
This function determines the fixed time step for all of the components having their own update rates.
If : 
	1. all the components have the same update rate, the simulation time step will be equal to the models'
update rate.
	2. components have varying update rates, GCD of these update rates are found and it is set to be the
simulation step.
*/
double SubModel_Component::determine_fixed_update_rate(){	
	Phys_Container<Link_layer_Component> *components = get_components();
	Link_layer_Component *comp = components->getNextItem();
	
	double submodel_step_size;
	double component_step_size;

	submodel_step_size = comp->determine_fixed_update_rate();
	while(components->hasMoreVariables()){
		component_step_size=components->getNextItem()->determine_fixed_update_rate();
		if(component_step_size - submodel_step_size < EPSILON){
		}
		else{
			submodel_step_size = gcd(submodel_step_size,component_step_size);
			/*if(mediator_step_size<0.1 && 0.1<component_step_size){
				mediator_step_size = 0.1;
			}*/
		}		
	}
	return submodel_step_size;

}

Phys_Container<double>* SubModel_Component::determine_variable_update_rates(){
	Phys_Container<double>* update_rates = new Phys_Container<double>;
	Phys_Container<Link_layer_Component>* components = get_components();
	while(components->hasMoreVariables()){
		update_rates->addtoList(components->getNextItem()->determine_variable_update_rates());
	}
	return update_rates;
}
Component* SubModel_Component::get_ModelComponent_by_name(System::String^ name){
	char* name2 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name);
	Component* cmp = get_ModelComponent_by_name(name2);
	System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void *)name2);
	return cmp;

}
Component* SubModel_Component::get_ModelComponent_by_name(char *name){
	Phys_Container<link_layer::Link_layer_Component>* cmps = this->get_runnable_components();
	cmps->reset_iterator();
	while(cmps->hasMoreVariables()){
		link_layer::Component *comp = (link_layer::Component*)cmps->getNextItem();
		if(strcmp(comp->get_name(),name)==0){
			return (comp); 
		}
	}
	return NULL;

}

		
/*
Given the target component , the components which has the same anatomical structure
as the target are searched.
*/
Phys_Container<Component>* SubModel_Component::find_components_by_AS(Component* target){

	Phys_Container<Component>* as_components = new Phys_Container<Component>;
	Phys_Container<link_layer::Link_layer_Component>* source_components = get_runnable_components();
	link_layer::Component *source ;
	while(source_components->hasMoreVariables()){
		source = (link_layer::Component*) source_components->getNextItem();
		if(source->get_anatomical_structure()!=NULL){
			if(source->get_anatomical_structure() == target->get_anatomical_structure()){
				as_components->addItem(source);
			}
		}
	}
	return as_components;
}

/*
Given the target component , the components which are in the arterial supply list of the target are searched.
*/
Phys_Container<Component>* SubModel_Component::find_components_by_arterial_supply(Component* target){
		
	Phys_Container<Component>* supply_components = new Phys_Container<Component>;
	Phys_Container<FMAID>* arterial_components = new Phys_Container<FMAID>;
	Phys_Container<Anatomical_entity> entitites = target->get_anatomical_structure()->get_arterial_supply();
	while(entitites.hasMoreVariables()){
		arterial_components->addItem(entitites.getNextItem()->get_FMAID());
	}
	
	Phys_Container<link_layer::Link_layer_Component>* source_components = get_runnable_components();
	link_layer::Component *source ;

	while(arterial_components->size()>0 && source_components->hasMoreVariables()){
		source = (link_layer::Component*) source_components->getNextItem();
		if(source->get_anatomical_structure()!=NULL){
			if( arterial_components->contains((source->get_anatomical_structure()->get_FMAID()))){
				supply_components->addItem(source);
			}
		}
	}
	return supply_components;
}
/*
Given the target component , the components which are in the venous drainage list of the target are searched.
*/

Phys_Container<Component>* SubModel_Component::find_components_by_venous_drainage(Component* target){
		
	Phys_Container<Component>* drainage_components = new Phys_Container<Component>;
	Phys_Container<FMAID>* venous_components = new Phys_Container<FMAID>;

	Phys_Container<Anatomical_entity> entitites = target->get_anatomical_structure()->get_venous_drainage();
	while(entitites.hasMoreVariables()){
		venous_components->addItem(entitites.getNextItem()->get_FMAID());
	}

	Phys_Container<link_layer::Link_layer_Component>* source_components = get_runnable_components();
	link_layer::Component *source ;
	while(venous_components->size()>0 && source_components->hasMoreVariables()){
		source = (link_layer::Component*) source_components->getNextItem();
		if(source->get_anatomical_structure()!=NULL){
			if( venous_components->contains(source->get_anatomical_structure()->get_FMAID())){
				drainage_components->addItem(source);
			}
		}
	}
	return drainage_components;
}
/*
Given the target component , the components which are the part of the target are searched.
*/

Phys_Container<Component>* SubModel_Component::find_components_by_part(Component* target){
	Phys_Container<Component>* part_components = new Phys_Container<Component>;
	Phys_Container<link_layer::Link_layer_Component>* source_components = get_runnable_components();
	link_layer::Component *source ;
	Phys_Container<FMAID> parts_list = new Phys_Container<FMAID>;
	Phys_Container<Anatomical_entity> entities =  target->get_anatomical_structure()->get_parts();	
	while(entities.hasMoreVariables()){
		parts_list.addItem(entities.getNextItem()->get_FMAID());
	}
	while(parts_list.size()>0 && source_components->hasMoreVariables()){
		source = (link_layer::Component*) source_components->getNextItem();
		if(source->get_anatomical_structure()!=NULL){
			if(parts_list.contains(source->get_anatomical_structure()->get_FMAID())){
				part_components->addItem(source);
			}
		}

	}
	return part_components;
}

/*Hidden Component*/
Hidden_Component::~Hidden_Component()
{
}
Hidden_Component::Hidden_Component(Component *cmp){
	master_component = cmp;
}

Phys_Container<Link_layer_Component>* Hidden_Component::get_predecessor_components(){
	return master_component->get_predecessor_components();

}

Phys_Container<Link_layer_Component>* Hidden_Component::get_successor_components(){
	return master_component->get_successor_components();
}

void Hidden_Component::add_successor_component(Link_layer_Component *successor){
	if(!(master_component->get_successor_components()->contains(successor))){
		master_component->get_successor_components()->addItem(successor);
	}

	successor->add_predecessor_component(master_component);
}

void Hidden_Component::add_predecessor_component(Link_layer_Component *predecessor){
	if(!(master_component->get_predecessor_components()->contains(predecessor))){
		master_component->get_predecessor_components()->addItem(predecessor);
	}	
}

Phys_Container<Semantic_Converter>* Hidden_Component::get_input_semantic_converters(){
	return  master_component->get_input_semantic_converters();

}

void Hidden_Component::add_input_semantic_converter(Semantic_Converter *sem_conv){
	get_input_semantic_converters()->addItem(sem_conv);
}


Phys_Container<Semantic_Converter>* Hidden_Component::get_output_semantic_converters(){
	return  master_component->get_output_semantic_converters();
	
}

void Hidden_Component::add_output_semantic_converter(Semantic_Converter *sem_conv){
	get_output_semantic_converters()->addItem(sem_conv);
}

Phys_Container<Link_layer_Component>* Hidden_Component:: get_runnable_components(){
	return NULL;
}
void Hidden_Component::update_variable(double current_time){
	;
}

Component* Hidden_Component::get_master(){
	return master_component;
}

physiological_layer::Physiological_Variable* Hidden_Component::get_variable(){
	return master_component->get_variable();
}



/*Memory_Component*/

Memory_Component::Memory_Component(Component *cmp) :  Hidden_Component(cmp){
	char *new_name = new char(strlen(cmp->get_name())+strlen("_memory"));
	history_value = new double;
	strcpy(new_name,cmp->get_name());
	set_name(strcat(new_name,"_memory"));
}

Memory_Component::~Memory_Component(){
}

double* Memory_Component::get_value(){
//	physiological_layer::Time_course_property *temp = (physiological_layer::Time_course_property*)m_Physiological_Variable->get_temporal_property();
	/*physiological_layer::Time_course_property *temp  = (physiological_layer::Time_course_property*)(get_master()->get_variable()->get_temporal_property());
	double *value;
	if(temp!=NULL){
		value = temp->get_state_variable(get_variable()->get_local_time()- get_memory_step_size());
	}
	return value;*/
	return history_value;

}
void Memory_Component::update_variable(double current_time){

	physiological_layer::Time_course_property *temp  = (physiological_layer::Time_course_property*)(get_master()->get_variable()->get_temporal_property());
	double *value;
	if(temp!=NULL){
		value = temp->get_state_variable(get_variable()->get_local_time()- get_memory_step_size());
	}
	if(value!=NULL){
		*(history_value) = *(value);
	}
	
}



/*Derivative_Component*/

Derivative_Component::Derivative_Component(Component *cmp){
	master_component = cmp;
	master_component->set_slave(this);
	//TODO: CHECK THIS!EVERY DERIVATIVE IS INITIALLY ZERO???
	master_component->get_variable()->set_derivative(0.0);
	char *new_name = new char(strlen(cmp->get_name())+strlen("_derivative"));
	strcpy(new_name,cmp->get_name());
	set_name(strcat(new_name,"_deri"));
	predecessor_components = master_component->get_predecessor_components();
}

Derivative_Component::~Derivative_Component(){
}

double* Derivative_Component::get_value(){
	return get_master()->get_variable()->get_derivative();
}
Component* Derivative_Component::get_master(){
	return master_component;
}

void Derivative_Component::set_master(Component* master){
	master_component = master;
}

physiological_layer::Physiological_Variable* Derivative_Component::get_variable(){
	return master_component->get_variable();
}

void Derivative_Component::update_variable(double current_time){
	get_variable()->update_derivative(current_time);
	//get_variable()->update_variable();
}

/*Phys_Container<Link_layer_Component>* Derivative_Component::get_predecessor_components(){
	return master_component->get_predecessor_components();
}*/
/*void Derivative_Component::add_successor_component(Link_layer_Component *successor){
	if(!successor_components->contains(successor)){
		successor_components->addItem(successor);
	}

	successor->add_predecessor_component(this);


	Phys_Container<Link_layer_Component>* master_pre = get_predecessor_components();
	while(master_pre->hasMoreVariables()){
		master_pre->getNextItem()->add_successor_component(this);
	}
	
}

void Derivative_Component::add_predecessor_component(Link_layer_Component *predecessor){
	if(!predecessor_components->contains(predecessor)){
		predecessor_components->addItem(predecessor);
	}
	
}*/
