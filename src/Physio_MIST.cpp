// Physio_MIST.cpp : main project file.

#include "stdafx.h"
#include "Main_Form.h"
#include "Query_Builder.cpp"



using namespace Physio_MIST;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;	
	




[STAThreadAttribute]
int main()
{


	Query_Builder *query_builder = new Query_Builder();
	char *q_str = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?esoph_continuity  FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:Aorta  fma:continuous_with ?esoph_continuity}";
	query_builder->call_query_engine(q_str);

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	Application::Run(gcnew Main_Form());

	return 0;
}
