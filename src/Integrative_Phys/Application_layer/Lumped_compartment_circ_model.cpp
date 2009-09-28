/**************************************************************************************************
  Circulatory_System_models.cpp
  Implementation of the Ciculatotry System models
  Contributor(s): E. Zeynep Erson
  Created on:     October 2007
  Description:	This file contains the mathematical models for the circulatory system models defined im
				"Mathematical Physiology".
				Single compartment, multicompartment and 3 compartment abstractions are defined.
**************************************************************************************************/

#include "Computational_layer.h"
#include "Link_layer.h"
#include "Circulatory_System.h"

namespace computational_layer{

	/*
	Mathematical models Circulatory system components for 3-compartment model,
	From "Mathematical Physiology", page.454 eqns. 15.76-15.81
	The defined models are for the 3 compartment circulatory system and following variables are used :
	1. p_sa: Pressure at the entrance to the systemic arteries
	2. p_sv: Pressure at the entrance to the systemic veins
	3. p_s:	 Pressure at the systemic system
	4. p_pa: Pressure at the entrance to the pulmonary arteries
	5. p_pv: Pressure at the entrance to the pulmonary veins
	6. q:	 Cardiac output
	*/

	class Model_p_sa:public Mathematical_Model{
	public:
		
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//F
			double var_3 = *(in_list->getNextItem());//c_rd
			double var_4 = *(in_list->getNextItem());//Rsa
			double var_5 = *(in_list->getNextItem());//Rsv

			double result = var_1*((1/(var_2*var_3))+var_4+var_5);

			return result;

		};
	};

	class Model_p_s:public Mathematical_Model{
	public:

		virtual double Model_p_s::apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//F
			double var_3 = *(in_list->getNextItem());//c_rd
			double var_4 = *(in_list->getNextItem());//Rsv

			double result = var_1*((1/(var_2*var_3))+var_4);

			return result;

		};

	};

	class Model_p_sv:public Mathematical_Model{
	public:		
		virtual double Model_p_sv::apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//F
			double var_3 = *(in_list->getNextItem());//c_rd

			double result = (var_1/(var_2*var_3));

			return result;
		}

	};

	class Model_p_pa:public Mathematical_Model{
	public:
		virtual double Model_p_pa::apply_model(double variable){

			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//F
			double var_3 = *(in_list->getNextItem());//c_ld
			double var_4 = *(in_list->getNextItem());//Rp

			double result = var_1*((1/(var_2*var_3))+var_4);
			return result;
		};
	};
	class Model_p_pv:public Mathematical_Model{
	public:
		virtual double Model_p_pv::apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//q
			double var_2 = *(in_list->getNextItem());//F
			double var_3 = *(in_list->getNextItem());//c_ld
			
			double result = (var_1/(var_2*var_3));

			return result;

		};
	};
	class Model_q:public Mathematical_Model{
	public:
		virtual double Model_q::apply_model(double variable){

			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//Ve
			double var_2 = *(in_list->getNextItem());//alpha
			double var_3 = *(in_list->getNextItem());//Cp
			double var_4 = *(in_list->getNextItem());//F
			double var_5 = *(in_list->getNextItem());//Cld
			double var_6 = *(in_list->getNextItem());//Csv
			double var_7 = *(in_list->getNextItem());//Csa
			double var_8 = *(in_list->getNextItem());//Crd
			
			double result = var_1 / (var_2 + (var_3/(var_4*var_5)) + ((var_6+var_7)/(var_4*var_8)));
			return result;

		};
	};
	class Model_alpha:public Mathematical_Model{
	public:
		virtual double Model_alpha::apply_model(double variable){

			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//Rsv
			double var_2 = *(in_list->getNextItem());//Csa
			double var_3 = *(in_list->getNextItem());//Csv
			double var_4 = *(in_list->getNextItem());//Rsa
			double var_5 = *(in_list->getNextItem());//Cp
			double var_6 = *(in_list->getNextItem());//Rp
			
			double result = var_1*(var_2+var_3/2) + var_4*var_2/2 + var_5*var_6/2	;

			return result;

		};

	};
	class Model_ve:public Mathematical_Model{
	public:
		virtual double Model_ve::apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//V
			double var_2 = *(in_list->getNextItem());//V0s
			double var_3 = *(in_list->getNextItem());//V0p
			
			double result = var_1 - var_2 - var_3;

			return result;

		};
	
	};

	/*
	Mathematical models Circulatory system components for 1-compartment model,
	From "Mathematical Physiology", page.450 eqns. 15.50-15.53

	The defined models are for the 1 compartment circulatory system and following variables are used :
	1. p_a: Arterial Pressure 
	2. p_v: Ventrical Pressure 
	3. q:	 Cardiac output
	*/
	class Model_p_a:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){				
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//F
			double var_2 = *(in_list->getNextItem());//Cd
			double var_3 = *(in_list->getNextItem());//Rs
			double var_4 = *(in_list->getNextItem());//V0
			double var_5 = *(in_list->getNextItem());//Cv
			double var_6 = *(in_list->getNextItem());//Ca
			
			double result = ((1+var_1*var_2*var_3)*var_4)/(var_5+(1+var_1*var_2*var_3)*var_6);

			return result;
		};
	};

	class Model_p_v:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//V0
			double var_2 = *(in_list->getNextItem());//CV
			double var_3 = *(in_list->getNextItem());//f
			double var_4 = *(in_list->getNextItem());//Cd
			double var_5 = *(in_list->getNextItem());//Rs
			double var_6 = *(in_list->getNextItem());//Ca
			
			double result = (var_1)/(var_2 + (1+var_3*var_4*var_5)*var_6);

			return result;
		};
	};

	class Model_q_1:public Mathematical_Model{
	public:
		virtual double apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//F
			double var_2 = *(in_list->getNextItem());//Cd
			double var_3 = *(in_list->getNextItem());//V0
			double var_4 = *(in_list->getNextItem());//Cv
			double var_5 = *(in_list->getNextItem());//Rs
			double var_6 = *(in_list->getNextItem());//Ca
			
			double result = (var_1*var_2*var_3)/(var_4+(1+var_1*var_2*var_5)*var_6);

			return result;
		};
	};

	}


	class Lumped_three_comp_Circ_Model{
	public:	
		Lumped_three_comp_Circ_Model(){;};
		virtual ~Lumped_three_comp_Circ_Model(){;};

		static link_layer::Mediator* create_lumped_circulatory_system_model(){

	//		link_layer::Circulatory_Mediator *circ_mediator = link_layer::Circulatory_Mediator::getInstance();
			link_layer::Circulatory_Mediator *circ_mediator = new link_layer::Circulatory_Mediator();
			link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();
			
			Physiological_Factory *factory = Physiological_Factory::getInstance();
			//Systemic System
			link_layer::SubModel_Component *systemic_system = new link_layer::SubModel_Component("systemic_system");
			

			computational_layer::Model_p_sa *p_sa_model = new computational_layer::Model_p_sa;
			link_layer::Component *comp_p_sa = factory->generate_component("p_sa",DISCRETE_TIME,DEPENDENT_VAR,p_sa_model,0,"mmHg");
			systemic_system->add_component(comp_p_sa);

			
			computational_layer::Model_p_s *p_s_model = new computational_layer::Model_p_s;
			link_layer::Component *comp_p_s = factory->generate_component("p_s",DISCRETE_TIME,DEPENDENT_VAR,p_s_model,0,"mmHg");
			systemic_system->add_component(comp_p_s);


			
			computational_layer::Model_p_sv *p_sv_model = new computational_layer::Model_p_sv;
			link_layer::Component *comp_p_sv = factory->generate_component("p_sv",DISCRETE_TIME,DEPENDENT_VAR,p_sv_model,0,"mmHg");
			systemic_system->add_component(comp_p_sv);


			intrinsic_mediator->add_component(systemic_system);
			//circ_mediator->set_intrinsic_components(systemic_system);

			//Pulmonary System
			link_layer::SubModel_Component *pulmonary_system = new link_layer::SubModel_Component ("pulmonary_system");


			computational_layer::Model_p_pa *p_pa_model = new computational_layer::Model_p_pa;
			link_layer::Component *comp_p_pa = factory->generate_component("p_pa",DISCRETE_TIME,DEPENDENT_VAR,p_pa_model,0,"mmHg");
			pulmonary_system->add_component(comp_p_pa);

			computational_layer::Model_p_pv *p_pv_model = new computational_layer::Model_p_pv;
			link_layer::Component *comp_p_pv = factory->generate_component("p_pv",DISCRETE_TIME,DEPENDENT_VAR,p_pv_model,0,"mmHg");
			pulmonary_system->add_component(comp_p_pv);

			intrinsic_mediator->add_component(pulmonary_system);
			//circ_mediator->set_intrinsic_components(pulmonary_system);


			//Heart system
			link_layer::SubModel_Component *heart_system = new link_layer::SubModel_Component ("heart_system");

			
			computational_layer::Model_q *q_model = new computational_layer::Model_q;
			link_layer::Component *comp_q = factory->generate_component("q",DISCRETE_TIME,DEPENDENT_VAR,q_model,0,"litre/min");
			heart_system->add_component(comp_q);



			computational_layer::Model_alpha *alpha_model = new computational_layer::Model_alpha;
			link_layer::Component *comp_alpha = factory->generate_component("alpha",DISCRETE_TIME,DEPENDENT_VAR,alpha_model,0,NULL);
			heart_system->add_component(comp_alpha);

			computational_layer::Model_ve *ve_model = new computational_layer::Model_ve;
			link_layer::Component *comp_ve = factory->generate_component("Ve",DISCRETE_TIME,DEPENDENT_VAR,ve_model,0,"litre");
			heart_system->add_component(comp_ve);

			intrinsic_mediator->add_component(heart_system);
			//circ_mediator->set_intrinsic_components(heart_system);


			//define parameters
			link_layer::Component *comp_F = factory->generate_component("F",NULL,INDEPENDENT_VAR,NULL,new double(80),"1/min");
			//circ_mediator->set_intrinsic_components(comp_F);
			heart_system->add_component(comp_F);

			link_layer::Component *comp_c_rd = factory->generate_component("c_rd",NULL,INDEPENDENT_VAR,NULL,new double(0.35),"(litre/mmHg)/stroke");
			//circ_mediator->set_intrinsic_components(comp_c_rd);
			heart_system->add_component(comp_c_rd);
			
			link_layer::Component *comp_r_sa = factory->generate_component("r_sa",NULL,INDEPENDENT_VAR,NULL,new double(12.5),"mmHg/(litre/min)");
			//circ_mediator->set_intrinsic_components(comp_r_sa);
			systemic_system->add_component(comp_r_sa);
			
			link_layer::Component *comp_r_sv = factory->generate_component("r_sv",NULL,INDEPENDENT_VAR,NULL,new double(5),"mmHg/(litre/min)");
			//circ_mediator->set_intrinsic_components(comp_r_sv);
			systemic_system->add_component(comp_r_sv);


			link_layer::Component *comp_c_ld = factory->generate_component("c_ld",NULL,INDEPENDENT_VAR,NULL,new double(0.014),"(litre/mmHg)/stroke");
			//circ_mediator->set_intrinsic_components(comp_c_ld);
			pulmonary_system->add_component(comp_c_ld);


			link_layer::Component *comp_r_p = factory->generate_component("r_p",NULL,INDEPENDENT_VAR,NULL,new double(1.78),"mmHg/(litre/min)");
			//circ_mediator->set_intrinsic_components(comp_r_p);
			pulmonary_system->add_component(comp_r_p);


			link_layer::Component *comp_c_sv = factory->generate_component("c_sv",NULL,INDEPENDENT_VAR,NULL,new double(0.22),"litre/mmHg");
			//circ_mediator->set_intrinsic_components(comp_c_sv);
			systemic_system->add_component(comp_c_sv);


			link_layer::Component *comp_c_sa = factory->generate_component("c_sa",NULL,INDEPENDENT_VAR,NULL,new double(0.0018),"litre/mmHg");
			//circ_mediator->set_intrinsic_components(comp_c_sa);
			systemic_system->add_component(comp_c_sa);


			link_layer::Component *comp_c_p = factory->generate_component("c_p",NULL,INDEPENDENT_VAR,NULL,new double(0.05),"litre/mmHg");
			//circ_mediator->set_intrinsic_components(comp_c_p);
			pulmonary_system->add_component(comp_c_p);


			link_layer::Component *comp_v = factory->generate_component("V",NULL,INDEPENDENT_VAR,NULL,new double(5),"litre");
			//circ_mediator->set_intrinsic_components(comp_v);
			heart_system->add_component(comp_v);



			link_layer::Component *comp_v0_s = factory->generate_component("v0_s",NULL,INDEPENDENT_VAR,NULL,new double(0.94),"litre");
			//circ_mediator->set_intrinsic_components(comp_v0_s);
			heart_system->add_component(comp_v0_s);

			link_layer::Component *comp_v0_p = factory->generate_component("v0_p",NULL,INDEPENDENT_VAR,NULL,new double(0.8),"litre");
			//circ_mediator->set_intrinsic_components(comp_v0_p);
			heart_system->add_component(comp_v0_p);

			
			//semantic converter for equation 15.76-for P_sa
			link_layer::Horizontal_semantic_converter *sem_con_p_sa= new link_layer::Horizontal_semantic_converter;
			Phys_Container<link_layer::Component>* input_container_p_sa = new Phys_Container<link_layer::Component>;
			input_container_p_sa->addItem(comp_q);
			input_container_p_sa->addItem(comp_F);
			input_container_p_sa->addItem(comp_c_rd);
			input_container_p_sa->addItem(comp_r_sa);
			input_container_p_sa->addItem(comp_r_sv);

			Phys_Container<link_layer::Component>* output_container_p_sa = new Phys_Container<link_layer::Component>;	
			output_container_p_sa->addItem(comp_p_sa);
			sem_con_p_sa->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_sa,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_sa);

			link_layer::Component* d; 
			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_sa->hasMoreVariables()){
				d = input_container_p_sa->getNextItem();
				std::cout<<"The current value for input variable in equation p_sa is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_p_sa);
			systemic_system->add_semantic_converter(sem_con_p_sa);


			//semantic converter for equation 15.77-for P_s		
			link_layer::Horizontal_semantic_converter *sem_con_p_s= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_p_s = new Phys_Container<link_layer::Component>;
			input_container_p_s->addItem(comp_q);
			input_container_p_s->addItem(comp_F);
			input_container_p_s->addItem(comp_c_rd);
			input_container_p_s->addItem(comp_r_sv);

			Phys_Container<link_layer::Component>* output_container_p_s = new Phys_Container<link_layer::Component>;	
			output_container_p_s->addItem(comp_p_s);
			sem_con_p_s->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_s,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_s);

			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_s->hasMoreVariables()){
				d = input_container_p_s->getNextItem();
				std::cout<<"The current value for input variable in equation p_s is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_p_s);
			systemic_system->add_semantic_converter(sem_con_p_s);


			//semantic converter for equation 15.78-for P_sv		
			link_layer::Horizontal_semantic_converter *sem_con_p_sv= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_p_sv = new Phys_Container<link_layer::Component>;
			input_container_p_sv->addItem(comp_q);
			input_container_p_sv->addItem(comp_F);
			input_container_p_sv->addItem(comp_c_rd);

			Phys_Container<link_layer::Component>* output_container_p_sv = new Phys_Container<link_layer::Component>;	
			output_container_p_sv->addItem(comp_p_sv);
			sem_con_p_sv->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_sv,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_sv);

			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_sv->hasMoreVariables()){
				d = input_container_p_sv->getNextItem();
				std::cout<<"The current value for input variable in equation p_sv is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_p_sv);
			systemic_system->add_semantic_converter(sem_con_p_sv);

			//semantic converter for equation 15.79-for P_pa		
			link_layer::Horizontal_semantic_converter *sem_con_p_pa= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_p_pa = new Phys_Container<link_layer::Component>;
			input_container_p_pa->addItem(comp_q);
			input_container_p_pa->addItem(comp_F);
			input_container_p_pa->addItem(comp_c_ld);
			input_container_p_pa->addItem(comp_r_p);

			Phys_Container<link_layer::Component>* output_container_p_pa = new Phys_Container<link_layer::Component>;	
			output_container_p_pa->addItem(comp_p_pa);
			sem_con_p_pa->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_pa,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_pa);

			
			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_pa->hasMoreVariables()){
				d = input_container_p_pa->getNextItem();
				std::cout<<"The current value for input variable in equation p_pa is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_p_pa);
			pulmonary_system->add_semantic_converter(sem_con_p_pa);


			//semantic converter for equation 15.80-for P_pv		
			link_layer::Horizontal_semantic_converter *sem_con_p_pv= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_p_pv = new Phys_Container<link_layer::Component>;
			input_container_p_pv->addItem(comp_q);
			input_container_p_pv->addItem(comp_F);
			input_container_p_pv->addItem(comp_c_ld);

			Phys_Container<link_layer::Component>* output_container_p_pv = new Phys_Container<link_layer::Component>;	
			output_container_p_pv->addItem(comp_p_pv);
			sem_con_p_pv->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_pv,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_pv);


			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_pv->hasMoreVariables()){
				d = input_container_p_pv->getNextItem();
				std::cout<<"The current value for input variable in equation p_pv is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_p_pv);
			pulmonary_system->add_semantic_converter(sem_con_p_pv);

			//semantic converter for equation 15.81-for q
			link_layer::Horizontal_semantic_converter *sem_con_q= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_q = new Phys_Container<link_layer::Component>;
			input_container_q->addItem(comp_ve);
			input_container_q->addItem(comp_alpha);
			input_container_q->addItem(comp_c_p);
			input_container_q->addItem(comp_F);
			input_container_q->addItem(comp_c_ld);
			input_container_q->addItem(comp_c_sv);
			input_container_q->addItem(comp_c_sa);
			input_container_q->addItem(comp_c_rd);

			Phys_Container<link_layer::Component>* output_container_q = new Phys_Container<link_layer::Component>;	
			output_container_q->addItem(comp_q);
			sem_con_q->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_q,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_q);


			std::cout<< "******************************************"<<std::endl;
			while(input_container_q->hasMoreVariables()){
				d = input_container_q->getNextItem();
				std::cout<<"The current value for input variable in equation q is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_q);
			heart_system->add_semantic_converter(sem_con_q);

			//semantic converter for equation 15.81-for ve
			link_layer::Horizontal_semantic_converter *sem_con_ve= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_ve = new Phys_Container<link_layer::Component>;
			input_container_ve->addItem(comp_v);
			input_container_ve->addItem(comp_v0_s);
			input_container_ve->addItem(comp_v0_p);

			Phys_Container<link_layer::Component>* output_container_ve = new Phys_Container<link_layer::Component>;	
			output_container_ve->addItem(comp_ve);
			sem_con_ve->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_ve,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_ve);


			std::cout<< "******************************************"<<std::endl;
			while(input_container_ve->hasMoreVariables()){
				d = input_container_ve->getNextItem();
				std::cout<<"The current value for input variable in equation ve is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_ve);
			heart_system->add_semantic_converter(sem_con_ve);

			//semantic converter for equation 15.81-for alpha
			link_layer::Horizontal_semantic_converter *sem_con_alpha= new link_layer::Horizontal_semantic_converter();
			Phys_Container<link_layer::Component>* input_container_alpha = new Phys_Container<link_layer::Component>;
			input_container_alpha->addItem(comp_r_sv);
			input_container_alpha->addItem(comp_c_sa);
			input_container_alpha->addItem(comp_c_sv);
			input_container_alpha->addItem(comp_r_sa);
			input_container_alpha->addItem(comp_c_p);
			input_container_alpha->addItem(comp_r_p);


			Phys_Container<link_layer::Component>* output_container_alpha = new Phys_Container<link_layer::Component>;	
			output_container_alpha->addItem(comp_alpha);
			sem_con_alpha->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_alpha,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_alpha);

			std::cout<< "******************************************"<<std::endl;
			while(input_container_alpha->hasMoreVariables()){
				d = input_container_alpha->getNextItem();
				std::cout<<"The current value for input variable in equation ve is"<<d->get_value()<<std::endl;
			}

			//circ_mediator->add_semantic_converter(sem_con_alpha);
			heart_system->add_semantic_converter(sem_con_alpha);

			circ_mediator->set_intrinsic_mediator(intrinsic_mediator);
			return circ_mediator;

		};
	
	};

	class Lumped_one_comp_Circ_Model{
	public:	
		Lumped_one_comp_Circ_Model(){;};
		virtual ~Lumped_one_comp_Circ_Model(){;};

		static link_layer::Mediator* create_lumped_circulatory_system_model(){
			
			Physiological_Factory *factory = Physiological_Factory::getInstance();

			link_layer::Circulatory_Mediator *circ_mediator = new link_layer::Circulatory_Mediator;
			link_layer::Mediator *intrinsic_mediator  = new link_layer::Mediator();

			//Arterial System
			link_layer::SubModel_Component *arterial_system = new link_layer::SubModel_Component("arterial_system");
			computational_layer::Model_p_a *p_a_model = new computational_layer::Model_p_a;
			link_layer::Component *comp_p_a = factory->generate_component("p_a",DISCRETE_TIME,DEPENDENT_VAR,p_a_model,0,"mmHg");
			arterial_system->add_component(comp_p_a);

			intrinsic_mediator->add_component(arterial_system);

			//Venous System
			link_layer::SubModel_Component *venous_system = new link_layer::SubModel_Component("venous_system");
			computational_layer::Model_p_v *p_v_model = new computational_layer::Model_p_v;
			link_layer::Component *comp_p_v = factory->generate_component("p_v",DISCRETE_TIME,DEPENDENT_VAR,p_v_model,0,"mmHg");
			venous_system->add_component(comp_p_v);

			intrinsic_mediator->add_component(venous_system);

			//Cardiac system
			link_layer::SubModel_Component *cardiac_system = new link_layer::SubModel_Component("cardiac_system");
			computational_layer::Model_q_1 *q_model = new computational_layer::Model_q_1;
			link_layer::Component *comp_q = factory->generate_component("q",DISCRETE_TIME,DEPENDENT_VAR,q_model,new double(0),"litre/min");
			cardiac_system->add_component(comp_q);

			intrinsic_mediator->add_component(cardiac_system);


			//define parameters
			link_layer::Component *comp_F = factory->generate_component("F",NULL,INDEPENDENT_VAR,NULL,new double(80),"1/min");
			cardiac_system->add_component(comp_F);

			link_layer::Component *comp_c_d = factory->generate_component("c_d",NULL,INDEPENDENT_VAR,NULL,new double(0.35),"(litre/mmHg)/stroke");
			cardiac_system->add_component(comp_c_d);

			link_layer::Component *comp_r_s = factory->generate_component("r_s",NULL,INDEPENDENT_VAR,NULL,new double(12.5),"mmHg/(litre/min)");
			arterial_system->add_component(comp_r_s);

			link_layer::Component *comp_v_0 = factory->generate_component("v_0",NULL,INDEPENDENT_VAR,NULL,new double(5),"litre");
			cardiac_system->add_component(comp_v_0);

			link_layer::Component *comp_c_v = factory->generate_component("c_v",NULL,INDEPENDENT_VAR,NULL,new double(0.22),"litre/mmHg");
			venous_system->add_component(comp_c_v);

			link_layer::Component *comp_c_a = factory->generate_component("c_a",NULL,INDEPENDENT_VAR,NULL,new double(0.0018),"litre/mmHg");
			arterial_system->add_component(comp_c_a);

			//define semantic_converters
			//semantic converter for equation 15.50-for P_a
			link_layer::Horizontal_semantic_converter *sem_con_p_a= new link_layer::Horizontal_semantic_converter;
			Phys_Container<link_layer::Component>* input_container_p_a = new Phys_Container<link_layer::Component>;
			input_container_p_a->addItem(comp_F);
			input_container_p_a->addItem(comp_c_d);
			input_container_p_a->addItem(comp_r_s);
			input_container_p_a->addItem(comp_v_0);
			input_container_p_a->addItem(comp_c_v);
			input_container_p_a->addItem(comp_c_a);

			Phys_Container<link_layer::Component>* output_container_p_a = new Phys_Container<link_layer::Component>;	
			output_container_p_a->addItem(comp_p_a);
			sem_con_p_a->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_a,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_a);

			link_layer::Component* d; 
			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_a->hasMoreVariables()){
				d = input_container_p_a->getNextItem();
				std::cout<<"The current value for input variable in equation p_a is"<<d->get_value()<<std::endl;
			}

			arterial_system->add_semantic_converter(sem_con_p_a);


			//semantic converter for equation 15.51-for P_v
			link_layer::Horizontal_semantic_converter *sem_con_p_v= new link_layer::Horizontal_semantic_converter;
			Phys_Container<link_layer::Component>* input_container_p_v = new Phys_Container<link_layer::Component>;
			input_container_p_v->addItem(comp_v_0);
			input_container_p_v->addItem(comp_c_v);
			input_container_p_v->addItem(comp_F);
			input_container_p_v->addItem(comp_c_d);
			input_container_p_v->addItem(comp_r_s);
			input_container_p_v->addItem(comp_c_a);

			Phys_Container<link_layer::Component>* output_container_p_v = new Phys_Container<link_layer::Component>;	
			output_container_p_v->addItem(comp_p_v);
			sem_con_p_v->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_p_v,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_p_v);

			std::cout<< "******************************************"<<std::endl;
			while(input_container_p_v->hasMoreVariables()){
				d = input_container_p_v->getNextItem();
				std::cout<<"The current value for input variable in equation p_v is"<<d->get_value()<<std::endl;
			}

			venous_system->add_semantic_converter(sem_con_p_v);


			//semantic converter for equation 15.52-for Q
			link_layer::Horizontal_semantic_converter *sem_con_q_1= new link_layer::Horizontal_semantic_converter;
			Phys_Container<link_layer::Component>* input_container_q_1 = new Phys_Container<link_layer::Component>;
			input_container_q_1->addItem(comp_F);
			input_container_q_1->addItem(comp_c_d);
			input_container_q_1->addItem(comp_v_0);
			input_container_q_1->addItem(comp_c_v);
			input_container_q_1->addItem(comp_r_s);
			input_container_q_1->addItem(comp_c_a);

			Phys_Container<link_layer::Component>* output_container_q_1 = new Phys_Container<link_layer::Component>;	
			output_container_q_1->addItem(comp_q);
			sem_con_q_1->set_input_output((Phys_Container<link_layer::Link_layer_Component>*)input_container_q_1,
				(Phys_Container<link_layer::Link_layer_Component>*)output_container_q_1);

			std::cout<< "******************************************"<<std::endl;
			while(input_container_q_1->hasMoreVariables()){
				d = input_container_q_1->getNextItem();
				std::cout<<"The current value for input variable in equation q_1 is"<<d->get_value()<<std::endl;
			}

			cardiac_system->add_semantic_converter(sem_con_q_1);
			circ_mediator->set_intrinsic_mediator(intrinsic_mediator);
			return circ_mediator;


		};
		
};
