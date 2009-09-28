#ifndef _SEMANTIC_CONVERTER_H
#define _SEMANTIC_CONVERTER_H
#include <list>
#include "utilities.h"
#include "Link_layer.h"
namespace link_layer{

	
	class Semantic_Converter
	{	
	public:
		Semantic_Converter();
		virtual ~Semantic_Converter();

		virtual void apply_semantic_operation();
		void add_Input(Link_layer_Component* input);
		void add_Output(Link_layer_Component* output);
		virtual void set_input_output(Phys_Container<Link_layer_Component> *inputs, Phys_Container<Link_layer_Component> *outputs);
		Phys_Container<Link_layer_Component>* get_inputs();
		Phys_Container<Link_layer_Component>* get_outputs();
		void delete_output(Component *comp);
		static Semantic_Converter* createSemanticConverter(EquationData *eq, link_layer::Mediator *mediator);
	
	protected:

		void set_inputs(Phys_Container<Link_layer_Component> *inputs);
		void set_outputs(Phys_Container<Link_layer_Component> *outputs);

	private:
		Phys_Container<Link_layer_Component> *input_variables;
		Phys_Container<Link_layer_Component> *output_variables;

	};

	
	class Vertical_semantic_converter : public Semantic_Converter
	{

		public:
			Vertical_semantic_converter();
			virtual ~Vertical_semantic_converter();

			virtual void apply_semantic_operation();
			//void set_inputs(Physiological_Variable inputs);
			//void set_outputs(Physiological_Variable outputs);

	};

		
	class Horizontal_semantic_converter : public Semantic_Converter
	{

		public:
			Horizontal_semantic_converter();
			virtual ~Horizontal_semantic_converter();

			virtual void apply_semantic_operation();

	};

	class Replacer_semantic_converter : public Horizontal_semantic_converter
	{

		public:
			Replacer_semantic_converter();
			virtual ~Replacer_semantic_converter();

			static Replacer_semantic_converter* create_replacer_semantic_converter(char *target_name, 
				link_layer::Mediator *target_mediator,
				char *source_name, 
				link_layer::Mediator *source_mediator);
			
			virtual void set_input_output(Phys_Container<Link_layer_Component> *inputs, Phys_Container<Link_layer_Component> *outputs);
			virtual void apply_semantic_operation();
					
	};

}
#endif