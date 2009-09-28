/**************************************************************************************************	
  Implementation of the Baroreflex feedback mechanism for the cardiac output	
  Contributor(s):	E. Zeynep Erson
  Created on:		October 2007
  Description:		Baroreceptor-feedback mechanism from paper: 
					"Modeling of the baroreflex-mechanism with time-delay", 
					by Ottesen, J. T
**************************************************************************************************/

#include "Computational_layer.h"
#include "Link_layer.h"
#include "factory.h"

namespace computational_layer{
	
	class Model_baroreflex_p_a:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			return this->get_Computation_Model()->run_Computation(variable, this);
		};
		virtual double derivative(double variable){				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//ca
			double var_2 = *(in_list->getNextItem());//R
			double var_3 = *(in_list->getNextItem());//Pv
			double var_4 = *(in_list->getNextItem());//vstr
			double var_5 = *(in_list->getNextItem());//h

			cout<<"var 1 is ca"<<var_1<<endl;
			cout<<"var 2 is R "<<var_2<<endl;
			cout<<"var 3 is pV "<<var_3<<endl;
			cout<<"var 4 is VSTR "<<var_4<<endl;
			cout<<"var 5 is H "<<var_5<<endl;
			

			double result = -((1/(var_1*var_2))*variable)+((1/(var_1*var_2))*var_3)+((1/var_1)*var_4*var_5);
			return result;
		};
	};
	
	class Model_baroreflex_p_v:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			return this->get_Computation_Model()->run_Computation(variable, this);
		};
		virtual double derivative(double variable){				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//cv
			double var_2 = *(in_list->getNextItem());//R
			double var_3 = *(in_list->getNextItem());//Pa
			double var_4 = *(in_list->getNextItem());//r

			cout<<"var 1 is cV"<<var_1<<endl;
			cout<<"var 2 is R "<<var_2<<endl;
			cout<<"var 3 is pA "<<var_3<<endl;
			cout<<"var 4 is R "<<var_4<<endl;
			

			
			double result = ((1/(var_1*var_2))*var_3)-((1/(var_1*var_2))+(1/(var_1*var_4)))*variable;
			return result;
		};
	};

	class Model_baroreflex_h:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			return this->get_Computation_Model()->run_Computation(variable, this);
		};
		virtual double derivative(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//alpha_h
			double var_2 = *(in_list->getNextItem());//T_s
			double var_3 = *(in_list->getNextItem());//gamma_h
			double var_4 = *(in_list->getNextItem());//T_p
			double var_5 = *(in_list->getNextItem());//beta_h

			cout<<"var 1 is ALPHA_H"<<var_1<<endl;
			cout<<"var 2 is T_S "<<var_2<<endl;
			cout<<"var 3 is GAMMA_H "<<var_3<<endl;
			cout<<"var 4 is T_P "<<var_4<<endl;
			cout<<"var 5 is BETA_H "<<var_5<<endl;

			double result = ((var_1*var_2)/(1+(var_3*var_4)))-(var_5*var_4);
			return result;
		};
	};

	class Model_baroreflex_T_s:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//Pa_t
			double var_2 = *(in_list->getNextItem());//alpha_s
			double var_3 = *(in_list->getNextItem());//beta_s
			
			cout<<"var 1 is PA_T"<<var_1<<endl;
			cout<<"var 2 is ALPHA_S "<<var_2<<endl;
			cout<<"var 3 is BETA_S "<<var_3<<endl;

			double result = 1/(1+pow(var_1/var_2,var_3));
			return result;
		};

	};
	
	class Model_baroreflex_T_p:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//P_a
			double var_2 = *(in_list->getNextItem());//alpha_p
			double var_3 = *(in_list->getNextItem());//beta_p

			cout<<"var 1 is Pa"<<var_1<<endl;
			cout<<"var 2 is ALPHA_P "<<var_2<<endl;
			cout<<"var 3 is BETA_P "<<var_3<<endl;


			double result = 1/(1+pow(var_1/var_2,-var_3));
			return result;
		};

	};
	
	class Model_baroreflex_Pa_t:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){	
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//P_a

			cout<<"var 1 is Pa"<<var_1<<endl;


			double result = var_1;
			return result;
		};
	};
}
class Baroreflex_Model{
public:
	Baroreflex_Model();
	~Baroreflex_Model();
	
	static link_layer::Mediator* create_Baroreflex_Model(){			
		link_layer::Component* d; 

		Physiological_Factory *factory = Physiological_Factory::getInstance();
		link_layer::Mediator *baroreflex_mediator = new link_layer::Mediator; 
		link_layer::SubModel_Component *baroreflex_model = new link_layer::SubModel_Component("Baroreflex_model");
		
		/***define variables***/

		//input variable_1: arterial pressure
		computational_layer::Model_baroreflex_p_a *baroreflex_p_a_model = new computational_layer::Model_baroreflex_p_a;
		link_layer::Component *comp_baroreflex_p_a = factory->generate_component("arterial pressure",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_p_a_model,new double(100),"mmHg");
		baroreflex_model->add_component(comp_baroreflex_p_a);


		//input variable_2: venous pressure
		computational_layer::Model_baroreflex_p_v *baroreflex_p_v_model = new computational_layer::Model_baroreflex_p_v;
		link_layer::Component *comp_baroreflex_p_v = factory->generate_component("venous pressure",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_p_v_model,new double(7), "mmHg");
		baroreflex_model->add_component(comp_baroreflex_p_v);

		//input variable_3: cardiac output
		computational_layer::Model_baroreflex_h *baroreflex_h_model = new computational_layer::Model_baroreflex_h;
		link_layer::Component *comp_baroreflex_h = factory->generate_component("cardiac output",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_h_model,new double(1.24),"1/sec");
		baroreflex_model->add_component(comp_baroreflex_h);

		//input variable_4: T_s
		computational_layer::Model_baroreflex_T_s *baroreflex_T_s_model = new computational_layer::Model_baroreflex_T_s;
		link_layer::Component *comp_baroreflex_T_s = factory->generate_component("T_s",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_T_s_model,new double(0),NULL);
		baroreflex_model->add_component(comp_baroreflex_T_s);

		//input variable_5: T_p
		computational_layer::Model_baroreflex_T_p *baroreflex_T_p_model = new computational_layer::Model_baroreflex_T_p;
		link_layer::Component *comp_baroreflex_T_p = factory->generate_component("T_p",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_T_p_model,new double(0), NULL);
		baroreflex_model->add_component(comp_baroreflex_T_p);

		//input variable_6: delayed arterial pressure
		computational_layer::Model_baroreflex_Pa_t *baroreflex_Pa_t_model = new computational_layer::Model_baroreflex_Pa_t;
		link_layer::Component *comp_baroreflex_Pa_t = factory->generate_component("delayed arterial pressure",RUNGE_KUTTA_2,DEPENDENT_VAR,baroreflex_Pa_t_model,new double(0),"mmHg");
		baroreflex_model->add_component(comp_baroreflex_Pa_t);
		

		/***define parameters***/

		link_layer::Component *comp_baroreflex_c_a = factory->generate_component("baroreflex_c_a",NULL,INDEPENDENT_VAR,NULL,new double(1.55), "ml/mmHg");
		baroreflex_model->add_component(comp_baroreflex_c_a);

		link_layer::Component *comp_baroreflex_R = factory->generate_component("baroreflex_R",NULL,INDEPENDENT_VAR,NULL,new double(1.05), "mmHg*sec/ml");
		baroreflex_model->add_component(comp_baroreflex_R);
		
		link_layer::Component *comp_baroreflex_V_str = factory->generate_component("baroreflex_V_str",NULL,INDEPENDENT_VAR,NULL,new double(67.9),"ml");
		baroreflex_model->add_component(comp_baroreflex_V_str);

		link_layer::Component *comp_baroreflex_r = factory->generate_component("baroreflex_r",NULL,INDEPENDENT_VAR,NULL,new double(0.068),"mmHg*sec/ml");
		baroreflex_model->add_component(comp_baroreflex_r);
		
		link_layer::Component *comp_baroreflex_c_v = factory->generate_component("baroreflex_c_v",NULL,INDEPENDENT_VAR,NULL,new double(519),"ml/mmHg");
		baroreflex_model->add_component(comp_baroreflex_c_v);

		link_layer::Component *comp_baroreflex_alpha_h = factory->generate_component("baroreflex_alpha_h",NULL,INDEPENDENT_VAR,NULL,new double(0.84),"1/(sec*sec)");
		baroreflex_model->add_component(comp_baroreflex_alpha_h);

		link_layer::Component *comp_baroreflex_gamma_h = factory->generate_component("baroreflex_gamma_h",NULL,INDEPENDENT_VAR,NULL,new double(0),"1/(sec*sec)");
		baroreflex_model->add_component(comp_baroreflex_gamma_h);

		link_layer::Component *comp_baroreflex_beta_h = factory->generate_component("baroreflex_beta_h",NULL,INDEPENDENT_VAR,NULL,new double(1.17),"1/(sec*sec)");
		baroreflex_model->add_component(comp_baroreflex_beta_h);

		link_layer::Component *comp_baroreflex_alpha_s = factory->generate_component("baroreflex_alpha_s",NULL,INDEPENDENT_VAR,NULL,new double(93),"mmHg");
		baroreflex_model->add_component(comp_baroreflex_alpha_s);


		link_layer::Component *comp_baroreflex_beta_s = factory->generate_component("baroreflex_beta_s",NULL,INDEPENDENT_VAR,NULL,new double(7),NULL);
		baroreflex_model->add_component(comp_baroreflex_beta_s);


		link_layer::Component *comp_baroreflex_alpha_p = factory->generate_component("baroreflex_alpha_p",NULL,INDEPENDENT_VAR,NULL,new double(93),"mmHg");
		baroreflex_model->add_component(comp_baroreflex_alpha_p);

		//beta_p
		link_layer::Component *comp_baroreflex_beta_p = factory->generate_component("baroreflex_beta_p",NULL,INDEPENDENT_VAR,NULL,new double(7),NULL);
		baroreflex_model->add_component(comp_baroreflex_beta_p);
		

		/***define semantic converters***/

		//Semantic Converter for Pa
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_p_a = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_p_a = new Phys_Container<link_layer::Component>;	
		input_container_baro_p_a->addItem(comp_baroreflex_c_a);
		input_container_baro_p_a->addItem(comp_baroreflex_R);
		input_container_baro_p_a->addItem(comp_baroreflex_p_v);
		input_container_baro_p_a->addItem(comp_baroreflex_V_str);
		input_container_baro_p_a->addItem(comp_baroreflex_h);

		Phys_Container<link_layer::Component>* output_container_baro_p_a = new Phys_Container<link_layer::Component>;	
		output_container_baro_p_a->addItem(comp_baroreflex_p_a);
		sem_con_baroreflex_p_a->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_p_a,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_p_a);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_p_a);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_p_a->hasMoreVariables()){
			d = input_container_baro_p_a->getNextItem();
			std::cout<<"The current value for input variable in equation p_a is"<<d->get_value()<<std::endl;
		}
		
		//Semantic Converter for Pv
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_p_v = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_p_v = new Phys_Container<link_layer::Component>;	
		input_container_baro_p_v->addItem(comp_baroreflex_c_v);
		input_container_baro_p_v->addItem(comp_baroreflex_R);
		input_container_baro_p_v->addItem(comp_baroreflex_p_a);
		input_container_baro_p_v->addItem(comp_baroreflex_r);

		Phys_Container<link_layer::Component>* output_container_baro_p_v = new Phys_Container<link_layer::Component>;	
		output_container_baro_p_v->addItem(comp_baroreflex_p_v);
		sem_con_baroreflex_p_v->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_p_v,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_p_v);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_p_v);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_p_v->hasMoreVariables()){
			d = input_container_baro_p_v->getNextItem();
			std::cout<<"The current value for input variable in equation p_v is"<<d->get_value()<<std::endl;
		}

		//Semantic Converter for Pa_t--time delayed version of P_a
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_Pa_t = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_Pa_t = new Phys_Container<link_layer::Component>;	
		input_container_baro_Pa_t->addItem(comp_baroreflex_p_a);

		Phys_Container<link_layer::Component>* output_container_baro_Pa_t = new Phys_Container<link_layer::Component>;	
		output_container_baro_Pa_t->addItem(comp_baroreflex_Pa_t);
		sem_con_baroreflex_Pa_t->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_Pa_t,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_Pa_t);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_Pa_t);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_Pa_t->hasMoreVariables()){
			d = input_container_baro_Pa_t->getNextItem();
			std::cout<<"The current value for input variable in equation Pa_t is"<<d->get_value()<<std::endl;
		}

		
		//Semantic Converter for T_s
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_T_s = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_T_s = new Phys_Container<link_layer::Component>;	
		input_container_baro_T_s->addItem(comp_baroreflex_Pa_t);
		input_container_baro_T_s->addItem(comp_baroreflex_alpha_s);
		input_container_baro_T_s->addItem(comp_baroreflex_beta_s);

		Phys_Container<link_layer::Component>* output_container_baro_T_s = new Phys_Container<link_layer::Component>;	
		output_container_baro_T_s->addItem(comp_baroreflex_T_s);
		sem_con_baroreflex_T_s->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_T_s,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_T_s);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_T_s);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_T_s->hasMoreVariables()){
			d = input_container_baro_T_s->getNextItem();
			std::cout<<"The current value for input variable in equation T_s is"<<d->get_value()<<std::endl;
		}

		//Semantic Converter for T_p
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_T_p = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_T_p = new Phys_Container<link_layer::Component>;	
		input_container_baro_T_p->addItem(comp_baroreflex_p_a);
		input_container_baro_T_p->addItem(comp_baroreflex_alpha_p);
		input_container_baro_T_p->addItem(comp_baroreflex_beta_p);

		Phys_Container<link_layer::Component>* output_container_baro_T_p = new Phys_Container<link_layer::Component>;	
		output_container_baro_T_p->addItem(comp_baroreflex_T_p);
		sem_con_baroreflex_T_p->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_T_p,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_T_p);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_T_p);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_T_p->hasMoreVariables()){
			d = input_container_baro_T_p->getNextItem();
			std::cout<<"The current value for input variable in equation T_p is"<<d->get_value()<<std::endl;
		}

		//Semantic Converter for H
		link_layer::Horizontal_semantic_converter *sem_con_baroreflex_h = new link_layer::Horizontal_semantic_converter();
		Phys_Container<link_layer::Component>* input_container_baro_h = new Phys_Container<link_layer::Component>;	
		input_container_baro_h->addItem(comp_baroreflex_alpha_h);
		input_container_baro_h->addItem(comp_baroreflex_T_s);
		input_container_baro_h->addItem(comp_baroreflex_gamma_h);
		input_container_baro_h->addItem(comp_baroreflex_T_p);
		input_container_baro_h->addItem(comp_baroreflex_beta_h);

		Phys_Container<link_layer::Component>* output_container_baro_h = new Phys_Container<link_layer::Component>;	
		output_container_baro_h->addItem(comp_baroreflex_h);
		sem_con_baroreflex_h->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_baro_h,
			(Phys_Container<link_layer::Link_layer_Component>*)output_container_baro_h);
		baroreflex_model->add_semantic_converter(sem_con_baroreflex_h);

		std::cout<< "******************************************"<<std::endl;
		while(input_container_baro_h->hasMoreVariables()){
			d = input_container_baro_h->getNextItem();
			std::cout<<"The current value for input variable in equation h is"<<d->get_value()<<std::endl;
		}

		baroreflex_mediator->add_component(baroreflex_model);

		return baroreflex_mediator;

	};
};