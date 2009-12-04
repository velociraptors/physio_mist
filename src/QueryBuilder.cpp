#include "StdAfx.h"
#include "QueryBuilder.h"
#include "Query_Sender.cpp"

QueryBuilder::QueryBuilder(void)
{
}

void QueryBuilder::build_query(String ^structure, String ^type)
{
	String^ sQuery = "PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?results FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:"+structure+" fma:"+type+" ?results}";

	char *query = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sQuery);

	// pass query to subsystem via query_sender
	Query_Sender *query_sender = new Query_Sender();
	query_sender->call_query_engine(query);
}
