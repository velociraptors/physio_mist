//#ifndef _ANATOMICALSTRUCT_H
//#define _ANATOMICALSTRUCT_H
#pragma once

#include "UI_Variable.h"
#include "stdafx.h"
#include "utilities.h"


//using namespace System::Collections::Generic;

//! Data structure representing anatomical structures
/*!
	More detail needed?
	\todo Implement method of getting physiological data ("slots") from FMA info (this is going to be a messy process)
*/
public ref class AnatomicalStruct
{
public:
	//! Default constructor
	/*!
		Instantiates List objects, sets Name to "default name"
		\todo Implement constructors as in UI_Variable
	*/
	AnatomicalStruct(void);

	//decleration based on the definitions in fmaid.h using mscorlib
	/*
	//! From FMA info? Details & usage?
	property List<FMAID^>^ venous_drainage;
	//! From FMA info? Details & usage?
	property List<FMAID^>^ nerve_supply;
	//! From FMA info? Details & usage?
	property List<FMAID^>^ arterial_supply;
	*/
	//! From FMA info? Details & usage?
	property Phys_Container<FMAID>* venous_drainage;
	//! From FMA info? Details & usage?
	property Phys_Container<FMAID>* nerve_supply;
	//! From FMA info? Details & usage?
	property Phys_Container<FMAID>* arterial_supply;


	//! Name to be displayed in various forms & dialog boxes
	/*!
		Should be from names in ontology.xml
	*/
	property System::String^ Name;

	/*//! Physiological variables associated with the structure
	property System::Collections::Generic::List<UI_Variable^ >^ VarsList;
	//! Parameters associated with the structure
	property System::Collections::Generic::List<UI_Variable^ >^ ParamList;

	void addVar(UI_Variable^ var);
	bool removeVar(UI_Variable^ var);
	UI_Variable^ findVar(System::String^ name);

	void addParam(UI_Variable^ param);
	bool removeParam(UI_Variable^ param);
	UI_Variable^ findParam(System::String^ name);*/
};
//#endif