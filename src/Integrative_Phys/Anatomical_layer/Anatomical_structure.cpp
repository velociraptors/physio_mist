//////////////////////////////////////////////////////
// Implementation of Anatomical_structure
//////////////////////////////////////////////////////
#include "Anatomical_structure.h"

void Anatomical_structure::add_regional_part_of( Anatomical_entity* nregional_part_of )
{
	regional_part_of.addItem( nregional_part_of);
}
Anatomical_entity* Anatomical_structure::getNext_regional_part_of()
{
	return regional_part_of.getNextItem();
}
void Anatomical_structure::reset_regional_part_of()
{
	regional_part_of.reset_iterator();
}

void Anatomical_structure::add_constitutional_part( Anatomical_entity* nconstitutional_part )
{
	constitutional_part.addItem( nconstitutional_part);
	
}
Anatomical_entity* Anatomical_structure::getNext_constitutional_part()
{
	return constitutional_part.getNextItem();
}
void Anatomical_structure::reset_constitutional_part()
{
	constitutional_part.reset_iterator();
}

void Anatomical_structure::add_location( Anatomical_entity* nlocation )
{
	location.addItem( nlocation);
}
Anatomical_entity* Anatomical_structure::getNext_location()
{
	return location.getNextItem();
}
void Anatomical_structure::reset_location()
{
	location.reset_iterator();
}

void Anatomical_structure::add_part( Anatomical_entity* npart )
{
	part.addItem( npart);
}
Phys_Container<Anatomical_entity> Anatomical_structure::get_parts()
{
	return part;
}
void Anatomical_structure::reset_part()
{
	part.reset_iterator();
}

void Anatomical_structure::add_constitutional_part_of( Anatomical_entity* nconstitutional_part_of )
{
	constitutional_part_of.addItem( nconstitutional_part_of);
}
Anatomical_entity* Anatomical_structure::getNext_constitutional_part_of()
{
	return constitutional_part_of.getNextItem();
}
void Anatomical_structure::reset_constitutional_part_of()
{
	constitutional_part_of.reset_iterator();
}

void Anatomical_structure::add_inherent_3_D_shape( Anatomical_entity* ninherent_3_D_shape )
{
	inherent_3_D_shape.addItem( ninherent_3_D_shape);
}
Anatomical_entity* Anatomical_structure::getNext_inherent_3_D_shape()
{
	return inherent_3_D_shape.getNextItem();
}
void Anatomical_structure::reset_inherent_3_D_shape()
{
	inherent_3_D_shape.reset_iterator();
}

void Anatomical_structure::add_custom_partonomy( Anatomical_entity* ncustom_partonomy )
{
	custom_partonomy.addItem( ncustom_partonomy);
}
Anatomical_entity* Anatomical_structure::getNext_custom_partonomy()
{
	return custom_partonomy.getNextItem();
}
void Anatomical_structure::reset_custom_partonomy()
{
	custom_partonomy.reset_iterator();
}

void Anatomical_structure::add_develops_from( Anatomical_entity* ndevelops_from )
{
	develops_from.addItem( ndevelops_from);
}
Anatomical_entity* Anatomical_structure::getNext_develops_from()
{
	return develops_from.getNextItem();
}
void Anatomical_structure::reset_develops_from()
{
	develops_from.reset_iterator();
}

void Anatomical_structure::add_venous_drainage( Anatomical_entity* nvenous_drainage )
{
	venous_drainage.addItem( nvenous_drainage);
}
Phys_Container<Anatomical_entity>	 Anatomical_structure::get_venous_drainage()
{
	return venous_drainage;
}
void Anatomical_structure::reset_venous_drainage()
{
	venous_drainage.reset_iterator();
}

void Anatomical_structure::add_regional_part( Anatomical_entity* nregional_part )
{
	regional_part.addItem( nregional_part);
}
Phys_Container<Anatomical_entity>	Anatomical_structure::get_regional_part()
{
	return regional_part;
}
void Anatomical_structure::reset_regional_part()
{
	regional_part.reset_iterator();
}

void Anatomical_structure::add_bounded_by( Anatomical_entity* nbounded_by )
{
	bounded_by.addItem( nbounded_by);
}
Phys_Container<Anatomical_entity> Anatomical_structure::get_bounded_by()
{
	return bounded_by;
}
void Anatomical_structure::reset_bounded_by()
{
	bounded_by.reset_iterator();
}

void Anatomical_structure::add_orientation( Anatomical_entity* norientation )
{
	orientation.addItem( norientation);
}
Anatomical_entity* Anatomical_structure::getNext_orientation()
{
	return orientation.getNextItem();
}
void Anatomical_structure::reset_orientation()
{
	orientation.reset_iterator();
}

void Anatomical_structure::add_arterial_supply( Anatomical_entity* narterial_supply )
{
	arterial_supply.addItem( narterial_supply);
}
Phys_Container<Anatomical_entity>	 Anatomical_structure::get_arterial_supply()
{
	return arterial_supply;
}
void Anatomical_structure::reset_arterial_supply()
{
	arterial_supply.reset_iterator();
}

void Anatomical_structure::add_has_inherent_3_D_shape( Anatomical_entity* nhas_inherent_3_D_shape )
{
	has_inherent_3_D_shape.addItem( nhas_inherent_3_D_shape);
}
Anatomical_entity* Anatomical_structure::getNext_has_inherent_3_D_shape()
{
	return has_inherent_3_D_shape.getNextItem();
}
void Anatomical_structure::reset_has_inherent_3_D_shape()
{
	has_inherent_3_D_shape.reset_iterator();
}

void Anatomical_structure::add_attributed_part( Anatomical_entity* nattributed_part )
{
	attributed_part.addItem( nattributed_part);
}
Phys_Container<Anatomical_entity> Anatomical_structure::get_attributed_part()
{
	return attributed_part;
}
void Anatomical_structure::reset_attributed_part()
{
	attributed_part.reset_iterator();
}

void Anatomical_structure::add_custom_partonomy_of( Anatomical_entity* ncustom_partonomy_of )
{
	custom_partonomy_of.addItem( ncustom_partonomy_of);
}
Anatomical_entity* Anatomical_structure::getNext_custom_partonomy_of()
{
	return custom_partonomy_of.getNextItem();
}
void Anatomical_structure::reset_custom_partonomy_of()
{
	custom_partonomy_of.reset_iterator();
}

void Anatomical_structure::add_nerve_supply( Anatomical_entity* nnerve_supply )
{
	nerve_supply.addItem( nnerve_supply);
}
Phys_Container<Anatomical_entity> Anatomical_structure::get_nerve_supply()
{
	return nerve_supply;
}
void Anatomical_structure::reset_nerve_supply()
{
	nerve_supply.reset_iterator();
}
Anatomical_structure::Anatomical_structure()
{
}

