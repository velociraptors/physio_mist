#ifndef _PHYSIOLOGICAL_LAYER_H
#define _PHYSIOLOGICAL_LAYER_H

#include "Computational_layer.h"

namespace physiological_layer{

	class State_Variable;
	class Physiological_Variable;

	class Qualitative_property
	{

		public:
			Qualitative_property();
			virtual ~Qualitative_property();

	};

	class Quantitative_property
	{

		public:
			Quantitative_property();
			virtual ~Quantitative_property();

	};

	class Scalar_property : public Qualitative_property
	{

		public:
			Scalar_property();
			virtual ~Scalar_property();

	};


	


	class Vectoral_property : public Qualitative_property
	{

		public:
			Vectoral_property();
			virtual ~Vectoral_property();

	};


	class Temporal_property
	{

		public:
			Temporal_property();
			virtual ~Temporal_property();

	};

	class Time_course_property : public Temporal_property
	{
		
	public:
		Time_course_property();
		Time_course_property(int size);
		virtual ~Time_course_property();

		double* get_state_variable(double index);
		double get_delay(){return delay;};
		int get_size(){ return size;};
		void set_delay(double _delay){delay = _delay;};
		void set_size(int _size){size = _size;};
		void add_state_variable(double index, double variable);

	private:
		Phys_Container<State_Variable> previous_variables;
		int size;
		double delay;
		
	};


	class Field_property : public Quantitative_property
	{

		public:
			Field_property();
			virtual ~Field_property();

	};
	
	class Physiological_Variable
	{
		

		public:
			Physiological_Variable();
			Physiological_Variable(double* new_value, char* unit);
			virtual ~Physiological_Variable();			


			void add_Model(computational_layer::Mathematical_Model *model);
			void update_variable(double current_time);	
			void update_derivative(double current_time);
			void set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space);
			void set_Independent_Variable(bool is_independent);
			void set_name(char *_name);
			void set_temporal_property(Temporal_property *prop);
			void update_local_time();
			void update_local_time(double current_time);
			void reset_local_time();

			virtual double* get_value();
			char* get_Model_Info();
			char *get_name();
			double get_local_time();
			double* get_derivative();
			double get_sample_time();
			computational_layer::Mathematical_Model* get_Model();
			Physiological_Variable* get_sources();
			Temporal_property* get_temporal_property(){return m_Temporal_property;};

			bool is_variable_DE();
			bool is_Independent_Variable();
			bool operator==(const Physiological_Variable &v1);

			char* get_unit(){return unit;};
			void set_unit(char *_unit){unit = _unit;};


/*todo: I want to limit the access to get_value(). But if I make it protected/private, Component cannot access it.
if i make component a friend class then, I violate the dependency rule. Normally Physiological_layer.h does not have any
dependency on link layer.
*/
			/*	protected:
		virtual double* get_value();*/
		
	//TODO: IMPORATANT!!JUST TO UPDATE THE TIME MORE PRACTICALLY!!MOVE BACK TO PRIVATE LIST ONCE THE TIME UPDATE
			//WITH THE MINOR STEPS IS RESOLVED!!
			void set_variable(double _new_value);
			void set_derivative(double _new_value);
	private:
		//void set_variable(double _new_value);
		

		//Semantic_Converter *m_Semantic_Converter;
		Quantitative_property *m_Quantitative_property;
		Temporal_property *m_Temporal_property;
		Qualitative_property *m_Qualitative_property;

		computational_layer::Mathematical_Model *m_Mathematical_Model;
		bool is_independent_variable;
		Qualitative_property qualitative_property;
		Quantitative_property quantitative;
		Temporal_property time_property;
		double* value;
		double* derivative;
		char *unit;
		bool is_DE;
		char *name;

	};

	class State_Variable{
	public:
		State_Variable(){
			index = NULL;
			value = NULL;
		};
		State_Variable(double _index,double _value){
			index = _index;
			value = new double(_value);
			//*value = _value;
		};
		~State_Variable();

		void set_index(double _index){
			index = _index;
		};

		void set_value(double _value){
			*value = _value;
		};

		double get_index(){
			return index;
		};
		
		double* get_value(){
			return value;
		};
	private:
		double index;
		double *value;

	};
/*
	//todo: implement hash table for state variables
	class State_Physiological_Variable : public Physiological_Variable{
	public:
		State_Physiological_Variable(double new_value, char* unit) : Physiological_Variable(new_value,unit);
		State_Physiological_Variable(int size);
		~State_Physiological_Variable();




	private:
		double get_state_variable(double index);
		void set_delay(double _delay);
		double get_delay();

		void add_state_variable(double index, double variable);
		
		Phys_Container<State_Variable> state_variables;
		int size;
		double delay;
		Physiological_Variable *variable;
	};

		
*/

	class Nervous_Phys_Var : public Physiological_Variable
	{

		public:
			Nervous_Phys_Var();
			virtual ~Nervous_Phys_Var();

			void add_Model(computational_layer::Mathematical_Model model);
			Physiological_Variable* get_sources();
			void run_Model();
			void set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space);
			void update_variable();

	};


	class Single_point_property : public Quantitative_property
	{

	public:			
		Single_point_property();			
		virtual ~Single_point_property();

	};

	class Single_Time_property : public Temporal_property
	{		
	public:
		Single_Time_property();
		virtual ~Single_Time_property();


	};

	class Spatial_Phys_Var : public Physiological_Variable
	{

		public:
			Spatial_Phys_Var();
			virtual ~Spatial_Phys_Var();

			void add_Model(computational_layer::Mathematical_Model model);
			Physiological_Variable* get_sources();
			void run_Model();
			void set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space);
			void update_variable();

	};

	class Circulatory_Phys_Variable : public Physiological_Variable
	{

		public:
			Circulatory_Phys_Variable();
			virtual ~Circulatory_Phys_Variable();

			void add_Model(computational_layer::Mathematical_Model model);
			Physiological_Variable* get_sources();
			void run_Model();
			void set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space);
			void update_variable();

	};

	class Pressure_Physiological_Variable : public Physiological_Variable
	{
	public:
		Pressure_Physiological_Variable();
		virtual ~Pressure_Physiological_Variable();


	};
	class Flow_Physiological_Variable : public Physiological_Variable
	{
	public:
		Flow_Physiological_Variable();
		virtual ~Flow_Physiological_Variable();


	};
	
};


#endif