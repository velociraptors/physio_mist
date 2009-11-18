#include "StdAfx.h"
#include "UIvarTest.h"

namespace NUnitTests{
	UIvarTest::UIvarTest(void)
	{
	}

	void UIvarTest::change_component()
	{
	}

	void UIvarTest::change_description()
	{
	}

	void UIvarTest::change_Name()
	{
		UI_Variable ^var = gcnew UI_Variable();
		var->Name = "heart";
		Assert::AreEqual("heart", var->Name);
	}

	void UIvarTest::change_structure()
	{
		// forcing this test to intentionally fail
		//UI_Variable ^var = gcnew UI_Variable();
		//int *x = nullptr;
		//var->structure = nullptr;
		Assert::AreEqual(3, 10);
	}

	void UIvarTest::change_Units()
	{
		UI_Variable ^var = gcnew UI_Variable();
		var->Units = "feet";
		Assert::AreEqual("feet", var->Units);
	}

	void UIvarTest::change_Value()
	{
		UI_Variable ^var = gcnew UI_Variable();
		var->Value = 11;
		Assert::AreEqual(11, var->Value);
	}
}