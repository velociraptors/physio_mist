#include "StdAfx.h"
#include "AnatomicalStruct.h"

using namespace System;
using namespace System::Collections::Generic;


AnatomicalStruct::AnatomicalStruct(void)
{
	Name = "default name";

	/*arterial_supply = gcnew List<FMAID^>();
	nerve_supply = gcnew List<FMAID^>();
	venous_drainage = gcnew List<FMAID^>();
	*/

	arterial_supply = new Phys_Container<FMAID>;
	nerve_supply = new Phys_Container<FMAID>();
	venous_drainage = new Phys_Container<FMAID>();

	/*VarsList = gcnew List<UI_Variable^>();
	ParamList = gcnew List<UI_Variable^>();*/
}

/*void AnatomicalStruct::addVar(UI_Variable ^var)
{
	(*VarsList).Add(var);
}

bool AnatomicalStruct::removeVar(UI_Variable ^var)
{
	return (*VarsList).Remove(var);
}

UI_Variable^ AnatomicalStruct::findVar(String ^name)
{
	for each(UI_Variable^ var in VarsList)
	{
		if(var->Name == name)
		{
			return var;
		}
	}
	return nullptr;
}

void AnatomicalStruct::addParam(UI_Variable ^param)
{
	(*ParamList).Add(param);
}

bool AnatomicalStruct::removeParam(UI_Variable ^param)
{
	return (*ParamList).Remove(param);
}

UI_Variable^ AnatomicalStruct::findParam(String ^name)
{
	for each(UI_Variable^ param in ParamList)
	{
		if(param->Name == name)
		{
			return param;
		}
	}
	return nullptr;
}*/