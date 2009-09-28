#include "FMA_Reader.h"

FMA_Reader::FMA_Reader(String^ _filename){
	filename = _filename;
	reader = gcnew IO::StreamReader(filename);
}

FMA_Reader::~FMA_Reader(){

}

Generic::List<SlotData^> ^ FMA_Reader::read_structure(System::String ^_structure_name){
	//replace the space characters with "+"
	structure_name =  _structure_name->Replace(' ','+');
	String^ parent = locate_structure();
	Generic::List<SlotData^> ^slot_data = read_slot_data(); 
	return slot_data;
}

//returns the parent of the located structure
String^ FMA_Reader::locate_structure(){

	String^ line;
	String^ str_name;

	while(!reader->EndOfStream){
		line = reader->ReadLine();
		if(line->Contains(STRUCTURE_DELIM)){
			str_name = read_structure_name(line);
			if(String::Compare(str_name,structure_name)==0){
				return read_parent(line);
				
			}
		}
	}//WHILE

	return nullptr;
}

String^ FMA_Reader::read_parent(System::String ^line){
	int end = line->IndexOf(STRUCTURE_END_DELIM);
	//remove "of"
	String^ parent = line->Substring(end+5);
	
	return parent;
}
String^ FMA_Reader::read_structure_name(String^ line){
	//tokenize between "([" and "]"
	String^ name;
		int str_index = line->IndexOf(STRUCTURE_DELIM);
		name = line->Substring(str_index+2);

		int str_end = name->IndexOf(STRUCTURE_END_DELIM);
		int length = name->Length;
		name = name->Substring(0,length-(length-str_end));
		name = name->Trim(' ');
	return name;
}


FMAID FMA_Reader::read_FMAID(){
	return NULL;
}
	
Generic::List<String ^>^ FMA_Reader::read_slot_names(){
	return nullptr;

}
	
Generic::List<String ^>^  FMA_Reader::read_slot_value(String ^slot_name){
	return nullptr;
}

Generic::List<SlotData^>^ FMA_Reader::read_slot_data(){
	bool structure_end = false;
	Generic::List<SlotData^>^ slot_data = gcnew Generic::List<SlotData^>;
	while(!structure_end){
		SlotData ^slot = gcnew SlotData();
		structure_end = read_single_slot(slot);
		slot_data->Add(slot);
	}

	return slot_data;
}


bool FMA_Reader::read_single_slot(SlotData^ slot_data){
	bool structure_end = false;
	bool slot_started = false;
	bool slot_ended = false;
	System::String ^slot_name;
	String ^line = reader->ReadLine();

	while(String::Compare(line,"")==0)
	{
		line = reader->ReadLine();
	}

	slot_started = line->Contains(SLOT_DELIM);
	//slot_ended = line->Contains(END_DELIM);

	while(slot_started && !slot_ended){		
		int start_index = line->IndexOf(SLOT_DELIM);
		//first line of slot decleration
		if(start_index > 0){
			//get the name
			System::String ^new_line = line->Substring(start_index+1);
			array<Char>^delim = {' ','\t','\n'};
			int index = new_line->IndexOfAny(delim);
			if(index > 0){
			slot_name =  new_line->Substring(0,index+1);
			}
			else{
				slot_name = new_line;
			}
			slot_data->name = slot_name->Trim(' ');
			line = line->Substring(start_index+slot_name->Length+1);
		}

		//parse the value
		System::String ^value;

		array<Char>^trim_chars = {'[','\t',']','"',')'};
		value = line->Trim(trim_chars);
		if(System::String::Compare("",value)!=0){
			slot_data->values->Add(value);
		}
		
		if(line->Contains(END_DELIM)){
			slot_ended = true;
			if(line->Contains("))")){
				structure_end = true;

			}
		}		
		else{
			line=reader->ReadLine();
		}
	}
	return structure_end;
}
/*SlotData^ FMA_Reader::read_single_slot(){
	SlotData^ slot_data = gcnew SlotData();
	bool slot_started = false;
	bool slot_ended = false;
	String ^name;
	String^ line = reader->ReadLine();
	while(String::Compare(line,"")==0)
	{
		line = reader->ReadLine();
	}


	int start_index = line->IndexOf(SLOT_DELIM);
	if(start_index>0){		
		slot_started = true;
		System::String ^new_line = line->Substring(start_index+1);
		//READ FROM START_INDEX UNTIL SPACE OR TAB-->THIS IS THE NAME
		array<Char>^delim = {' ',')','\t','\n'};
		int end_index = new_line->IndexOfAny(delim);
		System::String ^slot_name;
		if(end_index>0){
			slot_name = new_line->Substring(0,end_index);			
			if(new_line->Length > end_index+1){				
				System::String ^value = new_line->Substring(end_index+1);
				if(new_line->Contains(")")){
					slot_ended = true;
					value  = value->Trim(')');
				}
				slot_data->values->Add(value);
			}
		}
		else{
			slot_name = new_line->Trim('\t');
		}
		slot_data->name = slot_name;
		if(!slot_ended){
			line = reader->ReadLine();
			while(!line->Contains(END_DELIM)){
				array<Char>^trim_chars = {'[','\t',']'};
				line = line->Trim(trim_chars);
				slot_data->values->Add(line);
				line = reader->ReadLine();
			}
			array<Char>^trim_chars = {'[','\t',']',')'};
			line = line->Trim(trim_chars);
			slot_data->values->Add(line);
		}

					
	}

	return slot_data;
}*/