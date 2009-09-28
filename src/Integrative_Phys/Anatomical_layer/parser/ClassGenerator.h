/*
Contributor(s):	Robin Hu
				E. Zeynep Erson
Descriptions:
				
*/
#ifndef CLASSGENERATOR_H
#define CLASSGENERATOR_H
#include "stdheader.h"



#define	FLAG_CLEARLIST	0
#define	FLAG_APPENDLIST	1

/*The purpose of this class is to work with
the Protege files, like fmaclasses.txt and the files in the folder Classdefs.
The functions here mainly search through the Protege files and copy the information into a temp file.
That temp file can then be parsed using the Parser class.
*/
class ClassGenerator
{
public:
	ClassGenerator();

	/*A function that will get the FMAID of a structure, because it is important
	returns an instance of the FMAID object*/
	FMAID*	getFMAIDof(const char* structure);



	/*
	Gets all the parents of className 
	and puts them in cListParentClasses.
	You have two options: Clearing the list before adding the parents,
	or simply appending the parents to the list. Default is clear list.
	This function uses the Tree View List to find the parents of a structure. So
	before using this, you need to specify the handle to the tree view control using setTreeViewHandle.

	*/
	void	getParentsOf(char *className, int insertFlag = FLAG_CLEARLIST);


	//Generates a temp file for only ONE structure. Uses the Protege Instance files.
	//This function is quite useful. filename specifies the name of the temp file.
	void	generateTempFileSingle(const char* structure,const char* filename);


	/*
	The purpose of this function is to look at the temporary file (if it exists)
	and extract all the slot information. The slot information is placed in cListSlotClasses.
	No longer used.
	*/
	void	getSlotInfoFromTempFile();

	/*
	This function goes through the entire slot list (cListSlotClasses)
	and puts their parents into cListParentClasses.*/
	void	getParentsFromSlotList();


	//Use this to check if a slotvalue is of the type KB_INSTANCE, or some other weird name that we don't want to deal with.
	bool	isParentConceptName(const char *classname);
private:
	SlotAttributes	slotInfoStruct;

	
	bool	isInMainList(const char* classname);
};


#endif