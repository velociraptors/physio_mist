/**************************************************************************************************
  Circulatory_System_models.cpp
  Implementation of the Ciculatotry System models
  Contributor(s): E. Zeynep Erson
  Created on:     December 2007
  Description:	
**************************************************************************************************/
#ifndef _MML_MODEL_
#define _MML_MODEL_

#include "Computational_layer.h"
#include "Link_layer.h"
#include "Circulatory_System.h"
#include "mmlparser.h"
#include "mml_models.h"


#include "windows.h"
#include "commctrl.h"

class MML_Model{

public:	
	MML_Model(){;};
	virtual ~MML_Model(){;};
	static link_layer::Mediator* create_MML_Model_progress(char* filename, Phys_Container<char> *modelName,HWND progress_bar)
	{
				
		link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();		
		Physiological_Factory *factory = Physiological_Factory::getInstance(); 

		
		//MML parsing operations
		MMLParser	mp;
		mp.openFile (filename);
		
		//mp.openFile (loc);

		/*CREATE MODELS*/
		Phys_Container<Model> mml_models;
		while(modelName->hasMoreVariables()){
			mml_models.addItem(new Model(modelName->getNextItem()));
		}

		



		//Simulatin related parameters
		double *time = new double(0);
		double *t_min = new double(0);
		double *t_max = new double(0.1);
		double *t_delta = new double(0.0001);
				/*double *t_max = new double(1.0);
		double *t_delta = new double(0.05);*/



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

		/*
		NOTE TO SELF: Since we read the file sequentially, we parse first parameters, then variables and then equations.
		Later if we modify the way we read the file, we can just parse the file based on the models.
		*/	
		
		/*PARSE PARAMETERS*/
		
		mml_models.reset_iterator();
		Model *model;
		
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseParameters(model->getName(),model);
		}

		/*PARSE VARIABLES*/
		mml_models.reset_iterator();		
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseVariables(model->getName(), model);
		}


		/*PARSE EQUATIONS*/
		mml_models.reset_iterator();
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseEquations(model->getName(), model);
		}
		

		/*CREATE COMPONENTS AND ADD THEM TO THE MEDIATOR FOR PARAMETERS AND VARIABLES*/
		ParameterData * mml_model_pd;
		VariableData * mml_model_vd;
		mml_models.reset_iterator();
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			/*CREATE PARAMETERS*/
			link_layer::SubModel_Component *mml_model_system = new link_layer::SubModel_Component(model->getName());
			model->resetParameterIter();
			while(mml_model_pd = model->getNextParameter ())
			{
				mml_model_system->add_component(
					factory->generate_component(mml_model_pd->getName(),NULL,INDEPENDENT_VAR,NULL,(mml_model_pd->getValue()),mml_model_pd->getUnits()));
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
					factory->generate_component(mml_model_vd->getName(),NULL,DEPENDENT_VAR,NULL,(mml_model_vd->getInitValue()),mml_model_vd->getUnits()));
			}
			intrinsic_mediator->add_component(mml_model_system);
		}

		/*CREATE SEMANTIC CONVERTERS*/
		mml_models.reset_iterator();
		while(mml_models.hasMoreVariables()){
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			SendMessage(progress_bar,PBM_STEPIT,0,0);
			createSemanticConverters(mml_models.getNextItem(),intrinsic_mediator,t_delta);
		}

					

		mp.closeFile();
		
		return intrinsic_mediator;
	
	}

	static link_layer::Mediator* MML_Model::create_MML_Model(char* filename, Phys_Container<char> *modelName){

	
		link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();		
		Physiological_Factory *factory = Physiological_Factory::getInstance(); 

		
		//MML parsing operations
		MMLParser	mp;
		mp.openFile (filename);
		
		//mp.openFile (loc);
		Phys_Container<Model> *mml_models = new Phys_Container<Model>;
		mml_models = mp.parse_models(modelName);
		
/*
		//CREATE MODELS
		Phys_Container<Model> mml_models;
		while(modelName->hasMoreVariables()){
			mml_models.addItem(new Model(modelName->getNextItem()));
		}
*/
		



		//Simulatin related parameters
		double *time = new double(0);
		double *t_min = new double(0);
		//double *t_max = new double(1.0);
		double *t_max = new double(420);
		//double *t_delta = new double(0.000125);
		double *t_delta = new double(0.0001);


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
	
		/*
		NOTE TO SELF: Since we read the file sequentially, we parse first parameters, then variables and then equations.
		Later if we modify the way we read the file, we can just parse the file based on the models.
		*/	
		
		/*PARSE PARAMETERS*/
		
/*		mml_models.reset_iterator();
		Model *model;
		
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseParameters(model->getName(),model);
		}
*/
		/*PARSE VARIABLES*/
/*		mml_models.reset_iterator();		
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseVariables(model->getName(), model);
		}

*/
		/*PARSE EQUATIONS*/
/*		mml_models.reset_iterator();
		while(mml_models.hasMoreVariables()){
			model = mml_models.getNextItem();
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			mp.parseEquations(model->getName(), model);
		}
*/		

		Model *model;
		/*CREATE COMPONENTS AND ADD THEM TO THE MEDIATOR FOR PARAMETERS AND VARIABLES*/
		ParameterData * mml_model_pd;
		VariableData * mml_model_vd;
		mml_models->reset_iterator();
		while(mml_models->hasMoreVariables()){
			model = mml_models->getNextItem();
			/*CREATE PARAMETERS*/
			link_layer::SubModel_Component *mml_model_system = new link_layer::SubModel_Component(model->getName());
			model->resetParameterIter();
			while(mml_model_pd = model->getNextParameter ())
			{
				mml_model_system->add_component(
					factory->generate_component(mml_model_pd->getName(),NULL,INDEPENDENT_VAR,NULL,(mml_model_pd->getValue()),mml_model_pd->getUnits()));
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
					factory->generate_component(mml_model_vd->getName(),NULL,DEPENDENT_VAR,NULL,(mml_model_vd->getInitValue()),mml_model_vd->getUnits()));
			}
			intrinsic_mediator->add_component(mml_model_system);
		}

		/*CREATE SEMANTIC CONVERTERS*/
		mml_models->reset_iterator();
		while(mml_models->hasMoreVariables()){
			//SendMessage(progress_bar,PBM_STEPIT,0,0);
			createSemanticConverters(mml_models->getNextItem(),intrinsic_mediator,t_delta);
		}

					

		mp.closeFile();
		
		return intrinsic_mediator;
	};

	static void MML_Model::createSemanticConverters(Model *mml_model, link_layer::Mediator *intrinsic_mediator,double *t_delta){
		
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
	};


	
};
#endif