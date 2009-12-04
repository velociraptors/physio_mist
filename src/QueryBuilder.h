#pragma once

using namespace System;

ref class QueryBuilder
{
public:
	QueryBuilder(void);
	void build_query(String^ structure, String^ type);
};
