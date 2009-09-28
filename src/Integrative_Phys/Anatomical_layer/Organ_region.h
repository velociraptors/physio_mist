//////////////////////////////////////////////////////
// Organ_region
//////////////////////////////////////////////////////
#ifndef CLASS_Organ_region
#define CLASS_Organ_region

#include "Organ_part.h"

class Organ_region: public Organ_part
{
public:
	Organ_region();

	void 			add_venous_drainage( Anatomical_entity* nvenous_drainage );
	Anatomical_entity*			 getNext_venous_drainage();
	void			reset_venous_drainage();
protected:
		Phys_Container<Anatomical_entity>	venous_drainage;
};

#endif