/**************************************************************************************************
	Circulatory_Phys_Variable.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description:	Sub-class of Physiological variable.
**************************************************************************************************/

#include "Physiological_layer.h"

using namespace physiological_layer;
Circulatory_Phys_Variable::Circulatory_Phys_Variable(){

}



Circulatory_Phys_Variable::~Circulatory_Phys_Variable(){

}





void Circulatory_Phys_Variable::add_Model(computational_layer::Mathematical_Model model){

}


Physiological_Variable* Circulatory_Phys_Variable::get_sources(){

	return  new Physiological_Variable;
}


void Circulatory_Phys_Variable::run_Model(){

}


void Circulatory_Phys_Variable::set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space){

}


void Circulatory_Phys_Variable::update_variable(){

}