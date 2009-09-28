//////////////////////////////////////////////////////
// Implementation of Anatomical_entity
//////////////////////////////////////////////////////
#include "Anatomical_entity_template.h"

Anatomical_entity_template::Anatomical_entity_template()
{
	parts = new Phys_Container<FMAID>;
	part_of = new Phys_Container<FMAID>;
}

void Anatomical_entity_template::set_FMAID( FMAID *nFMAID )
{
	fmaid =  *nFMAID;
}
FMAID Anatomical_entity_template::get_FMAID()
{
	return fmaid;
}

void Anatomical_entity_template::set_definition( char* ndefinition )
{
	strcpy( definition, ndefinition);
}
char* Anatomical_entity_template::get_definition()
{
	return definition;
}
Phys_Container<FMAID> Anatomical_entity_template::get_parts(){
	return parts;
}

void Anatomical_entity_template:: add_part(FMAID *part){
	parts->addItem(part);
}

Phys_Container<FMAID> Anatomical_entity_template:: get_part_of(){
	return part_of;
}
void Anatomical_entity_template::add_part_of(FMAID *_part_of){
	part_of->addItem(_part_of);
}

/*Anatomical_entity_template* Anatomical_entity_template::Instance()
{
	static Anatomical_entity_template inst;
	return &inst;
}*/