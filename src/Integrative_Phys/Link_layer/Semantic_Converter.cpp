/**************************************************************************************************
	Semantic_Converter.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description:	Implementation of the Semantic Converter class.
					Base class for horizontal, vertical and custom semantic converters. Basic semantic converter
					operation will be overriden in every subclass.
					Has the following ports:
					1.	Input: List of Link_Layer_Components assigned to the input port.
					2.	Output: List of Link_Layer_Components assigned to the output port.
					The matching and processing on the input(s) to match to the output(s) depend on the 
					implementation of the apply_semantic_operation() in sub-semantic_converters.
**************************************************************************************************/

#include "Semantic_Converter.h"

using namespace link_layer;
Semantic_Converter::Semantic_Converter(){
	input_variables = new Phys_Container<Link_layer_Component>;
	output_variables = new Phys_Container<Link_layer_Component>;

}



Semantic_Converter::~Semantic_Converter(){

}





void Semantic_Converter::apply_semantic_operation(){


}

void Semantic_Converter::add_Input(Link_layer_Component* input)
{
	input = this->input_variables->addItem(input);
	input->add_output_semantic_converter(this);
}

void Semantic_Converter::add_Output(Link_layer_Component* output)
{
	output = this->input_variables->addItem(output);
	output->add_input_semantic_converter(this);
}



void Semantic_Converter::set_inputs(Phys_Container<Link_layer_Component> *inputs){
	Semantic_Converter::input_variables = inputs;
	while(inputs->hasMoreVariables()){
		inputs->getNextItem()->add_output_semantic_converter(this);
	}
}

void Semantic_Converter::delete_output(Component *comp){
	get_outputs()->deleteItem(comp);
}


void Semantic_Converter::set_outputs(Phys_Container<Link_layer_Component> *outputs){
	Semantic_Converter::output_variables = outputs;
	while(outputs->hasMoreVariables()){
		outputs->getNextItem()->add_input_semantic_converter(this);
	}
}

/*
Leave the application of the semantic operation to the model compilation
*/
void Semantic_Converter::set_input_output(Phys_Container<Link_layer_Component> *inputs,
										  Phys_Container<Link_layer_Component> *outputs)
{
	set_inputs(inputs);
	set_outputs(outputs);
}

Phys_Container<Link_layer_Component>* Semantic_Converter::get_inputs(){
	return input_variables;
}

Phys_Container<Link_layer_Component>* Semantic_Converter::get_outputs(){
	return output_variables;
}


Semantic_Converter* Semantic_Converter::createSemanticConverter(EquationData *eq, link_layer::Mediator *mediator){		
			
			link_layer::Horizontal_semantic_converter *sem_con = new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container = new Phys_Container<link_layer::Component>;	
			while(eq->getOperands()->hasMoreVariables()){
				char *input = eq->getOperands()->getNextItem();
				if(!isConstant(input)){
					//char *test = strstr(input,":");
					if(strstr(input, ":")!=NULL){
						char *name = new char[strlen(input)];
						strcpy(name,input);
						strtok(input,":");
						

						char *cmp_name =  new char[strlen(input)];
						strcpy(cmp_name,input);

						link_layer::Derivative_Component *_der_comp = (Derivative_Component*)mediator->get_ModelComponent_by_name(strcat(input,"_derivative"));
						if(_der_comp==NULL){

							link_layer::Component *cmp = mediator->get_ModelComponent_by_name(cmp_name);
							_der_comp = new link_layer::Derivative_Component(cmp);
							mediator->add_component(_der_comp);
						}						
						//todo: should we add this to the other mediators that the original component is attached to?
						input_container->addItem(_der_comp);					
					}
					
					else if(strstr(input,"[")!=NULL){
						char *state_variable = new char[strlen(input)];
						strcpy(state_variable,input);
						char *comp_name = strtok(state_variable,"[");
						char *delay = strtok(state_variable,"]");

						//TODO: parse the delay
						//todo: the size of the memory list should not rely on any information from the mathematical component
						// as it may not been initialized yet
						//FOR TEST SET IT TO 30
						//FOR TEST SET index TO 0.2
						//size = delay/step size
						double _delay = 3.0;
						//double index = 0.2


						link_layer::Component *cmp = mediator->get_ModelComponent_by_name(comp_name);
						link_layer::Memory_Component *memory_comp  = new Memory_Component(cmp);
						
						/*The memory component of the variable is not initialized yet*/
						if(cmp->get_variable()->get_temporal_property()==NULL){
							physiological_layer::Time_course_property *time_course = new physiological_layer::Time_course_property;
							//int size = _delay/(cmp->get_variable()->get_sample_time());
							time_course->set_delay(_delay);
							//todo: this is hard-coded for now
							//int size = _delay/0.001;
							int size = _delay/1;
							time_course->set_size(size);
							cmp->get_variable()->set_temporal_property(time_course);
						}

						double memory_step_size;

						//TODO: this shoiuld be done based on the parsing!
						if(strcmp(eq->getOutput(),"N_hrv")==0){
							memory_step_size = 0.2;							
						}
						else{
							memory_step_size = 3.0;							
						}
						memory_comp->set_memory_step_size(memory_step_size);

						mediator->add_component(memory_comp);
						mediator->add_memory_component(memory_comp);
						input_container->addItem(memory_comp);						

					}
					else{
						input_container->addItem(mediator->get_ModelComponent_by_name(input));
					}
					
				}
								
			}
			Phys_Container<link_layer::Component>* output_container = new Phys_Container<link_layer::Component>;	
			char *output = eq->getOutput();
			output_container->addItem(mediator->get_ModelComponent_by_name(output));
			
			sem_con->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container,
										(Phys_Container<link_layer::Link_layer_Component>*)output_container);

		return sem_con;
}

