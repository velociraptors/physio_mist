/**************************************************************************************************
	Physiological_Variable.cpp
	Contributor(s):	E. Zeynep Erson
	Created on:		September 2007
	Description:	Implementation of the Physiological variable class. It is base class for all types of 
					physiological variables, such as circulatory or nervous physiological variables.
					Contains following members:
					1. Actual physiological variable represented as a double value
					2. Mathematical model: Represents the mathematical model that updates the value of the 
						variable.
					3. Can be either:
						a. Independent: A constant variable, whose value does not change based on the other
										variables. They are the parameters to other models.
						b. Dependent: Variables which have a mathematical model, taking other physiological 
										variables as inputs
					4. Has the following attributes:
						a. Quantitative: Single point or field
						b. Qualitative: Scalar or vectoral
						c. Temporal: Single_time or time_course
**************************************************************************************************/

#include "Physiological_layer.h"
#include <math.h>
#include <iostream>

using namespace physiological_layer;

Physiological_Variable::Physiological_Variable(){
	is_DE = false;
	m_Mathematical_Model = NULL;
	m_Temporal_property = NULL;
	value = new double(EMPTY_INITIAL_VALUE);
	derivative = new double(EMPTY_INITIAL_VALUE);
}
Physiological_Variable::Physiological_Variable(double* new_value, char *_unit){
	
	value = new double(EMPTY_INITIAL_VALUE);
	derivative = new double(EMPTY_INITIAL_VALUE);
	if(new_value!=NULL){
		*value = *new_value;
		//*derivative = 0.0;
	}
	unit = _unit;
	is_DE = false;
	m_Mathematical_Model = NULL;
	m_Temporal_property = NULL;

}



Physiological_Variable::~Physiological_Variable(){

}





double Physiological_Variable::get_sample_time(){
	double samp = 0.;
	if(get_Model()!=NULL){
		samp = get_Model()->get_sample_time();
	}
	return samp;
}
void Physiological_Variable::add_Model(computational_layer::Mathematical_Model *model){
	m_Mathematical_Model = model;
}

computational_layer::Mathematical_Model* Physiological_Variable::get_Model(){
	return m_Mathematical_Model;
	
}


/*void Physiological_Variable::attach_semantic_converter(Semantic_Converter sc){

}*/


Physiological_Variable* Physiological_Variable::get_sources()
{

	return  new Physiological_Variable();
}


/*
check the next components local time and update rate, do not run the model 
if it is not the right update time for that component
*/
void Physiological_Variable::update_variable(double current_time){
	computational_layer::Mathematical_Model* model =  this->get_Model();
	double new_value;
	double new_derivative;
	double test =  current_time -( get_local_time()+ get_sample_time());
	//todo: do we run at t==0 ?
	//todo: should we update the local time before or after the variable update?
	
	if(test < EPSILON){				
//		new_derivative = get_Model()->derivative(*(get_value()));
		new_value = get_Model()->apply_model(*(get_value()));
					
		Physiological_Variable::set_variable(new_value);			
		if((0.011125-current_time)<= EPSILON)
		{
			int i=6;
		}

//		set_derivative(new_derivative);
		//update_local_time();
		update_local_time(current_time);
	}

}

void Physiological_Variable::update_derivative(double current_time){
	computational_layer::Mathematical_Model* model =  this->get_Model();
	double new_value;
	double new_derivative;
	double test =  current_time -( get_local_time()+ get_sample_time());

	if(test < EPSILON){				
		new_derivative = get_Model()->derivative(*(get_value()));
	
		set_derivative(new_derivative);
	}

}


void Physiological_Variable::set_properties(Qualitative_property direction, Temporal_property temporal, Quantitative_property space){

}
double Physiological_Variable::get_local_time(){
	computational_layer::Mathematical_Model* model =  this->get_Model();
	double local_time = model->get_local_time();
	return local_time;
}

void Physiological_Variable::update_local_time(){
	get_Model()->update_local_time(get_Model()->get_sample_time());

}

void Physiological_Variable::update_local_time(double current_time){
	get_Model()->set_local_time(current_time);
}

void Physiological_Variable::reset_local_time(){
	if(get_Model()!=NULL){
		get_Model()->set_local_time(0.0);
	}
	
}

void Physiological_Variable::set_variable(double new_value){
	*value = new_value;

	//todo: also check for the type of time_course or single point temporal property
	physiological_layer::Time_course_property *temp = (physiological_layer::Time_course_property*)get_temporal_property();
	if(temp!=NULL){
		temp->add_state_variable(get_local_time(),*(get_value()));
	}	

}
void Physiological_Variable::set_derivative(double new_derivative){
	*derivative = new_derivative;
}

double* Physiological_Variable::get_value(){
	return Physiological_Variable::value;
}

double* Physiological_Variable::get_derivative(){
	return Physiological_Variable::derivative;
}

bool Physiological_Variable::is_Independent_Variable(){
	return Physiological_Variable::is_independent_variable;
}

void Physiological_Variable::set_Independent_Variable(bool is_independent){
	is_independent_variable = is_independent;
}

bool Physiological_Variable::is_variable_DE(){
	return is_DE;
}

bool Physiological_Variable:: operator==(const Physiological_Variable &v1)
{
		std::cout<<"For comparison this is"<<std::endl; 
		std::cout<<&(*this)<<std::endl;
		std::cout<<"For comparison compared is"<<std::endl; 
		std::cout<<&v1<<std::endl;

	if(this == &v1){
	
		return true;
	}
	else{
		return false;
	}

	return true;
}

void Physiological_Variable::set_name(char *_name){
	name = _name;
}

char* Physiological_Variable::get_name(){
	return name;
}

void Physiological_Variable::set_temporal_property(physiological_layer::Temporal_property *prop){
	m_Temporal_property = prop;
	
	//todo: is this required? set the initiala value of the physiological variable as the first element of the memory block
	//((Time_course_property*)m_Temporal_property)->add_state_variable(get_local_time(),*(get_value()));
}

/*
//variable list related metods

Variable_Container::Variable_Container(){
	
	Variable_Container::variable_list = new std::list<Physiological_Variable*>;

	Variable_Container::var_iter = Variable_Container::variable_list->begin();
}

Physiological_Variable* Variable_Container::addItem(physiological_layer::Physiological_Variable* newItem){	
	//std::cout<<"Item to add is"<<newItem<<std::endl;
	//physiological_layer::Physiological_Variable* temp  = new Physiological_Variable;
	this->variable_list->push_back(newItem);

	//this->variable_list->push_back(*newItem);
	//newItem = &(this->variable_list->back());
	return (this->variable_list->back());
}


Physiological_Variable *  Variable_Container::getNextItem(){	
	Physiological_Variable *variable = (*Variable_Container::var_iter);
	
	if(Variable_Container::var_iter==Variable_Container::variable_list->end())
	{
		reset_iterator();
	}
	else
	{
		Variable_Container::var_iter++;
	}

	
	return  variable;
}

void Variable_Container::deleteItem(physiological_layer::Physiological_Variable* item){
	std::cout<<"In the deleteItem is"<<std::endl; 
	std::cout<<item<<std::endl; 
	variable_list.remove(*item);

}

int Variable_Container::size(){
	return variable_list->size();
}
void Variable_Container::reset_iterator(){
	var_iter = variable_list->begin();

}
bool Variable_Container::hasMoreVariables()
{
	return var_iter!=variable_list->end();
}

void Variable_Container::print_list(){
	// Create constant iterator for list.
	Variable_Container::reset_iterator();
  // Iterate through list and output each element.
	for (var_iter = variable_list->begin(); var_iter!=variable_list->end(); var_iter++)
  {
	 // std::cout << (var_iter)->get_value() << std::endl;
  }
	reset_iterator();
}

*/

/**************************************************************************************************
Implementation of Temporal Properties
1. Time_course: The variable keeps the state information for the previous simulation steps together
				with the time associated with those states.
**************************************************************************************************/

Time_course_property::Time_course_property(int _size){
	size = _size;
}

void Time_course_property::add_state_variable(double index, double variable){
	State_Variable *var = new State_Variable(index, variable);
	if(previous_variables.size()<size){
		previous_variables.addItem(var);
	}
	else{
		previous_variables.popFirstItem();
		previous_variables.addItem(var);
	}	
}

double* Time_course_property::get_state_variable(double index){
	previous_variables.reset_iterator();

	if(index >= 0){
		while(previous_variables.hasMoreVariables()){
			State_Variable *st = previous_variables.getNextItem();
			if(fabs(st->get_index()-index) < EPSILON){			
				return st->get_value();
			}
		}
	}
	return NULL;
}


