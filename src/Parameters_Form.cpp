#include "stdafx.h"
#include "Parameters_Form.h"

void Physio_MIST::Parameters_Form::attach_structure(){
	link_layer::Mediator *mediator = Phy_MIST_Manager::getInstance()->get_simulation_manager()->mediator;

	// Find anatomical structure selected in the ontology tree
	System::Windows::Forms::Form ^f;
	cli::array<System::Windows::Forms::Form ^> ^forms = this->MdiParent->MdiChildren;
	System::String ^path = gcnew System::String("");
	for(int i = 0;i<this->MdiParent->MdiChildren->Length;i++){	
		f = forms[i];
		if(f->Name->CompareTo("Ontology_Tree_Form")==0){
			path = ((Ontology_Tree_Form ^)f)->ontologyTreeView->SelectedNode->Text;
			break;
		}
	}

	if(path != "" && path != "ontology"){
		// Create the anatomical structure
		char* name2 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path);
		string *str_name = new string(name2);
		System::String ^locator = gcnew System::String(path->Substring(0,1));

		// Parse the file to get the slot data for the structure
		System::String ^filename = gcnew System::String(".\\Classdefs\\fmapins-");
		filename = filename->Concat(filename,locator,".txt");
		Anatomical_structure * str = new Anatomical_structure();
		str->set_name(str_name);

		FMA_Reader ^reader = gcnew FMA_Reader(filename);
		System::Collections::Generic::List<SlotData^> ^attributes = reader->read_structure(path);

		// Bind the slot data to the structure
		for each(SlotData ^item in attributes){
			if(System::String::Compare(item->name,"FMAID")==0){
				str->set_FMAID(new FMAID(new int(Convert::ToInt32(item->values[0]))));
				break;
			}
		}

		// Bind the structure to the variable
		Param->component->set_anatomical_structure(str);
	}
	else{
		Param->component->set_anatomical_structure(old_str);
	}
}

/// Accepts names containing A-Z, a-z, 0-9, _ (must start with a letter)
bool Physio_MIST::Parameters_Form::validName(System::String^ name, [Out]interior_ptr<String^> errorMessage){
	if(name->Length == 0){
		*errorMessage = "Name is required.";
		return false;
	}

	// Regex to match A-Z, a-z, 0-9, _
	Regex^ rx = gcnew Regex("\\A[A-Za-z_\\d]*\\Z");
	if( rx->IsMatch(name) ){
		// If it contains valid characters, make sure it starts with a letter
		Regex^ rx2 = gcnew Regex("\\A[A-Za-z]+");
		if( rx2->IsMatch(name) ){
			*errorMessage = "";
			return true;
		}
		else {
			*errorMessage = "Name must start with a letter.";
			return false;
		}
	}
	else {
		*errorMessage = "Name must contain only A-Z, a-z, 0-9, and _.";
		return false;
	}

	*errorMessage = "Name is not valid.";
	return false;
}

/// Accepts integer and decimal values, as well as variations of "infinity"
bool Physio_MIST::Parameters_Form::validValue(System::String ^value, [Out]interior_ptr<String^> errorMessage){
	if(value->Length == 0) {
		// if blank, default to 0
		valueTextBox->Text = "0";
		*errorMessage = "";
		return true;
	}

	// Regex to match integers, floating point numbers, scientific floating point numbers
	Regex^ rx = gcnew Regex("\\A(?:[-+]?\\b[0-9]*\\.?[0-9]+)\\Z|\\A(?:[eE][-+]?[0-9]+)?\\Z");
	if( rx->IsMatch(value) ){
		*errorMessage = "";
		return true;
	}

	if(value->ToLower() == "infinity"){
		*errorMessage = "";
		return true;
	}

	*errorMessage = "Value is not valid.";
	return false;
}

/// TODO: \todo Figure out units validation
bool Physio_MIST::Parameters_Form::validUnits(System::String ^units, [Out]interior_ptr<String^> errorMessage){
	*errorMessage = "";
	return true;
}

/// TODO: \todo Figure out description validation
bool Physio_MIST::Parameters_Form::validDesc(System::String ^desc, [Out]interior_ptr<String^> errorMessage){
	*errorMessage = "";
	return true;
}
