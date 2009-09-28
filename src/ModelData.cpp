#include "ModelData.h"

//! \brief Default constructor
ModelData::ModelData(void)
{
	varList = gcnew System::Collections::Generic::List<UI_Variable^>();
	paramList = gcnew System::Collections::Generic::List<UI_Variable^>();
}

//! \brief Constructor
ModelData::ModelData(System::String ^filename, bool isXML)
{
	varList = gcnew System::Collections::Generic::List<UI_Variable^>();
	paramList = gcnew System::Collections::Generic::List<UI_Variable^>();

	if(isXML){
		this->load_XMLfile(filename);
	}
	else {
		this->load_MMLfile(filename);
	}
}

//! \brief Loads a model from an MML text file
void ModelData::load_MMLfile(System::String ^filename){
	//MML parsing operations
	mml_parser = new MMLParser();
	mml_parser->openFile ((char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filename));

	Phys_Container<char> *model_names = new Phys_Container<char>;
	model_names->addItem("glucose");
	model_names->addItem("insulin");
	model_names->addItem("unit process");

	Phys_Container<Model>* mml_models = new Phys_Container<Model>;
	mml_models = mml_parser->parse_models(model_names);

	
	mml_models->reset_iterator();
	Phy_MIST_Manager *mngr = (Phy_MIST_Manager::getInstance());	
	link_layer::Mediator *mediator =  mngr->get_simulation_manager()->create_Mediator(mml_models);

	//Create the parameter, variable, equation data to be used in UI
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
				paramList->Add(par);
			}

		model->resetVariableIter();
		VariableData *variable;
		UI_Variable ^var;
			while(variable = model->getNextVariable()){

				//find the variable from the mediator and attach it
				link_layer::Component *comp =  mngr->get_simulation_manager()->mediator->get_ModelComponent_by_name(variable->getName());				
				var = gcnew UI_Variable();
				var->component  = comp;
				varList->Add(var);
			}

		model->resetEquationIter();
		EquationData *equation;
		while(equation = model->getNextEquationData()){
			for each(UI_Variable ^v in varList)			
			{
				if(System::String::Compare(v->Name,gcnew System::String(equation->getOutput()))==0){
					v->Formula = gcnew System::String(equation->getRHS());
					break;			
				}
			}
		}
	}
}

//! \brief Loads a model from an XML file.
//! Skips to the <model> tag, sets model_name, skips to the first <variable> tag, loads each variable until the end of the file is reached.
void ModelData::load_XMLfile(System::String ^filename){
	varList->Clear();
	paramList->Clear();

	XmlReaderSettings^ settings = gcnew XmlReaderSettings();
	settings->ValidationType = ValidationType::Schema;
	String^ schema = gcnew String(".\\model_schema.xsd");
	settings->Schemas->Add("http://tempuri.org/model_schema.xsd", schema);
	XmlReader^ reader = XmlReader::Create(filename, settings);

	while( reader->Read() ){
		switch(reader->NodeType){
			case XmlNodeType::Element:
			{
				if(reader->Name == "model"){
					reader->ReadToDescendant("model_name");
					this->ModelName = reader->ReadElementContentAsString();
					//! \todo decide if model description needs to be implemented
					//if(reader->ReadToDescendant("description")){
					//	this->ModelDesc = reader->ReadElementContentAsString();
					//}
				}
				else if(reader->Name == "variable"){
					load_variable(reader);
				}
				break;
			}
			case XmlNodeType::EndElement:
			{
				break;
			}
		}
	}
}

void ModelData::save_XMLfile(System::String ^filename){
	// Set the model name to the filename, for now.
	//! \todo Users should be able to set the name of the model.
	// This would allow multiple models to be saved in a single file.
	this->ModelName = filename;
	if( this->ModelName->EndsWith(".xml") ){
		String^ temp = this->ModelName->ToLower();
		int last = temp->LastIndexOf("\\");
		temp = temp->Substring(last+1);
		this->ModelName = temp->Substring(0, temp->Length-4);
	}

	XmlDocument ^document = gcnew XmlDocument();
	// Create the root element
	XmlElement ^root = document->CreateElement("model", "http://tempuri.org/model_schema.xsd");
	document->AppendChild(root);

	// Model name
	XmlElement ^model = document->CreateElement("model_name", "http://tempuri.org/model_schema.xsd");
	model->InnerText = this->ModelName;
	root->AppendChild(model);

	// write parameters
	for each(UI_Variable ^param in paramList){
		// Begin variable element
		XmlElement ^par_node = document->CreateElement("variable", "http://tempuri.org/model_schema.xsd");
		// "constant" attribute is true for parameters
		par_node->SetAttribute("constant", "true");
		// "type" attribute is "real" by default (this should be changed if/when UI_Variable holds type)
		par_node->SetAttribute("type", "real");

		// write name element
		XmlElement ^name = document->CreateElement("name", "http://tempuri.org/model_schema.xsd");
		name->InnerText = param->Name;
		par_node->AppendChild(name);
		//formula element is required, but it's empty for parameters
		XmlElement ^formula = document->CreateElement("formula", "http://tempuri.org/model_schema.xsd");
		formula->IsEmpty = true;
		par_node->AppendChild(formula);
		// write value element
		XmlElement ^value = document->CreateElement("value", "http://tempuri.org/model_schema.xsd");
		value->InnerText = param->Value.ToString();
		par_node->AppendChild(value);
		// units are optional, only write the element if units are set
		if(String::IsNullOrEmpty(param->Units) == false){
			XmlElement ^units = document->CreateElement("units", "http://tempuri.org/model_schema.xsd");
			units->InnerText = param->Units;
			par_node->AppendChild(units);
		}
		// as with units, description is optional
		if(String::IsNullOrEmpty(param->Desc) == false){
			XmlElement ^desc = document->CreateElement("description", "http://tempuri.org/model_schema.xsd");
			desc->InnerText = param->Desc;
			par_node->AppendChild(desc);
		}

		// anatomical structure is optional
		if( param->component->get_anatomical_structure() ){
			// begin anatomical_structure element
			XmlElement ^str = document->CreateElement("anatomical_structure", "http://tempuri.org/model_schema.xsd");

			// write the FMAID as an attribute
			String^ fmaid = param->component->get_anatomical_structure()->get_FMAID()->get_id().ToString();
			str->SetAttribute("FMAID", fmaid);

			// write name element
			String^ str_name = gcnew String( param->component->get_anatomical_structure()->get_name()->c_str() );
			XmlElement ^name2 = document->CreateElement("str_name", "http://tempuri.org/model_schema.xsd");
			name2->InnerText = str_name;
			str->AppendChild(name2);

			// end anatomical structure element
			par_node->AppendChild(str);
		}

		// end variable element
		root->AppendChild(par_node);
	}

	// write variables
	// this process is almost exactly the same as writing the parameters
	for each(UI_Variable ^var in varList){
		XmlElement ^var_node = document->CreateElement("variable", "http://tempuri.org/model_schema.xsd");
		// "constant" attribute is false for variables
		var_node->SetAttribute("constant", "false");
		var_node->SetAttribute("type", "real");

		XmlElement ^name = document->CreateElement("name", "http://tempuri.org/model_schema.xsd");
		name->InnerText = var->Name;
		var_node->AppendChild(name);

		//! \todo present error/dialog to user if validation fails, rather than just write the formula
		// formula element has content for variables, needs to be validated
		XmlElement ^formula = document->CreateElement("formula", "http://tempuri.org/model_schema.xsd");
		if(validate_equation(var->Formula)){
			formula->InnerText = var->Formula;
		}
		else {formula->InnerText = var->Formula;}
		//else {formula->IsEmpty = true;}

		var_node->AppendChild(formula);
		XmlElement ^value = document->CreateElement("value", "http://tempuri.org/model_schema.xsd");
		value->InnerText = var->Value.ToString();
		var_node->AppendChild(value);

		if(String::IsNullOrEmpty(var->Units) == false){
			XmlElement ^units = document->CreateElement("units", "http://tempuri.org/model_schema.xsd");
			units->InnerText = var->Units;
			var_node->AppendChild(units);
		}

		if(String::IsNullOrEmpty(var->Desc) == false){
			XmlElement ^desc = document->CreateElement("description", "http://tempuri.org/model_schema.xsd");
			desc->InnerText = var->Desc;
			var_node->AppendChild(desc);
		}

		if( var->component->get_anatomical_structure() ){
			XmlElement ^str = document->CreateElement("anatomical_structure", "http://tempuri.org/model_schema.xsd");

			String^ fmaid = var->component->get_anatomical_structure()->get_FMAID()->get_id().ToString();
			str->SetAttribute("FMAID", fmaid);

			String^ str_name = gcnew String( var->component->get_anatomical_structure()->get_name()->c_str() );
			XmlElement ^name2 = document->CreateElement("name", "http://tempuri.org/model_schema.xsd");
			name2->InnerText = str_name;
			str->AppendChild(name2);

			var_node->AppendChild(str);
		}

		root->AppendChild(var_node);
	}

	// write the document to the file
	XmlWriterSettings^ settings = gcnew XmlWriterSettings();
	settings->Indent = true; // elements are indented for readability
	XmlWriter ^writer = XmlWriter::Create(filename, settings);
	writer->WriteStartDocument(); // write the default xml declaration
	document->WriteTo(writer); // write all the elements processed above
	writer->WriteEndDocument(); // close elements as needed
	writer->Close();
}

//! \brief Sets UI_Variable properties based on each node found.
//! When </variable> is found, adds the new item to paramBindingSource or varBindingSource, and returns to load_XMLfile
void ModelData::load_variable(System::Xml::XmlReader ^reader){
	physiological_layer::Physiological_Variable *phys_var = new physiological_layer::Physiological_Variable();
	link_layer::Component *comp = new link_layer::Component(phys_var);
	UI_Variable^ var = gcnew UI_Variable();
	var->component = comp;

	bool isParameter;
	bool endOfVariable = false;

	while(!endOfVariable && reader->Read() ){
		switch(reader->NodeType){
			case XmlNodeType::Element:
			{
				//! \todo this probably ought to be a switch statement
				if(reader->Name == "name"){
					var->Name = reader->ReadElementContentAsString();
				}
				else if(reader->Name == "formula"){
					if(reader->IsEmptyElement){
						isParameter = true;
					}
					else {
						var->Formula = reader->ReadElementContentAsString();
						isParameter = false;
					}
				}
				else if(reader->Name == "value"){
					String^ val = reader->ReadElementContentAsString();
					if(val == "Infinity" || val == "INF"){
						var->Value = numeric_limits<double>::infinity();
					}
					else {
						var->Value = Double::Parse(val);
					}
				}
				else if(reader->Name == "units"){
					var->Units = reader->ReadElementContentAsString();
				}
				else if(reader->Name == "description"){
					var->Desc = reader->ReadElementContentAsString();
				}
				else if(reader->Name == "anatomical_structure"){
					Anatomical_structure * str = new Anatomical_structure();

					int fmaid = Convert::ToInt32( reader->GetAttribute("FMAID") );
					str->set_FMAID(new FMAID(new int(fmaid)));

					reader->ReadToDescendant("str_name");
					String^ tmp_name = reader->ReadElementContentAsString();
					char* name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tmp_name);
					string *str_name = new string(name);
					str->set_name(str_name);

					var->component->set_anatomical_structure(str);
				}
				break;
			}
			case XmlNodeType::EndElement:
			{
				if(reader->Name == "variable"){
					endOfVariable = true;
					break;
				}
			}
		}
	}
	if(isParameter){
		this->paramList->Add(var);
	}
	else {
		this->varList->Add(var);
	}
}


/** \brief Checks all operands in an equation to be sure they are defined as variables or parameters within the model

\bug The MML parser strips whitespace as it processes a file. Since if/else/elseif blocks can be delimited by whitespace, the regex won't find those keywords if the block isn't wrapped in parentheses or brackets. For example:
	"Y = if (X=0) A+B
		else A*C"
	becomes "if(X=0)A+BelseA*C" and the validation tries to find a parameter/variable named 'BelseA' and fails.
	The alternative is to remove the word boundaries from the regex (or add the keywords to the separators passed to String->Split), but this erroneously strips keywords from variable names. ("x_abs" becomes "x_" and validation fails.)
*/
bool ModelData::validate_equation(System::String ^eqn){
	// keywords & operators pulled from mml_tokens.h (other items from there may need to be added)
	array<String^>^ operators = {"(", ")", "+", "-", "*", "/", "^", "<", ">", "=", "!", "&", "[", "]", " ", "\t", "\n"};

	Regex^ keyword_rx = gcnew Regex("\\b(?:abs|cos|else|elseif|exp|if|ln|log|PI|pow|sin|sqrt)\\b"); // regex to match keywords at word boundaries

	Regex^ num_rx = gcnew Regex("\\b[0-9]*\\.?[0-9]+\\b"); // regex to match floating point number, optional integer part, no sign

	array<String^>^ split_eqn = eqn->Split(operators, StringSplitOptions::RemoveEmptyEntries);

	for( int i = 0; i < split_eqn->Length; i++ ){
		if( num_rx->IsMatch(split_eqn[i]) || keyword_rx->IsMatch(split_eqn[i]) ){
			split_eqn[i] = String::Empty;
		}
		else if( split_eqn[i]->Contains(":") ){
			split_eqn[i] = split_eqn[i]->Substring( 0, split_eqn[i]->IndexOf(":") );
		}
	}
	Array::Sort(split_eqn);
	array<String^>^ operands = gcnew array<String^>(split_eqn->Length);
	int index = 0;
	int op = 0;
	while(index < split_eqn->Length){
		index = Array::LastIndexOf(split_eqn, split_eqn[index]);
		if(split_eqn[index] != String::Empty){
			operands[op] = split_eqn[index];
			op++;
		}
		index++;
	}
	Array::Resize(operands, op);

	bool operandMissing;
	for each(String^ operand in operands){
		operandMissing = true;
		//! \todo fix the search for operand names
		//if( varList->Find("Name", operand) || paramList->Find("Name", operand) ){
			//operandMissing = false;
		//}
		if(operandMissing){
			return false;
		}
	}

	return true;
}