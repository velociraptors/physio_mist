#include "Computational_layer.h"
#include "Link_layer.h"
#include "Circulatory_System.h"
#include "mmlparser.h"
#include "mml_models.h"
class Simulink_test{

public:	
	Simulink_test(){;};
	virtual ~Simulink_test(){;};

	static link_layer::Mediator* create_Simulink_Test(){

		
		link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();
		
		Physiological_Factory *factory = Physiological_Factory::getInstance(); 

		
		//MML parsing operations
		MMLParser	mp;
		mp.openFile ("C:\\simulink_test.txt");
		
		Model*	simulink_model = new Model();
		mp.parseParameters("SIMULINK MODEL",simulink_model);


		/*CREATE PARAMETERS*/
		
		link_layer::SubModel_Component *simulink_model_system = new link_layer::SubModel_Component("simulink model");
		ParameterData * simulink_pd;
		while(simulink_pd = simulink_model->getNextParameter ())
		{
			simulink_model_system->add_component(factory->generate_component(simulink_pd->getName(),NULL,INDEPENDENT_VAR,NULL,simulink_pd->getValue(),simulink_pd->getUnits()));
		}


		/*PARSE VARIABLES*/
		mp.parseVariables("simulink MODEL", simulink_model);


		/*CREATE VARIABLES*/
		/*
		NOTE: CREATION OF VARIABLES ARE SAME AS THE PARAMETERS FOR NOW.
		LATER AS WE PARSE THE EQUATIONS, WE WILL KNOW THE COMPUTATION TYPE, MATHEMATICAL MODEL etc.
		*/
		//heart model subsytem
		VariableData *simulink_vd;
		simulink_model->resetVariableIter();
		while(simulink_vd = simulink_model->getNextVariable ())
		{
			
			char *comp_name = simulink_vd->getName();
			link_layer::Component* comp = factory->generate_component(comp_name,NULL,DEPENDENT_VAR,NULL,simulink_vd->getInitValue(),simulink_vd->getUnits());
			simulink_model_system->add_component(comp);

		}					
		intrinsic_mediator->add_component(simulink_model_system);

		/*PARSE EQUATIONS*/
		mp.parseEquations ("simulink model", simulink_model);

		//ADD TIME AS A PARAMETER TO THE MEDIATOR
		//TODO:NEED TO ASSOCIATE THESE COMPONENTS WITH THE SIMULATION PARAMETERS-
		computational_layer::Model_time *model_time = new computational_layer::Model_time;
		intrinsic_mediator->add_component(factory->generate_component("t",DISCRETE_TIME,DEPENDENT_VAR,model_time,new double(0),"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.min",NULL,INDEPENDENT_VAR,NULL,new double(0),"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.max",NULL,INDEPENDENT_VAR,NULL,new double(0.3),"sec"));
		intrinsic_mediator->add_component(factory->generate_component("t.delta",NULL,INDEPENDENT_VAR,NULL,new double(0.1),"sec"));

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
		EquationData *simulink_eq;
		while(simulink_eq = simulink_model->getNextEquationData()){
			intrinsic_mediator->add_semantic_converter(link_layer::Semantic_Converter::createSemanticConverter(simulink_eq, intrinsic_mediator));
				//create the mathematical model
				//find the method based on the output
				//attach the function to the model
				//find the variable based on the output of the equation
				//attach the model to the component

			char *comp_name = simulink_eq->getOutput();
			computational_layer::Mathematical_Model *mml ;
			if(simulink_eq->getModelType()==Discrete_time){
				mml = new computational_layer::Discrete_mml_Math_Model();
			}
			else{
				mml = new computational_layer::Continous_mml_Math_Model;
			}
				
			
			mml->setFunc(ff->getFunction(comp_name));
			link_layer::Component *comp = intrinsic_mediator->get_ModelComponent_by_name(comp_name);

			comp->get_variable()->add_Model(mml);
			
			computational_layer::Computation_Model *comp_model;
			int comp_type = simulink_eq->getModelType();
		
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

		
		return intrinsic_mediator;

	};
};