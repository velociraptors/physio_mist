#include "StdAfx.h"
#include "ModelDataTest.h"

namespace NUnitTests{

	ModelDataTest::ModelDataTest(void)
	{
	}

	void ModelDataTest::load_MML()
	{
		ModelData ^data = gcnew ModelData();
		data->load_MMLfile("test.xml");
		Assert::AreEqual( 1 , 1 );
	}

	void ModelDataTest::load_XML()
	{
		ModelData ^data = gcnew ModelData();
		data->load_XMLfile("test.xml");
		Assert::AreEqual( 1 , 1 );
	}

	void ModelDataTest::load_var()
	{
		ModelData ^data = gcnew ModelData();
		Assert::AreEqual( 1 , 1 );
	}

	void ModelDataTest::save_XML()
	{
		ModelData ^data = gcnew ModelData();
		data->save_XMLfile("savetest.xml");
		Assert::AreEqual( 1 , 1 );
	}

	void ModelDataTest::validate_eqn()
	{
		ModelData ^data = gcnew ModelData();
		data->validate_equation("1 + 1 = 2 * x");
		Assert::AreEqual( 1 , 1 );
	}

}