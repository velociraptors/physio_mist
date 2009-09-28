/**************************************************************************************************
  XML_Writer.h
  Definition of XML_Writer
  Contributor(s):	E. Zeynep Erson
  Created on:		September 2008
  Description:		Creates the XML files for storing physiological variable and anatomical structure
					assocications.
  Note:				Uses System.XML, can later switch to XMLlite
					using namespace System; would result in ambigous definitions of some services 
					(conflict in IServiceProvider, an interface defined in .NET System namespace)
					Instead call System namespace explicitly in XML related calls
**************************************************************************************************/
#ifndef XML_WRITER_H
#define XML_WRITER_H

#using <mscorlib.dll>
#using <System.Xml.dll>


#include "utilities.h"
#include <vcclr.h>



class XML_Element;
class XML_Attribute;
class XML_Data;

class XML_Writer
{
public:
	XML_Writer(System::String ^file_name,XML_Data *data);
	void write_XML_file();


private:
	void write_XMLData(XML_Data *data);
	XML_Data *data;
	gcroot<System::Xml::XmlTextWriter ^> xml_writer;

};
class XML_Type;

class XML_Data
{
public:
	XML_Data();
	XML_Element *get_next_element();
	XML_Element *get_root_element();
	bool hasMoreElelements();
	void reset_iterator();
	void add_element(XML_Element *element);

private:
	Phys_Container<XML_Element> *data;
	XML_Element *root_element;
	XML_Element *current_element;
};
class XML_Type
{
public:
	XML_Type();
	XML_Type(System::String ^ _name);
	void set_name(System::String ^name);
	virtual void set_value(System::String ^value);
	gcroot<System::String ^> get_name();
	virtual gcroot<System::String ^> get_value();
	virtual void write_type(System::Xml::XmlTextWriter ^writer) = 0;
		
private:
	gcroot<System::String ^> name;
	gcroot<System::String ^> value;

};
class XML_Attribute: public XML_Type
{
public:
	XML_Attribute();
	XML_Attribute(System::String ^thename);
	virtual void write_type(System::Xml::XmlTextWriter ^writer);
};
class XML_Element: public XML_Type
{
public:
	XML_Element();
	XML_Element(System::String ^ _name);
	void add_element(XML_Element *child);
	void add_attribute(XML_Attribute *attribute);
	XML_Element* get_next_child();
	XML_Attribute* get_next_attribute();
	virtual void write_type(System::Xml::XmlTextWriter ^writer);

private:
	Phys_Container<XML_Element> *children;
	Phys_Container<XML_Attribute> *attributes;
};


public class XML_Phy_Type
{
	public:
		XML_Phy_Type(){;};
	virtual ~XML_Phy_Type(){;};
	XML_Phy_Type(System::String ^ _name){name = _name;};
	void set_name(System::String ^_name){name = _name;};
	gcroot<System::String ^> get_name(){return name;};
		
private:
	gcroot<System::String ^> name;

};
public class XML_Phy_Anat_Str:public XML_Phy_Type
{
public:
	XML_Phy_Anat_Str(){fmaid  = NULL;};
	virtual ~XML_Phy_Anat_Str(){;};
	void set_fmaid(int *_id){fmaid = _id;};
	int* get_fmaid(){return fmaid;};
private:
	int *fmaid;
};
public class XML_Phy_Component:public XML_Phy_Type
{
public:
	XML_Phy_Component(){anatomical_str = NULL; isParameter = false;};
	virtual ~XML_Phy_Component(){delete anatomical_str;};
	void set_anatomical_str(XML_Phy_Anat_Str *_str){anatomical_str = _str;};
	XML_Phy_Anat_Str* get_anatomical_str(){return anatomical_str;};
	bool get_isParameter(){return isParameter;};
	void set_isParameter(bool _param){isParameter = _param;};
private:
	bool isParameter;
	XML_Phy_Anat_Str *anatomical_str;

};


#endif