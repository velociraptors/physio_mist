#include <iostream>
#include "mmlparser.h"


using namespace std;

static void simulink_model();
static void mml_model();
static void intrinsic_model();
static void iv_model();
static void iv_heart_model();
static void meal_model();
static void  parse_model(char *path, char*  model_name);

int main()
{
	cout << "Testing..." << endl;
	


	//mml_model();
	meal_model();
	//intrinsic_model();
	//parse_model("C:\\Pulsatile_insulin.txt", "pulsatile insulin model");
	//parse_model("C:\\baroreceptor_model.txt", "baroreceptor model");
	
	//simulink_model();
	//iv_model();
	//iv_heart_model();



	cin.get();
	double y =  3 ^ 2;
	return 0;
}

static void parse_model(char *path, char*  model_name){
	MMLParser	mp;
	mp.openFile (path);


	Model*	model = new Model();
	mp.parseEquations (model_name, model );

	mp.closeFile();
	model ->setName(model_name);

	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(model,dir, classnames);

	file_creator.createFactoryClass(classnames);
	
}
static void iv_heart_model(){
	MMLParser	mp;
	mp.openFile ("C:\\iv_injection_heart_model.txt");


	Model*	iv_model = new Model();
	mp.parseEquations ("iv model", iv_model );

	mp.closeFile();
	iv_model ->setName("iv_injection_heart");

	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(iv_model,dir, classnames);

	file_creator.createFactoryClass(classnames);
}
static void iv_model (){
	MMLParser	mp;
	mp.openFile ("C:\\iv_model.txt");


	Model*	iv_model = new Model();
	mp.parseEquations ("iv model", iv_model );

	mp.closeFile();
	iv_model ->setName("iv_model");

	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(iv_model,dir, classnames);

	file_creator.createFactoryClass(classnames);
}

static void simulink_model(){
	MMLParser	mp;
//	mp.openFile ("C:\\simulink_test.txt");
	mp.openFile ("C:\\sim_jsim_test.txt");


	Model*	simulink_model = new Model();
	mp.parseEquations ("simulink model", simulink_model);

	mp.closeFile();
	simulink_model->setName("simulink_model");

	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(simulink_model,dir, classnames);

	file_creator.createFactoryClass(classnames);
}

static void mml_model(){
	MMLParser	mp;
	mp.openFile ("C:\\spb_ha.txt");

	Model*	varying_elastance_heart_model = new Model();
	Model*	systemic_circulation_model = new Model();
	Model*	pulmonary_circulation_model = new Model(); 
	Model*	baroreceptor_model = new Model();
	Model*	airway_mechanics_model = new Model();
	Model*	pericardium_model = new Model();
	Model*	coronary_circulation_model = new Model();
	/*
	//= mp.parse("varying elastance heart model");
	mp.parseParameters("varying elastance heart model", varying_elastance_heart_model);

	//= mp.parse("systemic circulation");
	mp.parseParameters("systemic circulation", systemic_circulation_model);
	
	//= mp.parse("pulmonary circulation");
	mp.parseParameters("pulmonary circulation", pulmonary_circulation_model);
	
	//= mp.parse("Baroreceptor Model");
	mp.parseParameters("Baroreceptor Model", baroreceptor_model);
	
	//= mp.parse("airway mechanics");
	mp.parseParameters("airway mechanics", airway_mechanics_model);
	
	//= mp.parse("pericardium");
	mp.parseParameters("pericardium", pericardium_model);
	
	//= mp.parse("coronary circulation");
	mp.parseParameters("coronary circulation", coronary_circulation_model);

	mp.parseVariables("varying elastance heart model", varying_elastance_heart_model);
	mp.parseVariables("systemic circulation", systemic_circulation_model);
	mp.parseVariables("pulmonary circulation", pulmonary_circulation_model);
	mp.parseVariables("Baroreceptor Model", baroreceptor_model);
	mp.parseVariables("airway mechanics", airway_mechanics_model);
	mp.parseVariables("pericardium", pericardium_model);
	mp.parseVariables("coronary circulation", coronary_circulation_model);

*/
	mp.parseEquations ("varying elastance heart model", varying_elastance_heart_model);
	mp.parseEquations("systemic circulation", systemic_circulation_model);
	mp.parseEquations("pulmonary circulation", pulmonary_circulation_model);
	mp.parseEquations("Baroreceptor Model", baroreceptor_model);
	mp.parseEquations("airway mechanics", airway_mechanics_model);
	mp.parseEquations("pericardium", pericardium_model);
	mp.parseEquations("coronary circulation", coronary_circulation_model);



	mp.closeFile();
	varying_elastance_heart_model->setName("heart_model");
	systemic_circulation_model->setName("systemic_circulation");
	pulmonary_circulation_model->setName("pulmonary_circulation");
	baroreceptor_model->setName("baroreceptor");
	airway_mechanics_model->setName("airway_mechanics");
	pericardium_model->setName("pericardium");
	coronary_circulation_model->setName("coronary_circulation");


	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(varying_elastance_heart_model,dir, classnames);
	file_creator.createMathModelFiles(systemic_circulation_model,dir,classnames);
	file_creator.createMathModelFiles(pulmonary_circulation_model,dir,classnames);
	file_creator.createMathModelFiles(baroreceptor_model,dir,classnames);
	file_creator.createMathModelFiles(airway_mechanics_model,dir,classnames);
	file_creator.createMathModelFiles(pericardium_model,dir,classnames);
	file_creator.createMathModelFiles(coronary_circulation_model,dir,classnames);

	file_creator.createFactoryClass(classnames);

}

static void intrinsic_model(){
	MMLParser	mp;
	mp.openFile ("C:\\intrinsic_baroreceptor.txt");

	Model*	varying_elastance_heart_model = new Model();
	Model*	systemic_circulation_model = new Model();
	Model*	pulmonary_circulation_model = new Model(); 
	Model*	baroreceptor_model = new Model();
	Model*	pericardium_model = new Model();
	Model*	coronary_circulation_model = new Model();

	mp.parseEquations ("varying elastance heart model", varying_elastance_heart_model);
	mp.parseEquations("systemic circulation", systemic_circulation_model);
	mp.parseEquations("pulmonary circulation", pulmonary_circulation_model);
	mp.parseEquations("Baroreceptor Model", baroreceptor_model);
	mp.parseEquations("pericardium", pericardium_model);
	mp.parseEquations("coronary circulation", coronary_circulation_model);



	mp.closeFile();
	varying_elastance_heart_model->setName("heart_model");
	systemic_circulation_model->setName("systemic_circulation");
	pulmonary_circulation_model->setName("pulmonary_circulation");
	baroreceptor_model->setName("baroreceptor");
	pericardium_model->setName("pericardium");
	coronary_circulation_model->setName("coronary_circulation");


	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(varying_elastance_heart_model,dir, classnames);
	file_creator.createMathModelFiles(systemic_circulation_model,dir,classnames);
	file_creator.createMathModelFiles(pulmonary_circulation_model,dir,classnames);
	file_creator.createMathModelFiles(baroreceptor_model,dir,classnames);
	file_creator.createMathModelFiles(pericardium_model,dir,classnames);
	file_creator.createMathModelFiles(coronary_circulation_model,dir,classnames);

	file_creator.createFactoryClass(classnames);

}

static void meal_model(){
	MMLParser	mp;
	mp.openFile ("C:\\meal_model.txt");
	

	Model*	glucose_model = new Model();
	Model*	insulin_model = new Model();
	Model*	unit_process_model = new Model(); 
	
	mp.parseEquations ("glucose model", glucose_model);
	mp.parseEquations("insulin model", insulin_model);
	mp.parseEquations("unit process model", unit_process_model);

	mp.closeFile();
	glucose_model->setName("glucose_model");
	insulin_model->setName("insulin_model");
	unit_process_model->setName("unit_process_model");


	//char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\development_test\\mmlparser\\mmlparser";
	char *dir = "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\integrative_phys\\mml_models\\mml_c_files";
	File_Creator file_creator(dir);
	
	file_creator.createHeaderFile();
	
	Container<char> *classnames = new Container<char>;
	file_creator.createMathModelFiles(glucose_model,dir, classnames);
	file_creator.createMathModelFiles(insulin_model,dir,classnames);
	file_creator.createMathModelFiles(unit_process_model,dir,classnames);

	file_creator.createFactoryClass(classnames);

}