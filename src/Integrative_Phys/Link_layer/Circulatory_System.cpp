/************************************************************************************************
  Implementation of the Circulatory System Mediator
  Contributor(s):	E. Zeynep Erson
  Created on:		September, 2007
  Description:		Implements the Circulatory system with Singleton Pattern.
  Members:			1. Intrinsic Mediator: Encapsulates the models related to the intrinsic variables 
					   of the circulatory system, like:
					   a. Pressure
					   b. Volume
					   c. Compliance, etc.
					2. Extrinsic Mediator: Encapsulates the models related to the information carried
					   by the circulatory system, using the dynamics defined in the intrinsic mediator
					   a. Gas concentrations
					   b. Chemical concentrations, etc.
************************************************************************************************/
#include "Circulatory_System.h"
#include <iostream>

using namespace link_layer;

/*Circulatory_Mediator* Circulatory_Mediator::instance = 0;
Circulatory_Mediator* Circulatory_Mediator:: getInstance(){
		if (instance==NULL){
			instance = new Circulatory_Mediator();
		}
		else{
			return instance;
		}
	}

*/
Circulatory_Mediator::Circulatory_Mediator(){
	extrinsic_mediator = new Mediator();
	intrinsic_mediator = new Mediator();

	//create the anatomical structures associated with this mediator
	//when the organ system class is created, use it to instantiate cardiovascular system
	//when these instances are created they will be created with the parts assigned.
	/*
	when cerating these parts, ID numbers will be assigned to the parts
	
	*/
	Anatomical_structure *cardiovascular_system = new Anatomical_structure();
	
	/*Anatomical_structure *systemic_arterial_system = new Anatomical_structure();
	Anatomical_structure *systemic_venous_system = new Anatomical_structure();
	Anatomical_structure *pulmonary_vascular_system = new Anatomical_structure();
	Anatomical_structure *portal_venous_system = new Anatomical_structure();
	Organ *heart = new Organ();*/
	//NOTE: INSTEAD OF CREATING INSTANCES, JUST FIND THEIR ID's and assign them
	//TODO: THIS IS FOR TEST PURPOSES, IN REALITY, 
	//WE WOULD PARSE THE FILE AND FIND THE INT ID VALUE AND ASSIGN IT
	/*FMAID *systemic_arterial_system = new FMAID(new int(1));
	FMAID *systemic_venous_system = new FMAID(new int(2));
	FMAID *pulmonary_vascular_system = new FMAID(new int(3));
	FMAID *portal_venous_system = new FMAID(new int(4));
	FMAID *heart = new FMAID(new int(5));

	FMAID *body = new FMAID(new int(6));

	cardiovascular_system->add_part(systemic_arterial_system);
	cardiovascular_system->add_part(systemic_venous_system);
	cardiovascular_system->add_part(pulmonary_vascular_system);
	cardiovascular_system->add_part(portal_venous_system);
	cardiovascular_system->add_part(heart);

	cardiovascular_system->add_part_of(body);*/

}
Circulatory_Mediator::~Circulatory_Mediator(){
}




//Adds the mediator as an extrinsic mediator
//TODO:THINK IF ADDING THE EXTRINSIC MEDIATOR'S COMPONENTS TO THE CIRCULATORY MEDIATOR'S COMPONENT LIST
//IS REQUIRED...
void Circulatory_Mediator::set_extrinsic_mediator(Mediator *ext_med){
	extrinsic_mediator = ext_med;
	Phys_Container<Link_layer_Component> *comp_list = extrinsic_mediator->get_components();
	while(comp_list->hasMoreVariables()){
		add_component(comp_list->getNextItem());
	}

	
	//adds the semantic converters to the semantic converter list of the circulatory mediator
	Phys_Container<Semantic_Converter> *sem_converters = extrinsic_mediator->get_semantic_converters();
	while(sem_converters->hasMoreVariables()){
		add_semantic_converter(sem_converters->getNextItem());
	}


	//add the memory components
	Phys_Container<Memory_Component>* memory_components = new Phys_Container<Memory_Component>(ext_med->get_memory_components());
	memory_components->reset_iterator();
	while(memory_components->hasMoreVariables()){
		add_memory_component(memory_components->getNextItem());
	}


}

//Adds the component as an intrinsic component and also adds the component to the component list
void Circulatory_Mediator::set_intrinsic_mediator(Mediator *intr_med){	
	intrinsic_mediator = intr_med;
	//adds the components to the component list of the circulatory mediator
	Phys_Container<Link_layer_Component> *comp_list = intrinsic_mediator->get_components();
	while(comp_list->hasMoreVariables()){
		add_component(comp_list->getNextItem());
	}

	
	//adds the semantic converters to the semantic converter list of the circulatory mediator
	Phys_Container<Semantic_Converter> *sem_converters = intrinsic_mediator->get_semantic_converters();
	while(sem_converters->hasMoreVariables()){
		add_semantic_converter(sem_converters->getNextItem());
	}

	//add the memory components
	Phys_Container<Memory_Component>* memory_components = new Phys_Container<Memory_Component>(intr_med->get_memory_components());
	memory_components->reset_iterator();
	while(memory_components->hasMoreVariables()){
		add_memory_component(memory_components->getNextItem());
	}
}

void Circulatory_Mediator::add_component(Link_layer_Component *comp){	
//	get_components()->addItem(comp);
	component_list->addItem(comp);
}

void Circulatory_Mediator::remove_component(link_layer::Link_layer_Component *component){
	component_list->deleteItem(component);
	ordered_components->deleteItem(component);
	if(extrinsic_mediator->get_components()->contains(component)){
		extrinsic_mediator->get_components()->deleteItem(component);
	}
	else{
		intrinsic_mediator->get_components()->deleteItem(component);
	}
}

/*
Any component can ask for a component whose information is carried trough the blood-streamm.
In order to access that information, there are some anatomical restrictions. 
NOTE TO SELF: however if a component has a value for arterial supply, it means that it will have access
to the blood-stream.
On the other hand,if the circulatory system, does not include some specific part of the circulation, 
like coronary circulation, does this mean that heart won't have access to the variable??
*/
Component* Circulatory_Mediator::get_blood_stream_component(Component *receiving_component,char *variable_name){
	Component *component = extrinsic_mediator->get_ModelComponent_by_name(variable_name);
	//check if the component is accessible to the component asking for the variable
	Phys_Container<FMAID> *arterial_connection =  receiving_component->get_arterial_supply();
	//TODO: instead of comparing the parts of the anatomical structure and the arterial connection of the given component;
	//we should ask (recursively)every part of anatomical structure if 
	//they have a part same as the arterial connection of the given component
	/*while(arterial_connection->hasMoreVariables()){
		if(get_anatomical_structure()->get_parts().contains(arterial_connection->getNextItem())){
			return component;
		}
	}*/
	return NULL;
}
