#include "StdAfx.h"
#include "UIvarTest.h"

namespace NUnitTests{
	UIvarTest::UIvarTest(void)
	{
	}

	UIvarTest::change_component()
	{
	}

	UIvarTest::change_description()
	{
	}

	UIvarTest::change_Name()
	{
	}

	UIvarTest::change_structure()
	{
	}

	UIvarTest::change_Units()
	{
		String^ Units units = new String^ Units();
		units.set(
	}

	UIvarTest::change_Value()
	{
		Value value = new Value();
		//completely made up 11, maybe should change this?
		value.set(11);
		Assert::AreEqual(11, value.get());
	}
}
}