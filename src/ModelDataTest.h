#pragma once

#include "ModelData.h"

using namespace System;
using namespace NUnit::Framework;

namespace NUnitTests{

	[TestFixture]
	public ref class ModelDataTest
	{
	public:
		ModelDataTest(void); // i think this needs to go away

		[Test] void load_MML();
		[Test] void load_XML();
		[Test] void load_var();
		[Test] void save_XML();
		[Test] void validate_eqn();
	};

}