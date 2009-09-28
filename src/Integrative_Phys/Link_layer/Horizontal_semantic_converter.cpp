/**************************************************************************************************
	Horizontal_Semantic_Converter.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description:	Implementation of the Horizontal_Semantic Converter class. It matches the input components to 
					output components which are same level, i.e used for horizontal integration.
					apply_semantic_conversion assigns every component's variable as an input to every component at
					the output port.
					The values of the variables of each component is assigned as an input to the model of the variable
					of the component at the output port.
**************************************************************************************************/
#include "Semantic_Converter.h"

using namespace link_layer;

Horizontal_semantic_converter::Horizontal_semantic_converter(){

}



Horizontal_semantic_converter::~Horizontal_semantic_converter(){

}

/*Default semantic conversion behavior:
	1. Sets the input components' variables' values to the input values of the mathematical models' 
	of the variables' of the output components'.
	NOTE: Values are not copied, but rather the pointers' of the values' are passed.
*/

void Horizontal_semantic_converter::apply_semantic_operation(){
	Phys_Container<Component>* temp_outputs = new Phys_Container<Component>((Phys_Container<link_layer::Component>*)get_outputs());
	Phys_Container<Component>* temp_inputs = new Phys_Container<Component>((Phys_Container<link_layer::Component>*)get_inputs());	
	Phys_Container<double>* ins = new Phys_Container<double>;
	Component* var_input;
	Component *temp_component;


	temp_outputs->reset_iterator();
	//Simply adds every variable in the input port of the semantic converter as an input parameter to every variable
	//at the output port of the semantic converter.
	while(temp_outputs->hasMoreVariables())
	{
		
		temp_component = temp_outputs->getNextItem();
		cout<<"The output is "<<temp_component->get_name()<<endl;
		temp_inputs->reset_iterator();
		cout<<"	the input variables are:"<<endl;
		while(temp_inputs->hasMoreVariables())
		{
			
			var_input = temp_inputs->getNextItem();

			cout<<"	"<<var_input->get_variable()->get_name()<<endl;
			double *temp_value = new double;
			//temp_value = (var_input->get_variable()->get_value());
			temp_value = (var_input->get_value());
			ins->addItem(temp_value);
		}
		
		computational_layer::Mathematical_Model* mm = temp_component->get_variable()->get_Model();
		mm->set_inputs(ins);
	}
}