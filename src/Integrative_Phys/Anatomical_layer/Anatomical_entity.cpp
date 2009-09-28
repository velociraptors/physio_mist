//////////////////////////////////////////////////////
// Implementation of Anatomical_entity
//////////////////////////////////////////////////////
#include "Anatomical_entity.h"

void Anatomical_entity::set_FMAID( FMAID* nFMAID )
{
	fmaid = nFMAID;
}
FMAID* Anatomical_entity::get_FMAID()
{
	return fmaid;
}
Anatomical_entity::Anatomical_entity()
{
	fmaid = new FMAID();
	name = new string();

}

string* Anatomical_entity::get_name()
{
	return name;
}

void Anatomical_entity::set_name(string *_name){
	name = _name;
}