#pragma once

#include "Link_layer.h"
#include <vcclr.h>

//test
//! Data structure representing physiological variables and parameters
/*!
	All PhysVariables should belong to an AnatomicalStruct.
	If a model doesn't define structure information, they should default to "Anatomical_entity"
	(first "real" node in ontology.xml)
	\note Does UI_Variable need to include a pointer to the owner/parent structure?
	(Should a variable know what structure owns it or if it's orphaned?)
*/
public ref class UI_Variable
{
public:
	//! Default constructor
	/*!
		This constructor isn't meant to be used and will probably be removed in the near future.
		All instances of this class need to have at least a name so that will be visible
		in various forms and dialog boxes.
	*/
	UI_Variable(void);


	//! Constructor
	/*!
		\see UI_Variable()
	*/
	//UI_Variable(System::String^ name);


	//! Constructor
	/*!
		\see UI_Variable()
	*/
	//UI_Variable(System::String^ name, System::String^ description, System::String^ formula, double value, System::String^ units);


	//! The name to be displayed and referenced by other variables/parameters
	property System::String^ Name{
		System::String^ get(){
			return gcnew System::String(component->get_name());
		}

		void set(System::String ^_name){
			component->set_name((char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( _name).ToPointer());
		}
	
	};

	//! A description of the variable, details about use, etc
	/*!
		The description will (eventually) be parsed from the comments in an MML file
	*/
	property System::String^ Desc;

	//! A mathematical formula or differential equation used to calculate the value of a variable
	/*!
		Exact formatting details not yet determined.
		If the formula is null/blank, the object is a parameter with a constant value.
	*/
	property System::String^ Formula;
	//! Initial value of a variable; only value of a parameter
	property double Value{
		double get(){
			return *(component->get_value());
		}

		void set(double _value){							
			component->get_variable()->set_variable(_value);
		}
	
	};

	//! SI units
	/*!
		Exact formatting details not yet determined.
		Unit conversion not yet implemented.
	*/
	property System::String^ Units{
		System::String^ get(){
			return gcnew System::String(component->get_variable()->get_unit());
		}

		void set(System::String ^_unit){
			component->get_variable()->set_unit((char *)System::Runtime::InteropServices::Marshal::
				StringToHGlobalAnsi( _unit).ToPointer());
		}
	};

	//!Anatomical information
	/*!
		User determined anatomical association for the physiological variables
		Selection from the ontology tree determines it
	*/
	property Anatomical_structure *structure{
		Anatomical_structure* get(){
			return component->get_anatomical_structure();
		}

		void set(Anatomical_structure *str){
			component->set_anatomical_structure(str);
		}
	};

	property System::String^ str_name{
		void set(System::String ^_str_name){
			if(component->get_anatomical_structure()!=NULL){
				component->get_anatomical_structure()->set_name((std::string *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( _str_name).ToPointer());
			}			
		}

		System::String^ get(){
			if(component->get_anatomical_structure()!=NULL){
				return gcnew System::String(component->get_anatomical_structure()->get_name()->c_str());
			}
			else{
				return nullptr;
			}
		}
	};

	property link_layer::Component *component;




};