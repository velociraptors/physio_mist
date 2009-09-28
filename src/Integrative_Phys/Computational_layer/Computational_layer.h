/**************************************************************************************************
  Computational_layer.h
  Contributor(s):	E. Zeynep Erson
  Created on:		
  Description:		
**************************************************************************************************/

#ifndef	_COMPUTATIONAL_LAYER_H
#define _COMPUTATIONAL_LAYER_H

#include "utilities.h"
#include "EquationData.h"
//#include "Link_layer.h"
//#include "factory.h"

namespace computational_layer{

	class Mathematical_Model;
	
	//! A class for representing the computational model of a mathematical model.
	/*!
		Every mathematical model has different computational models. This is the superclass for such models.
		Encapsulates a mathematical model
	*/
	class Computation_Model
	{

	public:
		//!Default Constructor
		Computation_Model();
		//!Destructor
		virtual ~Computation_Model();

		//!Virtual method for running the model
		/*!
		 \param variable 
		 \param m
		*/
		virtual double run_Computation(double variable, Mathematical_Model* m);
		bool get_is_DE();
		void set_model(Mathematical_Model *model);
		Mathematical_Model* get_model();
		
	protected:
		bool is_DE;

	private:
		Mathematical_Model *model;
		

	};

		
	//! Continous time implementation of the Super class Computation_Model
	/*!
	\see Computation_Model

	*/

	class Continous_Time_Model : public Computation_Model
	{

	public:
		Continous_Time_Model();
		Continous_Time_Model(double step);
		virtual ~Continous_Time_Model();

		void set_h(double step);
		void calculate_error_estimate();
		virtual void determine_time_step();
		virtual void update_time_step();
		virtual double run_Computation(double variable, Mathematical_Model* m);
		virtual double integrate(double variable, Mathematical_Model* m, double h);
		double get_h();
	private:
		double h;

	};



	//! Discrecete time implementation of the Super class Computation_Model
	/*!
	\see Computation_Model
	*/

	class Discrete_Event_Model : public Computation_Model
	{

	public:
		Discrete_Event_Model();
		virtual ~Discrete_Event_Model();

		virtual void determine_time_step();
		virtual void update_time_step();
		void set_condition();
		bool get_condition();




	private:
		double arrival_time;
		double arrival_value;
		bool condition;

	};

	//! Discrete time implementation of the Super class Computation_Model
	/*!
	\see Computation_Model

	*/

	class Discrete_Time_Model : public Computation_Model
	{

	public:
		Discrete_Time_Model();
		virtual ~Discrete_Time_Model();

		virtual void determine_time_step();
		virtual void update_time_step();

	private:
		double time_step;

	};

	
	//! Class encapsulation the mathematical model of the physiological process 
	/*!
	Mathematical model contains computational information for the model, sampling time and imputs.
	The model to be executes is passed as a pointer to the class.
	\see setFunc(double (*pt2Func)(double,Phys_Container<double>)){;}

	*/

	class Mathematical_Model
	{

	public:	
		Mathematical_Model();
		virtual ~Mathematical_Model();

		void get_output_type();
		void set_Computation_Model(Computation_Model *computation_model);
		void set_inputs(Phys_Container<double> *in);
		void update_local_time(double _time);
		void set_sample_time(double time);
		void set_local_time(double time);
		double get_sample_time();
		double get_local_time();
		Computation_Model* get_Computation_Model();
		Phys_Container<double>* get_inputs();

		virtual double apply_model(double variable);
		virtual double derivative(double variable);
		virtual void setFunc(double (*pt2Func)(double,Phys_Container<double>)){;};


	private:
		Computation_Model *m_Computation_Model;
		bool isInitialConditionModel;
		Phys_Container<double> *inputs;
		double local_time;
		double sample_time;
	};

	class Model_time:public Mathematical_Model{
	public:
		Model_time();
		virtual ~Model_time();
		virtual double apply_model(double variable);
	};


	class Continous_mml_Math_Model : public Mathematical_Model
	{
	public:
		Continous_mml_Math_Model();
		Continous_mml_Math_Model(EquationData *eqdata);
		virtual ~Continous_mml_Math_Model(){;};

		virtual double apply_model(double variable);
		virtual double derivative(double variable);

		virtual void setFunc(double (*pt2Func)(double,Phys_Container<double>));

	private:
		double (*func)(double, Phys_Container<double>);
	};

	class Discrete_mml_Math_Model : public Mathematical_Model
	{
	public:
		Discrete_mml_Math_Model();
		Discrete_mml_Math_Model(EquationData *eqdata);
		virtual ~Discrete_mml_Math_Model(){;};

		virtual double apply_model(double variable);

		virtual void setFunc(double (*pt2Func)(double,Phys_Container<double>));

	private:
		double (*func)(double, Phys_Container<double>);
	};



	//!Continous Time Equation Integrator
	/*!
	Euler Integrator
	*/

class Euler_Computation_Model:public Continous_Time_Model{
public:
	virtual double integrate(double variable, Mathematical_Model* m, double h);

};

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

	//!Continous Time Equation Integrator
	/*!
	Runge_Kutta4 Integrator 
	 f1 = f(x)
	 x2 = x + h/2 * f1
	 f2 = f(x2)
	 x3 = x + h/2 * f2
	 f3 = f(x3)
	 x4 = x + h * f3
	 f4 = f(x4)
	 x = x + h/6 * (f1 + 2*f2 + 2*f3 + f4)
	*/
class Runge_Kutta_4:public Continous_Time_Model{
public:
	Runge_Kutta_4();
	Runge_Kutta_4(double step);
	virtual double integrate(double variable, Mathematical_Model* m, double h);
private:
	double f1;
	double x2;
	double f2;
	double x3;
	double f3;
	double x4;
	double f4;
	double initial_value;
	int rk4_step;


	/*double calculate_f1(double variable, Mathematical_Model* m);
	double calculate_f2(double variable, Mathematical_Model* m);
	double calculate_f3(double variable, Mathematical_Model* m);
	double calculate_f4(double variable, Mathematical_Model* m);*/


};


	//!Continous Time Equation Integrator
	/*!
	Runge_Kutta2 Integrator 
	*/
class Runge_Kutta_2:public Continous_Time_Model{
public:
	virtual double integrate(double variable, Mathematical_Model* m, double h);
};


}
#endif
