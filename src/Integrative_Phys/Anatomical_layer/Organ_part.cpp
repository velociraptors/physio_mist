//////////////////////////////////////////////////////
// Implementation of Organ_part
//////////////////////////////////////////////////////
#include "Organ_part.h"

void Organ_part::add_systemic_part( Anatomical_entity* nsystemic_part )
{
	systemic_part.addItem( nsystemic_part);
}
Anatomical_entity* Organ_part::getNext_systemic_part()
{
	return systemic_part.getNextItem();
}
void Organ_part::reset_systemic_part()
{
	systemic_part.reset_iterator();
}

void Organ_part::add_lymphatic_drainage( Anatomical_entity* nlymphatic_drainage )
{
	lymphatic_drainage.addItem( nlymphatic_drainage);
}
Anatomical_entity* Organ_part::getNext_lymphatic_drainage()
{
	return lymphatic_drainage.getNextItem();
}
void Organ_part::reset_lymphatic_drainage()
{
	lymphatic_drainage.reset_iterator();
}

void Organ_part::add_attaches_to( Anatomical_entity* nattaches_to )
{
	attaches_to.addItem( nattaches_to);
}
Anatomical_entity* Organ_part::getNext_attaches_to()
{
	return attaches_to.getNextItem();
}
void Organ_part::reset_attaches_to()
{
	attaches_to.reset_iterator();
}

void Organ_part::add_member_of( Anatomical_entity* nmember_of )
{
	member_of.addItem( nmember_of);
}
Anatomical_entity* Organ_part::getNext_member_of()
{
	return member_of.getNextItem();
}
void Organ_part::reset_member_of()
{
	member_of.reset_iterator();
}

void Organ_part::add_continuous_with_proximally( Anatomical_entity* ncontinuous_with_proximally )
{
	continuous_with_proximally.addItem( ncontinuous_with_proximally);
}
Anatomical_entity* Organ_part::getNext_continuous_with_proximally()
{
	return continuous_with_proximally.getNextItem();
}
void Organ_part::reset_continuous_with_proximally()
{
	continuous_with_proximally.reset_iterator();
}

void Organ_part::add_sends_output_to( Anatomical_entity* nsends_output_to )
{
	sends_output_to.addItem( nsends_output_to);
}
Anatomical_entity* Organ_part::getNext_sends_output_to()
{
	return sends_output_to.getNextItem();
}
void Organ_part::reset_sends_output_to()
{
	sends_output_to.reset_iterator();
}

void Organ_part::add_continuous_with_distally( Anatomical_entity* ncontinuous_with_distally )
{
	continuous_with_distally.addItem( ncontinuous_with_distally);
}
Anatomical_entity* Organ_part::getNext_continuous_with_distally()
{
	return continuous_with_distally.getNextItem();
}
void Organ_part::reset_continuous_with_distally()
{
	continuous_with_distally.reset_iterator();
}

void Organ_part::add_segmental_supply( Anatomical_entity* nsegmental_supply )
{
	segmental_supply.addItem( nsegmental_supply);
}
Anatomical_entity* Organ_part::getNext_segmental_supply()
{
	return segmental_supply.getNextItem();
}
void Organ_part::reset_segmental_supply()
{
	segmental_supply.reset_iterator();
}

void Organ_part::add_receives_input_from( Anatomical_entity* nreceives_input_from )
{
	receives_input_from.addItem( nreceives_input_from);
}
Anatomical_entity* Organ_part::getNext_receives_input_from()
{
	return receives_input_from.getNextItem();
}
void Organ_part::reset_receives_input_from()
{
	receives_input_from.reset_iterator();
}
Organ_part::Organ_part()
{
}

