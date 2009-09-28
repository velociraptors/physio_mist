#pragma once

#include "UI_Variable.h"
#include "slotdata.h"
#include "Anatomical_structure.h"
#include "mmlparser.h"
#include "Phy_MIST_Manager.h"

using namespace System;
using namespace System::Xml;
using namespace System::Text::RegularExpressions;

public ref class ModelData
{
public:
	ModelData(void);
	ModelData(String^ filename, bool isXML);

	property System::String^ ModelName;
	property System::String^ ModelDesc;
	property System::Collections::Generic::List<UI_Variable^>^ varList;
	property System::Collections::Generic::List<UI_Variable^>^ paramList;

	void load_MMLfile(String^ filename);
	void load_XMLfile(String^ filename);
	void save_XMLfile(String^ filename);
	void load_variable(XmlReader ^reader);
	bool validate_equation(String^ eqn);

private: MMLParser *mml_parser;
};
