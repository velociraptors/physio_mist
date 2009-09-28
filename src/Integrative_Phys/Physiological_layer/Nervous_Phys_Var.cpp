/**************************************************************************************************
	Nervous_Phys_Variable.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description: 
**************************************************************************************************/

#include "Physiological_layer.h"

using namespace physiological_layer;
Nervous_Phys_Var::Nervous_Phys_Var(){

}



Nervous_Phys_Var::~Nervous_Phys_Var(){

}





void Nervous_Phys_Var::add_Model(computational_layer::Mathematical_Model model){

}


Physiological_Variable* Nervous_Phys_Var::get_sources(){

	return  new Physiological_Variable;
}


void Nervous_Phys_Var::run_Model(){

}


void Nervous_Phys_Var::set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space){

}


void Nervous_Phys_Var::update_variable(){

}