#pragma once
//#include "AnatomicalStruct.h"


//! Data structure representing a physiological model
/*!
	Created & edited via the GUI or loaded from an MML file
	\todo Implement loading/saving & parsing MML
*/
public ref class CustomModel
{
public:
	//! Default constructor
	/*!
		\todo Implement constructor that sets the model Name as in UI_Variable
	*/
	CustomModel(void);

	//! Constructor
	/*!
		Should eventually replace the default constructor?
	*/
	CustomModel(System::String^ name);

	void addStructure(AnatomicalStruct^ structure);
	void removeStructure(AnatomicalStruct^ structure);
	AnatomicalStruct^ findStruct(System::String^ name);

	//! PhysVariables belong to AnatomicalStructs which belong to CustomModel
	property System::Collections::Generic::List<AnatomicalStruct^>^ Structures;
	//! Same as the name of the MML file for saving/loading (?)
	property System::String^ Name;
};
