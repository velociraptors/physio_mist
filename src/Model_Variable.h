#pragma once
#include "UI_Variable.h"

using namespace System;

ref class Model_Variable : public UI_Variable
{
public:
	Model_Variable(void);

	//property String^ ModelName;
	property bool isConstant;
};
