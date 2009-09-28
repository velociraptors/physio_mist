#include "StdAfx.h"
#include "Model_Variable.h"

Model_Variable::Model_Variable(void)
{
	component = new link_layer::Component();
	Desc = nullptr;
	Formula = nullptr;
	isConstant = false;
	//ModelName = nullptr;
}
