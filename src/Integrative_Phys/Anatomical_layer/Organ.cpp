//////////////////////////////////////////////////////
// Implementation of Organ
//////////////////////////////////////////////////////
#include "Organ.h"

void Organ::set_physical_state( Physical_State_Type nphysical_state )
{
	physical_state = nphysical_state;
}
Physical_State_Type Organ::get_physical_state()
{
	return physical_state;
}

void Organ::add_attributed_continuous_with( Anatomical_entity* nattributed_continuous_with )
{
	attributed_continuous_with.addItem( nattributed_continuous_with);
}
Anatomical_entity* Organ::getNext_attributed_continuous_with()
{
	return attributed_continuous_with.getNextItem();
}
void Organ::reset_attributed_continuous_with()
{
	attributed_continuous_with.reset_iterator();
}

void Organ::add_lymphatic_drainage( Anatomical_entity* nlymphatic_drainage )
{
	lymphatic_drainage.addItem( nlymphatic_drainage);
}
Anatomical_entity* Organ::getNext_lymphatic_drainage()
{
	return lymphatic_drainage.getNextItem();
}
void Organ::reset_lymphatic_drainage()
{
	lymphatic_drainage.reset_iterator();
}

void Organ::add_location( Anatomical_entity* nlocation )
{
	location.addItem( nlocation);
}
Anatomical_entity* Organ::getNext_location()
{
	return location.getNextItem();
}
void Organ::reset_location()
{
	location.reset_iterator();
}

void Organ::add_member_of( Anatomical_entity* nmember_of )
{
	member_of.addItem( nmember_of);
}
Anatomical_entity* Organ::getNext_member_of()
{
	return member_of.getNextItem();
}
void Organ::reset_member_of()
{
	member_of.reset_iterator();
}

void Organ::add_segmental_supply( Anatomical_entity* nsegmental_supply )
{
	segmental_supply.addItem( nsegmental_supply);
}
Anatomical_entity* Organ::getNext_segmental_supply()
{
	return segmental_supply.getNextItem();
}
void Organ::reset_segmental_supply()
{
	segmental_supply.reset_iterator();
}

void Organ::add_bounded_by( Anatomical_entity* nbounded_by )
{
	bounded_by.addItem( nbounded_by);
}
Anatomical_entity* Organ::getNext_bounded_by()
{
	return bounded_by.getNextItem();
}
void Organ::reset_bounded_by()
{
	bounded_by.reset_iterator();
}

void Organ::add_systemic_part( Anatomical_entity* nsystemic_part )
{
	systemic_part.addItem( nsystemic_part);
}
Anatomical_entity* Organ::getNext_systemic_part()
{
	return systemic_part.getNextItem();
}
void Organ::reset_systemic_part()
{
	systemic_part.reset_iterator();
}

void Organ::set_dimension( DimensionType ndimension )
{
	dimension = ndimension;
}
DimensionType Organ::get_dimension()
{
	return dimension;
}

void Organ::add_surrounded_by( Anatomical_entity* nsurrounded_by )
{
	surrounded_by.addItem( nsurrounded_by);
}
Anatomical_entity* Organ::getNext_surrounded_by()
{
	return surrounded_by.getNextItem();
}
void Organ::reset_surrounded_by()
{
	surrounded_by.reset_iterator();
}

void Organ::add_systemic_part_of( Anatomical_entity* nsystemic_part_of )
{
	systemic_part_of.addItem( nsystemic_part_of);
}
Anatomical_entity* Organ::getNext_systemic_part_of()
{
	return systemic_part_of.getNextItem();
}
void Organ::reset_systemic_part_of()
{
	systemic_part_of.reset_iterator();
}

void Organ::add_contained_in( Anatomical_entity* ncontained_in )
{
	contained_in.addItem( ncontained_in);
}
Anatomical_entity* Organ::getNext_contained_in()
{
	return contained_in.getNextItem();
}
void Organ::reset_contained_in()
{
	contained_in.reset_iterator();
}

void Organ::add_innervation( Anatomical_entity* ninnervation )
{
	innervation.addItem( ninnervation);
}
Anatomical_entity* Organ::getNext_innervation()
{
	return innervation.getNextItem();
}
void Organ::reset_innervation()
{
	innervation.reset_iterator();
}

void Organ::add_attributed_part( Anatomical_entity* nattributed_part )
{
	attributed_part.addItem( nattributed_part);
}
Anatomical_entity* Organ::getNext_attributed_part()
{
	return attributed_part.getNextItem();
}
void Organ::reset_attributed_part()
{
	attributed_part.reset_iterator();
}

void Organ::add_nerve_supply( Anatomical_entity* nnerve_supply )
{
	nerve_supply.addItem( nnerve_supply);
}
Anatomical_entity* Organ::getNext_nerve_supply()
{
	return nerve_supply.getNextItem();
}
void Organ::reset_nerve_supply()
{
	nerve_supply.reset_iterator();
}

void Organ::add_primary_site_of( Anatomical_entity* nprimary_site_of )
{
	primary_site_of.addItem( nprimary_site_of);
}
Anatomical_entity* Organ::getNext_primary_site_of()
{
	return primary_site_of.getNextItem();
}
void Organ::reset_primary_site_of()
{
	primary_site_of.reset_iterator();
}
Organ::Organ()
{
}

