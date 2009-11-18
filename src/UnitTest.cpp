// UnitTest.cpp - Test Loading and Saving of XML files
//

#include "stdafx.h"
#include "ModelData.h"
#include "tchar.h"
#include <fstream>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	ModelData testData;
	//testData = gcnew ModelData::ModelData( "test.xml", true );
	testData.load_XMLfile("test.xml");
	
	ofstream out( "logfile.txt",ios::ate);
	out << "Load XML - PASS! \n";

	testData.save_XMLfile("savetest.xml");

	out << "Save XML - PASS! \n";
	out.close();
	return 0;

}

