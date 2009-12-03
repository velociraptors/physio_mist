#include "StdAfx.h"
#include "QueryBuilder.h"
#include "Query_Sender.cpp"

QueryBuilder::QueryBuilder(void)
{
}

void QueryBuilder::build_query(String ^qName, String ^qType)
{
	// process strings
	char* structure = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(qName);
	char* type = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(qType);

	// build query
	char *prefix = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#>";
	char *results = "?results";
	char *from = "FROM <http://sig.biostr.washington.edu/fma3.0>";
	char *query = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?esoph_continuity  FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:Aorta  fma:continuous_with ?esoph_continuity}";

	// pass query to subsystem via query_sender
	Query_Sender *query_sender = new Query_Sender();
	query_sender->call_query_engine(query);
}
