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

class Lumped_parameter_circulation_mml{

public:	
	Lumped_parameter_circulation_mml(){;};
	virtual ~Lumped_parameter_circulation_mml(){;};

	static link_layer::Mediator* create_Lumped_parameter_circulation_mml(){

//		link_layer::Circulatory_Mediator *circ_mediator = link_layer::Circulatory_Mediator::getInstance();
		link_layer::Circulatory_Mediator *circ_mediator = new link_layer::Circulatory_Mediator;
		link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();
		
		Physiological_Factory *factory = Physiological_Factory::getInstance(); 

		
		//MML parsing operations
		MMLParser	mp;
		mp.openFile ("C:\\spb_ha.txt");
		
		
		//mp.openFile (loc);

		/*CREATE MODELS*/
		//Heart model system
		Model*	heart_model = new Model();
		//systemic_circulation_model
		Model*	systemic_circulation_model = new Model();
	
		//pulmonary circulation
		Model*	pulmonary_circulation_model = new Model();
	
		//baroreceptor model
		Model*	baroreceptor_model = new Model();
	
		//airway mechanics
		Model*	airway_model = new Model();
	
		//Pericardium
		Model*	pericardium_model = new Model();
	
		//coronary circulation
		Model* coronary_circulation_model = new Model();
	


		/*PARSE PARAMETERS*/
		mp.parseParameters("VARYING ELASTANCE HEART MODEL",heart_model);
		mp.parseParameters("SYSTEMIC CIRCULATION",systemic_circulation_model);
		mp.parseParameters("PULMONARY CIRCULATION",pulmonary_circulation_model);
		mp.parseParameters("BARORECEPTOR MODEL",baroreceptor_model);
		mp.parseParameters("AIRWAY MECHANICS",airway_model);
		mp.parseParameters("PERICARDIUM",pericardium_model);
		mp.parseParameters("CORONARY CIRCULATION",coronary_circulation_model);


		
		/*CREATE PARAMETERS*/
		//heart system submodel
		link_layer::SubModel_Component *heart_model_system = new link_layer::SubModel_Component("varying elastance heart model");
		ParameterData * heart_pd;
		while(heart_pd = heart_model->getNextParameter ())
		{
			heart_model_system->add_component(factory->generate_component(heart_pd->getName(),NULL,INDEPENDENT_VAR,NULL,heart_pd->getValue(),heart_pd->getUnits()));
		}

		//systemic circulation submodel
		link_layer::SubModel_Component *systemic_circulation_model_system = new link_layer::SubModel_Component("systemic circulation");
		ParameterData * sys_circ_pd;
		while(sys_circ_pd = systemic_circulation_model->getNextParameter ())
		{
			systemic_circulation_model_system->add_component(
				factory->generate_component(sys_circ_pd->getName(),NULL,INDEPENDENT_VAR,NULL,sys_circ_pd->getValue(),sys_circ_pd->getUnits()));
		}

		//pulmonary circulation submodel
		link_layer::SubModel_Component *pulmonary_circulation_model_system = new link_layer::SubModel_Component("pulmonary circulation");
		ParameterData * pul_circ_pd;
		while(pul_circ_pd = pulmonary_circulation_model->getNextParameter ())
		{
			pulmonary_circulation_model_system->add_component(
				factory->generate_component(pul_circ_pd->getName(),NULL,INDEPENDENT_VAR,NULL,pul_circ_pd->getValue(),pul_circ_pd->getUnits()));
		}


		//baroreceptor submodel		
		link_layer::SubModel_Component *baroreceptor_model_system = new link_layer::SubModel_Component("baroreceptor model");ParameterData * baroreceptor_pd;
		while(baroreceptor_pd = baroreceptor_model->getNextParameter ())
		{
			baroreceptor_model_system->add_component(
				factory->generate_component(baroreceptor_pd->getName(),NULL,INDEPENDENT_VAR,NULL,baroreceptor_pd->getValue(),baroreceptor_pd->getUnits()));
		}


		//airway mechanics submodel
		link_layer::SubModel_Component *airway_model_system = new link_layer::SubModel_Component("airway mechanics model");
		ParameterData * airway_pd;
		while(airway_pd = airway_model->getNextParameter ())
		{
			airway_model_system->add_component(
				factory->generate_component(airway_pd->getName(),NULL,INDEPENDENT_VAR,NULL,airway_pd->getValue(),airway_pd->getUnits()));
		}

		//pericardium submodel
		link_layer::SubModel_Component *pericardium_model_system = new link_layer::SubModel_Component("pericardium model");
		ParameterData * pericardium_pd;
		while(pericardium_pd = pericardium_model->getNextParameter ())
		{
			pericardium_model_system->add_component(
				factory->generate_component(pericardium_pd->getName(),NULL,INDEPENDENT_VAR,NULL,pericardium_pd->getValue(),pericardium_pd->getUnits()));
		}


		//coronary circulation submodel
		link_layer::SubModel_Component *coronary_circulation_model_system = new link_layer::SubModel_Component("coronary_circulation_ model");
		ParameterData * coronary_circulation_pd;
		while(coronary_circulation_pd = coronary_circulation_model->getNextParameter ())
		{
			coronary_circulation_model_system->add_component(
				factory->generate_component(coronary_circulation_pd->getName(),NULL,INDEPENDENT_VAR,NULL,coronary_circulation_pd->getValue(),coronary_circulation_pd->getUnits()));
		}



		/*PARSE VARIABLES*/
		mp.parseVariables("varying elastance heart model", heart_model);
		mp.parseVariables("systemic circulation", systemic_circulation_model);
		mp.parseVariables("pulmonary circulation", pulmonary_circulation_model);
		mp.parseVariables("Baroreceptor Model", baroreceptor_model);
		mp.parseVariables("airway mechanics", airway_model);
		mp.parseVariables("pericardium", pericardium_model);
		mp.parseVariables("coronary circulation", coronary_circulation_model);

		/*CREATE VARIABLES*/
		/*
		NOTE: CREATION OF VARIABLES ARE SAME AS THE PARAMETERS FOR NOW.
		LATER AS WE PARSE THE EQUATIONS, WE WILL KNOW THE COMPUTATION TYPE, MATHEMATICAL MODEL etc.
		*/
		//heart model subsytem
		VariableData *heart_vd;
		heart_model->resetVariableIter();
		while(heart_vd = heart_model->getNextVariable ())
		{
			
			char *comp_name = heart_vd->getName();
			link_layer::Component* comp = factory->generate_component(comp_name,NULL,DEPENDENT_VAR,NULL,heart_vd->getInitValue(),heart_vd->getUnits());
			heart_model_system->add_component(comp);

		}					
		intrinsic_mediator->add_component(heart_model_system);

		
		//systemic circulation submodel
		VariableData * sys_circ_vd;
		systemic_circulation_model->resetVariableIter();
		while(sys_circ_vd = systemic_circulation_model->getNextVariable ())
		{
			systemic_circulation_model_system->add_component(
				factory->generate_component(sys_circ_vd->getName(),NULL,DEPENDENT_VAR,NULL,sys_circ_vd->getInitValue(),sys_circ_vd->getUnits()));
		}
		intrinsic_mediator->add_component(systemic_circulation_model_system);

		//pulmonary circulation submodel
		VariableData * pul_circ_vd;
		pulmonary_circulation_model->resetVariableIter();
		while(pul_circ_vd = pulmonary_circulation_model->getNextVariable ())
		{
			pulmonary_circulation_model_system->add_component(
				factory->generate_component(pul_circ_vd->getName(),NULL,DEPENDENT_VAR,NULL,pul_circ_vd->getInitValue(),pul_circ_vd->getUnits()));
		}
		intrinsic_mediator->add_component(pulmonary_circulation_model_system);


		//baroreceptor submodel
		VariableData * baroreceptor_vd;
		baroreceptor_model->resetVariableIter();
		while(baroreceptor_vd = baroreceptor_model->getNextVariable ())
		{
			baroreceptor_model_system->add_component(
				factory->generate_component(baroreceptor_vd->getName(),NULL,DEPENDENT_VAR,NULL,baroreceptor_vd->getInitValue(),baroreceptor_vd->getUnits()));
		}
		intrinsic_mediator->add_component(baroreceptor_model_system);


		//airway mechanics submodel
		VariableData * airway_vd;
		airway_model->resetVariableIter();
		while(airway_vd = airway_model->getNextVariable ())
		{
			airway_model_system->add_component(
				factory->generate_component(airway_vd->getName(),NULL,DEPENDENT_VAR,NULL,airway_vd->getInitValue(),airway_vd->getUnits()));
		}
		intrinsic_mediator->add_component(airway_model_system);

		//pericardium submodel
		VariableData * pericardium_vd;
		pericardium_model->resetVariableIter();
		while(pericardium_vd = pericardium_model->getNextVariable ())
		{
			pericardium_model_system->add_component(
				factory->generate_component(pericardium_vd->getName(),NULL,DEPENDENT_VAR,NULL,pericardium_vd->getInitValue(),pericardium_vd->getUnits()));
		}
		intrinsic_mediator->add_component(pericardium_model_system);


		//coronary circulation submodel
		VariableData * coronary_circulation_vd;
		coronary_circulation_model->resetVariableIter();
		while(coronary_circulation_vd = coronary_circulation_model->getNextVariable ())
		{
			coronary_circulation_model_system->add_component(
				factory->generate_component(coronary_circulation_vd->getName(),NULL,DEPENDENT_VAR,NULL,coronary_circulation_vd->getInitValue(),coronary_circulation_vd->getUnits()));
		}
		intrinsic_mediator->add_component(coronary_circulation_model_system);

		/*PARSE EQUATIONS*/
		mp.parseEquations ("varying elastance heart model", heart_model);
		mp.parseEquations("systemic circulation", systemic_circulation_model);
		mp.parseEquations("pulmonary circulation", pulmonary_circulation_model);
		mp.parseEquations("Baroreceptor Model", baroreceptor_model);
		mp.parseEquations("airway mechanics", airway_model);
		mp.parseEquations("pericardium", pericardium_model);
		mp.parseEquations("coronary circulation", coronary_circulation_model);
		


		
		
		//ADD TIME AS A PARAMETER TO THE MEDIATOR
		//TODO:NEED TO ASSOCIATE THESE COMPONENTS WITH THE SIMULATION PARAMETERS-
		double *time = new double(0);
		double *t_min = new double(0);
		double *t_max = new double(0.3);
		double *t_delta = new double(0.1);
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

		//heart model
		EquationData *heart_eq;
		while(heart_eq = heart_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(heart_eq, intrinsic_mediator));
				//create the mathematical model
				//find the method based on the output
				//attach the function to the model
				//find the variable based on the output of the equation
				//attach the model to the component

			char *comp_name = heart_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(heart_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);

			comp->get_variable()->add_Model(mml);
			
			computational_layer::Computation_Model *comp_model;
			int comp_type = heart_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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
			//update the temporal property of the 
			
		}
		

		//systemic circulation submodel
		EquationData *sys_eq;
		while(sys_eq = systemic_circulation_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(sys_eq, intrinsic_mediator));

			char *comp_name = sys_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(sys_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = sys_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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

		//pulmonary circulation submodel
		EquationData *pul_eq;
		while(pul_eq = pulmonary_circulation_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(pul_eq, intrinsic_mediator));

			char *comp_name = pul_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(pul_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = pul_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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
		
		//baroreceptor submodel
		EquationData *baroreceptor_eq;
		while(baroreceptor_eq = baroreceptor_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(baroreceptor_eq, intrinsic_mediator));

			char *comp_name = baroreceptor_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(baroreceptor_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);
			
			computational_layer::Computation_Model *comp_model;
			int comp_type = baroreceptor_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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

		//pericardium submodel
		EquationData *pericardium_eq;
		while(pericardium_eq = pericardium_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(pericardium_eq, intrinsic_mediator));

			char *comp_name = pericardium_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(pericardium_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = pericardium_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_2;
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

		//coronary circulation subsystem
		EquationData *coronary_eq;
		while(coronary_eq = coronary_circulation_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(coronary_eq, intrinsic_mediator));

			char *comp_name = coronary_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(coronary_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);
			comp->get_variable()->add_Model(mml);

			computational_layer::Computation_Model *comp_model;
			int comp_type = coronary_eq->getModelType();
		
			switch(comp_type){
				case Continous:
				comp_model = new computational_layer::Runge_Kutta_4(0.1);
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