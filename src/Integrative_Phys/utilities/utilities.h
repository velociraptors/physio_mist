/**************************************************************************************************
	utilities.h
	Date: September 2007
	Contributor(s):E. Zeynep Erson
	Description: This header file contains important utility classes that will be used throughout the project
	Included classes:
		1. Container: A template class to maintain a list of object pointers of type T.
		2. Char_Container: A non-template class extending Phys_Container<char>, use this class when you will use "CONTAINS"
		3. FMAID: Identifier class for the anatomical entities in the ontology. Every anatomical entity has a unique FMAID			  
**************************************************************************************************/

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <list>
#include <iostream>
#include <math.h>
#include <limits>
#include <vector>
#include "definitions.h"


using namespace std;


template<class T>
class Phys_Container
{	
	typename list<T*>::iterator var_iter;
	list<T*>* variable_list;
public:
	Phys_Container (){
	
		Phys_Container::variable_list = new std::list<T*>;
		Phys_Container::var_iter = Phys_Container::variable_list->begin();

	};

	Phys_Container(Phys_Container<T>* copy){
		Phys_Container::variable_list = new std::list<T*>;
		variable_list = copy->variable_list;
		reset_iterator();

	}

	~Phys_Container()	{};
	
	T* addItem(T* newItem){
	
		this->variable_list->push_back(newItem);
		//Resets the iterator to the first element when the list is no more empty!
		if(variable_list->size()==1){
			reset_iterator();
		}
		return (this->variable_list->back());

	};

	T* add_front(T* newItem){
		this->variable_list->push_front(newItem);
		if(variable_list->size()==1){
				reset_iterator();
			}
			
		return (this->variable_list->front());
	}

	void prependList(Phys_Container<T>* _list){
		if(_list!=NULL){
			this->reset_iterator();
			_list->reset_iterator();
			while(_list->hasMoreVariables()){
				add_front(_list->popLastItem());
			}
		}
	};

	void addList(Phys_Container<T>* _list){
		if(_list!=NULL){
			while(_list->hasMoreVariables()){
				this->addItem(_list->getNextItem());
			}

		}
	}


	/*Creates the copy of the original list, except for the target element, 
	which is replaced by the target, and then swaps it with the original one*/
	void replaceItem(T* target,T* source){
		T* item;
		Phys_Container<T> *temp_list = new Phys_Container<T>;
		reset_iterator();
		while(hasMoreVariables()){
			item = getNextItem();
			if(*item == *target){
				temp_list->addItem(source);
			}
			else{
				temp_list->addItem(item);
			}

		}

		variable_list->swap(*(temp_list->getItemList()));
	}

	list<T*>* getItemList(){
		return variable_list;
	}
		
	/*
	Only adds the elements who are NOT already in the list
	*/
	void addtoList(Phys_Container<T>* _list){	
		while(_list->hasMoreVariables()){
			T* new_item = _list->getNextItem();
			if(!this->contains(new_item)){
				this->addItem(new_item);
			}
		}
	}

	T * getNextItem(){
		T *variable = (*Phys_Container::var_iter);
	
		if(Phys_Container::var_iter==Phys_Container::variable_list->end())
		{
			reset_iterator();
		}
		else
		{
			Phys_Container::var_iter++;
		}

		
		return  variable;
	};
	T* popLastItem(){
		T* variable = variable_list->back();
		variable_list->pop_back();
		reset_iterator();
		return variable;
	}

	T* popFirstItem(){
		T* variable = variable_list->front();
		variable_list->pop_front();
		reset_iterator();
		return variable;
	}
	
	int size(){
		return variable_list->size();
	};


	void reset_iterator(){
		var_iter = variable_list->begin();

	};

	bool hasMoreVariables()
	{	
		return var_iter!=variable_list->end();

	};


void deleteItem(T * item){		
	variable_list->remove(item);
};

/*
AFTER THE DELETION THE ITERETOR IS SET TO POINT TO THE HEAD OF THE LIST
*/
	void SAFE_deleteItem(T * item){
		
		//if the variable iterator points to the item to be deleted, it should be updated so that it will point
		//to the next item
		variable_list->remove(item);

		if(variable_list->size()>0){
			var_iter = variable_list->begin();
		}
		else{
			var_iter = variable_list->begin();
		}
		/*else{
			var_iter = NULL;
		}*/

	};

	/*
	 IMPORTANT TODO: THE COMPARISON IS NOT CORRECT FOR CHAR *'S; SINCE IT ONLY COMPARES THE FIRST CHARACTER
	*/
	bool contains(T* new_item){
		reset_iterator();
		while(hasMoreVariables()){
			T* item = this->getNextItem();
			if(*item == *new_item){
				reset_iterator();
				return true;
				break;
			}
		}
		reset_iterator();
		return false;
	};



	int getIndexOf(T* item){
		reset_iterator();
		int i =0;
		while(hasMoreVariables()){
			if(*getNextItem()== *item){
				return i;
			}
			i++;
		}
		return -1;
	}

	Phys_Container<T>* getSublist(int start,int end){
		if(start<=end){
			Phys_Container<T> *result = new Phys_Container<T>;
			result->addItem(getItemAt(start));
			for(int index=start+1;index<=end;index++){
				result->addItem(getNextItem());
			}

			return result;

		}
		else{
			return NULL;
		}
		
	}


	T* getItemAt(int i){
		if(i<size()){
			reset_iterator();
			for(int k=0;k<i;k++){
				getNextItem();
			}
			return getNextItem();
		}
		else{
			return NULL;
		}
	}

	void clear(){
		this->reset_iterator();
		this->variable_list->clear();
	};


	/*
	This function returns a sorted COPY  of the current list.
	NOTE: The original container is not sorted, it is left as is.
		1. A temporary list of the elements in the container is composed.
		2. The temporary list is sorted (NlogN time)
		3. A new Container instance is created and the sorted list of elements of type T 
			is added to this container and it is returned.
	*/
	Phys_Container<T>* getSortedList(){
		list<T>* temp_list = new list<T>;
		Phys_Container<T>* return_list = new Phys_Container<T>;

		while(this->hasMoreVariables()){
			temp_list->push_back(*this->getNextItem());
		}

		temp_list->sort();
		reset_iterator();
		int size=temp_list->size();

		for(int i=0;i<size;i++){
			T* item = new T;
			*item = temp_list->front();
			temp_list->pop_front();
			if(!return_list->contains(item)){
				return_list->addItem(item);
			}
		}

		return return_list;
	}

	void reverseList(){
		variable_list->reverse();
		reset_iterator();
	}
};


class Char_Container : public Phys_Container<char>
{
public:
	bool contains(char* new_item){
	reset_iterator();
	while(hasMoreVariables()){
		char* item = this->getNextItem();
		if(strcmp(item,new_item)==0){
			reset_iterator();
			return true;
			break;
		}
	}
	reset_iterator();
	return false;
};

};
/*
THIS IS A PRELIMINARY IMPLEMANTATION,
REQUIRES IMPROVEMENT TO AVOID SMALL TIME STEPS!!!
*/
static double gcd(double v1, double v2)
     {
         while (v2!=0.0) {
             double temp = v2;
             v2 = fmod(v1,v2);
             v1 = temp;
         }
         return v1;
     };

static bool isConstant(char *test){
	if(atof(test)!=0.0 || strcmp(test,"0")==0 || strcmp(test,"0.0")==0){
		return true;
	}
	else{
		return false;
	}
}


/*
Class: FMAID
Description: Every item in the anatomical ontology has a unique identifier number.
This class encapsualtes the identification numbers and implements utility functions with FMAID's that
can be performed on the ontology tree.
*/
class FMAID{
public:
	FMAID(){
		id = EMPTY_INITIAL_VALUE;
		parent_FMAID = NULL;
		children = new Phys_Container<FMAID>;
	};
	FMAID(int *value){
		id = *value;

	};
	~FMAID(){};

	int get_id(){
		return id;
	};
	void set_id(int *value){
		id = *value;
	};

	bool operator==(FMAID compare){
		return compare.get_id() == get_id();
	};

	FMAID *get_Parent(){
		return parent_FMAID;
	};
	
	Phys_Container<FMAID> *get_children(){
		return children;
	}

private:
	int id;
	FMAID *parent_FMAID;
	Phys_Container<FMAID> *children;

};

#endif

