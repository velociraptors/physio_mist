/**************************************************************************************************
	Replacer_semantic_converter.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		October 2007
	Description:	Is-a type of horizontal semantic converter. 
					It will perform replacement type of integration between the input and output components
					The input component will replace the output component once the semantic compatibility is validated.
					In order to replace the output with the input; following procedure is followed:
						All the semantic converters which has the target at the output port, removes target from the output port
							and the semantic converter is deleted from the semantic converter list of the target
						All the semantic converters which has the target at the input port, removes target from the input port
							and the semantic converter is deleted from the semantic converter list of the target
							and the source is added to the input port
	Restrictions:	Being different from the horizontal semantic converter, replacer_semantic_converters;
						MUST have ONLY ONE input and ONLY ONE output component.
					Semantic compatibility checks are performed at the apply_semantic_converter() method

**************************************************************************************************/
#include "Semantic_Converter.h"
#include <assert.h>
using namespace link_layer;

Replacer_semantic_converter::Replacer_semantic_converter(){

}

Replacer_semantic_converter::~Replacer_semantic_converter(){

}


Replacer_semantic_converter* Replacer_semantic_converter::create_replacer_semantic_converter(char *target_name, link_layer::Mediator *target_mediator, char *source_name, link_layer::Mediator *source_mediator){
	link_layer::Replacer_semantic_converter *replacer = new link_layer::Replacer_semantic_converter;
	Phys_Container<link_layer::Link_layer_Component> *targets = new Phys_Container<link_layer::Link_layer_Component>;
	targets->addItem(target_mediator->get_ModelComponent_by_name(target_name));
	Phys_Container<link_layer::Link_layer_Component> *sources = new Phys_Container<link_layer::Link_layer_Component>;
	sources->addItem(source_mediator->get_ModelComponent_by_name(source_name));
	replacer->set_input_output(sources,targets);
	return replacer;

}
/*

Requires semantic comparison for the compatibality of the variables.
The anatomical entities attached to the input and output variables should be same level anatomical structures
todo: think about the concept of "same level". Does same level mean identical anatomical structures??
Or can the source variable can have an anatomical entity which has the anatomical entity of the target as a part??
note: for now assume that they should be identical.


Although it accepts a list of inputs and outputs, the list SHOULD contain, ONE element each.
All the semantic converters which has the target at the output port, removes target from the output port
	and the semantic converter is deleted from the semantic converter list of the target
All the semantic converters which has the target at the input port, removes target from the input port
	and the semantic converter is deleted from the semantic converter list of the target
	and the source is added to the input port
*/

void Replacer_semantic_converter::apply_semantic_operation(){

	
	//make the semantic check:
	Phys_Container<Component> *inputs = (Phys_Container<Component> *)get_inputs();
	Phys_Container<Component> *outputs = (Phys_Container<Component> *)get_outputs();
		
	assert((inputs->size()==1) && (outputs->size()==1));
	inputs->reset_iterator();
	outputs->reset_iterator();

	if((inputs->getNextItem())->get_anatomical_structure()==(outputs->getNextItem())->get_anatomical_structure())
	{

		Phys_Container<double>* ins = new Phys_Container<double>;
		Component* input_variable;
		Component *target;
		Component *source;


		outputs->reset_iterator();
		inputs->reset_iterator();
		while(outputs->hasMoreVariables() && inputs->hasMoreVariables())
		{
			target = outputs->getNextItem();
			source = inputs->getNextItem();

			target->replace_with(source,this);
		
		}
	}
	else
	{
		//todo:throw an exception;
		//which will be caught by the ui and the user will be warned for the selection
	}
}

void Replacer_semantic_converter::set_input_output(Phys_Container<Link_layer_Component> *inputs, Phys_Container<Link_layer_Component> *outputs)
{
	set_inputs(inputs);
	set_outputs(outputs);
}



