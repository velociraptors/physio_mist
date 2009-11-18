#pragma once

#include "UI_Variable.h"

using namespace System;
using namespace NUnit::Framework;

namespace NUnitTests {
	[TestFixture]
	public ref class UIvarTest
	{
	public:
		UIvarTest(void);
		[Test] void change_component();
		[Test] void change_description();
		[Test] void change_Name();
		[Test] void change_structure();
		[Test] void change_Units();
		[Test] void change_Value();
	};

}