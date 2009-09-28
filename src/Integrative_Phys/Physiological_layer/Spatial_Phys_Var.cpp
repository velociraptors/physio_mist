/*************************************************************************************************
  Spatial_Phys_Var.cpp
  Implementation of the Class Spatial_Phys_Var
  Contributor(s):	E. Zeynep Erson
  Created on:		26-Jul-2007 2:05:26 PM
*************************************************************************************************/

#include "Physiological_layer.h"

#include <iostream>

using namespace physiological_layer;

Spatial_Phys_Var::Spatial_Phys_Var(){

}



Spatial_Phys_Var::~Spatial_Phys_Var(){

}





void Spatial_Phys_Var::add_Model(computational_layer::Mathematical_Model model){

}


Physiological_Variable* Spatial_Phys_Var::get_sources(){

	return new Physiological_Variable;
}


void Spatial_Phys_Var::run_Model(){

}


void Spatial_Phys_Var::set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space){

}


void Spatial_Phys_Var::update_variable(){

}