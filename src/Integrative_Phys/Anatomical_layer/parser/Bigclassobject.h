#pragma once

#include "utilities.h"
#include "macros.h"
//String container
/*Purpose: to store basic information about a structure. It can store a name and an FMAID.
Allows you to associate the two.*/
class	XString
{
public:
	XString()			{	//constructor
			setString("");
			fid = new FMAID();
	}
	XString(const char	*str)	{ setString(str); 
									fid = new FMAID();}

	~XString() { delete fid; }

	void	setString(const char *str)	{ strncpy(string,str,MAX_TOKEN_LEN); }
	char	*getString()				{ return string; }

	void	setID(int id) //set the FMAID number.
	{
		fid->set_id (&id);
	}

	int		getID()	{return fid->get_id(); } //returns FMAID number
private:
	char	string[MAX_TOKEN_LEN];
	FMAID * fid;
	
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
	SlotData(const char *name)	{ setSlotName(name); }

	SlotData(const char *nSlotName,const char *nSlotValue)	{ 
						setSlotName(nSlotName); 
						addSlotValue(nSlotValue);
						}

	/*returns slot name.*/
	char *	getSlotName()	{return slotName; }


	/*returns a string representing the next slot value from the slotValues list.*/
	char *	getNextSlotValue()	
		{
		
			if (slotValues.hasMoreVariables())
			{
				XString *tempStr = slotValues.getNextItem ();
				return tempStr->getString ();
			}
			else
				return "";
		}

	//Returns an XString, which contains the next slot name AND FMAID.
	XString*	getNextSlotInfo()
	{
		if (slotValues.hasMoreVariables())
			{
				return slotValues.getNextItem ();
			}
			else
				return NULL;
	}

	/*set slot name */
	void	setSlotName(const char *nSlotName)	{ strcpy(slotName,nSlotName); }

	/* insert a value to the slotValues list.*/
	void	addSlotValue(const char *nSlotValue)	{ slotValues.add_front(new XString(nSlotValue)); }

	void	resetSlotValuesCursor()			{ 
		if (getValueCount() > 0)	
			slotValues.reset_iterator(); 
	} //resets slotValues cursor.
	int		getValueCount()			{ return slotValues.size();} //returns number of items in slotValues list.
private:
	char slotName[50];

	Container<XString>	slotValues;
};

//Object to store class information. Will have class name, class parent, slots, slot values.
//This object has ALL the information about a structure.
/*
For example:
BigClassObject for "Liver"
Classname = "Liver"
Classparent = "Organ"
Slots = FMAID, Arterial_supply, veinous_drainage, etc...
FMAID = 12345
*/
class BigClassObject
{
public:
	BigClassObject()	{ /*constructor*/ 
							setSingletonStatus(true); //singleton will be on by DEFAULT (2/4/2008) 
							itemAdded = false;
							fid = new FMAID();
						}

	~BigClassObject() { delete fid; }
	void	setClassName( const char* str)	{ strncpy(className,str,MAX_TOKEN_LEN); }
	void	setClassParent( const char* str)	{ strncpy(classParent,str,MAX_TOKEN_LEN); }
	char*	getClassName()		{ return className; }
	char*	getClassParent()	{ return classParent; }

	void	setID(int id)	{fid->set_id(&id);}
	int		getID()				{return fid->get_id();}

	void	setSingletonStatus(bool flag)	{ singleton = flag; }
	bool	getSingletonStatus()			{ return singleton; }

	SlotData*	addSlot( SlotData* sD)	{ 
		itemAdded = true;
		return slotList.addItem(sD);

	}
	SlotData*	getNextSlot()					
	{ 
		if (slotList.hasMoreVariables ())
			return slotList.getNextItem(); 
		else
			return NULL;
	}
	void		resetSlotCursor()				{ 
		  if(itemAdded) slotList.reset_iterator();
	}
private:
	char	className[MAX_TOKEN_LEN];	//Structure name
	char	classParent[MAX_TOKEN_LEN];	//THe Structure's parent.
	bool	singleton;					//Should this structure use singleton?
	Container<SlotData>	slotList;		//A list of slots for this structure.
	bool	itemAdded;					//Has an slot been added to the list yet?
	FMAID * fid;						//FMAID of this structure.
};