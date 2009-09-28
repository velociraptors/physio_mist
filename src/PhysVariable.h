#pragma once

#include "stdafx.h"



//! Data structure representing physiological variables and parameters
/*!
	All PhysVariables should belong to an AnatomicalStruct.
	If a model doesn't define structure information, they should default to "Anatomical_entity"
	(first "real" node in ontology.xml)
	\note Does PhysVariable need to include a pointer to the owner/parent structure?
	(Should a variable know what structure owns it or if it's orphaned?)
*/
public ref class PhysVariable
{
public:
	//! Default constructor
	/*!
		This constructor isn't meant to be used and will probably be removed in the near future.
		All instances of this class need to have at least a name so that will be visible
		in various forms and dialog boxes.
	*/
	PhysVariable(void);

	//! Constructor
	/*!
		\see PhysVariable()
	*/
	PhysVariable(System::String^ name);

	//! Constructor
	/*!
		\see PhysVariable()
	*/
	PhysVariable(System::String^ name, System::String^ description, System::String^ formula, double value, System::String^ units);

	//! The name to be displayed and referenced by other variables/parameters
	property System::String^ Name;

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
	property double Value;

	//! SI units
	/*!
		Exact formatting details not yet determined.
		Unit conversion not yet implemented.
	*/
	property System::String^ Units;

};
