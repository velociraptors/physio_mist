#include "mmlparser.h"


File_Creator::File_Creator(char *_dir){
	dir = _dir;
}

File_Creator::~File_Creator(){

}

void File_Creator::createMathModelFiles(Model *model, const char *directory, Phys_Container<char>* fun_names) {


	char fileName[MAX_PATH_LEN] = "";
	char cppFileName[MAX_PATH_LEN] = "";
	


		
		/*Get class name and it's parent's name.*/
		
		char *modelName =  strcat(model->getName(),"_Math_Model");
		

		strncpy(fileName,directory,MAX_PATH_LEN);
		strncat(fileName,"\\",MAX_PATH_LEN);
		strncat(fileName,modelName,MAX_PATH_LEN);
		strncpy(cppFileName,fileName,MAX_PATH_LEN);
		strncat(cppFileName,".cpp",MAX_PATH_LEN);		//
		

		outCppFile.open (cppFileName);//opens the .cpp file
		
		outHFile<<"#include \""<<modelName<<".cpp"<<"\""<<endl;
		


		
		
		/*Preprocessor. Headers, comments and macros.*/

		outCppFile << "//////////////////////////////////////////////////////" << endl;
		outCppFile << "// Implementation of " << modelName << endl;
		outCppFile << "//////////////////////////////////////////////////////" << endl;
		//outCppFile << "#include \"" << "#include \"Computational_layer.h\"" << endl;
		outCppFile << "#include <math.h>" << endl;		
		outCppFile << "#include \"utilities.h\" " << endl;		
		outCppFile<<"#define PI 3.14159265"<<endl;


		//outCppFile <<"namespace computational_layer{"<<endl;

		/*start implemention of the mathematical models for each equation*/
		EquationData *equation;
		Phys_Container<char> *classnames = new Phys_Container<char>;
		while((equation = (model->getNextEquationData()))!=NULL){			
			char *className = equation->getOutput();
			classnames->addItem(className);
			char *in;
		
			if(equation->getModelType()==Discrete_time)
			{
				//implement this
				
				outCppFile <<"static double math_model_"<<className<<"(double variable, Phys_Container<double> in_list){"<<endl;
				outCppFile<<"double result=variable;"<<endl;
			}

			else if(equation->getModelType()==Continous){
				outCppFile <<"static double math_model_"<<className<<"(double variable,Phys_Container<double> in_list){"<<endl;
				outCppFile<<"double result = variable;"<<endl;

			}
				
			//if the condition is not null, add the "if" condition			
			//for discrete event models with event = {}
			if(equation->getCondition()!=NULL){				
				equation->getCondition()->getInputs()->reset_iterator();
				outCppFile<<"\t if(";
				while(equation->getCondition()->getInputs()->hasMoreVariables()){					
					in = equation->getCondition()->getInputs()->getNextItem();						
					//if operator, just print it						 
					print_OperatorOperand(equation,in,new int(0));
				}
				outCppFile<<"){"<<endl;
				outCppFile<<"\t ";
				
			}
				
			in = equation->getInputs()->getNextItem();

			//IF THERE IS AN IF-ELSE CONDITION
			if(strcmp(in,IF)==0){
				//print if
				outCppFile<<in<<" ";					
				int count = 0;
				in = equation->getInputs()->getNextItem();
				
				//if operator, just print it
				print_OperatorOperand (equation,in,new int(0));
				if(strcmp(in,"(")==0){
					count++;
				}

				//print until the matching paranthesis end
				while(count>0 && equation->getInputs()->hasMoreVariables()){														
					in = equation->getInputs()->getNextItem();
					
					//if operator, just print it
					if((!equation->getOperands()->contains(in) || isConstant(in)) && (strchr(in,'[')==NULL)){
						if(strcmp(in,LN)==0){
							outCppFile<<"log";
						}
						else if(strcmp(in,LOG10)==0){
							outCppFile<<"log10";
						}							
						else{
							outCppFile<<in;
						}
						if(strcmp(in,"&")==0){								
							outCppFile<<"&";	
						}
						if(strcmp(in,"(")==0){
							count++;
						}
						else if(strcmp(in,")")==0)
						{
							count--;
						}
					}
					else{
						outCppFile<<"(*(in_list.getNextItem()))";
					}
				}
				//print the event if the IF is TRUE
				//print {
				outCppFile<<"{"<<endl;
				//print result = 
				outCppFile<<"result = ";
				//print everyting until else
				int *variable_count = new int(0);
				for(in = equation->getInputs()->getNextItem();
					strstr(in,ELSE)==NULL && equation->getInputs()->hasMoreVariables();
					in =equation->getInputs()->getNextItem())				
				{													
					
					//if operator, just print it
					print_OperatorOperand (equation,in, variable_count);
				}
				outCppFile<<";"<<endl;
				outCppFile<<"return result;"<<endl;
				//print }
				outCppFile<<"}"<<endl;


				//print else if
				if(strcmp(in,ELSEIF)==0){

					//first get rid of the variables that are not poped from the list, since the if condition is not satisfied!
					outCppFile<<"for(int i =0;i<"<<*(variable_count)<<";i++){"<<endl;
					outCppFile<<"in_list.getNextItem();"<<endl;
					outCppFile<<"}"<<endl;

					*variable_count = 0;

					outCppFile<<"if";
					int count = 0;
					in = equation->getInputs()->getNextItem();
					//if operator, just print it
					print_OperatorOperand(equation,in,variable_count);

					if(strcmp(in,"(")==0){
						count++;
					}
					//print the condition with the matching paranthesis
					while(count>0 && equation->getInputs()->hasMoreVariables()){														
						in = equation->getInputs()->getNextItem();
						//if operator, just print it
						if((!equation->getOperands()->contains(in) || isConstant(in)) && (strchr(in,'[')==NULL)){
							if(strcmp(in,LN)==0){								
								outCppFile<<"log";							
							}
							else if(strcmp(in,LOG10)==0){
								outCppFile<<"log10";
							}
							else{
								outCppFile<<in;
							}
							if(strcmp(in,"&")==0){								
								outCppFile<<"&";	
							}
							if(strcmp(in,"(")==0){
								count++;
							}
							else if(strcmp(in,")")==0)
							{
								count--;
							}
						}
						else{
							outCppFile<<"(*(in_list.getNextItem()))";
						}
					}
					//print {
					outCppFile<<"{"<<endl;
					

					//print result = 
					outCppFile<<"result = ";

					*variable_count = 0;
					//print everything until else
					for(in = equation->getInputs()->getNextItem();
						strstr(in,ELSE)==NULL && equation->getInputs()->hasMoreVariables();
						in =equation->getInputs()->getNextItem())
					{														
						
						//if operator, just print it
						print_OperatorOperand(equation,in,variable_count);	
					}

					outCppFile<<";"<<endl;
					outCppFile<<"return result;"<<endl;

					//print }
					outCppFile<<"}"<<endl;
				}
				
				if(strcmp(in,ELSE)==0){					
					//first get rid of the variables that are not poped from the list, since the if condition is not satisfied!
					outCppFile<<"for(int i =0;i<"<<*(variable_count)<<";i++){"<<endl;
					outCppFile<<"in_list.getNextItem();"<<endl;
					outCppFile<<"}"<<endl;												
					
					//print result =
					outCppFile<<"result = ";
					//print everything
					while(equation->getInputs()->hasMoreVariables()){

						in = equation->getInputs()->getNextItem();
						//if operator, just print it
						print_OperatorOperand(equation, in, new int(0));
					}

					outCppFile<<";"<<endl;
				}

			}

				//THERE IS NO IF-ELSE CONDITION
				else{
					outCppFile<<"result = ";

					//if operator, just print it
					print_OperatorOperand(equation, in,new int(0));
					while(equation->getInputs()->hasMoreVariables()){
						 in = equation->getInputs()->getNextItem();
						//if operator, just print it
						 print_OperatorOperand(equation,in,new int(0));
					}

					outCppFile<<";"<<endl;
				}
				
				
				//if the condition for the event is not null, add the "if" condition
				if(equation->getCondition()!=NULL){
					outCppFile<<"}"<<endl;
				}
				outCppFile<<"return result;"<<endl;
				outCppFile<<"};"<<endl;			
		}

		classnames->reset_iterator();
		fun_names->addList(classnames);
		
		outCppFile.close();
		

	cout << "Finished creating c++ files from the .mml file" << endl;


}

/*create the header file*/
void File_Creator::createHeaderFile()
{
	char fileName[MAX_PATH_LEN] = "";
	char hFileName[MAX_PATH_LEN] = "";


	char  *mml_models = "mml_models";
	
	//strcat(hFileName,".h");


	strncpy(fileName,dir,MAX_PATH_LEN);
	strncat(fileName,"\\",MAX_PATH_LEN);
	strncat(fileName,mml_models,MAX_PATH_LEN);
	strncpy(hFileName,fileName,MAX_PATH_LEN);
	strncat(hFileName,".h",MAX_PATH_LEN);		//

	
	outHFile.open(hFileName);
	outHFile<<"#ifndef _MML_MODELS_H"<<endl;
	outHFile<<"#define _MML_MODELS_H"<<endl;
	

}

void File_Creator::print_OperatorOperand(EquationData *equation, char *in, int *operand_count){
	
	if((!equation->getOperands()->contains(in) || isConstant(in)) && (strchr(in,'[')==NULL)){
		if(strcmp(in,LN)==0){
			outCppFile<<"log";
		}
		else if(strcmp(in,LOG10)==0){
			outCppFile<<"log10";
		}
		else if(strcmp(in,"&")==0){
			outCppFile<<"&&";
		}
		else{
			outCppFile<<in;
		}
	}
	else{
		(*operand_count)++;
		outCppFile<<"(*(in_list.getNextItem()))";
	}
}
void File_Creator::createFactoryClass(Phys_Container<char> *classnames){
		//generate the factory class for each name of the equation:
		outHFile <<"class function_factory"<<"{"<<endl;
		outHFile <<"public: "<<endl;
		
		outHFile<<"double (*getFunction(char *fun_name))(double variable, Phys_Container<double> in_list){"<<endl;
		classnames->reset_iterator();
		while(classnames->hasMoreVariables()){
			char *name = classnames->getNextItem(); 
			outHFile<<"\t if(strcmp(fun_name,\""<<name<<"\") == 0){"<<endl;
			outHFile<<"\t\t return &math_model_"<<name<<";"<<endl;
			outHFile<<"\t }"<<endl;
		}
		outHFile<<"};"<<endl;
		outHFile<<"};"<<endl;

		outHFile<<"#endif"<<endl;
		outHFile.close();
}