//#include "stdafx.h"
#include "Load_Model_Form.h"
#include "FMA_Reader.h"

/*
1.	Find the selected anatomical structure from the ontology tree
2.	Find the selected variable from the selected cell in the datagrid
3.	Find the associated "component" using the previous step in the mediator owned 
		by simulation manager.
4.	Bind the anatomical structure to the component
*/
void Physio_MIST::Load_Model_Form::attach_anatomical_str(DataGridViewRow ^current_row){
			
	link_layer::Mediator *mediator = Phy_MIST_Manager::getInstance()->get_simulation_manager()->mediator;
	//1.	Find the selected anatomical structure from the ontology tree
	System::Windows::Forms::Form ^f;
	cli::array<System::Windows::Forms::Form ^> ^forms = this->MdiParent->MdiChildren;
	System::String ^path = gcnew System::String("");
	for(int i = 0;i<this->MdiParent->MdiChildren->Length;i++){	
		f = forms[i];
		if(f->Name->CompareTo("Ontology_Tree_Form")==0){
			path =  
				((Ontology_Tree_Form ^)f)->ontologyTreeView->SelectedNode->Text;
			break;
		}				
	}


	//2.	Find the selected variable from the selected cell in the datagrid
	System::String^ variable_name  = "";
	UI_Variable ^var;
	if(System::String::Compare(path,"")!=0){
		var =  (UI_Variable ^)current_row->DataBoundItem;
		variable_name =  var->Name;
	}


	/*3.	Find the associated "component" using the previous step in the mediator owned 
		by simulation manager.*/
	link_layer::Component *cmp =  var->component;

	//4.	Create and set the anatomical structure to the component
	char* name2 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path);
	string *str_name = new string(name2);
	System::String ^locator = gcnew System::String(path->Substring(0,1));

	
	//5.	Parse the file to get the slot data for the anatomical structure
	System::String ^filename = gcnew System::String(".\\Classdefs\\fmapins-");
	filename = filename->Concat(filename,locator,".txt");
	Anatomical_structure * str = new Anatomical_structure();
	str->set_name(str_name);

	FMA_Reader ^reader = gcnew FMA_Reader(filename);
	System::Collections::Generic::List<SlotData^> ^attributes = reader->read_structure(path);

	bindAttrToStructure(attributes,str);
	
	cmp->set_anatomical_structure(str);
	var->structure = str;

	dataGridView2->UpdateCellValue(5,current_row->Index);


}

void Physio_MIST::Load_Model_Form::attach_anatomical_str_collection(DataGridViewSelectedRowCollection ^selected_rows){
	for each(DataGridViewRow ^v in selected_rows)
	{
		 attach_anatomical_str(v);
	}
}


void Physio_MIST::Load_Model_Form::load_theModel(System::String ^filename){

	//MML parsing operations
	//mml_parser->openFile ("C:\\meal_model.txt");
	mml_parser->openFile ((char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filename));
	//mml_parser->parseSubModelNames();

	Phys_Container<char> *model_names = new Phys_Container<char>;
	model_names->addItem("glucose");
	model_names->addItem("insulin");
	model_names->addItem("unit process");

	Phys_Container<Model>* mml_models = new Phys_Container<Model>;
	mml_models = mml_parser->parse_models(model_names);

	
	mml_models->reset_iterator();
	Phy_MIST_Manager *mngr = (Phy_MIST_Manager::getInstance());	
	link_layer::Mediator *mediator =  mngr->get_simulation_manager()->create_Mediator(mml_models);

	
	//Create the parameter,variable, equation data to be used in UI
	mml_models->reset_iterator();
	while(mml_models->hasMoreVariables()){
		Model *model= mml_models->getNextItem();
		model->resetParameterIter();
		ParameterData *parameter;
		UI_Variable ^par;

			while(parameter = model->getNextParameter()){
				//find the parameter from the mediator and attach it
				link_layer::Component *comp =  mngr->get_simulation_manager()->mediator->get_ModelComponent_by_name(parameter->getName());
				par = gcnew UI_Variable();
				par->component = comp;	
				parameters_list->Add(par);
			}

		model->resetVariableIter();
		VariableData *variable;
		UI_Variable ^var;
			while(variable = model->getNextVariable()){

				//find the variable from the mediator and attach it
				link_layer::Component *comp =  mngr->get_simulation_manager()->mediator->get_ModelComponent_by_name(variable->getName());				
				var = gcnew UI_Variable();
				var->component  = comp;
				variables_list->Add(var);
			}

		model->resetEquationIter();
		EquationData *equation;
		while(equation = model->getNextEquationData()){
			for each(UI_Variable ^v in variables_list)			
			{
				if(System::String::Compare(v->Name,gcnew System::String(equation->getOutput()))==0){
					v->Formula = gcnew System::String(equation->getRHS());
					break;			
				}
			}
		}
	}	

}

void Physio_MIST::Load_Model_Form::load_anatomical_information(){
	//Phy_MIST_Manager::getInstance()->load_XML_file();

	String ^current_dir = System::IO::Directory::GetCurrentDirectory();
	openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
	System::Windows::Forms::DialogResult result= openFileDialog->ShowDialog();
	Phy_MIST_Manager::getInstance()->load_XML_file(openFileDialog->FileName);
	//System::IO::Directory::SetCurrentDirectory(current_dir);

	for(int i=0;i<dataGridView2->RowCount;i++){
		dataGridView2->UpdateCellValue(5,i);
	}
}


void Physio_MIST::Load_Model_Form::bindAttrToStructure(System::Collections::Generic::List<SlotData^>  ^attributes, Anatomical_structure *str){
	
	//get the FMAID
	for each(SlotData ^item in attributes){
		if(System::String::Compare(item->name,"FMAID")==0){
			str->set_FMAID(new FMAID(new int(Convert::ToInt32(item->values[0]))));
			break;
		}
	}



}
