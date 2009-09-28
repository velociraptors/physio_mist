/**************************************************************************************************
  XML_Reader.CPP
  Implementation of XML_Reader
  Contributor(s):	E. Zeynep Erson
  Created on:		September 2008
  Description:		Reads the XML documents into XML_Data, which is composed of XML elements.
					(See XML_Writer.h for XML_Data, a wrapper for DOM)
  Note:				Uses System.XML, can later switch to XMLlite
**************************************************************************************************/
#include "XML_Reader.h"


XML_Reader::XML_Reader(System::String ^_path){
	document = gcnew System::Xml::XmlDocument();	
	reader = gcnew System::Xml::XmlNodeReader(document);
	
	
	file_path = _path;
	document->Load(file_path);


}

/*
Parent is the current element being read.
Reading of the parent continous until the end tag is reached.
If new elements are discovered, the method is called recursively.
*/

XML_Phy_Component* XML_Reader::read_Variable()
{
	XML_Phy_Component *cmp = new XML_Phy_Component;
	bool end_element = false;
	//read the attributes

	if(reader->HasAttributes){					
		for(int i=0;i<reader->AttributeCount;i++){
			reader->MoveToAttribute(i);
			if(System::String::Compare(reader->Name,"isParameter")==0){
				cmp->set_isParameter(System::Convert::ToBoolean(reader->Value));
			}
		}
	}

	//read the anatomical str and name node
	while(!end_element && reader->Read()){
		switch (reader->NodeType){
			case System::Xml::XmlNodeType::EndElement:
			{												
				if(System::String::Compare("name",reader->Name)==0){
					
				}
				else if(System::String::Compare("variable",reader->Name)==0){
					end_element = true;
				}
				break;
				
			}
			case System::Xml::XmlNodeType::Element:
			{			
				if(System::String::Compare("anatomical_str", reader->Name)==0)
				{

					
					XML_Phy_Anat_Str *element = read_Anatomical_Str();
					cmp->set_anatomical_str(element);

				}
				else if(System::String::Compare("name", reader->Name)==0)
				{
					//skip this node, its value will be parsed

				}
				break;							
			}			
			case System::Xml::XmlNodeType::Text:{
				cmp->set_name(reader->Value);
				//think about this?
				break;
			}

		}

	}
	return cmp;

}
XML_Phy_Anat_Str* XML_Reader::read_Anatomical_Str(){
	XML_Phy_Anat_Str *anat_str = new XML_Phy_Anat_Str();
	bool end_element  = false;
	//read the attributes
	//read the element attributes to the parent element
	if(reader->HasAttributes){				
		for(int i=0;i<reader->AttributeCount;i++){
			reader->MoveToAttribute(i);
			if(System::String::Compare(reader->Name,"FMAID")==0){
				anat_str->set_fmaid(new int(System::Convert::ToInt32(reader->Value)));
			}
			else{
				//namespace attribute for the root element--we can skip it
			}
		}
	}
	//read the name node
	
	while(!end_element && reader->Read()){
		switch (reader->NodeType){
			case System::Xml::XmlNodeType::EndElement:
			{												

				if(System::String::Compare("name",reader->Name)==0){
					
				}
				else if(System::String::Compare("anatomical_str",reader->Name)==0){
					end_element = true;
				}

				break;
			}
			case System::Xml::XmlNodeType::Element:
			{			
				XML_Phy_Type *element;
				if(System::String::Compare("name", reader->Name)==0)
				{
					//read_Name_Node();

				}
				break;							
			}			
			case System::Xml::XmlNodeType::Text:{
				anat_str->set_name(reader->Value);
				//think about this?
				break;
			}

		}

	}
	return anat_str;
}
Phys_Container<XML_Phy_Component> * XML_Reader::read_element(XML_Phy_Type *parent){
	Phys_Container<XML_Phy_Component> *cmps = new Phys_Container<XML_Phy_Component>;
	bool end_element = false;

	

	//read the element attributes to the parent element
	if(reader->HasAttributes){				
		for(int i=0;i<reader->AttributeCount;i++){
			reader->MoveToAttribute(i);
				//namespace attribute for the root element--we can skip it
		}
	}

	//continue reading until the end of element is reached
	while(!end_element && reader->Read() ){
		switch (reader->NodeType){
			case System::Xml::XmlNodeType::EndElement:
			{												
				if(System::String::Compare(parent->get_name(),reader->Name)==0){
					end_element = true;
				}				
				break;
			}
			case System::Xml::XmlNodeType::Element:
			{			
				//XML_Phy_Type *element;
				if(System::String::Compare("variable", reader->Name)==0)
				{									
					XML_Phy_Component *element = read_Variable();
					cmps->addItem(element);

				}
				break;							
			}			
			case System::Xml::XmlNodeType::Text:{
				break;
			}

		}
	}
	return cmps;
}


Phys_Container<XML_Phy_Component>* XML_Reader::read_xml(){

	XML_Phy_Type *element = new XML_Phy_Type;

	bool root_found = false;

	//find the first element
	while(!root_found && reader->Read()){
		switch(reader->NodeType){
			case System::Xml::XmlNodeType::XmlDeclaration:
				{
					//do nothing continue reading
					break;
				}
			case System::Xml::XmlNodeType::Element:
				{
					//start reading;
					//fill in the name/value of the element
					/*element->set_name(reader->Name);
					element->set_value(reader->Value);*/
					root_found = true;
					break;

				}
		}
	}

	Phys_Container<XML_Phy_Component> *cmps =  read_element(element);
	return cmps;

}

/*static void ValidationEventHandler(Object* sender,System::Xml::Schema::ValidationEventArgs* args){
	System::Console::WriteLine("\r\n\tValidation error: {0}", args->Message);
}*/