#include "StdAfx.h"
#include "PhysVariable.h"
using namespace System;
PhysVariable::PhysVariable(void)
{
	Name = nullptr;
	Desc = nullptr;
	Formula = nullptr;
	Value = NULL;
	Units = nullptr;
}

PhysVariable::PhysVariable(String ^name)
{
	Name = name;
	Desc = nullptr;
	Formula = nullptr;
	Value = NULL;
	Units = nullptr;
}

PhysVariable::PhysVariable(String ^name, String ^description, String ^formula, double value, String ^units)
{
	Name = name;
	Desc = description;
	Formula = formula;
	Value = value;
	Units = units;
}
