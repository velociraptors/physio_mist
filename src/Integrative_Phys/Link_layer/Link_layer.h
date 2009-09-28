#ifndef _LINK_LAYER_H
#define _LINK_LAYER_H

#include "Physiological_layer.h"
#include "utilities.h"
#include "Organ_region.h"





namespace link_layer{
	
	
	class Semantic_Converter;
	class Replacer_semantic_converter;
	class Hidden_Component;
	class Derivative_Component;
	
	class Link_layer_Component
	{
	public:
		Link_layer_Component();
		virtual ~Link_layer_Component();
		

		void set_name(char *newname){
			name = newname;
		};

		char* get_name(){
			return name;
		};

		virtual double determine_fixed_update_rate();
		virtual Phys_Container<double>* determine_variable_update_rates();		
		
		
		virtual void add_successor_component(Link_layer_Component* comp);
		virtual void add_input_semantic_converter(Semantic_Converter* sem_conv);
		virtual void reset_order_info();
		virtual void add_output_semantic_converter(Semantic_Converter* sem_conv);
		
		
		virtual Phys_Container<Link_layer_Component>* get_predecessor_components();
		virtual Phys_Container<Link_layer_Component>* get_successor_components();
		virtual Phys_Container<Semantic_Converter>* get_input_semantic_converters();
		virtual Phys_Container<Semantic_Converter>* get_output_semantic_converters();
		virtual Phys_Container<Link_layer_Component>* get_runnable_components();
		virtual Phys_Container<Semantic_Converter>* get_semantic_converters();

		virtual void deleteSuccessor(Link_layer_Component *succ);
		virtual void deletePredecessor(Link_layer_Component *pre);


	
		void set_color(int _color);
		int get_color();
		int get_order();
		void set_order(int ord);
		virtual bool is_DE_component(){return false;};


		/*TODO: COMPLETE THE IMPLEMENTATION*/
		virtual bool operator==(Link_layer_Component component);

		void set_slave(Derivative_Component *der);
		Derivative_Component* get_slave();


		
	protected:
		virtual void add_predecessor_component(Link_layer_Component* comp);
		Phys_Container<Link_layer_Component>* predecessor_components;
		Phys_Container<Link_layer_Component>* successor_components;
		Phys_Container<Semantic_Converter>* 	input_semantic_converters;
		Phys_Container<Semantic_Converter>* output_semantic_converters;
		Derivative_Component *slave;
		int color;
		int order;
		char *name;
		friend class Hidden_Component;
		

	};
	


	/**
	 * Each colleague class knows its mediator object and communicates with its
	 * mediator whenever it would have otherwise communicated with another colleague.
	 */
	class Component : public Link_layer_Component
	{

	public:
		Component();
	    Component(physiological_layer::Physiological_Variable *phys_var);
		virtual ~Component();

		virtual double determine_fixed_update_rate();
		virtual Phys_Container<double>* determine_variable_update_rates();
		void set_variable(physiological_layer::Physiological_Variable *variable);
		void set_anatomical_structure(Anatomical_structure *str);		
		virtual bool is_DE_component();
		virtual void update_variable(double current_time);
		virtual double* get_value();
		virtual physiological_layer::Physiological_Variable* get_variable();
		
		Anatomical_structure* get_anatomical_structure();
		virtual Phys_Container<FMAID>* get_arterial_supply();
		virtual Phys_Container<FMAID>* get_venous_drainage();
		virtual Phys_Container<FMAID>* get_nerve_supply();
		

		/*TODO: COMPLETE THE IMPLEMENTATION*/
		virtual bool operator==(Component component);

		void replace_with(Component *source,Replacer_semantic_converter *replacer);

	protected:
		physiological_layer::Physiological_Variable *m_Physiological_Variable;

	private:
		Anatomical_structure *anatomical_structure;
		Phys_Container<FMAID>* arterial_supply;
		Phys_Container<FMAID>* venous_drainage;
		Phys_Container<FMAID>* nerve_supply;
		



	};
	class Hidden_Component: public Component
	{
	public:
		Hidden_Component();
		Hidden_Component(Component *comp);
		virtual ~Hidden_Component();

		virtual void add_successor_component(Link_layer_Component* comp);
		
		virtual void add_input_semantic_converter(Semantic_Converter* sem_conv);
		virtual void add_output_semantic_converter(Semantic_Converter* sem_conv);
		
		virtual Phys_Container<Link_layer_Component>* get_predecessor_components();
		virtual Phys_Container<Link_layer_Component>* get_successor_components();
		virtual Phys_Container<Semantic_Converter>* get_input_semantic_converters();
		virtual Phys_Container<Semantic_Converter>* get_output_semantic_converters();
		virtual Phys_Container<Link_layer_Component>* get_runnable_components();
		virtual void update_variable(double current_time);
		virtual physiological_layer::Physiological_Variable* get_variable();

		Component* get_master();

	private:
		virtual void add_predecessor_component(Link_layer_Component* comp);
		Component *master_component;

	};

	/*
	Memory component, contains a physiological variable, whose temporal attribute is a time_course temporal one;
	i.e stores the previous states of the variable based on the size of the memory
	*/
	class Memory_Component : public Hidden_Component
	{

	public:
		Memory_Component();
		Memory_Component(Component *comp);
		virtual ~Memory_Component();
		virtual double* get_value();
		virtual void update_variable(double current_time);

		void set_memory_step_size(double _size){memory_step_size = _size;};
		double get_memory_step_size(){return memory_step_size;};

	private:
		double memory_step_size;
		double *history_value;

	};

	/*This class is to attach the the derivative of a variable to a component 
	so that it will be an input to a semantic converter*/
	class Derivative_Component : public Component
	{
	public:
		Derivative_Component();
		//Derivative_Component(physiological_layer::Physiological_Variable *phys_var);
		Derivative_Component(Component *comp);
		virtual ~Derivative_Component();
		virtual double* get_value();
		Component* get_master();
		void set_master(Component* master);
		virtual physiological_layer::Physiological_Variable* get_variable();
		virtual void update_variable(double current_time);

	protected:
		//virtual void add_predecessor_component(Link_layer_Component* comp);
		
	private:
		Component *master_component;
	};
	/*
	SubModel_Component: A component which contains a model, a container component
	*/
	class SubModel_Component : public Component
	{
	public:
		SubModel_Component();
		SubModel_Component(char *name);
		virtual ~SubModel_Component();
		void add_component(Link_layer_Component* component);
		void add_memory_component(Memory_Component *mem_comp);
		void add_semantic_converter(Semantic_Converter *sem_converter);
		void add_to_integrators(Semantic_Converter *sem_converter);

		Component* get_ModelComponent_by_name(char *name);
		Component* get_ModelComponent_by_name(System::String^ name);
		virtual Phys_Container<Memory_Component>* get_memory_components();


		Phys_Container<Component>* find_components_by_AS(Component* target);
		Phys_Container<Component>* find_components_by_arterial_supply(Component* target);
		Phys_Container<Component>* find_components_by_venous_drainage(Component* target);
		Phys_Container<Component>* find_components_by_part(Component* target);

		virtual Phys_Container<Link_layer_Component>* get_components();		
		virtual Phys_Container<Link_layer_Component>* get_runnable_components();
		virtual Phys_Container<Semantic_Converter>* get_semantic_converters();
		virtual double determine_fixed_update_rate();
		virtual Phys_Container<double>* determine_variable_update_rates();		
		
	private:
		Phys_Container<Semantic_Converter> *semantic_converter_list;
		
	protected:
		Phys_Container<Link_layer_Component>* component_list;
		Phys_Container<Memory_Component>* memory_component_list;
	};
	
	class Director:public Link_layer_Component
	{

	public:
		Director();
		virtual ~Director();

		void find_simulation_time_step();
		void increment_time_step();

	private:

		double global_time;
		bool isFixedTimeStep;
		double simulation_time_step;

	};

	/**
	 * This class defines an interface for communicating with Colleague objects.
	 */
	class Mediator:public SubModel_Component
	{

	public:
		Mediator();
		Mediator(char *name);
		virtual ~Mediator();


		//Model and order related methods
		void compile_model();		
		void check_DE_queue(int global_time);		
		void resolve_cycles();
		int get_order();
		void set_order(int ord);

		//Related to components
		virtual Phys_Container<Link_layer_Component>* get_components();	
		void remove_component(Link_layer_Component *component);
		void add_to_ordered_components(Link_layer_Component* item);
		void run_components(double current_time,bool major);
		void run_components(double current_time,Phys_Container<Component> *list);
		void run_minor_step_components(double current_time);
		void replace_component(Component *target, Component *source, Mediator *source_mediator);
		Phys_Container<Link_layer_Component>* get_ordered_components();

		Phys_Container<Replacer_semantic_converter>* get_integrators();
		void add_to_integrators(Replacer_semantic_converter *replacer);

		//Integration of components by mediators
		
		/*
		horizontal integration methods:
		1. Components with same anatomical structure
		2. Components associated with information flow mechanism:
			a. Circulatory system--arterial supply/venous drainage
			b. Nervous system--nervous supply

		vertical integration methods:
		1. Components with part/part_of/constitutional relations
		*/
		void integrate_Mediators(Phys_Container<Component> *target_comps, Phys_Container<Component> *source_comps, Mediator *source_mediator);
		Replacer_semantic_converter* define_horizontal_integration_point(char *name, Mediator *mediator);
		Replacer_semantic_converter* define_vertical_integration_point(char *name, Mediator *mediator);



	
	protected:
		Phys_Container<Link_layer_Component> *ordered_components;
		Phys_Container<Link_layer_Component> *vip_list;

	private:		
		Director *m_Director;
		Phys_Container<Link_layer_Component> *DE_queue;
		Phys_Container<Replacer_semantic_converter> *integrators;
		

		void build_DAG();
		void build_DE_queue();
		void build_DG();
		bool resolve_cycles(Component *item, Component *root);
		void topological_sort(Phys_Container<Link_layer_Component>* dag);
		void visit_DFS(Link_layer_Component *component);
		int order;

	};

};

#endif
