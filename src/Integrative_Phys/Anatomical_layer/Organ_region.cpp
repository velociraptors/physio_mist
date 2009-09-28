//////////////////////////////////////////////////////
// Implementation of Organ_region
//////////////////////////////////////////////////////
#include "Organ_region.h"

void Organ_region::add_venous_drainage( Anatomical_entity* nvenous_drainage )
{
	venous_drainage.addItem( nvenous_drainage);
}
Anatomical_entity* Organ_region::getNext_venous_drainage()
{
	return venous_drainage.getNextItem();
}
void Organ_region::reset_venous_drainage()
{
	venous_drainage.reset_iterator();
}
Organ_region::Organ_region()
{
}

