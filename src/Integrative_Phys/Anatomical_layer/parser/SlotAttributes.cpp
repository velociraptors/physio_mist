#include "SlotAttributes.h"

SlotObj::SlotObj(char *slotName, char *slotType, bool hasptr)
{
	setName( slotName );
	setType ( slotType);
	setHasPointer ( hasptr );
}

SlotAttributes::SlotAttributes ()
{
	//constructor
	slotsLoaded = false;
	defaultClassDefined = false;
}

void SlotAttributes::loadSlots(char *slotConfigFileName)
{
	if (slotsLoaded) return;		//if slots have already been loaded, do not run this routine.
	else	slotsLoaded = true;

	ifstream	slotConfigFile;
	char *delimiter = "+;";
	char lineBuffer[MAX_PATH_LEN];
	slotConfigFile.open(slotConfigFileName);

	if (!slotConfigFile)
	{
		cerr << "File Could Not Be Found: " << slotConfigFileName << endl;
		exit(0);
	}
	else cout << "File " << slotConfigFileName << " opened successfully." << endl;

	while ( strcmp(lineBuffer,delimiter) != 0)	slotConfigFile.getline(lineBuffer,MAX_PATH_LEN);

	while ( !slotConfigFile.eof() )
	{
		if (strcmp(lineBuffer,delimiter) == 0)
		{
			char slotName[MAX_PATH_LEN];
			char slotType[MAX_PATH_LEN];
			char slotHasPtr[7];
			bool slotHp = false;
			slotConfigFile.getline(slotName,MAX_PATH_LEN);
			slotConfigFile.getline(slotType,MAX_PATH_LEN);
			slotConfigFile.getline(slotHasPtr,7);

			if ( strcmp(slotHasPtr,"hasptr") == 0)
				slotHp = true;

			if (strcmp(slotName,"DefaultClass") == 0)	//if the slot definition "DefaultClass" is found, then set defaultClassDefined to true.
				defaultClassDefined = true;

			SlotList.addItem(new SlotObj(slotName,slotType,slotHp) );
		}

		slotConfigFile.getline(lineBuffer,MAX_PATH_LEN);
	}
	
	slotConfigFile.close();
}

//searches the array for the slot name, returns the slot type.
char* SlotAttributes::getSlotType (char *slotName)
{
	SlotObj	* cursor = NULL;
	SlotList.resetCursor();
	while ( cursor = SlotList.getNextItem() )
	{
		if (strcmp(cursor->getName(),slotName) == 0)
		{
			return cursor->getType();
		}
	}
	//if slotName is not found in the config file...
	if (defaultClassDefined)			//this boolean prevents infinite recursion. If "DefaultClass" is not found ih the slot config file, return NULL string.
		return getSlotType("DefaultClass");	//return the default parent class. It should be Anatomical_structure.
	else
		return "void";
}

//tells if a slot should be a pointer or not.
bool SlotAttributes::slotHasPointer (char *slotName)
{
	SlotObj	* cursor = NULL;
	SlotList.resetCursor();
	while ( cursor = SlotList.getNextItem() )
	{
		if (strcmp(cursor->getName(),slotName) == 0)
		{
			return cursor->getHasPointer();
		}
	}
	//if slotName is not found in the config file...
	return true;
}