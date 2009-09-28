/*************************************************************************************************
  Continous_Time_Model.cpp
  Contributor(s): E. Zeynep Erson
  Created on:      31-Jul-2007 1:50:07 PM
  Description:	Gives the different implementations for the continous time solvers.
				1. Euler method:
				2. Runge-Kutta method: 4 step or 2 step method
*************************************************************************************************/

#include "computational_layer.h"


using namespace computational_layer;
Continous_Time_Model::Continous_Time_Model(double step){
	
	is_DE = false;
	h = step;

}

Continous_Time_Model::Continous_Time_Model(){
	
	is_DE = false;

}

Continous_Time_Model::~Continous_Time_Model(){

}

void Continous_Time_Model::calculate_error_estimate(){

}

void Continous_Time_Model::set_h(double step){
	h = step;
}

double Continous_Time_Model::get_h(){
	return h;
}
void Continous_Time_Model::determine_time_step(){

}

void Continous_Time_Model::update_time_step(){
}

double Continous_Time_Model::run_Computation(double variable, Mathematical_Model* m){
	return integrate(variable, m, m->get_sample_time());
}
double Continous_Time_Model::integrate(double variable, Mathematical_Model* m, double h){
	return 0.;

}

double Euler_Computation_Model::integrate(double variable, Mathematical_Model* m, double h){

	double derivative = m->derivative(variable);
	return variable + h * derivative;
}


/*double Runge_Kutta_4::calculate_f1(double variable, Mathematical_Model* m){
	f1 = m->derivative(variable);
}

double Runge_Kutta_4::calculate_f2(double variable, Mathematical_Model* m){

	double x2 = variable + h/2*f1;
    f2 = m->derivative(x2);
}

double Runge_Kutta_4::calculate_f3(double variable, Mathematical_Model* m){
	double x3 = variable + h/2*f2;
	 f3 = m->derivative(x3);
}

double Runge_Kutta_4::calculate_f4(double variable, Mathematical_Model* m){

	double x4 = variable + h*f3;
	f4 = m->derivative(x4);

}*/
Runge_Kutta_4::Runge_Kutta_4(){
	rk4_step = 0;
}
Runge_Kutta_4::Runge_Kutta_4(double step):Continous_Time_Model(step){
	rk4_step = 0;
}
double Runge_Kutta_4::integrate(double variable, Mathematical_Model* m, double step){
	
	if(rk4_step==0){
		initial_value = variable;
		f1 = m->derivative(variable);	   
		x2 = initial_value + ((get_h()/2)*f1);
		rk4_step++;
		return x2;
	}
	else if(rk4_step==1){
		f2 = m->derivative(x2);
	    x3 = initial_value + ((get_h()/2)*f2);
		rk4_step++;
		return x3;

	}
	else if(rk4_step==2){
		f3 = m->derivative(x3);
		x4 = initial_value + ((get_h())*f3);
		rk4_step++;
		return  x4;
	}
	else{
		f4 = m->derivative(x4);
		double result = initial_value + ((get_h()/6) * (f1+ 2*f2 + 2*f3 + f4));
		rk4_step=0;
		return result;
		
	}
	/*
	// f1 = f(x)
	// x2 = x + h/2 * f1
	// f2 = f(x2)
	// x3 = x + h/2 * f2
	// f3 = f(x3)
	// x4 = x + h * f3
	// f4 = f(x4)
	// x = x + h/6 * (f1 + 2*f2 + 2*f3 + f4)

	*/

}
double Runge_Kutta_2::integrate(double variable, Mathematical_Model* m, double h){
	/*
	// f1 = f(x)
	// x2 = x + h/2 * f1
	// f2 = f(x2)
	// x = x + h * (f2)

	*/
	double f1 = m->derivative(variable);
	double x2 = variable + h/2*f1;
	double f2 = m->derivative(x2);
	double result = variable + h* (f2);
	return result;

}


/*
template <class S>
void Euler<S>::Integrate(S &system, Real h)
{
  State &state = system.GetState();
  
  // calculate f(t, x(t))
  system.DerivState(f, state);

  // x = x + h * f;
  system.AccumState(state, state, f, h); 
  
}

*/