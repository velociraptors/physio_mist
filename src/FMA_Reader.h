#ifndef _FMA_READER_H_
#define _FMA_READER_H_

#define STRUCTURE_DELIM "(["
#define SLOT_DELIM "("
#define END_DELIM ")"
#define STRUCTURE_END_DELIM "]"

#include "utilities.h"
#include "SlotData.h"


using namespace System;
using namespace System::Collections;


public ref class FMA_Reader
{
public:
	FMA_Reader(String ^filename);
	~FMA_Reader();

	Generic::List<SlotData^> ^ read_structure(String^ structure_name);


	property String^ structure_name;


private:
	String^ locate_structure();
	String^ read_structure_name(String^ line);
	FMAID read_FMAID();
	String^ read_parent(String^ line);
	bool read_single_slot(SlotData^ data);
	Generic::List<SlotData^>^ read_slot_data();
	Generic::List<String ^>^ read_slot_names();
	Generic::List<String ^>^ read_slot_value(System::String^ slot_name);

	property String^ filename;
	property IO::StreamReader^ reader;
	


};
#endif