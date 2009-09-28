/**************************************************************************************************
  Pulsatile_insulin
  Contributor(s):	E. Zeynep Erson
  Created on:		July 31, 2007
  Description:		This class implements the mathematical models required for the pulsatile insulin model described in
					"Mathematical Physiology".
**************************************************************************************************/

#include "Computational_layer.h"
#include "Link_layer.h"
#include "factory.h"


namespace computational_layer{
	//THIS IS TO TEST INTEGRATION		
	class Model_29_2:public Mathematical_Model{	
		virtual double apply_model(double variable){
			return this->get_Computation_Model()->run_Computation(variable, this);
		};
	
		virtual double derivative(double variable){			
			//we assume we know the size of the variable container
			//think of a more smart way to do this!
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());

			double result = var_1;	
			std::cout<<"This is the integrated plasma insulin model"<<std::endl;
			return result;
		};
	};




	class Model_29:public Mathematical_Model{

		virtual double apply_model(double variable){

			return this->get_Computation_Model()->run_Computation(variable, this);
		};

		virtual double derivative(double variable){
				//we assume we know the size of the variable container
			//think of a more smart way to do this!
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());
			double var_3 = *(in_list->getNextItem());
			double var_4 = *(in_list->getNextItem());
			double var_5 = *(in_list->getNextItem());
			double var_6 = *(in_list->getNextItem());

			double result = var_1 - (variable/var_2 - var_3/var_4)*var_5 - variable/var_6;
			return result;
		};
	};


	class Model_30:public Mathematical_Model{

		virtual double apply_model(double variable){

			return this->get_Computation_Model()->run_Computation(variable, this);
		};

		virtual double derivative(double variable){

			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());
			double var_3 = *(in_list->getNextItem());
			double var_4 = *(in_list->getNextItem());
			double var_5 = *(in_list->getNextItem());

			double result = (var_1/var_2 - variable/var_3)*var_4 - variable/var_5;

			return result;
		};
	
	};


	class Model_f5:public Mathematical_Model{

		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());

			return 180/(1+ exp((0.29*var_1/var_2)-7.5));

		};
	};
	
	class Model_f4:public Mathematical_Model{

		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());
			double var_3 = *(in_list->getNextItem());
			double var_4 = *(in_list->getNextItem());

			double exp_deno  = exp(-1.772*log(var_1*(1/var_2 + 1/var_3*var_4))+7.76);
			return (90/(1+exp_deno+7.76))+4;

		};
	};

	class Model_f3:public Mathematical_Model{

		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());

			return 0.01*var_1/var_2;

		};
	};
	
	class Model_f2:public Mathematical_Model{
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());

			return 72*(1-exp(-var_1/(144*var_2)));

		};
	};
	
	class Model_31:public Mathematical_Model{

		virtual double apply_model(double variable){

			return this->get_Computation_Model()->run_Computation(variable, this);
		};

		virtual double derivative(double variable){
				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());
			double var_2 = *(in_list->getNextItem());
			double var_3 = *(in_list->getNextItem());
			double var_4 = *(in_list->getNextItem());
			double var_5 = *(in_list->getNextItem());


			double derivative = var_1+var_2-var_3-var_4*var_5;
			return derivative;
		};
	};
}

class Insulin_Model{
public:
	Insulin_Model();
	~Insulin_Model();

	static link_layer::Mediator* create_Insulin_Model(){
				
		/*Physiological_Factory *factory = Physiological_Factory::getInstance();

		link_layer::Mediator *insulin_mediator = new link_layer::Mediator;
		link_layer::SubModel_Component *insulin_model = new link_layer::SubModel_Component;
		//TODO: Check the units for the variables

		//input variable_1: plasma insulin
		computational_layer::Model_29 *plasma_insulin_model = new computational_layer::Model_29;
		link_layer::Component *comp_1 = factory->generate_component("plasma_insulin",EULER_COMPUTATION,DEPENDENT_VAR,plasma_insulin_model,new double(60),NULL);
		plasma_insulin_model->set_sample_time(0.5);
		insulin_model->add_component(comp_1);


		//input variable_2: remote insulin
		computational_layer::Model_30 *remote_insulin_model = new computational_layer::Model_30;
		link_layer::Component *comp_2 = factory->generate_component("remote_insulin",EULER_COMPUTATION,DEPENDENT_VAR,remote_insulin_model,new double(0),NULL);
		remote_insulin_model->set_sample_time(0.75);
		insulin_model->add_component(comp_2);


		//input variable_3: glucose amount
		computational_layer::Model_31 *glucose_amount_model = new computational_layer::Model_31;
		link_layer::Component *comp_3 = factory->generate_component("glucose_amount",EULER_COMPUTATION,DEPENDENT_VAR,glucose_amount_model,new double(1100),NULL);
		//glucose_amount_model->set_sample_time(0.02);
		insulin_model->add_component(comp_3);

		//temporary variables for f5
		computational_layer::Model_f5 *f5_model = new computational_layer::Model_f5;
		link_layer::Component *comp_16 = factory->generate_component("temp_var_f5",DISCRETE_TIME,DEPENDENT_VAR,f5_model,new double(0),"mg/min");
		insulin_model->add_component(comp_16);
		
		//temporary variables for f2
		computational_layer::Model_f2 *f2_model = new computational_layer::Model_f2;
		link_layer::Component *comp_13 = factory->generate_component("temp_var_f2",DISCRETE_TIME,DEPENDENT_VAR,f2_model,new double(0),"mg/min");
		insulin_model->add_component(comp_13);

		//temporary variables for f3
		computational_layer::Model_f3 *f3_model = new computational_layer::Model_f3;
		link_layer::Component *comp_14 = factory->generate_component("temp_var_f3",DISCRETE_TIME,DEPENDENT_VAR,f3_model,new double(0),"mg/min");
		insulin_model->add_component(comp_14);

		//temporary variables for f4
		computational_layer::Model_f4 *f4_model = new computational_layer::Model_f4;
		link_layer::Component *comp_15 = factory->generate_component("temp_var_f4",DISCRETE_TIME,DEPENDENT_VAR,f4_model,new double(0),NULL);
		insulin_model->add_component(comp_15);

		//parameters
		link_layer::Component *comp_10 = factory->generate_component("V_1",NULL,INDEPENDENT_VAR,NULL,new double(3),"litre");
		insulin_model->add_component(comp_10);

		link_layer::Component *comp_11 = factory->generate_component("V_2",NULL,INDEPENDENT_VAR,NULL,new double(11),"litre");
		insulin_model->add_component(comp_11);

		link_layer::Component *comp_12 = factory->generate_component("V_3",NULL,INDEPENDENT_VAR,NULL,new double(10),"litre");
		insulin_model->add_component(comp_12);

		link_layer::Component *comp_6 = factory->generate_component("E",NULL,INDEPENDENT_VAR,NULL,new double(0.2),"litre/min");
		insulin_model->add_component(comp_6);

		link_layer::Component *comp_7 = factory->generate_component("t_1",NULL,INDEPENDENT_VAR,NULL,new double(6),"min");
		insulin_model->add_component(comp_7);

		link_layer::Component *comp_8 = factory->generate_component("t_2",NULL,INDEPENDENT_VAR,NULL,new double(100),"min");
		insulin_model->add_component(comp_8);

		link_layer::Component *comp_9 = factory->generate_component("t_3",NULL,INDEPENDENT_VAR,NULL,new double(100),"min");
		insulin_model->add_component(comp_9);

		link_layer::Component *comp_17 = factory->generate_component("glucose_intake",NULL,INDEPENDENT_VAR,NULL,new double(108),"mg/min");
		insulin_model->add_component(comp_17);

		link_layer::Component *comp_18 = factory->generate_component("h_3",NULL,INDEPENDENT_VAR,NULL,new double(6),NULL);
		insulin_model->add_component(comp_18);
					

		//Semantic Converter for eq19.29
		link_layer::Horizontal_semantic_converter *sem_con_29 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_29 = new Phys_Container<link_layer::Component>;
		input_container_29->addItem(comp_3);
		input_container_29->addItem(comp_10);
		input_container_29->addItem(comp_2);
		input_container_29->addItem(comp_11);
		input_container_29->addItem(comp_6);
		input_container_29->addItem(comp_7);

		Phys_Container<link_layer::Component>* output_container_29 = new Phys_Container<link_layer::Component>;	
		output_container_29->addItem(comp_1);
		sem_con_29->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_29,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_29);

		link_layer::Component* d; 
		std::cout<< "******************************************"<<std::endl;
		while(input_container_29->hasMoreVariables()){
			d = input_container_29->getNextItem();
			std::cout<<"The current value for input variable in equation 29 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_29);

			
		//Semantic Converter for eq19.30
		link_layer::Horizontal_semantic_converter *sem_con_30 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_30 = new Phys_Container<link_layer::Component>;	
		input_container_30->addItem(comp_1);
		input_container_30->addItem(comp_10);
		input_container_30->addItem(comp_11);
		input_container_30->addItem(comp_6);
		input_container_30->addItem(comp_8);
		Phys_Container<link_layer::Component>* output_container_30 = new Phys_Container<link_layer::Component>;	
		output_container_30->addItem(comp_2);
		sem_con_30->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_30,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_30);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_30->hasMoreVariables()){
			d = input_container_30->getNextItem();
			std::cout<<"The current value for input variable in equation 30 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_30);

		//Semantic Converter for eq19.31 for f5
		link_layer::Horizontal_semantic_converter *sem_con_f5 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_f5 = new Phys_Container<link_layer::Component>;	
		input_container_f5->addItem(comp_9);
		input_container_f5->addItem(comp_10);
		Phys_Container<link_layer::Component>* output_container_f5 = new Phys_Container<link_layer::Component>;	
		output_container_f5->addItem(comp_16);
		sem_con_f5->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_f5,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_f5);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_f5->hasMoreVariables()){
			d = input_container_f5->getNextItem();
			std::cout<<"The current value for input variable in equation f5 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_f5);
		
		//Semantic Converter for eq19.31 for f2
		link_layer::Horizontal_semantic_converter *sem_con_f2 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_f2 = new Phys_Container<link_layer::Component>;	
		input_container_f2->addItem(comp_3);
		input_container_f2->addItem(comp_12);
		Phys_Container<link_layer::Component>* output_container_f2 = new Phys_Container<link_layer::Component>;	
		output_container_f2->addItem(comp_13);
		sem_con_f2->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_f2,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_f2);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_f2->hasMoreVariables()){
			d = input_container_f2->getNextItem();
			std::cout<<"The current value for input variable in equation f2 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_f2);

		
		//Semantic Converter for eq19.31 for f3
		link_layer::Horizontal_semantic_converter *sem_con_f3 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_f3 = new Phys_Container<link_layer::Component>;	
		input_container_f3->addItem(comp_3);
		input_container_f3->addItem(comp_12);
		Phys_Container<link_layer::Component>* output_container_f3 = new Phys_Container<link_layer::Component>;	
		output_container_f3->addItem(comp_14);
		sem_con_f3->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_f3,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_f3);


		std::cout<< "******************************************"<<std::endl;
		while(input_container_f3->hasMoreVariables()){
			d = input_container_f3->getNextItem();
			std::cout<<"The current value for input variable in equation f3 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_f3);

		//Semantic Converter for eq19.31 for f4
		link_layer::Horizontal_semantic_converter *sem_con_f4 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_f4 = new Phys_Container<link_layer::Component>;	
		input_container_f4->addItem(comp_2);
		input_container_f4->addItem(comp_11);
		input_container_f4->addItem(comp_6);
		input_container_f4->addItem(comp_8);
		Phys_Container<link_layer::Component>* output_container_f4 = new Phys_Container<link_layer::Component>;	
		output_container_f4->addItem(comp_15);
		sem_con_f4->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_f4,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_f4);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_f4->hasMoreVariables()){
			d = input_container_f4->getNextItem();
			std::cout<<"The current value for input variable in equation f4 is"<<d->get_value()<<std::endl;
		}		
		insulin_model->add_semantic_converter(sem_con_f4);
		
		//Semantic Converter for eq19.31
		link_layer::Horizontal_semantic_converter *sem_con_31 = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_31 = new Phys_Container<link_layer::Component>;	
		input_container_31->addItem(comp_16);
		input_container_31->addItem(comp_13);
		input_container_31->addItem(comp_14);
		input_container_31->addItem(comp_15);
		input_container_31->addItem(comp_17);
		Phys_Container<link_layer::Component>* output_container_31 = new Phys_Container<link_layer::Component>;	
		output_container_31->addItem(comp_3);
		sem_con_31->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_31,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_31);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_31->hasMoreVariables()){
			d = input_container_31->getNextItem();
			std::cout<<"The current value for input variable in equation 31 is"<<d->get_value()<<std::endl;
		}
		insulin_model->add_semantic_converter(sem_con_31);
		insulin_mediator->add_component(insulin_model);

		return insulin_mediator;*/

	};
};