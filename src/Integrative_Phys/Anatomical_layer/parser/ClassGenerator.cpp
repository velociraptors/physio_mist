/*
Contributor(s):	Robin Hu
				E. Zeynep Erson
Descriptions:
				
*/
#include "ClassGenerator.h"

ClassGenerator::ClassGenerator ()
{
	//constructor
	slotInfoStruct.loadSlots ("slotConfig.inf");
}


/*Finds the parents of a class, puts them into a listbox (which is sorted alphabetically).
The list box will be invisible and act like a data structure.
*/
void	ClassGenerator::getParentsOf(char *className, int insertFlag) 
{
	if (insertFlag == FLAG_CLEARLIST)
	{
		cListParentClasses.clearList ();		//clears list box.
	}
	else
	{
		//don't do anything
	}
		

	/* Search the tree for className. 
	hClass will store the handle to that tree item. */
	HTREEITEM	hClass = cTreeViewWindow.searchTreeForText ( cTreeViewWindow.getRootOfTree (), className);

	if (hClass == NULL) return;		//if the class name was not found in the tree, exit function.
	
	/*
	*Store class name into bufClassName.
	*/
	char bufClassName[MAX_FORMULA_LEN];
	strcpy(bufClassName,cTreeViewWindow.getTextFromHandle (hClass) );
	//insertPlusSigns(bufClassName);	//adds "+" chars to the Class Name
	cListParentClasses.addExclusiveItem ( bufClassName);	//insert class name into the list box.


	HTREEITEM hParent = cTreeViewWindow.getParentOfItem (hClass);	//get parent of class.

	while (hParent != NULL)
	{
		/*
		Finds all parents of class. Adds them to the list box.
		*/
		char buf[MAX_FORMULA_LEN];
		strcpy(buf,cTreeViewWindow.getTextFromHandle (hParent));
		//insertPlusSigns(buf);  //adds "+" chars to the Class Name
		cListParentClasses.insertToFront (buf);
		hParent = cTreeViewWindow.getParentOfItem (hParent);
	}
}

/*Given a structure name, obtain the FMAID of it. Important function.*/
FMAID* ClassGenerator::getFMAIDof(const char* structure)
{
	generateTempFileSingle(structure,"classes\\tmp.txt");		//Obtain the information, put it in temp file.
	ProtegeParser	parser;				
	FMAID	*f = new FMAID();				//added 3-17-2008. Tests to see if we can create instances of anatomical structures.
	parser.openFileToParse ("classes\\tmp.txt");
	BigClassObject	*bco = parser.parseProtegeFile();	//Parse the temp file. Obtain slot information
	if (bco == NULL)	return f;
	int id = bco->getID();

	f->set_id (&id);

	return f;
}

//given a listbox of class names, this function will generate the temporary file.
//The temporary file is what needs to be parsed.
void ClassGenerator::generateTempFileFromList (HWND hListBox)
{
	CtlListBox	clb;					//clb is a list box object.
	clb.setHandle ( hListBox );			//set the list box handle
	int listSize = clb.getItemCount ();	//get size of list.

	CreateDirectory("classes",NULL);	//create a directory

	char *tempFileName = PATH_OF_TEMPFILE;
	ofstream	tempFile;
	tempFile.open (tempFileName);		//opens the temporary file.
	if (!tempFile ) exit(0);

	ifstream	pinsFile;
	char pinsFileName[] = "Classdefs\\fmapins-A.txt";	
	pinsFile.open(pinsFileName);		//opens the class definitions file.
	const int locationOfChar = 18;		//location of the special letter in pinsFileName. 
	char *pinsDelimiter = "([";			
	char lastCharUsed = ' ';

	for (int i=0; i< listSize ; i++)
	{
		clb.setSelection (i);			//move list box selection.
		char className[MAX_FORMULA_LEN];
		clb.getSelectedText (className);	//retrive class name.
		insertPlusSigns(className);			//adds "+" chars to the class name.
		if ( strcmp(className,"") == 0) break;	//if className is blank, exit.
		strcat(className,"]");				//add a "]" to the end of className.

		char firstCharOfClassName = className[0];	//get the first char of className.
		convertToUpperCase(firstCharOfClassName);	//oonvert it to upper case.

		if ( firstCharOfClassName != lastCharUsed)	//if the first char of className is different from the last character used...
		{
			pinsFile.close();						//reopen the class def file.
			pinsFileName[locationOfChar] = firstCharOfClassName;	//replace the special character in the file name with a new letter.
			pinsFile.open(pinsFileName);
			if (!pinsFile) 
			{
				MessageBox(NULL,pinsFileName,"Can't OPen File",NULL);
				exit(0);
			}
			lastCharUsed = firstCharOfClassName;		//update last char used.
		}

		
		bool foundClass = false;
		bool classWritten = false;
		while (!pinsFile.eof())
		{

			char lineBuffer[MAXLINELEN] = "";
			pinsFile.getline(lineBuffer,MAXLINELEN);


			if ( strstr(lineBuffer,pinsDelimiter) )
			{
									//if the delimiter is found in the line
									//check if the line contains the class name.
				if ( strstr(lineBuffer,className) )
				{	//if the class name is found, start writing to the temp file.
					foundClass = true;
				}	 //end if
			}		//end if

			if (foundClass)
			{
				//write to tempfile.
				tempFile << lineBuffer << endl;
				classWritten = true;
			}

			if ( strstr(lineBuffer,"))") )
			{
				//if a line contains "))", it means the end of the class has been reached. Stop writing.
				if (classWritten) break;
			}
		}			//end while

	}
	
	MessageBox(NULL,"Search Completed","Search Completed",NULL);
	tempFile.close();
	pinsFile.close();
}

/*Look in the *.pins files library.
Get the slot data, put it in a temp file, FOR A SINGLE structure.*/
void ClassGenerator::generateTempFileSingle(const char *structure,const char* filename) 
{

	CreateDirectory("classes",NULL);	//create a directory called "classes"

	const char *tempFileName = filename;
	ofstream	tempFile;
	tempFile.open (tempFileName);		//opens the temporary file.
	if (!tempFile ) exit(0);

	ifstream	pinsFile;
	char pinsFileName[] = "Classdefs\\fmapins-A.txt";	
	pinsFile.open(pinsFileName);		//opens the class definitions file.
	const int locationOfChar = 18;		//location of the special letter in pinsFileName. 
	char *pinsDelimiter = "([";			
	char lastCharUsed = ' ';


	char className[MAX_FORMULA_LEN];
	strcpy(className,structure);		//get the class name.

	if ( strcmp(className,"") == 0) return;	//if className is blank, exit.

	insertPlusSigns(className);			//adds "+" chars to the class name.
	

	strcat(className,"]");				//add a "]" to the end of className.

	char firstCharOfClassName = className[0];	//get the first char of className.
	convertToUpperCase(firstCharOfClassName);	//oonvert it to upper case.

	if ( firstCharOfClassName != lastCharUsed)	//if the first char of className is different from the last character used...
	{
		pinsFile.close();						//reopen the class def file.
		pinsFileName[locationOfChar] = firstCharOfClassName;	//replace the special character in the file name with a new letter.
		pinsFile.open(pinsFileName);
		if (!pinsFile) 
		{
			MessageBox(NULL,pinsFileName,"Can't OPen File",NULL);
			exit(0);
		}
		lastCharUsed = firstCharOfClassName;		//update last char used.
	}

	
	bool foundClass = false;
	bool classWritten = false;
	while (!pinsFile.eof())
	{

		char lineBuffer[MAXLINELEN] = "";
		pinsFile.getline(lineBuffer,MAXLINELEN);


		if ( strstr(lineBuffer,pinsDelimiter) )
		{
								//if the delimiter is found in the line
								//check if the line contains the class name.
			if ( strstr(lineBuffer,className) )
			{	//if the class name is found, start writing to the temp file.
				foundClass = true;
			}	 //end if
		}		//end if

		if (foundClass)
		{
			//write to tempfile.
			tempFile << lineBuffer << endl;
			classWritten = true;
		}

		if ( strstr(lineBuffer,"))") )
		{
			//if a line contains "))", it means the end of the class has been reached. Stop writing.
			if (classWritten) break;
		}
	}			//end while

	
	
	//MessageBox(NULL,"Search Completed","Search Completed",NULL);
	tempFile.close();
	pinsFile.close();
}

/*Use this method if you want to generate a temp file from fmaclasses.txt*/
void ClassGenerator::generateFMATempFile(HWND hListBox) 
{
	/*Assuming the list box is sorted in heiarchical order, meaning superclasses come first.*/
	CtlListBox classList;
	const char delimFirstLine[] = "defclass";
	const char delimLastLine[] = "";
	const char *tempFileName = PATH_OF_TEMPFILE;
	const int	MAXNAMESIZE = 200;
	classList.setHandle (hListBox);
	int listSize = classList.getItemCount ();	//get size of list.

	CreateDirectory("classes",NULL);	//create a directory

	
	ofstream	tempFile;
	tempFile.open (tempFileName);		//opens the temporary file.
	if (!tempFile ) exit(0);

	ifstream	inputFile;
	inputFile.open("fmaclasses.txt");
	if (!inputFile) MessageBox(NULL,"Can't open fmaclasses.txt","ERROR",NULL);


	for(int index = 0; index < listSize; index++)
	{
		/*Obtain class name.*/
		char className[MAXNAMESIZE];
		classList.setSelection (index);
		classList.getSelectedText (className);
		insertPlusSigns(className);
		if ( strcmp(className,"") == 0) break;
		/*Search for class name in fmaclasses file.
		Save the class data to the temporary file.*/
		bool	flag_ClassFound = false;
		bool	flag_finalClass = false;

		if (index == (listSize-1))	flag_finalClass = true;	//We are at the last class in the list.

		while(!inputFile.eof())
		{
			char lineBuffer[MAXLINELEN];
			inputFile.getline(lineBuffer,MAXLINELEN);
			if ( strstr(lineBuffer,delimFirstLine) )
			{
				//If the word "Defclass" is found on a line, check to see if it's the class we're looking for.
				const char delims[] = " ()";
				char *pch;
				char lineBuffer_temp[4000];
				strcpy(lineBuffer_temp,lineBuffer);
				strtok(lineBuffer_temp,delims);
				pch = strtok(NULL,delims);
				if (strncmp(pch,className,MAXNAMESIZE) == 0)//(strstr(lineBuffer,className))
				{
					//We found the correct class. Now copy its data to the temp file.
					flag_ClassFound = true;
				}
			}

			if (flag_ClassFound)
			{
				if (strstr(lineBuffer,";+"))
				{
					//if ";+" is found on a line, replace it with spaces.
					strncpy(lineBuffer,"  ",2);	//";+" will only be found in the beginning of a line.
				}

				if (flag_finalClass)
				{
					//If we are at the last class, the line at this point should look like (defclass ...
					//We are going to replace the "(" with a "[", to indicate that we are at the final class.
					lineBuffer[0] = '[';
					flag_finalClass = false;	//Once we are done with the first line, that is all we should change.
				}

				tempFile << lineBuffer << endl;	//Write line to temp file.

				if ( strcmp(lineBuffer,delimLastLine)==0)
				{
					/*If this line being written contains a "))" string, stop writing because 
					we reached the end.*/
					break;
				}
			}
		}///end while loop
	}
	/*Close everything*/
	MessageBox(NULL,"Search Completed","Search Completed",NULL);
	tempFile.close();
	inputFile.close();

}

/*Searches a temporary file and extracts slot info. 
PLaces slot info into the slot list.*/
void ClassGenerator::getSlotInfoFromTempFile()
{
	ProtegeParser	pp;	//parse the temp file,using the protege parser.
	pp.openFileToParse (PATH_OF_TEMPFILE);	//open temp file.

	BigClassObject	*classdata = NULL;
	
	cListSlotClasses.clearList ();		//clear slot list.

	while (classdata = pp.parseClass ())	//start getting class data.
	{
		classdata->resetSlotCursor ();		//reset slot cursor.
		SlotData *sd = NULL;
		while (true)						//get slot data.
		{
			sd = classdata->getNextSlot ();
			if (sd == NULL)	break;			//if no more slots, break.
			
			/*
			Checks if a slot has aggregated classes.
			*/
			bool slotIsImportant = slotInfoStruct.slotHasPointer (sd->getSlotName() );

			if (slotIsImportant)
			{
				sd->resetSlotValuesCursor ();
				while(true)	//go through all of a slots values.
				{
					char *slotValue = sd->getNextSlotValue ();
					if (strcmp(slotValue,"") == 0) break;

					//insert slot values into the slot list.
					if ( isParentConceptName(slotValue) ) break; //if a slot is a concept name, don't add it to the slot list.
					if ( !isParentConceptName(slotValue)) replaceChars(slotValue,'_','+');
					cListSlotClasses.addExclusiveItem (slotValue);
				}
			}
		}
	}

	pp.closeFile ();
}

/*Looks through slot list and finds parents of everything.
Places parents into the parent list.*/
void	ClassGenerator::getParentsFromSlotList() 
{
	int slotListSize = cListSlotClasses.getItemCount ();

	cListParentClasses.clearList ();	//clears parent list.

	for (int i=0; i<slotListSize ; i++) //goes through slot list.
	{
			cListSlotClasses.setSelection (i);
			char	classname[MAX_FORMULA_LEN];
			cListSlotClasses.getSelectedText (classname);	//get class name
			
			if (isInMainList(classname))	continue;

			if (isParentConceptName(classname)) //check if class name is a concept name.
			{
				//if a class name is a concept name, skip it. 
				cListParentClasses.addExclusiveItem ("Concept+name");
				continue;
			}

			getParentsOf(classname,FLAG_APPENDLIST); //add parents to the parent list.
	}

}

/*Checks if any of the concept name prefixes are in the class name.
Returns true if a prefix is found.*/
bool	ClassGenerator::isParentConceptName(const char *classname) 
{
	char	*conceptNames[] = {"fm-live",
							   "FM_live",
							   "fm_live",
							   "fma_p2_Instance",
							   "KB_AUTO",
							   "KB_INSTANCE",
							   "live_incus",
							   "live_uneditable",
							   "ONARD_Instance",
							   "su_incus"
							};

	const	int	sizeOfList = sizeof(conceptNames)/sizeof(conceptNames[0]);

	bool	returnvalue = false;
	for (int i=0; i< sizeOfList; i++)
	{
		if ( strstr(classname,conceptNames[i]) )
		{
			returnvalue = true;
			break;
		}
	}

	return returnvalue;
}

/*Checks if a class is in the Main List. */
bool	ClassGenerator::isInMainList(const char*	classname)
{
	int search = cListMain.findText (classname);
	if (search == NOTFOUND)
	{
		return	false;
	}
	else
	{
		return true;
	}
}

/*Copies the values from one list into another.*/
void	ClassGenerator::copyList(HWND hSource, HWND hDest) 
{
	CtlListBox	src, dest;
	src.setHandle (hSource);
	dest.setHandle (hDest);
	//the destination list is NOT cleared.

	int srcSize = src.getItemCount ();	//get source list's size.

	for (int i=0; i< srcSize; i++)
	{
		src.setSelection (i);	//move down the source list.

		char	classname[MAX_FORMULA_LEN];
		src.getSelectedText (classname);	//get class name

		dest.addExclusiveItem (classname);	//add string exlusively to the destination.
	}

}