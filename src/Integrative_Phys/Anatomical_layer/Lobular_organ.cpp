//////////////////////////////////////////////////////
// Implementation of Lobular_organ
//////////////////////////////////////////////////////
#include "Lobular_organ.h"

void Lobular_organ::add_location( FMAID* nlocation )
{
	location.addItem( nlocation);
}
FMAID* Lobular_organ::getNext_location()
{
	return location.getNextItem();
}
void Lobular_organ::reset_location()
{
	location.reset_iterator();
}

void Lobular_organ::add_clinical_part( FMAID* nclinical_part )
{
	clinical_part.addItem( nclinical_part);
}
FMAID* Lobular_organ::getNext_clinical_part()
{
	return clinical_part.getNextItem();
}
void Lobular_organ::reset_clinical_part()
{
	clinical_part.reset_iterator();
}

void Lobular_organ::add_attributed_regional_part( FMAID* nattributed_regional_part )
{
	attributed_regional_part.addItem( nattributed_regional_part);
}
FMAID* Lobular_organ::getNext_attributed_regional_part()
{
	return attributed_regional_part.getNextItem();
}
void Lobular_organ::reset_attributed_regional_part()
{
	attributed_regional_part.reset_iterator();
}

void Lobular_organ::add_clinical_part_of( FMAID* nclinical_part_of )
{
	clinical_part_of.addItem( nclinical_part_of);
}
FMAID* Lobular_organ::getNext_clinical_part_of()
{
	return clinical_part_of.getNextItem();
}
void Lobular_organ::reset_clinical_part_of()
{
	clinical_part_of.reset_iterator();
}
Lobular_organ::Lobular_organ()
{
}

