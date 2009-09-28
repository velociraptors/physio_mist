/**************************************************************************************************
  XML_Writer.cpp
  Implementation of XML_Writer
  Contributor(s):	E. Zeynep Erson
  Created on:		September 2008
  Description:		Creates the XML files for storing physiological variable and anatomical structure
					assocications.
  Note:				Uses System.XML, can later switch to XMLlite
**************************************************************************************************/

#include "XML_Writer.h"


XML_Type::XML_Type(){
	set_name("");
	set_value("");
}
XML_Type::XML_Type(System::String ^_name){
	set_name(_name);
	set_value("");
}
	
void XML_Type::set_name(System::String ^ _name){
	this->name = _name;

}

void XML_Type::set_value (System::String ^_value){
	this->value = _value;
}

gcroot<System::String ^> XML_Type::get_name(){
	return this->name;
	
}

gcroot<System::String ^> XML_Type::get_value(){
	return this->value;
}


XML_Element::XML_Element(){
	children = new Phys_Container<XML_Element>;
	attributes = new Phys_Container<XML_Attribute>;

}


XML_Element::XML_Element(System::String ^_name):XML_Type(_name){
	children = new Phys_Container<XML_Element>;
	attributes = new Phys_Container<XML_Attribute>;
}
	
	
XML_Element * XML_Element::get_next_child(){

	if(this->children->hasMoreVariables()){
		return children->getNextItem();
	}
	else
	{
		return NULL;
	}

}

XML_Attribute * XML_Element::get_next_attribute(){

	if(this->attributes->hasMoreVariables()){
		return attributes->getNextItem();
	}
	else
	{
		return NULL;
	}

}

void XML_Element::add_attribute(XML_Attribute *attribute){
	attributes->addItem(attribute);
}

void XML_Element::add_element(XML_Element *child){
	children->addItem(child);
}


void XML_Element::write_type(System::Xml::XmlTextWriter ^writer){
	writer->WriteStartElement("xmlns",this->get_name(),"http://tempuri.org/Variable_schema.xsd");
	

	//write the attributes
	while(this->attributes->hasMoreVariables()){
		this->get_next_attribute()->write_type(writer);
	}

	//write the children
	while(this->children->hasMoreVariables()){
		this->get_next_child()->write_type(writer);
	}


	//write the string
	if(System::String::Compare(this->get_value(),"")!=0){
			writer->WriteString(this->get_value());
	}
	
	
	writer->WriteEndElement();
}

XML_Attribute::XML_Attribute()
{
}
XML_Attribute::XML_Attribute(System::String ^thename) : XML_Type(thename){
}
void XML_Attribute::write_type(System::Xml::XmlTextWriter ^writer){
	writer->WriteAttributeString(this->get_name(),this->get_value());
}


XML_Data::XML_Data(){
	data = new Phys_Container<XML_Element>;
	root_element = data->getItemAt(0);
	current_element = root_element;
}
void XML_Data::add_element(XML_Element *element){
	data->addItem(element);
}
void XML_Data::reset_iterator(){
	this->data->reset_iterator();
}

XML_Element* XML_Data::get_next_element(){
	if(this->data->hasMoreVariables()){
		return data->getNextItem();
	}
	else{
		return NULL;
	}
}
bool XML_Data::hasMoreElelements(){
	return this->data->hasMoreVariables();
}

XML_Element* XML_Data::get_root_element(){
	this->data->reset_iterator();
	return get_next_element();
}

XML_Writer::XML_Writer(System::String ^file_name,XML_Data *_data){
	xml_writer = gcnew System::Xml::XmlTextWriter(file_name,System::Text::Encoding::ASCII);
	xml_writer->Formatting = System::Xml::Formatting::Indented;
	this->data = _data;
}

void XML_Writer::write_XML_file(){
	xml_writer->WriteStartDocument(true);
	write_XMLData(this->data);
	xml_writer->WriteEndDocument();
	xml_writer->Flush();
	xml_writer->Close();

}
void XML_Writer::write_XMLData(XML_Data *data){
	
	while(data->hasMoreElelements()){
		data->get_next_element()->write_type(xml_writer);
	}

}