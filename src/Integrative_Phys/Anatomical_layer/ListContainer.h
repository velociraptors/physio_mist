//ListContainer class. A class that stores and manipulates a linked list.
//The linked list is created as a template so it can link any type of object.
//Note: The only data type that this container has trouble working with are character strings.
//I suggest creating a character string wrapper class to work with that issue.
//Author: Robin Hu (6-18-07)
#ifndef	LISTCON_H
#define	LISTCON_H


//A node in a linked list.
//T*data is a pointer to our data object.
//Node*next is a pointer to the next node.
//The Destructor deletes the data.
//For all intents and purposes, you do not need to use this class outside of ListContainer.
template<class T> class Node
{
public:
	Node<T>(T *newData) { data = newData ; next = NULL; }
	~Node<T>()			{/*destructor*/ delete data; }
	Node * getNextNode()	{ return next; }
	T *	   getData()	{ return data; }
	void   setNextNode(Node * nextNode) { next = nextNode; }
private:
	T    *  data;
	Node *	next;
};


//Our List Container class. Linked List of Nodes, where each node contains data of type T.
template<class T> class ListContainer
{
public:
	ListContainer<T> ();
	~ListContainer<T>();
	T *  addItem( T * newItem);
	T *  addItemExSorted(T * newItem);
	T *  getNextItem();
	void resetCursor()	{  pCursor = pFirst;  }	//sets pCursor to the first element.
	int	 countItems();
	bool deleteItem(T * item);

private:
	Node<T> * pFirst;	//pointer to the first element.
	Node<T> * pCursor;

};


//Constructor.
template<class T> ListContainer<T>::ListContainer()
{
	//initializes our pointers to NULL.
	
	pFirst = NULL;
	pCursor = NULL;

	
}

//Destructor. Removes everything from the linked list.
template<class T> ListContainer<T>::~ListContainer()
{
	if (pFirst != NULL)
	{
		//If the list is not empty.
		pCursor = pFirst->getNextNode();
		delete	pFirst;				//delete first item.
		while (pCursor != NULL)
		{
			//iterate through the list and delete all nodes.
			pFirst = pCursor;
			pCursor = pCursor->getNextNode ();
			delete pFirst;
		}
	}
}

//Inserts a new Node at the beginning of the list.
//T*newItem is a pointer to the new object.
template<class T> T * ListContainer<T>::addItem ( T * newItem)
{
	
	Node<T> * temp = new Node<T>(newItem);	//Creates a new Node.
	temp->setNextNode (pFirst);					//Inserts node at beginning of list.
	pFirst = temp;
	pCursor = pFirst;
	return temp->getData ();	//returns pointer to new data.
	
}

//Returns a pointer to the current object pointed to by pCursor.
//Increments pCursor to the next item.
template<class T> T * ListContainer<T>::getNextItem ()
{
	
	T * temp = NULL;
	
	if (pCursor != NULL) 
	{
		temp = pCursor->getData ();
		pCursor = pCursor->getNextNode ();
	}
	return temp;


}

//counts number of items, but does not move the cursor.
template<class T> int	ListContainer<T>::countItems()
{
	Node<T>	*cursorOldPosition = pCursor;
	resetCursor();
	int count = -1;
	while (getNextItem())
	{
		count++;
	}

	pCursor = cursorOldPosition;

	return count;
}

//T*item is a pointer to the item we want to delete.
//Funtion searches the list for T*item.
//if found, function deletes item and returns true. False otherwise.
template<class T> bool ListContainer<T>::deleteItem (T * item)
{

	
	pCursor = pFirst;
	if (pCursor == NULL) return false; //empty list, return.
	if (item == NULL)	return false;  //return false if item==null

	if (pCursor->getData() == item)
	{
		//checks first item.
		pFirst = pCursor->getNextNode ();
		delete pCursor;
		pCursor = pFirst;	//sets pCursor to the root to prevent dangling pointer.
		return true;
	}

	while (pCursor != NULL)
	{
		if (pCursor -> getNextNode() -> getData() == item)
		{
			//item found. delete it.
			Node<T> * temp = pCursor->getNextNode ();
			pCursor->setNextNode (pCursor->getNextNode()->getNextNode());
			delete temp;
			return true;
		}
		pCursor = pCursor->getNextNode();	//increment pCursor
	}
	return false;
	

}

#endif //_LISTCON_H

