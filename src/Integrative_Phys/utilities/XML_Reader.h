/**************************************************************************************************
  XML_Reader.h
  Definition of XML_Reader
  Contributor(s):	E. Zeynep Erson
  Created on:		September 2008
  Description:		Reads the XML documents into XML_Data, which is composed of XML elements.
					(See XML_Writer.h for XML_Data, a wrapper for DOM)
  Note:				Uses System.XML, can later switch to XMLlite
**************************************************************************************************/

#ifndef XML_READER_H
#define XML_READER_H

#include <vcclr.h>
#include <iostream>

#include "XML_Writer.h"


//using namespace System;

class XML_Reader{
public:
	XML_Reader(System::String ^file_path);
	Phys_Container<XML_Phy_Component>* read_xml();
	Phys_Container<XML_Phy_Component> *read_element(XML_Phy_Type *parent);
	XML_Phy_Component* read_Variable();
	XML_Phy_Anat_Str* read_Anatomical_Str();
	
	
	//static void ValidationEventHandler(System::Xml::Schema::ValidationEventArgs^ args);

private:
	gcroot<System::Xml::XmlNodeReader ^> reader;
	gcroot<System::Xml::XmlDocument ^>   document;
	gcroot<System::String ^>file_path;

	
};

#endif