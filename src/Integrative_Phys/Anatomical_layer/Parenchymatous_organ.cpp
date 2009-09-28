//////////////////////////////////////////////////////
// Implementation of Parenchymatous_organ
//////////////////////////////////////////////////////
#include "Parenchymatous_organ.h"

void Parenchymatous_organ::add_orientation( FMAID* norientation )
{
	orientation.addItem( norientation);
}
FMAID* Parenchymatous_organ::getNext_orientation()
{
	return orientation.getNextItem();
}
void Parenchymatous_organ::reset_orientation()
{
	orientation.reset_iterator();
}

void Parenchymatous_organ::add_location( FMAID* nlocation )
{
	location.addItem( nlocation);
}
FMAID* Parenchymatous_organ::getNext_location()
{
	return location.getNextItem();
}
void Parenchymatous_organ::reset_location()
{
	location.reset_iterator();
}
Parenchymatous_organ::Parenchymatous_organ()
{
}

