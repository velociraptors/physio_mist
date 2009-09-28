#include "Phy_MIST_Manager.h"
#include "XML_Reader.h"

Phy_MIST_Manager* Phy_MIST_Manager::instance= 0;
Phy_MIST_Manager* Phy_MIST_Manager::getInstance(){

	if(instance==NULL){
		instance = new Phy_MIST_Manager();
	}		
	return instance;

}

Phy_MIST_Manager::Phy_MIST_Manager(){	
	simulation_manager = new Simulation_Manager();

}

Simulation_Manager* Phy_MIST_Manager::get_simulation_manager(){
	return simulation_manager;
}

void Phy_MIST_Manager::set_simulation_manager(Simulation_Manager *manager){
	simulation_manager = manager;
}

void Phy_MIST_Manager::load_XML_file(System::String ^filename){

	//read the xml_file

	XML_Reader *my_reader = new XML_Reader(filename);			
	Phys_Container<XML_Phy_Component> *cmps =  my_reader->read_xml();
		
	//parse the xml components to add the anatomical information to the link layer compoenents in memory
	cmps->reset_iterator();
	XML_Phy_Component *xml_comp;
	link_layer::Component* cmp;
	while(cmps->hasMoreVariables()){
		xml_comp = cmps->getNextItem();
		cmp = this->get_simulation_manager()->mediator->get_ModelComponent_by_name(xml_comp->get_name());
		Anatomical_structure *str = new Anatomical_structure();
		const char* chars = (const char*)( System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(xml_comp->get_anatomical_str()->get_name())).ToPointer();
		std::string *os = new std::string(chars);
		str->set_name(os);
		str->set_FMAID(new FMAID((xml_comp->get_anatomical_str()->get_fmaid())));
		cmp->set_anatomical_structure(str);
	}
	


}


void Phy_MIST_Manager::create_XML_file(System::String ^filename){



	
	//create xmldocument

	System::Xml::XmlDocument ^document = gcnew System::Xml::XmlDocument;
	//create the root element-variable list
	System::Xml::XmlElement ^root  =  document->CreateElement("variable_list","http://tempuri.org/Variable_schema.xsd");;
	document->AppendChild(root);
	
	//parse the components in the system
	link_layer::Mediator *mediator =  this->get_simulation_manager()->mediator;
	
	Phys_Container<link_layer::Link_layer_Component> *cmps =  mediator->get_runnable_components();
	while(cmps->hasMoreVariables()){
		link_layer::Component *cmp = (link_layer::Component*)cmps->getNextItem();

		if(cmp->get_anatomical_structure()!=NULL){
					
			System::Xml::XmlElement ^var  =  document->CreateElement("variable","http://tempuri.org/Variable_schema.xsd");		
			System::Xml::XmlAttribute ^par= (document->CreateAttribute("isParameter"));
		
			if(cmp->get_variable()->get_Model()!=NULL){			
				par->Value = "false";
			}
			else{
				par->Value = "true";
			}

			var->SetAttributeNode(par);
			System::Xml::XmlElement ^var_name  =  document->CreateElement("name","http://tempuri.org/Variable_schema.xsd");
			var_name->AppendChild(document->CreateTextNode(gcnew System::String(cmp->get_name())));
			var->AppendChild(var_name);

			//child->AppendChild( document->CreateElement("name","http://tempuri.org/Variable_schema.xsd");

			
						
			System::Xml::XmlElement ^anat_str =  document->CreateElement("anatomical_str","http://tempuri.org/Variable_schema.xsd");					
			anat_str->SetAttribute("FMAID",gcnew System::String(cmp->get_anatomical_structure()->get_FMAID()->get_id().ToString()));
			//sub_child->SetAttribute("anat_name",gcnew System::String(cmp->get_anatomical_structure()->get_name()->c_str()));
			//sub_child->Value =  gcnew System::String(cmp->get_anatomical_structure()->get_name()->c_str());
			//sub_child->AppendChild(document->CreateElement("name",gcnew System::String(cmp->get_anatomical_structure()->get_name()->c_str())));
			System::Xml::XmlElement ^anat_name  =  document->CreateElement("name","http://tempuri.org/Variable_schema.xsd");
			anat_name->AppendChild(document->CreateTextNode(gcnew System::String(cmp->get_anatomical_structure()->get_name()->c_str())));
			anat_str->AppendChild(anat_name);

			var->AppendChild(anat_str);
			root->AppendChild(var);

		}

	}
	//create the xmlelements
	//add these elements to the document
	//write the document

/*	System::Xml::XmlElement ^el =  document->CreateElement("variable","http://tempuri.org/Variable_schema.xsd");
	System::Xml::XmlAttribute ^at= (document->CreateAttribute("isParameter"));
	at->Value = "false";
	el->SetAttributeNode(at);
	el->SetAttribute("var_name","PAOC");
	document->AppendChild(el);

	System::Xml::XmlElement ^el2 =  document->CreateElement("anatomical_str","http://tempuri.org/Variable_schema.xsd");
	el2->SetAttribute("anat_name","Heart");
	el2->SetAttribute("FMAID","111");
	el->AppendChild(el2);
*/

	System::Xml::XmlTextWriter ^writer  = gcnew System::Xml::XmlTextWriter(filename,System::Text::Encoding::ASCII);
	writer->WriteStartDocument();
	document->WriteTo(writer);
	writer->WriteEndDocument();
	writer->Flush();
	writer->Close();

}