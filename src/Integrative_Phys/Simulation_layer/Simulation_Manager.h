#ifndef _SIMULATION_LAYER_H
#define _SIMULATION_LAYER_H


#include "link_layer.h"
#include "model.h"
#include "factory.h"
#include <fstream>


class Simulation_Manager
{
public:
	//Constructors
	Simulation_Manager(void);
	Simulation_Manager(int _step_type);
	~Simulation_Manager(void);
	
	void simulate(Phys_Container<double>* time_step);
	void set_mediator(link_layer::Mediator *_mediator);
	bool determine_time_step_type();	

	//creating the link_layer
	link_layer::Mediator *create_Mediator(Phys_Container<Model> mml_models);
	static void createSemanticConverters(Model *mml_model, link_layer::Mediator *intrinsic_mediator,double *t_delta);
	
	
	//Simulation parameter setting functions
	void set_t_component(link_layer::Component *time);
	void set_t_min_component(link_layer::Component *time);
	void set_t_max_component(link_layer::Component *time);
	void set_t_delta_component(link_layer::Component *time);
	void set_is_fixed_time_step(bool fixed);
	bool get_is_fixed_time_step();

	void set_time_step(Phys_Container<double>* time);
	void set_time_step(double time);
	void set_start_time(double start);
	void set_end_time(double end);
	Phys_Container<double>* get_time_step();
	int get_step_type();
	void set_step_type(int _type);
	void set_CT_solver(int type);

	//Simulation result reporting
	void set_report_environment(char *filename);
	void report_simulation_results( int iteration);
	void create_matlab_file();
	
	link_layer::Mediator *mediator;

protected:
	void update_current_time(double time_step);

private:
	int step_type;
	int CT_solver;

	link_layer::Component *t_component;
	link_layer::Component *t_min_component;
	link_layer::Component *t_max_component;
	link_layer::Component *t_delta_component;

	ofstream result_report;
	vector<vector<double>> result_matrix;

	Physiological_Factory *factory;



};
#endif
