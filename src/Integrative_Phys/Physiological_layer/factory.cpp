/**************************************************************************************************
	factory.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description:	Implementation of the factory class. It implements the factory design pattern.
					Factory creates physiological_layer and link_layer instances using the required parameters
					These parameters are passed by the user through the user interface.
**************************************************************************************************/

#include "factory.h"


Physiological_Factory* Physiological_Factory::instance = 0;
Physiological_Factory* Physiological_Factory:: getInstance(){
		if (instance==NULL){
			instance = new Physiological_Factory();
		}			
		return instance;

	}
	
physiological_layer::Physiological_Variable* Physiological_Factory::generate_variable(char *_name, 
						int comp_type, 
						bool is_independent, 
						computational_layer::Mathematical_Model *_mathematical_model,
						double* initial_value, char *_unit)
	{
		
		computational_layer::Computation_Model *comp_model;
		switch(comp_type){
			case EULER_COMPUTATION:
				comp_model = new computational_layer::Euler_Computation_Model;
				break;
			case RUNGE_KUTTA_4:
				comp_model = new computational_layer::Runge_Kutta_4(1);
				break;
			case RUNGE_KUTTA_2:
			comp_model = new computational_layer::Runge_Kutta_2;
			break;
			case DISCRETE_EVENT:
				comp_model = new computational_layer::Discrete_Event_Model;
				break;
			case DISCRETE_TIME:
				comp_model = new computational_layer::Discrete_Time_Model;
				break;
			default:
				comp_model = NULL;

		}
		physiological_layer::Physiological_Variable *variable =new physiological_layer::Physiological_Variable(initial_value, _unit);
		variable->set_Independent_Variable(is_independent);

		if(comp_model!=NULL){
			computational_layer::Mathematical_Model *mathematical_model = _mathematical_model;
			mathematical_model->set_Computation_Model(comp_model);
			variable->add_Model(mathematical_model);
		}
		variable->set_name(_name);
		
		return variable;	
}

link_layer::Component* Physiological_Factory::generate_component(char *_name, 
						int comp_type, 
						bool is_independent, 
						computational_layer::Mathematical_Model *_mathematical_model,
						double* initial_value,
						char *_unit)	
{		
	//generate_variable(_name,comp_type,is_independent,_mathematical_model,initial_value);
	link_layer::Component *component = new link_layer::Component;	
	component->set_variable(generate_variable(_name,comp_type,is_independent,_mathematical_model,initial_value,_unit));	
	component->set_name(_name);
	return component;
}


link_layer::Semantic_Converter*  Physiological_Factory::generate_Semantic_Converter(link_layer::Semantic_Converter *sem_converter, 
		Phys_Container<link_layer::Link_layer_Component>* inputs,
		Phys_Container<link_layer::Link_layer_Component>* outputs)
{
		sem_converter->set_input_output(inputs,outputs);			
		
		//for test purposes
		link_layer::Component* d; 
		cout<< "******************************************"<<endl;
		while(inputs->hasMoreVariables()){
			d = (link_layer::Component*)inputs->getNextItem();
			std::cout<<"The current value for input variable in equation 29 is"<<d->get_value()<<std::endl;
		}

		return sem_converter;
}

/*link_layer::Circulatory_Mediator* Physiological_Factory::generate_Circulatory_System(int compartment_size){
	link_layer::Circulatory_Mediator *circ_med = new link_layer::Circulatory_Mediator(compartment_size);
	return circ_med;

}*/
