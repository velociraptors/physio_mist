/**************************************************************************************************
Implementation for the mathematical models for the IV injection model  
  Contributor(s):	E. Zeynep Erson
  Created on:		October, 2007
  Description:		"A model OF the first pass passage of drugs from i.v injection site to the 
					heart-parameter estimates for lignocaine in the sheep" by R. N. UPTON

**************************************************************************************************/

#include "Computational_layer.h"
#include "Link_layer.h"
#include "factory.h"
#include "Liver.h"

namespace computational_layer{

	class Model_Conc_inj:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){

			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//doserate
			double var_2 = *(in_list->getNextItem());//q_inj
			
			cout<<"var 1 is doserate "<<var_1<<endl;
			cout<<"var 2 is q_inj "<<var_2<<endl;
			double result = var_1/var_2;
			return result;

		};
	};

	class Model_Conc_unmixed:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//doserate
			double var_2 = *(in_list->getNextItem());//q

			cout<<"var 1 is doserate "<<var_1<<endl;
			cout<<"var 2 is q "<<var_2<<endl;
			
			double result = var_1/var_2;
			return result;
		};
	};

	class Model_Conc_pa:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			return this->get_Computation_Model()->run_Computation(variable, this);
		};
		virtual double derivative(double variable){
				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//v-mix
			double var_3 = *(in_list->getNextItem());//C_unmixed
			
			cout<<"var 1 is q "<<var_1<<endl;
			cout<<"var 2 is v-mix "<<var_2<<endl;
			cout<<"var 3 is C_unmixed "<<var_3<<endl;

			double result = (var_1/var_2)*(var_3-variable);
			return result;
		};
	};

	class Model_Conc_aa:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//Ca
			double var_2 = *(in_list->getNextItem());//e-lung

			cout<<"var 1 is Ca "<<var_1<<endl;
			cout<<"var 1 is e-lung "<<var_2<<endl;

			double result = var_1/(1-var_2);
			return result;
		};
	};

	
}

	
class IV_Model{
public:
	IV_Model();
	~IV_Model();

	static link_layer::Mediator* create_IV_model(){				
		link_layer::Component* d; 

		Physiological_Factory *factory = Physiological_Factory::getInstance();
		link_layer::Mediator *iv_mediator = new link_layer::Mediator;
		//link_layer::SubModel_Component *iv_model = new link_layer::SubModel_Component("iv_model");
					
		/*Liver *liver = Liver::getInstance();
		iv_model->set_anatomical_structure(liver);*/

		/**define variables***/

		//input variable_1: Conc_inj
		computational_layer::Model_Conc_inj *conc_inj_model = new computational_layer::Model_Conc_inj;
		link_layer::Component *comp_conc_inj = 
			factory->generate_component("Conc_inj",DISCRETE_TIME,DEPENDENT_VAR,conc_inj_model,new double(EMPTY_INITIAL_VALUE),"mg/litre");
		iv_mediator ->add_component(comp_conc_inj);

		//input variable_2: Conc_unmixed
		computational_layer::Model_Conc_unmixed *conc_unmixed_model = new computational_layer::Model_Conc_unmixed;
		link_layer::Component *comp_conc_unmixed = 
			factory->generate_component("Conc_unmixed",DISCRETE_TIME,DEPENDENT_VAR,conc_unmixed_model,new double(EMPTY_INITIAL_VALUE), "mg/litre");
		iv_mediator ->add_component(comp_conc_unmixed);

		//input variable_3: Conc_pa
		computational_layer::Model_Conc_pa *conc_pa_model = new computational_layer::Model_Conc_pa;
		link_layer::Component *comp_conc_pa = 
			factory->generate_component("Conc_pa",RUNGE_KUTTA_4,DEPENDENT_VAR,conc_pa_model,new double(0),"mg/litre");
		iv_mediator ->add_component(comp_conc_pa);

		/***define parameters***/

		link_layer::Component *comp_iv_doserate = factory->generate_component("iv_doserate",NULL,INDEPENDENT_VAR,NULL,new double(100),"mg/sec");
		iv_mediator ->add_component(comp_iv_doserate);

		/*be careful about the units q =1.0 litre/min=1.0/60 litre/sec*/
		link_layer::Component *comp_iv_qinj = factory->generate_component("iv_qinj",NULL,INDEPENDENT_VAR,NULL,new double(0.017),"litre/sec");
		iv_mediator ->add_component(comp_iv_qinj);

		/*be careful about the units q =5.6 litre/min=5.6/60 litre/sec*/
		link_layer::Component *comp_iv_q = factory->generate_component("iv_q",NULL,INDEPENDENT_VAR,NULL,new double(0.093),"litre/sec");
		iv_mediator ->add_component(comp_iv_q);

		link_layer::Component *comp_iv_vlung = factory->generate_component("iv_vlung",NULL,INDEPENDENT_VAR,NULL,new double(1.06),"litre");
		iv_mediator ->add_component(comp_iv_vlung);

		link_layer::Component *comp_iv_elung = factory->generate_component("iv_elung",NULL,INDEPENDENT_VAR,NULL,new double(0.32), NULL);
		iv_mediator ->add_component(comp_iv_elung);

		link_layer::Component *comp_iv_vmix = factory->generate_component("iv_vmix",NULL,INDEPENDENT_VAR,NULL,new double(0.255),"litre");
		iv_mediator ->add_component(comp_iv_vmix);

		
		/***define semantic converters***/

		//Semantic Converter for Cinj
		link_layer::Horizontal_semantic_converter *sem_con_iv_conc_inj = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_iv_conc_inj = new Phys_Container<link_layer::Component>;	
		input_container_iv_conc_inj->addItem(comp_iv_doserate);	
		input_container_iv_conc_inj->addItem(comp_iv_qinj);

		Phys_Container<link_layer::Component>* output_container_iv_conc_inj = new Phys_Container<link_layer::Component>;	
		output_container_iv_conc_inj->addItem(comp_conc_inj);
		sem_con_iv_conc_inj->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_iv_conc_inj,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_iv_conc_inj);
		iv_mediator ->add_semantic_converter(sem_con_iv_conc_inj);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_iv_conc_inj->hasMoreVariables()){
			d = input_container_iv_conc_inj->getNextItem();
			std::cout<<"The current value for input variable in equation Cinj is"<<d->get_value()<<std::endl;
		}


		//Semantic Converter for Cunmixed
		link_layer::Horizontal_semantic_converter *sem_con_iv_conc_unmixed = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_iv_conc_unmixed = new Phys_Container<link_layer::Component>;	
		input_container_iv_conc_unmixed->addItem(comp_iv_doserate);	
		input_container_iv_conc_unmixed->addItem(comp_iv_q);

		Phys_Container<link_layer::Component>* output_container_iv_conc_unmixed = new Phys_Container<link_layer::Component>;	
		output_container_iv_conc_unmixed->addItem(comp_conc_unmixed);
		sem_con_iv_conc_unmixed->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_iv_conc_unmixed,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_iv_conc_unmixed);
		iv_mediator ->add_semantic_converter(sem_con_iv_conc_unmixed);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_iv_conc_unmixed->hasMoreVariables()){
			d = input_container_iv_conc_unmixed->getNextItem();
			std::cout<<"The current value for input variable in equation Cunmixed is"<<d->get_value()<<std::endl;
		}

		//Semantic Converter for Cnc_pa
		link_layer::Horizontal_semantic_converter *sem_con_iv_conc_pa = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_iv_conc_pa = new Phys_Container<link_layer::Component>;	
		input_container_iv_conc_pa->addItem(comp_iv_q);	
		input_container_iv_conc_pa->addItem(comp_iv_vmix);
		input_container_iv_conc_pa->addItem(comp_conc_unmixed);

		Phys_Container<link_layer::Component>* output_container_iv_conc_pa = new Phys_Container<link_layer::Component>;	
		output_container_iv_conc_pa->addItem(comp_conc_pa);
		sem_con_iv_conc_pa->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_iv_conc_pa,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_iv_conc_pa);
		iv_mediator ->add_semantic_converter(sem_con_iv_conc_pa);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_iv_conc_pa->hasMoreVariables()){
			d = input_container_iv_conc_pa->getNextItem();
			std::cout<<"The current value for input variable in equation Cpa is"<<d->get_value()<<std::endl;
		}


		//Simulatin related parameters
		double *time = new double(0);
		double *t_min = new double(0);
		double *t_max = new double(0.003);
		double *t_delta = new double(0.001);


		//ADD TIME AS A PARAMETER TO THE MEDIATOR
		//TODO:NEED TO ASSOCIATE THESE COMPONENTS WITH THE SIMULATION PARAMETERS-
		computational_layer::Model_time *model_time = new computational_layer::Model_time;
		iv_mediator->add_component(factory->generate_component("t",DISCRETE_TIME,DEPENDENT_VAR,model_time,time,"sec"));
		iv_mediator->add_component(factory->generate_component("t.min",NULL,INDEPENDENT_VAR,NULL,t_min,"sec"));
		iv_mediator->add_component(factory->generate_component("t.max",NULL,INDEPENDENT_VAR,NULL,t_max,"sec"));
		iv_mediator->add_component(factory->generate_component("t.delta",NULL,INDEPENDENT_VAR,NULL,t_delta,"sec"));

		link_layer::Horizontal_semantic_converter *sem_con_time= new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_time = new Phys_Container<link_layer::Component>;
		input_container_time->addItem(iv_mediator->get_ModelComponent_by_name("t.delta"));
		input_container_time->addItem(iv_mediator->get_ModelComponent_by_name("t.max"));

		Phys_Container<link_layer::Component>* output_container_time = new Phys_Container<link_layer::Component>;	
		output_container_time->addItem(iv_mediator->get_ModelComponent_by_name("t"));
		sem_con_time->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_time,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_time);
		iv_mediator->add_semantic_converter(sem_con_time);





		//iv_mediator->add_component(iv_model);

		return iv_mediator;

		};
};
