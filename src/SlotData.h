/*
Date:			March 04. 2009
Author(s):		Zeynep Erson
Description:	SlotData holds the name and values of the attributes of the anatomical structure
			in the FMA ontology represented which is represented with slots and values in the frame
			based representation(Protege).
*/
#ifndef	_SLOTDATA_H
#define _SLOTDATA_H

using namespace System;
using namespace System::Collections;


public ref class SlotData
{
public:
	SlotData(){
		name = nullptr;
		type = nullptr;
		values = gcnew Generic::List<String ^>();
	
	};
	SlotData(String^ slotName, String^ slotType, Generic::List<String ^> ^slotvalues){
		name = slotName;
		type = slotType;
		values = slotvalues;

	};

	property String^ name;
	property String^ type;
	property Generic::List<String ^> ^values;

};


#endif