#include "Parser.h"

//member functions for parser.
//Constructor.
ProtegeParser::ProtegeParser ()
{
	tokenType = T_ERROR;
	strcpy(tokenBuffer,"");
}

//gets next token. Stores the next token type into tokenType.
//Stores token string into tokenBuffer.
void ProtegeParser::advanceToken ()
{

	tokenType = PScanner.getNextToken (tokenBuffer);
}

/*Gets next line from the input file. The line is saved in the global var lineBuffer.
lineBuffer can be accessed using the method getLineBuffer().*/
void ProtegeParser::getNextLine() 
{
	if (inputFile.is_open() && !inputFile.eof()) //checks if file is open and file ptr is not at EOF.
	{
		inputFile.getline(lineBuffer,MAXLINEBUF);	//get next line and save it in lineBuffer.
		//if ( strcmp(lineBuffer,"") == 0) getNextLine(); //a little recursion
	}
}

//Returns the current token type.
ProtegeToken ProtegeParser::getTokenType ()
{
	return tokenType;
}

//Returns the current token string.
char * ProtegeParser::getTokenString ()
{
	return tokenBuffer;
}

//opens file to parse.
void ProtegeParser::openFileToParse(const char *fileName)
{
	PScanner.openFile (fileName);
	inputFile.open(fileName);
}

//closes the file that was opened.
void ProtegeParser::closeFile()
{
	PScanner.closeFile();
	inputFile.close();
}

//parses the grammar, returns pointer to root of the syntax tree.
BigClassObject * ProtegeParser::parseClass() 
{
	//return pClass();
	return parseData();
}

//parse a single class and store data in BigClassObject
/*Use this if you want to parse a file that is from fmaclasses.txt. 
The Ontology file format.
This method does NOT use the Scanner class.*/
BigClassObject * ProtegeParser::parseData() 
{
	BigClassObject *classData = new BigClassObject();	//Create new BigClassObject to save data.
	bool parseIsOkay = false;							//variable to determine if parsing is going well.
	getNextLine();		//Get next line from file.
	if ( lineBufferContains("defclass") )
	{
			//if 'defclass' line is found, extract class name.	
		classData->setClassName ( getClassNameFromLine() );

			//Check if class is the final class in the heiarchy. If it is, it should be designated "singleton"
		if (lineBuffer[0] == '[')//the final class starts with a '['.
		{
			classData->setSingletonStatus (true);	//set singleton status to true.
		}

		//move on
		getNextLine();

		if ( lineBufferContains("is-a") )
		{
			//parent found, so save the name of the parent.
			classData->setClassParent ( getClassParentFromLine() );
			getNextLine();
			if (lineBufferContains("role")) parseIsOkay = true;
		}
	}

	//so far so good, continue gathering slot data
	if (parseIsOkay)
	{
		parseIsOkay = false;
		while(true)	//Loop through all the slots.
		{
			getNextLine();
			if (lineBufferContains("slot"))
			{
				//save slot name
				SlotData *s = new SlotData();
				s->setSlotName (getSlotNameFromLine());
				classData->addSlot (s);
				while(true)
				{
					getNextLine();
					if (lineBufferContains("))")) break;	//skip all slot attributes
				}
			}
			else 
			{
				break;
			}
		}
		parseIsOkay = true;
	}

	if (parseIsOkay)
		return classData;
	else
		return NULL;
}

//Looks at lineBuffer and extracts the class name from it.
char * ProtegeParser::getClassNameFromLine() 
{
	const char delims[] = " (";
	char *pch;

	pch = strtok(getLineBuffer(),delims);
	pch = strtok(NULL,delims);
	replaceChars(pch,'+','_');
	return pch;
}

//Looks at lineBuffer and extracts the class parent from it.
char * ProtegeParser::getClassParentFromLine ()
{
	const char delims[] = " ()\t";
	char *pch;

	pch = strtok(getLineBuffer(),delims);
	pch = strtok(NULL,delims);
	replaceChars(pch,'+','_');
	return pch;
}

//Looks at lineBuffer and extracts the slot name from it.
char * ProtegeParser::getSlotNameFromLine() 
{
	const char delims[] = " ()\t";
	char *pch;

	pch = strtok(getLineBuffer(),delims);
	pch = strtok(NULL,delims);
	replaceChars(pch,'+','_');
	replaceChars(pch,'-','_'); //replace "3-D" with "3_D"
	return pch;
}

//parse a class definition. This is the old method, used for the Protege instance file.
//THe pins file contains slot defs AND their values. THe pont file does not. 
//This method uses the Scanner class.
BigClassObject * ProtegeParser::pClass()
{
	BigClassObject	*classdata = NULL;	//class data is initially NULL.
			///if there is a parsing error, then this function returns NULL.

	bool parseOkay = false;

	advanceToken();
	if ( getTokenType() == T_LP )
	{
		// "(" is found.
		parseOkay = true;
	}

	if (parseOkay)
	{
		parseOkay = false;
		advanceToken();
		if ( getTokenType() == T_CLASS)
		{							//a class is found.Classes are between brackets.
			parseOkay = true;
			classdata = new BigClassObject();		//create new class object since everything is okay so far.
			classdata->setClassName (getTokenString());//if class is found, it is the class name. Save it in the class data obj.
		}
	}
	

	//checks for parent relationship.
	if (parseOkay)
	{
		parseOkay = false;
		advanceToken();
		if ( getTokenType() == T_OF)
		{
			advanceToken();
			if ( getTokenType() == T_ID)	//parent relation found, set inheritance
			{
				classdata->setClassParent (getTokenString());
				parseOkay = true;
			}
		}
	}

	if (parseOkay)
	{
		parseOkay = false;
		advanceToken();
		if ( getTokenType() == T_LP )
		{
			cout << "Parsing Attributes" << endl;
			
			pClassAttr(classdata);	//parse class attributes
		}
	}
	
	if (classdata != NULL)  cout << "Finished Parsing class: " << classdata->getClassName () << endl;
	cout << "********************************" << endl;

	return classdata;	//returns classdata. NULL if there was a parsing error (or end of file reached).
}

//parse slots. Depreciated.
//You pass in a BigClassObject. This function will fill in its slots and slot values.
//This is used in the old method pClass(). It is NOT used in parseData().
void ProtegeParser::pClassAttr(BigClassObject	*bco) 
{

	bool parseOkay = false;

	advanceToken();	//advance before even looking at anything. Assumes file ptr is at the first "("

	if ( getTokenType() == T_ID )
	{
		cout << "Attribute: " << getTokenString() << endl;

		char	*slotname = getTokenString();	//gets slot name.

		/*If we find a concept name, we should ignore it.*/
		if ( isSlotConceptName(slotname) )
		{	//skip over the entire slot and all its values.
			while (true)
			{
				advanceToken();
				if ( getTokenType() == T_RP )	break;//loop through unecessary tokens until we find a left parenthesis.
			}
			
		}
		else
		{
			SlotData *slotdataObj = bco->addSlot (new SlotData(slotname,""));	//add a slot to the class data object.

			advanceToken();
			while ( getTokenType() != T_RP )	//if there are multiple slot values, this loop will continue to add them.
			{
				slotdataObj->addSlotValue (getTokenString());	//insert a slot value.
				advanceToken();					//if the next token ISN'T a ")", add more attributes.
			}
		}
		parseOkay = true;
	}

	if (parseOkay = true)
	{
		parseOkay = false;
			//file ptr should be at ")" right now.
		advanceToken();	//a few possibilities here. You will either find a "(", or another ")"
		if ( getTokenType() == T_LP )	
		{
			//if a "(" is found, that means there are still more attributes.
			pClassAttr(bco);	//recursive call.
		}
		else if ( getTokenType() == T_RP)
		{
			parseOkay = true;
		}
	}

	return;

}

//Determines if a slot is a concept name. We may want to ignore those.
bool	ProtegeParser::isSlotConceptName(const char *slotName) 
{
	char* conceptNames[] = {"Preferred","Synonym","equivalent","location","attributed","orientation"};
	const int sizeOfList = sizeof(conceptNames)/sizeof(conceptNames[0]);

	for (int i = 0; i < sizeOfList ; i++)
	{
		if ( strstr(slotName,conceptNames[i]) )	//a match is found
		{
			return true;
		}
	}
	return false;

}
