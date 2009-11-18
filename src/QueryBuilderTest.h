#pragma once


using namespace System;
using namespace NUnit::Framework;

namespace NUnitTests {
	[TestFixture]
	public ref class QueryBuilderTest
	{
	public:
		QueryBuilderTest(void);
		[Test] void create_Query();
		[Test] void display_Results();
	};
}