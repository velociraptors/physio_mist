/*************************************************************************************************
  Mathematical_Model.cpp
  Contributor(s): E. Zeynep Erson
  Created on:      31-Jul-2007 1:50:07 PM
  Description:	Mathematical formulation of any process are described with Mathematical_models.
				The model is applied through apply_model() and of the computation model is a continous model, 
				the derivative() and integrate() methods are used.
*************************************************************************************************/




#include "computational_layer.h"

using namespace computational_layer;

Mathematical_Model::Mathematical_Model(){
	m_Computation_Model = NULL;
	inputs = new Phys_Container<double>;
	//todo:FOR TEST PURPOSES
	//set_sample_time(0.000125);
	set_sample_time(0.0001);
	set_local_time(0.0);
}



Mathematical_Model::~Mathematical_Model(){

}



void Mathematical_Model::set_Computation_Model(Computation_Model *computation_model){
	m_Computation_Model = computation_model;
	m_Computation_Model->set_model(this);
	
}

Computation_Model* Mathematical_Model::get_Computation_Model(){
	return Mathematical_Model::m_Computation_Model;
}
void Mathematical_Model::get_output_type(){

}


void Mathematical_Model::set_inputs(Phys_Container<double> *in){
	inputs->clear();
	while(in->hasMoreVariables())
	{
		inputs->addItem(in->getNextItem());
	}
}

Phys_Container<double>* Mathematical_Model::get_inputs(){
	return inputs;
}
void Mathematical_Model::set_sample_time(double time){
	sample_time = time;
}
double Mathematical_Model::get_sample_time(){
	return sample_time;
}

void Mathematical_Model::update_local_time(double _time){
	local_time+=_time;
}
void Mathematical_Model::set_local_time(double time){
	local_time = time;
}

double Mathematical_Model::get_local_time(){
	return local_time;
}
double Mathematical_Model::apply_model(double variable){return NULL;}

//todo: what should the default behavior do?return NULL or return 0?
double Mathematical_Model::derivative(double variable){return NULL;}



/*Mathematical Models extracted from mml files*/

Continous_mml_Math_Model::Continous_mml_Math_Model(){
	
			func = NULL;
}

Continous_mml_Math_Model::Continous_mml_Math_Model(EquationData *eqdata){
	func = NULL;
}

double Continous_mml_Math_Model::apply_model(double variable){
	return this->get_Computation_Model()->run_Computation(variable, this);
}

void Continous_mml_Math_Model::setFunc(double (*pt2Func)(double,Phys_Container<double>))
{
	func = pt2Func;
}

double Continous_mml_Math_Model::derivative(double variable){

	double result =  (*func)(variable,get_inputs());
	return result;		
}

//Mathematical model for time
Model_time::Model_time(){
}
Model_time::~Model_time(){
}

double Model_time::apply_model(double variable){
			Phys_Container<double> *in_list = new Phys_Container<double>(Mathematical_Model::get_inputs());
			double var_1 = *(in_list->getNextItem());//t_delta
			double var_2 = *(in_list->getNextItem());//t_max
			double result = variable ;
			if(variable+var_1<=var_2){
				result = variable+var_1;
			}
			return result;
}




/*Mathematical Models extracted from mml files*/

Discrete_mml_Math_Model::Discrete_mml_Math_Model(){
			func = NULL;
}

Discrete_mml_Math_Model::Discrete_mml_Math_Model(EquationData *eqdata){
	func = NULL;

}

double Discrete_mml_Math_Model::apply_model(double variable){
	double result =  (*func)(variable,get_inputs());
	return result;

}

void Discrete_mml_Math_Model::setFunc(double (*pt2Func)(double,Phys_Container<double>))
{
	func = pt2Func;
}