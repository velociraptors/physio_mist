//////////////////////////////////////////////////////
// Implementation of Material_physical_anatomical_entity
//////////////////////////////////////////////////////
#include "Material_physical_anatomical_entity.h"

void Material_physical_anatomical_entity::set_has_boundary( bool nhas_boundary )
{
	has_boundary = nhas_boundary;
}
bool Material_physical_anatomical_entity::get_has_boundary()
{
	return has_boundary;
}

void Material_physical_anatomical_entity::set_physical_state( Physical_State_Type nphysical_state )
{
	physical_state = nphysical_state;
}
Physical_State_Type Material_physical_anatomical_entity::get_physical_state()
{
	return physical_state;
}

void Material_physical_anatomical_entity::add_attributed_continuous_with( Anatomical_entity* nattributed_continuous_with )
{
	attributed_continuous_with.addItem( nattributed_continuous_with);
}
Anatomical_entity* Material_physical_anatomical_entity::getNext_attributed_continuous_with()
{
	return attributed_continuous_with.getNextItem();
}
void Material_physical_anatomical_entity::reset_attributed_continuous_with()
{
	attributed_continuous_with.reset_iterator();
}

void Material_physical_anatomical_entity::set_dimension( DimensionType ndimension )
{
	dimension = ndimension;
}
DimensionType Material_physical_anatomical_entity::get_dimension()
{
	return dimension;
}

void Material_physical_anatomical_entity::set_has_mass( bool nhas_mass )
{
	has_mass = nhas_mass;
}
bool Material_physical_anatomical_entity::get_has_mass()
{
	return has_mass;
}

void Material_physical_anatomical_entity::add_has_shape( Anatomical_entity* nhas_shape )
{
	has_shape.addItem( nhas_shape);
}
Anatomical_entity* Material_physical_anatomical_entity::getNext_has_shape()
{
	return has_shape.getNextItem();
}
void Material_physical_anatomical_entity::reset_has_shape()
{
	has_shape.reset_iterator();
}

void Material_physical_anatomical_entity::add_continuous_with( Anatomical_entity* ncontinuous_with )
{
	continuous_with.addItem( ncontinuous_with);
}
Anatomical_entity* Material_physical_anatomical_entity::getNext_continuous_with()
{
	return continuous_with.getNextItem();
}
void Material_physical_anatomical_entity::reset_continuous_with()
{
	continuous_with.reset_iterator();
}
Material_physical_anatomical_entity::Material_physical_anatomical_entity()
{
}

