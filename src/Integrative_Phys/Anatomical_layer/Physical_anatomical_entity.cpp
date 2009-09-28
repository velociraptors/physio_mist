//////////////////////////////////////////////////////
// Implementation of Physical_anatomical_entity
//////////////////////////////////////////////////////
#include "Physical_anatomical_entity.h"

void Physical_anatomical_entity::set_has_boundary( bool nhas_boundary )
{
	has_boundary = nhas_boundary;
}
bool Physical_anatomical_entity::get_has_boundary()
{
	return has_boundary;
}

void Physical_anatomical_entity::set_dimension( DimensionType ndimension )
{
	dimension = ndimension;
}
DimensionType Physical_anatomical_entity::get_dimension()
{
	return dimension;
}

void Physical_anatomical_entity::add_has_dimension( Anatomical_entity* nhas_dimension )
{
	has_dimension.addItem( nhas_dimension);
}
Anatomical_entity* Physical_anatomical_entity::getNext_has_dimension()
{
	return has_dimension.getNextItem();
}
void Physical_anatomical_entity::reset_has_dimension()
{
	has_dimension.reset_iterator();
}
Physical_anatomical_entity::Physical_anatomical_entity()
{
}

