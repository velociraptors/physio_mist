#include "Model_Form.h"

void Physio_MIST::Model_Form::load_anatomical_information(){
	String ^current_dir = System::IO::Directory::GetCurrentDirectory();
	openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
	System::Windows::Forms::DialogResult result= openFileDialog->ShowDialog();
	Phy_MIST_Manager::getInstance()->load_XML_file(openFileDialog->FileName);
	System::IO::Directory::SetCurrentDirectory(current_dir);
}

UI_Variable^ Physio_MIST::Model_Form::create_UIvar(){
	physiological_layer::Physiological_Variable *phys_var = new physiological_layer::Physiological_Variable();
	link_layer::Component *comp = new link_layer::Component(phys_var);
	
	UI_Variable^ new_var = gcnew UI_Variable();
	new_var->component = comp;
	new_var->Name = "";
	new_var->Value = 0.0;
	new_var->Units = "";
	new_var->Desc = "";
	new_var->Formula = "";

	return new_var;
}

void Physio_MIST::Model_Form::reset_UIvar(UI_Variable^ variable){
	physiological_layer::Physiological_Variable *phys_var = new physiological_layer::Physiological_Variable();
	link_layer::Component *comp = new link_layer::Component(phys_var);

	variable->component = comp;
	variable->Name = "";
	variable->Value = 0.0;
	variable->Units = "";
	variable->Desc = "";
	variable->Formula = "";
}

void Physio_MIST::Model_Form::xmlserial(ModelData^ model, String^ filename){
    //System::Xml::Serialization::XmlSerializer^ serializer = gcnew System::Xml::Serialization::XmlSerializer(ModelData::typeid);
    //HumanGUI::model_schema^ ms = gcnew HumanGUI::model_schema;
    //int index = filename->LastIndexOf('.');
    //filename->Insert(index, "_serialized");
    //System::IO::TextWriter^ writer = gcnew System::IO::StreamWriter( filename );
    //serializer->Serialize(writer, model);
    //writer->Close();
}