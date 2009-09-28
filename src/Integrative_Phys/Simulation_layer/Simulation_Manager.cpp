/**************************************************************************************************
	Simulation_Manager.cpp
	Contributor(s): E. Zeynep Erson
	Created on: September 17, 2007
	Description:Simulation_Manager handles the simulation of the mathematical models of the 
				physiological processes.
				Each manager has one Mediator object (from the Link layer).
				Simulation manager determines the simulation step size.
	Following types of simulation steps are possible:
		1.	Fixed step size: Global time of the simulation increases by fixed step sizes.
			1.1 RK4
			1.2 Euler
		2.	Variable step size: Global time of the simulation increases based on the individual's update 
		rates and will vary.
			2.1 RK4
			2.2 Euler
**************************************************************************************************/

#include "Simulation_Manager.h"
#include "mml_models.h"
#include <iostream>
#include <iomanip>

Simulation_Manager::Simulation_Manager(void)
{
	mediator = new link_layer::Mediator;
	factory = Physiological_Factory::getInstance();
	set_step_type(FIXED_TIME);
	//time_step = new Phys_Container<double>;

	t_component = NULL;
	t_min_component = NULL;
	t_max_component = NULL;
	t_delta_component = NULL;
	//set_report_environment("simulation_results.txt");
}
Simulation_Manager::Simulation_Manager(int _step_type)
{
	mediator = new link_layer::Mediator;
	factory = Physiological_Factory::getInstance();
	//	time_step = new Phys_Container<double>;
	set_step_type(_step_type);

	t_component = NULL;
	t_min_component = NULL;
	t_max_component = NULL;
	t_delta_component = NULL;
	//set_report_environment("simulation_results.txt");
}

Simulation_Manager::~Simulation_Manager(void)
{
}

void Simulation_Manager::simulate(Phys_Container<double>* steps){

	double *step;
	double *current_time = (t_component->get_value());
	double limit = *(t_max_component->get_value());
	
	//todo: needs to be modulated
	//for now the below execution is only for rk_4 solver case, with steps, 0,h/2,h/2 and h.
	//if the simulation runs at fixed rate, call the run_components at every step
	//else run run_minor_step_components at intermediate steps

	Phys_Container<link_layer::Component> *comps = (Phys_Container<link_layer::Component>*)mediator->get_ordered_components();
	Phys_Container<link_layer::Component> *initial_list = new Phys_Container<link_layer::Component>;
	comps->reset_iterator();
	link_layer::Component *comp = new link_layer::Component;
	while(comps->hasMoreVariables()){
		comp = comps->getNextItem(); 
		if(*(comp->get_value())==EMPTY_INITIAL_VALUE)
		{
			initial_list->addItem(comp);
		}
	}


	//if fixed_time and if solver is RK4
	int iteration = 0;
	if(get_step_type()==FIXED_TIME && CT_solver == RK4){
		step = t_delta_component->get_value();
		
		//RK4
		while(limit - *(current_time)>EPSILON)
		{			
					
			if((0.0110625-*(current_time))<= EPSILON)
			{
				int i=6;
			}
			(result_report)<<"-------------------major TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			(result_report)<<"\t"<<(*current_time);
			
			//major step
			//runge-kutta4-step4
			if(iteration==0){
				mediator->run_components(*(current_time),initial_list);
				report_simulation_results(iteration);
			}
			else{
				
				mediator->run_components(*(current_time), true);
				report_simulation_results(iteration);
			}
			
			update_current_time((*step)/2);

				
			//minor step1
			//runge-kutta4-step1
			mediator->run_components(*(current_time), false);


			//minor step2
			//runge-kutta4-step2
			mediator->run_components(*(current_time),false);

			update_current_time((*step)/2);
						

			
			//minor step3
			//runge-kutta4-step3
			mediator->run_components(*(current_time),false);
			

			iteration++;
		}
		
		//EULER
	/*	while(limit - *(current_time)>EPSILON)
		{			
			(result_report)<<"-------------------major TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			(result_report)<<"\t"<<(*current_time);
			mediator->run_components(*(current_time));
			report_simulation_results(iteration);
			update_current_time((*step));
			iteration++;
		}*/

	}
	//if variable time and if solver is NOT rk4
	//TODO: NOT VALIDATED, CHECKED YET!
	else if(get_step_type()!=FIXED_TIME && CT_solver == RK4){
		step = steps->getNextItem();
		while(limit - *(current_time)>EPSILON)
		{			
			(result_report)<<"-------------------major TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			mediator->run_components(*(current_time), true);
			//mediator->print_values_of_components(&(result_report),result_matrix);
			report_simulation_results(iteration);
			update_current_time((*step)/2);
			(result_report)<<"-------------------minor TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			mediator->run_minor_step_components(*(current_time));
			//mediator->print_values_of_components(&(result_report),result_matrix);
			report_simulation_results(iteration);
			
			(result_report)<<"-------------------minor TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;			
			mediator->run_minor_step_components(*(current_time));
			//mediator->print_values_of_components(&(result_report),result_matrix);			
			report_simulation_results(iteration);
			update_current_time((*step)/2);
			(result_report)<<"-------------------minor TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			mediator->run_minor_step_components(*(current_time));
			//mediator->print_values_of_components(&(result_report),result_matrix);
			report_simulation_results(iteration);
			//update_current_time(*step);
			iteration++;
		}

	}
	/*
	Variable time step case:
		1. Find all the update rates for all the components
		2. Find the time_points for these update rates during the simulation
		3. Sort this list to compose the simulation flow with the corresponding update time points
		4. Run the simulation at these time points.
	*/
/*	else{

		Phys_Container<double> *all_steps = new Phys_Container<double>;

		double *_step = new double;
		while(steps->hasMoreVariables()){
			_step = steps->getNextItem();
			double i=1.;
			while((i* (*_step)) <= limit &&(*_step)!=0){
				double *add_step = new double;
				*add_step = i* (*_step);
				all_steps->addItem(add_step);
				i++;
			}
		}


		Phys_Container<double>* sequence = all_steps->getSortedList();
		
		double *time = new double;
		while((*current_time)<=limit && sequence->hasMoreVariables())
		{			
			(result_report)<<"-------------------TIME STEP = "<<(*current_time)<<"-----------------------"<<endl;
			mediator->run_components((*current_time));
			(*current_time) = *(sequence->getNextItem());
			
		}
	}*/

	result_report<<"\0";
	result_report.close();


}

void Simulation_Manager::set_report_environment(char *filename)
{
	(result_report).open(filename);	

	Phys_Container<link_layer::Component>* components = new Phys_Container<link_layer::Component>( (Phys_Container<link_layer::Component> *)mediator->get_ordered_components());

	link_layer::Component *next_component;
	components->reset_iterator();
	result_report<<"\t"<<"time";

	while(components->hasMoreVariables()){		
		next_component = components->getNextItem();
		result_report<<"\t"<<next_component->get_name();
		result_matrix.push_back(vector<double>());
	}

	result_report<<endl;

}

void Simulation_Manager::report_simulation_results( int iteration){

	Phys_Container<link_layer::Component>* components = new Phys_Container<link_layer::Component>( (Phys_Container<link_layer::Component> *)mediator->get_ordered_components());
	link_layer::Component *next_component;
	components->reset_iterator();
	std::vector<std::vector<double>> buffer;
	int i = 0;
	while(components->hasMoreVariables()){		
		next_component = components->getNextItem();
		if(next_component->get_variable()->get_Model()!=NULL){		
			result_report<<"\t"<<*(next_component->get_value());
			//result_matrix[i][iteration] = *(next_component->get_value());
			result_matrix[i].push_back(*(next_component->get_value()));
			i++;
		}
		
	}
	result_report<<endl;


}

void Simulation_Manager::update_current_time(double time_steppp){
	double virtual_current_time = *(t_component->get_value())+ time_steppp;
	t_component->get_variable()->set_variable(virtual_current_time);

}


void Simulation_Manager::set_mediator(link_layer::Mediator *_mediator){
	mediator = _mediator;
	/*check through the mediator/mediators and decide whether this should be a fixed/variable time step 
	simulation*/
}

bool Simulation_Manager::determine_time_step_type(){
	bool is_fixed_step_size = true;
	double *step = new double;
	
	if(get_step_type() == FIXED_TIME){
		*step = mediator->determine_fixed_update_rate();
	}
	/*if(get_step_type()== VARIABLE_TIME){
		step_size = mediator->determine_variable_update_rates();
	}*/
	set_time_step(*step);
	return true;


	//NOTE: Add a control mechanism to the simulation step family;
	/*if((get_step_type() == 0 && is_fixed_step_size) || (get_step_type() == 1 && !is_fixed_step_size)
		|| (get_step_type() == 1 && is_fixed_step_size) ){
		set_time_step(step_size);
		return true;
	}
	else{
		std::(result_report)<<"change simulation step size"<<std::endl;
		return false;
	}*/
}

void Simulation_Manager::set_time_step(Phys_Container<double>* time){
//	t_max_component->get_variable()->set_variable(*time);
}
void Simulation_Manager::set_time_step(double time){
	if(t_delta_component!=NULL){
		t_delta_component->get_variable()->set_variable(time);
	}
	
}

Phys_Container<double>* Simulation_Manager::get_time_step(){
	return NULL;
}

void Simulation_Manager::set_step_type(int _type){
	step_type =_type;
}
void Simulation_Manager::set_end_time(double end){
	if(t_max_component!=NULL){
		t_max_component->get_variable()->set_variable(end);
	}
}
void Simulation_Manager::set_start_time(double start){
	if(t_min_component!=NULL){
		t_min_component->get_variable()->set_variable(start);
	}	
}

void Simulation_Manager::set_CT_solver(int type){
	CT_solver = type;
}

int Simulation_Manager::get_step_type(){
	return step_type;
}

void Simulation_Manager::set_t_component(link_layer::Component *time){
	t_component = time;
	
}

void Simulation_Manager::set_t_min_component(link_layer::Component *time){
	t_min_component = time;
}
void Simulation_Manager::set_t_max_component(link_layer::Component *time){
	t_max_component = time;
}
void Simulation_Manager::set_t_delta_component(link_layer::Component *time){
	t_delta_component = time;
	Phys_Container<double>* t  = new Phys_Container<double>;
	t->addItem(t_delta_component->get_value());
	set_time_step(t);
}

void Simulation_Manager::create_matlab_file(){
	ofstream matlabfile;
	matlabfile.open("plot_results");
	matlabfile<<setprecision(10);
	Phys_Container<link_layer::Component>* components = new Phys_Container<link_layer::Component>( (Phys_Container<link_layer::Component> *)mediator->get_ordered_components());
	link_layer::Component *next_component;
	components->reset_iterator();
	std::vector<std::vector<double>> buffer;
	int i = 0;
	while(components->hasMoreVariables()){		
		next_component = components->getNextItem();
		if(next_component->get_variable()->get_Model()!=NULL){
			matlabfile<<(next_component->get_name())<<" =[";
			int size = result_matrix[i].size();
			for(int ii= 0;ii<result_matrix[i].size();ii++)
			{
				matlabfile<<result_matrix[i][ii]<<";";
			}
			matlabfile<<"]"<<endl;
			i++;
		}
	}
	matlabfile<<endl;

	
}

link_layer::Mediator* Simulation_Manager::create_Mediator(Phys_Container<Model> mml_models){

	link_layer::Mediator *mediator = new link_layer::Mediator();
	/*CREATE COMPONENTS AND ADD THEM TO THE MEDIATOR FOR PARAMETERS AND VARIABLES*/
	Model *model;
	ParameterData * mml_model_pd;
	VariableData * mml_model_vd;

	//Simulatin related parameters
	double *time = new double(0);
	double *t_min = new double(0);
	double *t_max = new double(0.1);
	double *t_delta = new double(0.0001);



	//ADD TIME AS A PARAMETER TO THE MEDIATOR
	//TODO:NEED TO ASSOCIATE THESE COMPONENTS WITH THE SIMULATION PARAMETERS-
	computational_layer::Model_time *model_time = new computational_layer::Model_time;
	mediator->add_component(factory->generate_component("t",DISCRETE_TIME,DEPENDENT_VAR,model_time,time,"sec"));
	mediator->add_component(factory->generate_component("t.min",NULL,INDEPENDENT_VAR,NULL,t_min,"sec"));
	mediator->add_component(factory->generate_component("t.max",NULL,INDEPENDENT_VAR,NULL,t_max,"sec"));
	mediator->add_component(factory->generate_component("t.delta",NULL,INDEPENDENT_VAR,NULL,t_delta,"sec"));

	link_layer::Horizontal_semantic_converter *sem_con_time= new link_layer::Horizontal_semantic_converter();
	Phys_Container<link_layer::Component>* input_container_time = new Phys_Container<link_layer::Component>;
	input_container_time->addItem(mediator->get_ModelComponent_by_name("t.delta"));
	input_container_time->addItem(mediator->get_ModelComponent_by_name("t.max"));

	Phys_Container<link_layer::Component>* output_container_time = new Phys_Container<link_layer::Component>;	
	output_container_time->addItem(mediator->get_ModelComponent_by_name("t"));
	sem_con_time->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_time,
		(Phys_Container<link_layer::Link_layer_Component>*)output_container_time);
	mediator->add_semantic_converter(sem_con_time);


	mml_models.reset_iterator();
	while(mml_models.hasMoreVariables()){
		model = mml_models.getNextItem();
		/*CREATE PARAMETERS*/
		link_layer::SubModel_Component *mml_model_system = new link_layer::SubModel_Component(model->getName());
		model->resetParameterIter();
		while(mml_model_pd = model->getNextParameter ())
		{
			mml_model_system->add_component(
				factory->generate_component(mml_model_pd->getName(),NULL,INDEPENDENT_VAR,NULL,mml_model_pd->getValue(),mml_model_pd->getUnits()));
		}
		
		/*CREATE VARIABLES*/
		/*
		NOTE TO SELF: CREATION OF VARIABLES ARE SAME AS THE PARAMETERS FOR NOW.
		LATER AS WE PARSE THE EQUATIONS, WE WILL KNOW THE COMPUTATION TYPE, MATHEMATICAL MODEL etc.
		*/
		
		model->resetVariableIter();
		while(mml_model_vd = model->getNextVariable ())
		{
			mml_model_system->add_component(
				factory->generate_component(mml_model_vd->getName(),NULL,DEPENDENT_VAR,NULL,mml_model_vd->getInitValue(),mml_model_vd->getUnits()));
		}
		mediator->add_component(mml_model_system);
	}

	/*CREATE SEMANTIC CONVERTERS*/
	mml_models.reset_iterator();
	while(mml_models.hasMoreVariables()){
		//SendMessage(progress_bar,PBM_STEPIT,0,0);
		createSemanticConverters(mml_models.getNextItem(),mediator,t_delta);
	}

			
	this->set_mediator(mediator);
	return mediator;

}

	void Simulation_Manager::createSemanticConverters(Model *mml_model, link_layer::Mediator *intrinsic_mediator,double *t_delta){
		
		/*CREATE SEMANTIC CONVERTERS*/		
		function_factory *ff = new function_factory();

		EquationData *mml_model_eq;
		while(mml_model_eq = mml_model->getNextEquationData()){
			
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(mml_model_eq, intrinsic_mediator));

			char *comp_name = mml_model_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(mml_model_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = mml_model_eq->getModelType();
		
			//for this application, RK4 is chosen
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_4(*(t_delta));
				//comp_model = new computational_layer::Euler_Computation_Model;
				break;
				case Discrete_event:
					comp_model = new computational_layer::Discrete_Event_Model;
					break;
				case Discrete_time:
					comp_model = new computational_layer::Discrete_Time_Model;
					break;
				default:
					comp_model = NULL;
			}

			comp->get_variable()->get_Model()->set_Computation_Model(comp_model);
		}
	}