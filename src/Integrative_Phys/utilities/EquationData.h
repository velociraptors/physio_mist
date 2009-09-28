#ifndef EQUATIONDATA_H
#define EQUATIONDATA_H
#include <cstring>
#include <iostream>
#include "utilities.h"
#include "mml_tokens.h"
#include "mmldata.h"
#include <string>

using namespace std;



class EquationData
{
public:
	//constructor
	EquationData() {
		inputs = new Char_Container;
		operands = new Char_Container;
		output = "";
		model_type = 0;
		condition = NULL;
		//rhs = "";
		} ;

	//set methods
	void setRHS(char *_rhs){
		//strcpy(rhs,_rhs);
		rhs  = new char[strlen(_rhs)];
		strcpy(rhs,_rhs);
		//rhs = _rhs;
	};
	void	setInputs(Phys_Container<char> *list)	{ 
		inputs = (Char_Container*)list;
		setOperands();

	};

	void	setOutput(char * str)	{ output  = str; };
	void	setModelType(int number){	model_type = number; };
	
	void setCondition(EquationData	*_cond){
		condition = _cond;
		setOperands();
		
	};

	//Get methods
	char* getRHS(){
		return rhs;
	};
	Phys_Container<char>*	getInputs()	{return inputs;};
	char*	getOutput()	{return output;};
	int	getModelType()	{return model_type;};
	EquationData* getCondition(){return condition;};


	void	printequation()
	{
		cout<<getOutput();
		while(getInputs()->hasMoreVariables()){
			cout<<getInputs()->getNextItem();
		}
		cout << ";"<< endl;
	};

	Char_Container* getOperands(){
		return operands;
	}

private:
	void setOperands(){
		operands->clear();
		Phys_Container<char>* all_inputs = new Phys_Container<char>;
		if(getCondition()!=NULL)
		{
			all_inputs->addList(getCondition()->getInputs());
			getCondition()->getInputs()->reset_iterator();
		}
		all_inputs->addList(getInputs());
		getInputs()->reset_iterator();
		while(all_inputs->hasMoreVariables()){
			char *input = all_inputs->getNextItem();
			//SPECIAL CASE: FOR MEMORY VARIABLES
			if(strpbrk(input,"[]")!=NULL){
				operands->addItem(input);
			}
			//check if the input is an operand or operator, if it is an operand put it to the proper list
			if( strpbrk (input, OPERATORS)==NULL && 
				strcmp(input,EXPONENT)!=0	&&
				strcmp(input,SQUARE_RT)!=0	&&
				strcmp(input,ABS)!=0		&& 
				strcmp(input,LN)!=0			&&
				strcmp(input,COS)!=0		&&
				strcmp(input,SIN)!=0		&&
				strcmp(input,POW)!=0		&&
				strcmp(input,COMMA)!=0		&&
				strcmp(input,LOG10)!=0		&&
				strcmp(input,IF)!=0			&&
				strcmp(input,ELSEIF)!=0		&&
				strcmp(input,ELSE)!=0		&&
				strcmp(input,PI)!=0){
					//TODO: also remove the unnecessary empty characters
					operands->addItem(input);			
			}
		}	
	};

	Char_Container *inputs;	//Parameters IN THE ORDER OF APPEARANCE on the right hand side of equation
	char *output;				//Name of the variable that is on the left hand side of the equation
	int model_type;				//Continous time model, discrete time model, discrete event model
	Char_Container	*operands;	//A seperate list of operands extracted from the input list
	EquationData *condition;			//Condition for the discrete event models or conditional models
	char *rhs;

};



class EquationParser{
public:
	

	EquationParser(){
		lhs = "";
		rhs = "";
	};
	
	EquationData* parseCondition(char* equation){
		EquationData *conditionData = new EquationData;
		char* parsed_equation = removeSpace(equation);
		
		int type = analyzeLHS();
		Phys_Container<char>* inputs = new Phys_Container<char>;
		
		inputs->addList(tokenizeEquation(parsed_equation));
		
		//FOR POWER OPERATION
		conditionData->setInputs(inputs);
		conditionData->getInputs()->reset_iterator();
		
		return conditionData;

	};
	EquationData* parse(char* equation){
		EquationData *equationData = new EquationData;
		parseEquation(equation);
		
		int type = analyzeLHS();
		equationData->setOutput(lhs);
		equationData->setModelType(type);
		
		cout<<"LHS is"<<lhs<<endl;
		cout<<"RHS is"<<rhs<<endl;
		cout<<"model type is";

		if(equationData->getModelType() == Continous){
			cout<<"CONTINOUS"<<endl;
		}
		else{
			cout<<"DISCRETE"<<endl;
		}
		equationData->setRHS(rhs);
		equationData->setInputs(tokenizeEquation(rhs));
		//todo: remove this temporary solution, 
		//temporary solution: to correct some of the representations
		//1. replace * with pow
		equationData->setInputs(postProcess(equationData->getInputs()));
		equationData->getInputs()->reset_iterator();
		
		return equationData;



	};


		
	Phys_Container<char>* postProcess(Phys_Container<char> *inputs){
		Phys_Container<char>* processed_inputs = new Phys_Container<char>;

		Phys_Container<char>* temp_inputs = inputs;
		if(temp_inputs->contains("^")){
			int index = temp_inputs->getIndexOf("^");
			Phys_Container<char> left = temp_inputs->getSublist(0,index-1);
			Phys_Container<char>* temp_left = new Phys_Container<char>;
			char *item = left.popLastItem();
			int count_l = 0;
			//if item before ^ is )
			//then go back and keep track of matching parantheses and find the parathneses matching the first )
			//copy the prior element to the final container
			//insert pow
			//insert(
			//insert the rest of the list
			//add ) at the end of the list
			//insert , at the location of ^
			if(strcmp(item,")")==0){
				temp_left->add_front(item);
				int par_count = 1;
				while(par_count!=0){
					count_l++;
					char *next_item = left.popLastItem();
					temp_left->add_front(next_item);
					if(strcmp(next_item,"(")==0){
						par_count--;
					}
					else if(strcmp(next_item,")")==0){
						par_count++;
					}
				}
					temp_left->add_front("(");
					temp_left->add_front("pow");
					while(left.size()>0){
						temp_left->add_front(left.popLastItem());
					}
				
			}
			else{
				temp_left->addList(&left);
				temp_left->addItem("pow");
				temp_left->addItem("(");
				temp_left->addItem(item);
			}			

			//for right
			Phys_Container<char> *right = new Phys_Container<char>;
			right->addList(temp_inputs->getSublist(index+1,temp_inputs->size()-1));
			char *item_r = right->getItemAt(0);
			//if item after ^ is (
			//itereate and keep track of matching parantheses and find the parathneses matching the first (
			//insert )
			//copy the rest elements to the final container
			int count_r = 0;
			if(strcmp(item_r,"-")==0){
				count_r++;
			}
			if(strcmp(item_r,"(")==0){
				int par_count_r = 1;
				while(par_count_r!=0){
					count_r++;
					char *next_item = right->getNextItem();
					if(strcmp(next_item,"(")==0){
						par_count_r++;
					}
					else if(strcmp(next_item,")")==0){
						par_count_r--;
					}
				}
			}
			Phys_Container<char> *temp_right = new Phys_Container<char>;
			temp_right->addList(right->getSublist(0,count_r));
				
			temp_right->addItem(")");
			Phys_Container<char>* _proc_right = right->getSublist(count_r+1,right->size()-1);
			Phys_Container<char> *processed_right = new Phys_Container<char>;
			if(_proc_right!=NULL){
				processed_right = postProcess(_proc_right);
			}
			
			temp_right->addList(processed_right);

			temp_left->reset_iterator();
			temp_right->reset_iterator();
			processed_inputs->addList(temp_left);
			processed_inputs->addItem(",");
			processed_inputs->addList(temp_right);
		}
		else{	
			processed_inputs = inputs;
		}
		return processed_inputs;

	};



/*
0. Remove all spcace characters from the equation
1. Tokenize the string with the delimeter = as "left hand side" and "right hand side" of the equation.
2. All equations terminate with ";", eliminate that token from RHS
*/
	void parseEquation(char* _eqn){
		
		char* cleared_sqn = removeSpace(_eqn);
		lhs = strtok(cleared_sqn,EQUAL_SIGN);
		rhs = strtok(NULL,TERMINATION_CHAR);
				
	};

	char* removeSpace(char* _buffer){

		char *pch;
		char *eqn = new char[strlen(_buffer)];
		eqn[0] = '\0';
		    
		pch = strtok (_buffer,SPACE_CHARS);
		  while (pch != NULL)
		  {
			  strcat(eqn,pch);
			  pch = strtok (NULL, SPACE_CHARS);
		  }

		  return eqn;
		

	};


/*
1. find the string before =
2. check to see if it has : in the string
	2.1 if so, everything before : is the variable name and make mark to indicate it is a continous time model
	2.2 if not, whole thing is the varianle name and and make mark to indicate it is a discrete time model
*/

	int analyzeLHS(){
		char *delim;
		delim = strchr(lhs,':');
		if(delim == NULL){
			return Discrete_time;
		}
		else{
			lhs = strtok(lhs,":");
			return Continous;
		}
	};
	
	/*
	Tokenize the rhs using the operators as tokens
	*/	
	Phys_Container<char> *tokenizeEquation(char* _buffer){

		//get the first token before the operators
		//get the operator
		//copy the rest of the characters
		
		//perform the above operations until there is nothing to tokenize
		Phys_Container<char> *inputs = new Phys_Container<char>;


		while(1){
			int opt_index;
			
			char *operand = new char[100];
			char *cond = new char[7];
			char *opt = new char[2];
			char *temp = new char[128];
			char *temp_operand = new char[50];

			//Get span until the first operator character in string
			//add the operand to input list
			opt_index = strcspn (_buffer,OPERATORS);
			if(opt_index>0){								

				//state variable is scanned
				//if the operator is "["
				//treat everyting as an operand until "]"
				if(_buffer[opt_index]=='['){					
					
					opt_index = strcspn(_buffer,"]");
					//include the  "]" to the operand part
					strncpy(operand,_buffer,opt_index+1);
					operand[opt_index+1] = '\0';

					//update the buffer
					if(strlen(_buffer)-(opt_index+1)>0 ){
						memmove(temp,&(_buffer[opt_index+1]),strlen(_buffer)-(opt_index));
						memmove(_buffer,temp,strlen(temp));
						_buffer[strlen(temp)] = '\0';
						opt_index = strcspn (_buffer,OPERATORS);					
					
					}
					else{
						inputs->addItem(operand);
						break;
					}

				}

				//no state variable is scanned
				else{
					strncpy (operand,_buffer,opt_index);
					operand[opt_index]='\0';
				}

				//TODO: GIVE DETAILS
				//IF THE OPERAND STRING CONTAINS AN OPERAND AND ANOTHER TOKEN LIKE, ELSEIF, ELSE, SEPERATE THEM.
				//BECAUSE WHEN THE EQUATION IS PARSED; ELSEIF STATEMENT IS APPENDED TO THE END OF IF STATEMENT.
				if((cond = strstr(operand,ELSEIF))!=NULL){
					memcpy(temp_operand,operand,strlen(operand)-strlen(cond));										
					temp_operand[strlen(operand)-strlen(cond)] = '\0';
					inputs->addItem(temp_operand);
					inputs->addItem(cond);

				}
				else if((cond = strstr(operand,ELSE))!=NULL){
					if(strlen(operand)-strlen(cond)>0){
						memcpy(temp_operand,operand,strlen(operand)-strlen(cond));										
						temp_operand[strlen(operand)-strlen(cond)] = '\0';
						inputs->addItem(temp_operand);
					}
					//means that there is an operand right after ELSE instead of an operator
					if(strlen(cond)>strlen(ELSE)){
						char *tt = new char[strlen(ELSE)];
						memcpy(tt,cond,strlen(ELSE));
						tt[strlen(ELSE)] = '\0';
						char *op2 = new char[100];
						int size = strlen(cond);
						cond++;
						cond++;
						cond++;
						cond++;
						memcpy(op2,cond,size-strlen(ELSE));
						op2[size-strlen(ELSE)] = '\0';
						inputs->addItem(tt);
						inputs->addItem(op2);

					}
					else{
						inputs->addItem(cond);
					}					
				}
				//there is no else or else if
				else{
					inputs->addItem(operand);
				}
				
			}

			//add the operator and update the buffer
			if(opt_index>=0 && opt_index<strlen(_buffer)){
				opt[0] = _buffer[opt_index];
				opt[1] = '\0';
				inputs->addItem(opt);
				int x = strlen(_buffer);
				if(strlen(_buffer)-(opt_index+1)>0 ){
					memmove(temp,&(_buffer[opt_index+1]),strlen(_buffer)-(opt_index));
					memmove(_buffer,temp,strlen(temp));
					_buffer[strlen(temp)] = '\0';
				}
				else{
					break;
				}
				
			}
			else{
				break;
			}


		}
		return inputs;

	};

private:
	char *lhs;
	char *rhs;
};

#endif
