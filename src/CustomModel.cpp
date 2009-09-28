#include "stdafx.h"
#include "CustomModel.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

CustomModel::CustomModel(void)
{
	
}

CustomModel::CustomModel(String ^name)
{
	Name = name;
	
}

void CustomModel::addStructure(AnatomicalStruct^ structure)
{
	(*Structures).Add(structure);
}

void CustomModel::removeStructure(AnatomicalStruct^ structure)
{
	(*Structures).Remove(structure);
}

AnatomicalStruct^ CustomModel::findStruct(String ^name)
{
	for each(AnatomicalStruct^ a in Structures)
	{
		if(a->Name == name)
		{
			return a;
		}
	}
	return nullptr;
}