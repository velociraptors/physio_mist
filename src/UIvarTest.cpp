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
		str_name name = new str_name();
		name.set("heart");
		Assert::AreEqual("heart", name.get());
	}

	UIvarTest::change_structure()
	{
		Anatomical_structure structure = new Anatomical_structure();
		*x = null;
		Anatomical_structure.set(x);
		Assert::AreEqual(x, Anatomical_structure.get());
	}

	UIvarTest::change_Units()
	{
		Units units = new Units();
		units.set("feet");
		Assert::AreEqual("feet", units.get());
	}

	UIvarTest::change_Value()
	{
		Value value = new Value();
		//completely made up 11, maybe should change this?
		value.set(11);
		Assert::AreEqual(11, value.get());
	}
}