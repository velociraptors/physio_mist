#include "StdAfx.h"
#include "QueryBuilder.h"
#include "Query_Sender.cpp"

QueryBuilder::QueryBuilder(void)
{
}

void QueryBuilder::build_query(String ^structure, String ^type)
{
	// process strings
	//char* structure = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(qName);
	//char* type = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(qType);

	// build query
	//char *prefix = "PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> ";
	//char *select = "SELECT ?results ";
	//char *from = "FROM <http://sig.biostr.washington.edu/fma3.0> ";
	//char *test = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?esoph_continuity  FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:Aorta  fma:continuous_with ?esoph_continuity}";
	//char *query = prefix + select + from + "WHERE {fma:"+structure + " fma:"+type + "?results}";

	String^ sQuery = "PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?results FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:"+structure+" fma:"+type+" ?results}";

	char *query = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sQuery);

	// pass query to subsystem via query_sender
	Query_Sender *query_sender = new Query_Sender();
	query_sender->call_query_engine(query);
}
