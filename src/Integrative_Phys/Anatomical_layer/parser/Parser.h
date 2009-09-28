//This program scans a Protege grammar and creates a complex syntax tree.
//The class builder then uses this syntax tree to write the C++ code.
//Author: Robin Hu


#ifndef PARSER_H
#define PARSER_H
#include "Scanner.h"
#include "ListContainer.h"
#include "utilities.h"
#include "specialfunctions.h"

//String container
class	XString
{
public:
	XString()			{ setString(""); }
	XString(const char	*str)	{ setString(str); }

	void	setString(const char *str)	{ strncpy(string,str,MAX_TOKEN_LEN); }
	char	*getString()				{ return string; }
private:
	char	string[MAX_TOKEN_LEN];
};

//a class to store slot data.
//for example, FMAID -> "4234"
/*
You can get/set the slot name.
add/get values of the slot.
*/
class SlotData
{
public:
	SlotData()		{ 
					setSlotName("");	
					 }
	/*constructor*/
	SlotData(const char *nSlotName,const char *nSlotValue)	{ 
						setSlotName(nSlotName); 
						addSlotValue(nSlotValue);
						}

	/*returns slot name.*/
	char *	getSlotName()	{return slotName; }


	/*returns a string representing the next slot value from the slotValues list.*/
	char *	getNextSlotValue()	
		{
		XString *tempStr = slotValues.getNextItem ();
		if (tempStr != NULL)
			return tempStr->getString ();
		else
			return "";
		}

	/*set slot name */
	void	setSlotName(const char *nSlotName)	{ strcpy(slotName,nSlotName); }

	/* insert a value to the slotValues list.*/
	void	addSlotValue(const char *nSlotValue)	{ slotValues.addItem (new XString(nSlotValue)); }

	void	resetSlotValuesCursor()			{ slotValues.resetCursor(); } //resets slotValues cursor.
	int		getValueCount()			{ return slotValues.countItems (); } //returns number of items in slotValues list.
private:
	char slotName[50];

	ListContainer<XString>	slotValues;
};

//Object to store class information. Will have class name, class parent, slots, slot values.
class BigClassObject
{
public:
	BigClassObject()	{ /*constructor*/ 
							setSingletonStatus(true); //singleton will be on by DEFAULT (2/4/2008) 
						}
	void	setClassName( const char* str)	{ strncpy(className,str,MAX_TOKEN_LEN); }
	void	setClassParent( const char* str)	{ strncpy(classParent,str,MAX_TOKEN_LEN); }
	char*	getClassName()		{ return className; }
	char*	getClassParent()	{ return classParent; }

	void	setSingletonStatus(bool flag)	{ singleton = flag; }
	bool	getSingletonStatus()			{ return singleton; }

	SlotData*	addSlot( SlotData* sD)	{ return slotList.addItem(sD); }
	SlotData*	getNextSlot()					
	{ 
		if (slotList.hasMoreVariables ())
			return slotList.getNextItem(); 
		else
			return NULL;
	}
	void		resetSlotCursor()				{ slotList.reset_iterator();}
private:
	char	className[MAX_TOKEN_LEN];
	char	classParent[MAX_TOKEN_LEN];
	bool	singleton;
	//ListContainer<SlotData>	slotList;
	Container<SlotData>	slotList;
};


///Parses the input text file. Returns a class object with class data.
class ProtegeParser
{
public:
	ProtegeParser();
	void openFileToParse(const char * fileName);
	void closeFile();
	BigClassObject * parseClass();	//parses a single class. Returns BigClassObject which has all the data.

private:
	ProtegeScanner PScanner;

	ProtegeToken tokenType;
	char tokenBuffer[MAX_TOKEN_LEN];

	char lineBuffer[MAXLINEBUF];
	ifstream	inputFile;
	void	getNextLine();
	char * getLineBuffer() { return lineBuffer; }
	char * getClassNameFromLine();
	char * getClassParentFromLine();
	char * getSlotNameFromLine();
	bool lineBufferContains(const char *str)	{ return strstr(getLineBuffer(),str); }

	void advanceToken();		//Gets next token from input file. Saves type in tokenType. Saves string in tokenBuffer.
	ProtegeToken getTokenType();
	char * getTokenString();

	BigClassObject * pClass();	//

	/*New method for parsing the FMA file. This is the ontology file that does not contain slot values.*/
	BigClassObject * parseData();


	//parse slots. 
//You pass in a BigClassObject. This function will fill in its slots and slot values.
	void	pClassAttr(BigClassObject	*bco);

	bool	isSlotConceptName(const char* slotName);


};



#endif //PARSER_H