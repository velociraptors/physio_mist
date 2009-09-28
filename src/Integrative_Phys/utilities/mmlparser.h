/**************************************************************************************************
  mmlparser.cpp
  Definition of MML Parser
  Contributor(s): Robin Hu
				  E. Zeynep Erson
  Created on:     Summer 2007
**************************************************************************************************/

#ifndef	MMLPARSER_H
#define	MMLPARSER_H
#include <iostream>
#include "model.h"
#include <fstream>
#include "UI_Variable.h"




class	MMLParser
{
public:
	MMLParser()	{ strcpy(linebuffer,""); }

	void	openFile(const char *filename);
	void	closeFile();

	//Return a "Model" object with all the parameters, variables and equations filled out.
	//The parser will search the .mml file for the "modelname" and parse only that model.
	//For each model, you must call parse a separate time. Perhaps you could write a script
	/*where if you give it a list of models, it will run parse through the list of models.*/
	Model*	parse(const char *modelname);
	Phys_Container<Model>* parse_models(Phys_Container<char>* model_names);
	void	parseParameters(const char *modelname, Model *model);
	void	parseVariables(const char *modelname, Model *model);
	void	parseInitialValues(const char *modelname, Model *model);
	void	parseEquations(const char *modelname, Model *model);
	char*	parseCondition(char *buffer);
	Phys_Container<std::string> *parseSubModelNames();
		
private:
	ifstream	inputfile;
	//modification by: E. Zeynep Erson
	//reason: when parsing equations, size of the equation may be greater than the LINEBUFFERSIZE
	char	linebuffer[EQUATIONBUFFERSIZE];



	/*Returns the current value of the linebuffer*/
	char*	getLineBuffer()	{ 
		return linebuffer; 
	
	}

	/*Retreives the next line in the file stream.*/
	//MODIFIED: BY Zeynep Erson, to skip the comment blocks
	void	fileGetNextLine()	{	
		if (inputfile.is_open())
		{
			if (!inputfile.eof()){
				inputfile.getline(getLineBuffer(),LINEBUFFERSIZE);
				//skip the comment block
				if(strstr(getLineBuffer(),COMMENT_BLOCK_START)!=NULL){
					while(1){
						inputfile.getline(getLineBuffer(),LINEBUFFERSIZE);
						if(strstr(getLineBuffer(),COMMENT_BLOCK_END)!=NULL){
							inputfile.getline(getLineBuffer(),LINEBUFFERSIZE);
							break;
						}
					}
				}


			}
		}
	}

	/*Retrieves the next equation in the file stream.
	Any equation can span multiple lines, so getting a line is not sufficient. 
	Filestream should be read until a ";" is reached, which indicates the end of equation decleration
	Comments should be ignored: Sometimes comments are added at the end of a line, 
	when the rest of the equation is in the second line.
	*/
	/*ALGORITHM
	1.	get next line 
		ignore the empty lines
	2.	if line containes comment, remove everything from // to \n
	3.	and append the line to the the equation buffer
	4.	if line does not terminate with ;
	5.	loop
	*/

	bool	fileGetNextEquation();
	
	
	/*Moves file pointer until it finds the line that contains the string delim.*/
	void	locateLineThatContains(const char* delim1,
									const char* delim2 = NULL);



	/*Moves file pointer to line that has delim and the model name. This is a special function, that
	tries to locate lines that look like this:
	
	//------------------------
	PARAMETERS OF    S Y S T E M I C    C I R C U L A T I O N
	//------------------------
	
	"delim" would be the word "PARAMETERS" and modelname would be the string "systemic circulation".
	*/
	void	locateLineWithModelName(const char* delim, const char* modelname);

	void	extractParameterData(ParameterData *parameter);
	void	extractVariableData(VariableData *variable);
	void	extractVariableInitialValue(Model *model);
	EquationData*	extractEquationData();


};

class File_Creator{
public:
	File_Creator(char* _dir);
	~File_Creator();

	void createMathModelFiles(Model *model, const char *directory, Phys_Container<char>* fun_names);
	void createHeaderFile();
	void createFactoryClass(Phys_Container<char> *classnames);
	void print_OperatorOperand(EquationData *equation, char *in, int *var_count);

private:
	char *dir;

	ofstream	outCppFile;
	ofstream	outHFile;

};



#endif