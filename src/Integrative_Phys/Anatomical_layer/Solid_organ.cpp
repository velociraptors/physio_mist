//////////////////////////////////////////////////////
// Implementation of Solid_organ
//////////////////////////////////////////////////////
#include "Solid_organ.h"

void Solid_organ::add_attributed_continuous_with( FMAID* nattributed_continuous_with )
{
	attributed_continuous_with.addItem( nattributed_continuous_with);
}
FMAID* Solid_organ::getNext_attributed_continuous_with()
{
	return attributed_continuous_with.getNextItem();
}
void Solid_organ::reset_attributed_continuous_with()
{
	attributed_continuous_with.reset_iterator();
}

void Solid_organ::add_location( FMAID* nlocation )
{
	location.addItem( nlocation);
}
FMAID* Solid_organ::getNext_location()
{
	return location.getNextItem();
}
void Solid_organ::reset_location()
{
	location.reset_iterator();
}

void Solid_organ::add_sends_output_to( FMAID* nsends_output_to )
{
	sends_output_to.addItem( nsends_output_to);
}
FMAID* Solid_organ::getNext_sends_output_to()
{
	return sends_output_to.getNextItem();
}
void Solid_organ::reset_sends_output_to()
{
	sends_output_to.reset_iterator();
}

void Solid_organ::add_bounded_by( FMAID* nbounded_by )
{
	bounded_by.addItem( nbounded_by);
}
FMAID* Solid_organ::getNext_bounded_by()
{
	return bounded_by.getNextItem();
}
void Solid_organ::reset_bounded_by()
{
	bounded_by.reset_iterator();
}

void Solid_organ::add_receives_input_from( FMAID* nreceives_input_from )
{
	receives_input_from.addItem( nreceives_input_from);
}
FMAID* Solid_organ::getNext_receives_input_from()
{
	return receives_input_from.getNextItem();
}
void Solid_organ::reset_receives_input_from()
{
	receives_input_from.reset_iterator();
}
Solid_organ::Solid_organ()
{
}

