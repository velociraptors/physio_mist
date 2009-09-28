//Parses a Protege file and generates C++ code.
//Author: Robin Hu
//Requires the protege source file AND the slot definitions file.
//Every slot must be defined in the slot definitions file.

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "Parser.h"
#include "SlotAttributes.h"

/*Purpose: ClassBuilder was a class I wrote to automatically generate C++ source and header files.
It may still be useful in the future. This class was used to generate the files in the folder "classheader"*/
class ClassBuilder
{
public:
	ClassBuilder();
	ClassBuilder(char *protegeFileName, char *slotResource);
	void buildToFiles(const char *directory);	//call this function to build the C++ class files.
private:
	ProtegeParser PParser;			//parser, used to create syntax tree.
	SlotAttributes	SlotArray;		//used to determine slot type, memory allocation style (hasptr, noptr).
	ofstream	outHFile;			//file descriptor for the header file.
	ofstream	outCppFile;			//file descriptor for the cpp file.

	void   buildSlots(BigClassObject	*bco);		//writes all the class members in the class definitions. (All the stuff that appears under "private:")
	bool	slotUsesList(SlotData * sd);	//determines if a slot needs to be declared as a ListContainer, because it has more than one value.
	void	buildGetSetMethods(BigClassObject *bco);	//writes all the get, set, add, reset methods. All the stuff that goes under "public:".
	void	buildConstructor(SlotData	*sd);	//writes the constructor.
	void	writeEnumDefs(const char *directory);					//writes enum declarations into another header file.

	bool	classIsSameAsParent(const char* className, const char* classParent);
};






#endif  //INTERPRETER_H