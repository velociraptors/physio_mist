/**************************************************************************************************
  mmldata.h

  Contributor(s): Robin Hu
				  E. Zeynep Erson				  
  Created on:     December 2007
  Definition:	  Wrappers for storing parsed parameter and variable data,
					ParameterData, stores name, unit and value of parameter
					VariableData, stores name, unit and initial value of variable
**************************************************************************************************/

#ifndef PARAMETER_DATA_H
#define PARAMETER_DATA_H

#include <cstring>
#include <iostream>
#include "utilities.h"
#include "mml_tokens.h"
#include <string>
using namespace std;
/*
Class ParameterData stores data for a single parameter.
[paramname] = [value] [units] 
*/


class	ParameterData
{
public:
	ParameterData() 
	{ 
		setName("");
		setUnits("");
		value = new double(EMPTY_INITIAL_VALUE);
	}		//constructor

	//Set methods
	void	setName(const char * str)	{ strcpy(name,str); }
	void	setUnits(const char * str)	{ strcpy(units,str); }
	void	setValue(double	number)	{
		*value = number; 
	}

	//Get methods
	char*	getName()	{return name;}
	char*	getUnits()	{return units;}
	double*	getValue()	{return value;}

	void	printParameter()
	{
		cout << "Real	" << getName() << " = " << getValue() << " " << getUnits() << endl;
	}

private:
	char	name[20];		//parameter name
	char	units[40];		//parameter units
	double* value;			//value of paramter
};
namespace Physio_MIST{
ref class Managed_ParameterData
{
public:
	Managed_ParameterData(){
		name = gcnew System::String("");
		unit = gcnew System::String("");
		value = gcnew System::Double();
	};
	Managed_ParameterData(ParameterData *parameter)
	{
		name = gcnew System::String(parameter->getName());
		unit = gcnew System::String(parameter->getUnits());
		value = gcnew System::Double(*(parameter->getValue()));

	};

	void set_name(System::String ^_name){name = _name;};
	void set_unit(System::String ^_unit){unit = _unit;};
	void set_value(System::Double ^_value){value = _value;};

protected:
	System::String^ get_name(){return name;};
	System::String^ get_unit(){return unit;};
	System::Double^ get_value(){return value;};

private:
	System::String ^name;
	System::String ^unit;
	System::Double ^value;
};
}
/*
Object to store variable data. 
*/
 class VariableData
{
public:
	//constructor
	//Modified by: E. Zeynep Erson
	//Reason, unless specified a variable shouldn't have an initial value, setting it to 0.0 is not right
	//initial value must be NULL until it is assigned a specific value
	VariableData() {
		setName("");
		setUnits("");
		initialvalue = new double(EMPTY_INITIAL_VALUE);
		} 

	//set methods
	void	setName(const char* str)	{ strcpy(name,str); }
	void	setUnits(const char * str)	{ strcpy(units,str); }
	void	setInitValue(double	number)	{
		*initialvalue = number; 
	}

	//Get methods
	char*	getName()	{return name;}
	char*	getUnits()	{return units;}
	double*	getInitValue()	{return initialvalue;}

	void	printvariable()
	{
		cout << "Real " << getName() << "(t) " << getUnits() << " = " << getInitValue() << endl;
	}

private:
	char name[20];			//Variable name
	char units[40];			//Variable units
	double*	initialvalue;	//Variable's initial value

};



#endif