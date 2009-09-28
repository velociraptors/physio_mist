//////////////////////////////////////////////////////
// Anatomical_entity
//////////////////////////////////////////////////////
#ifndef CLASS_Anatomical_entity
#define CLASS_Anatomical_entity

#include <cstring>
#include <string>
#include "utilities.h"
#include "symbolDefs.h"
class Anatomical_entity
{
public:
	Anatomical_entity();

	void 			set_FMAID( FMAID* fmaid );
	FMAID*			get_FMAID();
	string*			get_name();
	void			set_name(string *_name);

protected:
	FMAID*	fmaid;
	string *name;
};

#endif