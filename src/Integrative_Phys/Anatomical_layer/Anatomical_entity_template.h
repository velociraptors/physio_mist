//////////////////////////////////////////////////////
// Anatomical_entity_template
//////////////////////////////////////////////////////
#ifndef CLASS_Anatomical_entity_template
#define CLASS_Anatomical_entity_template

#include <string.h>
#include "utilities.h"

class Anatomical_entity_template
{
public:
//	Anatomical_entity_template *Instance();
	Anatomical_entity_template();

	void 			set_FMAID( FMAID *nFMAID );
	FMAID			 get_FMAID();

	void 			set_definition( char* ndefinition );
	char*			 get_definition();

	Phys_Container<FMAID> get_parts();
	void add_part(FMAID *part);

	Phys_Container<FMAID> get_part_of();
	void add_part_of(FMAID *part_of);

	bool operator==(Anatomical_entity_template *temp){
		return (this->get_FMAID() == temp->get_FMAID());
	};



private:
	FMAID	fmaid;
	char	definition[255];

	Phys_Container<FMAID>* parts;
	Phys_Container<FMAID>* part_of;

};

#endif