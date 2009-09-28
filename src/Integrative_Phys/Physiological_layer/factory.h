/*
Date: September 2007
Contributor(s):E. Zeynep Erson
Description: A Singleton class, used to generate the essential components such as :
		phsyiological variable,
		component,
		semantic converter.
	Instances of these classes require lots of parameters most of which will be obtained from the user.
	Once these parameters/preferences are collected from the user, they will be passed to the proper factory method.
*/

#ifndef _FACTORY_H
#define _FACTORY_H

#include <list>
#include <iostream>
#include "Physiological_layer.h"
#include "Link_layer.h"
#include "Circulatory_System.h"
#include "Semantic_Converter.h"

const static int DISCRETE_TIME = 1;
const static int DISCRETE_EVENT = 2;
const static int EULER_COMPUTATION = 3;
const static int RUNGE_KUTTA_2 = 4;
const static int RUNGE_KUTTA_4 = 5;


const static int INDEPENDENT_VAR = 0;
const static int DEPENDENT_VAR = 1;
const static char *VAR = "_var";

using namespace std;

//Factory class used to create link layer and physiological layer elements 
//based on the user selected preferneces
class Physiological_Factory{

public:
	physiological_layer::Physiological_Variable *physiological_variable;
	static Physiological_Factory* getInstance();
	
	physiological_layer::Physiological_Variable* generate_variable(char *_name, 
						int comp_type, 
						bool is_independent, 
						computational_layer::Mathematical_Model *_mathematical_model,
						double* initial_value,
						char *unit);

	link_layer::Component* generate_component(char *_name, 
						int comp_type, 
						bool is_independent, 
						computational_layer::Mathematical_Model *_mathematical_model,
						double* initial_value,
						char *_unit);

	link_layer::Semantic_Converter*  generate_Semantic_Converter(link_layer::Semantic_Converter *sem_converter, 
		Phys_Container<link_layer::Link_layer_Component>* inputs,
		Phys_Container<link_layer::Link_layer_Component>* outputs);
	
protected:
	Physiological_Factory(){;};
	~Physiological_Factory(){;};
private:
	static Physiological_Factory *instance;
};






#endif