/**************************************************************************************************
  Circulatory_System_models.cpp
  Implementation of the Ciculatotry System models
  Contributor(s): E. Zeynep Erson
  Created on:     December 2007
  Description:	
**************************************************************************************************/

#include "Computational_layer.h"
#include "Link_layer.h"
#include "Circulatory_System.h"
#include "mmlparser.h"
#include "mml_models.h"

class Airway{

public:	
	Airway(){;};
	virtual ~Airway(){;};

	static link_layer::Mediator* create_Airway(){

//		link_layer::Circulatory_Mediator *circ_mediator = link_layer::Circulatory_Mediator::getInstance();
		link_layer::Circulatory_Mediator *circ_mediator = new link_layer::Circulatory_Mediator;
		link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();
		
		Physiological_Factory *factory = Physiological_Factory::getInstance(); 

		
		//MML parsing operations
		MMLParser	mp;
		mp.openFile ("C:\\airway_mechanics.txt");
		
		//mp.openFile (loc);

		/*CREATE MODELS*/
		//airway mechanics
		Model*	airway_model = new Model();



		//Simulatin related parameters
		double *time = new double(0);
		double *t_min = new double(0);
		double *t_max = new double(0.3);
		double *t_delta = new double(0.1);

	
	


		/*PARSE PARAMETERS*/
		mp.parseParameters("AIRWAY MECHANICS",airway_model);


		
		/*CREATE PARAMETERS*/

		//airway mechanics submodel
		link_layer::SubModel_Component *airway_model_system = new link_layer::SubModel_Component("airway mechanics model");
		ParameterData * airway_pd;
		while(airway_pd = airway_model->getNextParameter ())
		{
			airway_model_system->add_component(
				factory->generate_component(airway_pd->getName(),NULL,INDEPENDENT_VAR,NULL,airway_pd->getValue(),airway_pd->getUnits()));
		}




		/*PARSE VARIABLES*/
		mp.parseVariables("airway mechanics", airway_model);

		/*CREATE VARIABLES*/
		/*
		NOTE: CREATION OF VARIABLES ARE SAME AS THE PARAMETERS FOR NOW.
		LATER AS WE PARSE THE EQUATIONS, WE WILL KNOW THE COMPUTATION TYPE, MATHEMATICAL MODEL etc.
		*/

		//airway mechanics submodel
		VariableData * airway_vd;
		airway_model->resetVariableIter();
		while(airway_vd = airway_model->getNextVariable ())
		{
			airway_model_system->add_component(
				factory->generate_component(airway_vd->getName(),NULL,DEPENDENT_VAR,NULL,airway_vd->getInitValue(),airway_vd->getUnits()));
		}
		intrinsic_mediator->add_component(airway_model_system);

		/*PARSE EQUATIONS*/
		mp.parseEquations("airway mechanics", airway_model);
		
		
		//ADD TIME AS A PARAMETER TO THE MEDIATOR
		//TODO:NEED TO ASSOCIATE THESE COMPONENTS WITH THE SIMULATION PARAMETERS-
		computational_layer::Model_time *model_time = new computational_layer::Model_time;
		intrinsic_mediator->add_component(factory->generate_component("t",DISCRETE_TIME,DEPENDENT_VAR,model_time,time,"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.min",NULL,INDEPENDENT_VAR,NULL,t_min,"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.max",NULL,INDEPENDENT_VAR,NULL,t_max,"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.delta",NULL,INDEPENDENT_VAR,NULL,t_delta,"sec"));

		link_layer::Horizontal_semantic_converter *sem_con_time= new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_time = new Phys_Container<link_layer::Component>;
		input_container_time->addItem(intrinsic_mediator->get_ModelComponent_by_name("t.delta"));
		input_container_time->addItem(intrinsic_mediator->get_ModelComponent_by_name("t.max"));

		Phys_Container<link_layer::Component>* output_container_time = new Phys_Container<link_layer::Component>;	
		output_container_time->addItem(intrinsic_mediator->get_ModelComponent_by_name("t"));
		sem_con_time->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_time,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_time);
		intrinsic_mediator->add_semantic_converter(sem_con_time);

		
		
		
		/*CREATE SEMANTIC CONVERTERS*/		
		function_factory *ff = new function_factory();


		//airway mechanics submodel
		EquationData *airway_eq;
		while(airway_eq = airway_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(airway_eq, intrinsic_mediator));

			char *comp_name = airway_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(airway_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = airway_eq->getModelType();
		
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

		mp.closeFile();


		circ_mediator->set_intrinsic_mediator(intrinsic_mediator);
		return circ_mediator;
	};


	
};