//////////////////////////////////////////////////////
// Implementation of Liver
//////////////////////////////////////////////////////
#include "Liver.h"


void Liver::add_systemic_part_of( Anatomical_structure* nsystemic_part_of )
{
	systemic_part_of.addItem( nsystemic_part_of);
}
Anatomical_structure* Liver::getNext_systemic_part_of()
{
	return systemic_part_of.getNextItem();
}
void Liver::reset_systemic_part_of()
{
	systemic_part_of.resetCursor();
}

void Liver::add_regional_part( Anatomical_structure* nregional_part )
{
	regional_part.addItem( nregional_part);
}
Anatomical_structure* Liver::getNext_regional_part()
{
	return regional_part.getNextItem();
}
void Liver::reset_regional_part()
{
	regional_part.resetCursor();
}

void Liver::add_part_of( Anatomical_structure* npart_of )
{
	part_of.addItem( npart_of);
}
Anatomical_structure* Liver::getNext_part_of()
{
	return part_of.getNextItem();
}
void Liver::reset_part_of()
{
	part_of.resetCursor();
}

void Liver::add_part( Anatomical_structure* npart )
{
	part.addItem( npart);
}
Anatomical_structure* Liver::getNext_part()
{
	return part.getNextItem();
}
void Liver::reset_part()
{
	part.resetCursor();
}


void Liver::set_member_of( Anatomical_structure* nmember_of )
{
	member_of = nmember_of;
}
Anatomical_structure* Liver::get_member_of()
{
	return member_of;
}

void Liver::set_lymphatic_drainage( Anatomical_structure* nlymphatic_drainage )
{
	lymphatic_drainage = nlymphatic_drainage;
}
Anatomical_structure* Liver::get_lymphatic_drainage()
{
	return lymphatic_drainage;
}

void Liver::set_inherent_3_D_shape( Anatomical_structure* ninherent_3_D_shape )
{
	inherent_3_D_shape = ninherent_3_D_shape;
}
Anatomical_structure* Liver::get_inherent_3_D_shape()
{
	return inherent_3_D_shape;
}


void Liver::set_develops_from( Anatomical_structure* ndevelops_from )
{
	develops_from = ndevelops_from;
}
Anatomical_structure* Liver::get_develops_from()
{
	return develops_from;
}


void Liver::set_contained_in( Anatomical_structure* ncontained_in )
{
	contained_in = ncontained_in;
}
Anatomical_structure* Liver::get_contained_in()
{
	return contained_in;
}

void Liver::add_constitutional_part( Anatomical_structure* nconstitutional_part )
{
	constitutional_part.addItem( nconstitutional_part);
}
Anatomical_structure* Liver::getNext_constitutional_part()
{
	return constitutional_part.getNextItem();
}
void Liver::reset_constitutional_part()
{
	constitutional_part.resetCursor();
}

void Liver::add_clinical_part( Anatomical_structure* nclinical_part )
{
	clinical_part.addItem( nclinical_part);
}
Anatomical_structure* Liver::getNext_clinical_part()
{
	return clinical_part.getNextItem();
}
void Liver::reset_clinical_part()
{
	clinical_part.resetCursor();
}

void Liver::set_bounded_by( Anatomical_structure* nbounded_by )
{
	bounded_by = nbounded_by;
}
Anatomical_structure* Liver::get_bounded_by()
{
	return bounded_by;
}

Liver::Liver()
{
}

Liver* Liver::getInstance()
{
	static Liver inst;
	return &inst;
}