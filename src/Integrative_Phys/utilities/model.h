/**************************************************************************************************
  model.h
  Definition of Model
  Contributor(s): Robin Hu
				  E. Zeynep Erson
  Created on:     Summer 2007
  Definition:	  Parsed information from the MML files are wrapped in this structure with 
					Equationdata, VariableData and ParameterData
**************************************************************************************************/

#ifndef	MODEL_H
#define	MODEL_H
#include <iostream>
#include "functions.h"
#include "mmldata.h"
#include "EquationData.h"
#include "utilities.h"

class	Model
{
public:
	Model()	{
		model_name = new char[50];
	}
	Model(char *name)	{
		model_name = name;
	}

	//Insert/ retrieve parameters
	ParameterData*	addParameter(ParameterData *pd) { return parameters.addItem(pd); }
	ParameterData*	getNextParameter()	{
			if (parameters.hasMoreVariables())
				return parameters.getNextItem();
			else
				return NULL;
	}

	//insert/retrieve variables
	VariableData*	addVariable(VariableData *vd) { return variables.addItem(vd); }
	VariableData*	getNextVariable()	{
			if (variables.hasMoreVariables())
				return variables.getNextItem();
			else
				return NULL;
	}

	/*Search the variable list for a certain variable name. */
	VariableData*	findVariable(const char* varname)
	{
		resetVariableIter();
		VariableData*	vd;
		while(vd = getNextVariable() )
		{
			if (strcmp(vd->getName(),varname) == 0)	return vd;
		}

		return NULL;
	}

	/*Equations*/
	EquationData* addEquationData(EquationData *eq){ return equations.addItem(eq);}
	EquationData* getNextEquationData()	{
		if(equations.hasMoreVariables()){
			return equations.getNextItem();
		}
		else {
			return NULL;
		}
	}

	void	resetParameterIter()	{	parameters.reset_iterator(); }
	void	resetVariableIter()		{	variables.reset_iterator(); }
	void	resetEquationIter()		{	equations.reset_iterator(); }
	void	setName(char *_name)	{	
		strcpy(model_name,_name);	
	} 
	char*	getName()				{	return model_name;			}

private:
	Phys_Container<ParameterData>	parameters;	//Model contains a list of parameters
	Phys_Container<VariableData>		variables;	//List of variables
	Phys_Container<EquationData>		equations;	//List of equations
	char						*model_name;//Name of the model parsed

};

#endif