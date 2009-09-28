/**************************************************************************************************
  mmlparser.cpp
  Implementation of MML Parser
  Contributor(s): Robin Hu
				  E. Zeynep Erson
  Created on:     December 2007
  Description:    MML file is composed of parameters, variables and equations. These units are parsed to map
					them to the software units.
				  Stores the parsed information in ParameterData, VariableData and EquationData
**************************************************************************************************/
#include "mmlparser.h"
#include <string.h>


void	MMLParser::openFile(const char *fileName)
{
	bool test = false;
	if (!inputfile.is_open()){
		inputfile.open(fileName);

		test = inputfile.is_open();
			
	}
}

void MMLParser::closeFile()
{
	if (inputfile.is_open ()) inputfile.close();
}
Phys_Container<std::string> * MMLParser::parseSubModelNames(){
	return NULL;
}
void MMLParser::parseParameters(const char *modelname, Model *modeldata){
	/*Begin parsing parameter data*/
	locateLineWithModelName("PARAMETERS",modelname);
	
	fileGetNextLine();	//skip the next line, which is just a comment.
	while(true)
	{
		fileGetNextLine();	//move to next line.
		if (strstr(getLineBuffer(),EQUAL_SIGN))	//If a line contains an "=" sign, it must be a parameter declaration.
		{
			//Begin gathering parameter data, like parameter name, value and units.
			ParameterData * parameterdata = new ParameterData();
			extractParameterData(parameterdata);
			modeldata->addParameter (parameterdata);	//save parameter data after it's been extracted.
		}

		if ( strstr(getLineBuffer(),SECTION_HEADER))	break;	//if we reach a newline that contains a "//-----", stop parsing.
	}
}

void MMLParser::parseVariables(const char *modelname, Model *modeldata){
		
	/*Begin parsing variable data*/
	locateLineWithModelName("VARIABLES",modelname);

	fileGetNextLine();
	while(true)
	{
		fileGetNextLine();
		if (strstr(getLineBuffer(),"(t)"))
		{
			/*A line with "(t)" means it has variable definitions*/
			VariableData * variabledata = new VariableData();
			extractVariableData(variabledata);
			modeldata->addVariable (variabledata);
		}
		
		
		//found initial values section or another section header
		if ( strstr(getLineBuffer(),"t.min")){
			parseInitialValues(modelname, modeldata);
		}
		if( strstr(getLineBuffer(),SECTION_HEADER)){
			break;	
		}
	}
}

void MMLParser::parseInitialValues(const char *modelname, Model *modeldata){
	//begin parsing initial values
	
	while(true)
	{
		fileGetNextLine();
		if (strstr(getLineBuffer(),EQUAL_SIGN))
		{
			extractVariableInitialValue(modeldata);
		}

		if(strstr(getLineBuffer(),"}")!=NULL){
			break;
		}
	}
}


void MMLParser::parseEquations(const char *modelname, Model *modeldata){
		
	/*begin parsin equations*/
	locateLineWithModelName("EQUATIONS",modelname);

	//todo:these line skips should not be made, it should detect empty lines and skip if necessesary
	//gets the end of the section
	fileGetNextLine();
	//gets the empty line after the section
	fileGetNextLine();


	EquationParser *parser = new EquationParser;
	while(fileGetNextEquation())
	{
		
		//LINE SHOULD NOT START WITH "//" 
		if (strstr(getLineBuffer(),"event")==NULL)
		{
			if( strcmp(getLineBuffer(),"")!=0){
			EquationData *equationdata = extractEquationData();
			modeldata->addEquationData(equationdata);
			}
		}

		else{
			//get the condition
			char *condition = parseCondition(getLineBuffer());
			EquationData *conditiondata = parser->parseCondition(condition);

			for(fileGetNextLine();strcmp(getLineBuffer(),"}")!=0;fileGetNextLine()){
				//get the next equation upto the end of event
				//add the condition to the equation for each of the equation
				EquationData *con_eq  = extractEquationData();
				con_eq->setCondition(conditiondata);
				modeldata->addEquationData(con_eq);
			}

		}
	}

}
/*Parse the MML file for the model specified by modelname. This function only parses one model at a time.*/
Model* MMLParser::parse(const char *modelname)
{
	/*Create a Model data structure to store model information: parameters, variables, equations.*/
	Model*	modeldata = new Model();
	
	
	/*Begin parsing parameter data*/
	locateLineWithModelName("PARAMETERS",modelname);
	
	fileGetNextLine();	//skip the next line, which is just a comment.
	while(true)
	{
		fileGetNextLine();	//move to next line.
		if (strstr(getLineBuffer(),EQUAL_SIGN))	//If a line contains an "=" sign, it must be a parameter declaration.
		{
			//Begin gathering parameter data, like parameter name, value and units.
			ParameterData * parameterdata = new ParameterData();
			extractParameterData(parameterdata);
			modeldata->addParameter (parameterdata);	//save parameter data after it's been extracted.
		}

		if ( strstr(getLineBuffer(),SECTION_HEADER))	break;	//if we reach a newline that contains a "//-----", stop parsing.
	}

	/*Begin parsing variable data*/
	locateLineWithModelName("VARIABLES",modelname);

	fileGetNextLine();
	while(true)
	{
		fileGetNextLine();
		if (strstr(getLineBuffer(),"(t)"))
		{
			/*A line with "(t)" means it has variable definitions*/
			VariableData * variabledata = new VariableData();
			extractVariableData(variabledata);
			modeldata->addVariable (variabledata);
		}
		
		if ( strstr(getLineBuffer(),"t.min"))	break;	//found initial values section
	}

	//begin parsing initial values
	
	while(true)
	{
		fileGetNextLine();
		if (strstr(getLineBuffer(),EQUAL_SIGN))
		{
			extractVariableInitialValue(modeldata);
		}

		if (strstr(getLineBuffer(),SECTION_HEADER)) break;
	}
	
	/*begin parsin equations*/
	locateLineWithModelName("EQUATIONS",modelname);

	//gets the end of the section
	fileGetNextLine();
	//gets the empty line after the section
	fileGetNextLine();


	EquationParser *parser = new EquationParser;
	while(fileGetNextEquation())
	{
				

		//LINE SHOULD NOT START WITH // OR event
		//TODO: WILL BE UPDATED TO HANDLE DISCRETE EVENTS
		if (strstr(getLineBuffer(),"event")==NULL)
		{
			if( strcmp(getLineBuffer(),"")!=0){
			EquationData *equationdata = new EquationData;
			equationdata = extractEquationData();
			modeldata->addEquationData(equationdata);
			}
		}
		
	}


	return modeldata;	//return our model.
}

Phys_Container<Model>* MMLParser::parse_models(Phys_Container<char>* modelName){
		
	/*CREATE MODELS*/
	Phys_Container<Model> *mml_models = new Phys_Container<Model>;
	while(modelName->hasMoreVariables()){
		mml_models->addItem(new Model(modelName->getNextItem()));
	}

	/*
	NOTE TO SELF: Since we read the file sequentially, we parse first parameters, then variables and then equations.
	Later if we modify the way we read the file, we can just parse the file based on the models.
	*/	
	
	/*PARSE PARAMETERS*/
	
	mml_models->reset_iterator();
	Model *model;
	
	while(mml_models->hasMoreVariables()){
		model = mml_models->getNextItem();
		//SendMessage(progress_bar,PBM_STEPIT,0,0);
		parseParameters(model->getName(),model);
	}

	/*PARSE VARIABLES*/
	mml_models->reset_iterator();		
	while(mml_models->hasMoreVariables()){
		model = mml_models->getNextItem();
		//SendMessage(progress_bar,PBM_STEPIT,0,0);
		parseVariables(model->getName(), model);
	}


	/*PARSE EQUATIONS*/
	mml_models->reset_iterator();
	while(mml_models->hasMoreVariables()){
		model = mml_models->getNextItem();
		//SendMessage(progress_bar,PBM_STEPIT,0,0);
		parseEquations(model->getName(), model);
	}
	return mml_models;

}
void MMLParser::locateLineWithModelName (const char* delim, const char* modelname)
{
	char *pch;
	char *modelname_tmp = new char[strlen(modelname)];
	strcpy(modelname_tmp,modelname);	//create copy of modelname
	pch = strtok(modelname_tmp," ");	//tokenize modelname_tmp, with " " as delim
	while(pch != NULL)
	{
		char*	modelstr = convertToUpper(insertSpaces(pch));
		//Move to line that contains the word "PARAMETERS" and the model name.
		locateLineThatContains(delim,modelstr);	
		
		pch = strtok(NULL," ");
	}
}

/*Moves file pointer until it finds the line that contains the string delim1 and delim2.*/
void	MMLParser::locateLineThatContains(const char *delim1, const char *delim2) 
{
	if (delim1 == NULL)	return;

	while(true)
	{
		//If the current line already contains the delimiters, don't do anything, just break the loop.
		if (delim2 != NULL)
		{
			if (strstr(getLineBuffer(),delim1) && strstr(getLineBuffer(),delim2)){
				break;
			}
		}
		else
		{
			if (strstr(getLineBuffer(),delim1)){	
				break;
			}

		}
		
		fileGetNextLine();
	}
}

/*Retrieves the next equation in the file stream.
Any equation can span multiple lines, so getting a line is not sufficient. 
Filestream should be read until a ";" is reached, which indicates the end of equation decleration
Comments should be ignored: Sometimes comments are added at the end of a line, 
when the rest of the equation is in the second line.
*/
/*ALGORITHM
0. loop
1.	get next line 
2.  if the next line starts a block comment with "/*", ignore everything until the end of block
2.	if the next line is a new section, break the loop and return false
3.	ignore the empty lines
4.	if line contains comment, remove everything from '//' to '\n'
5.	and append the line to the the equation buffer
6.	break the loop if the termination char ';' is reached
7.  return true;
*/

bool MMLParser::fileGetNextEquation() {

	
	char equation[EQUATIONBUFFERSIZE];
	char temp_equation[EQUATIONBUFFERSIZE];
	
	char *pch;
	equation[0] = NULL;
	if (inputfile.is_open())
	{		
		
		if(inputfile.eof()){
			return false;
		}
		//read until end of file or another section is reached!
		while(!inputfile.eof()){
			inputfile.getline(temp_equation,EQUATIONBUFFERSIZE);
			if(strstr(temp_equation,SECTION_HEADER)!=NULL || strcmp(temp_equation,"}")==0){
				memcpy(linebuffer,equation,EQUATIONBUFFERSIZE);
				return false;
			}

			//skip the comment block
			if(strstr(temp_equation,COMMENT_BLOCK_START)!=NULL){
				while(1){
					inputfile.getline(temp_equation,EQUATIONBUFFERSIZE);
					if(strstr(temp_equation,COMMENT_BLOCK_END)!=NULL){
						inputfile.getline(temp_equation,EQUATIONBUFFERSIZE);
						break;
					}
				}
			}

			if(strcmp(temp_equation,"")!=0){
				pch = strstr(temp_equation,COMMENT_CHARS);
				if(pch!=NULL){
					temp_equation[strlen(temp_equation)-strlen(pch)] = NULL;
				}

				strcat(equation,temp_equation);

				if(strpbrk (equation, TERMINATION_CHAR)!=NULL || strstr(equation,"event")!=NULL){
					break;
				}
			}			
		}

		if(strcmp(equation,"")!=0){
			memcpy(linebuffer,equation,EQUATIONBUFFERSIZE);
		}
		else{
			return false;
		}
		
	}	
	return true;

}

/*
Parses the condition for the discrete event models or the conditional events
Algorithm:
1.	get everyting between the first occurance of "(" and last occurance of ")"
2.	return the char array
*/
char* MMLParser::parseCondition(char *buffer){

	char * last;
	char * first;

	first = strstr(buffer,"(");
	last=strrchr(buffer,')');
	int size = strlen(first)-strlen(last)+1;
	char *condition = new char[size];
	strncpy (condition,first,size);
	condition[size] = '\0';
	
 return condition;
}



/*Looks at current line and extracts parameter data from that line.*/
void	MMLParser::extractParameterData(ParameterData *parameter) 
{


	char *delims = " =,;\t";
	char *pch;
	char *linebuffer_tmp = new char[strlen(getLineBuffer())];
	strcpy(linebuffer_tmp,getLineBuffer());

	pch = strtok(linebuffer_tmp,delims);	//tokenizes the line

	if ( strcmp(pch,"real") == 0 )	pch = strtok(NULL,delims); //if first token is the word "real", skip it.

	UI_Variable ^param = gcnew UI_Variable();
	
	parameter->setName(pch);	//gets name
	double value =atof(strtok(NULL,delims));
	parameter->setValue(value); //initial value
	parameter->setUnits (strtok(NULL,delims));	//units*/
	


}

void	MMLParser::extractVariableData(VariableData *variable) 
{
	char *delims = " ;\t";
	char *pch; 
	char *linebuffer_tmp = new char[strlen(getLineBuffer())];
	strcpy(linebuffer_tmp,getLineBuffer());

	pch = strtok(linebuffer_tmp,delims);	//tokenizes the line

	if ( strcmp(pch,"real") == 0 || strcmp(pch,"realState")==0)	pch = strtok(NULL,delims); //if first token is the word "real", skip it.

	//pch should have the variable name now.
	//But we don't want the three characters "(t)" at the end.
	int	nullescapeloc = strlen(pch) - 3;
	pch[nullescapeloc] = '\0';
	variable->setName(pch);
	variable->setUnits(strtok(NULL,delims));
}

void	MMLParser::extractVariableInitialValue(Model *model)
{
	char *delims = " =;\t";
	char *pch = new char[LINEBUFFERSIZE];
	char *linebuffer_tmp = new char[strlen(getLineBuffer())];
	strcpy(linebuffer_tmp,getLineBuffer());

	strcpy(pch,strtok(linebuffer_tmp,delims));	//tokenizes the line


	VariableData *vd = model->findVariable (pch); //find the variable with the given name.

	strcpy(pch,strtok(NULL,delims));	//get floating pt initial value

	if (vd != NULL)	vd->setInitValue(atof(pch)); //set initial value

}

EquationData* MMLParser::extractEquationData(){
	
	int size = strlen(getLineBuffer());
	char *linebuffer_tmp = new char[size];
	strcpy(linebuffer_tmp,getLineBuffer());
	EquationParser *parser = new EquationParser;
	return parser->parse(linebuffer_tmp);
}


