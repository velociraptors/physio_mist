//////////////////////////////////////////////////////
// Anatomical_structure
//////////////////////////////////////////////////////
#ifndef CLASS_Anatomical_structure
#define CLASS_Anatomical_structure

#include "Material_physical_anatomical_entity.h"


class Anatomical_structure: public Material_physical_anatomical_entity
{
public:
	Anatomical_structure();


	void 			add_regional_part_of( Anatomical_entity* nregional_part_of );
	Anatomical_entity*			 getNext_regional_part_of();
	void			reset_regional_part_of();

	void 			add_constitutional_part( Anatomical_entity* nconstitutional_part );
	Anatomical_entity*			 getNext_constitutional_part();
	void			reset_constitutional_part();

	void 			add_location( Anatomical_entity* nlocation );
	Anatomical_entity*			 getNext_location();
	void			reset_location();

	void 			add_part( Anatomical_entity* npart );
	Phys_Container<Anatomical_entity>  get_parts();
	void			reset_part();

	void 			add_constitutional_part_of( Anatomical_entity* nconstitutional_part_of );
	Anatomical_entity*			 getNext_constitutional_part_of();
	void			reset_constitutional_part_of();

	void 			add_inherent_3_D_shape( Anatomical_entity* ninherent_3_D_shape );
	Anatomical_entity*			 getNext_inherent_3_D_shape();
	void			reset_inherent_3_D_shape();

	void 			add_custom_partonomy( Anatomical_entity* ncustom_partonomy );
	Anatomical_entity*			 getNext_custom_partonomy();
	void			reset_custom_partonomy();

	void 			add_develops_from( Anatomical_entity* ndevelops_from );
	Anatomical_entity*			 getNext_develops_from();
	void			reset_develops_from();

	void 			add_venous_drainage( Anatomical_entity* nvenous_drainage );
	Phys_Container<Anatomical_entity>	get_venous_drainage();
	void			reset_venous_drainage();

	void 			add_regional_part( Anatomical_entity* nregional_part );
	Phys_Container<Anatomical_entity>	get_regional_part();
	void			reset_regional_part();

	void 			add_bounded_by( Anatomical_entity* nbounded_by );
	Phys_Container<Anatomical_entity>	 get_bounded_by();
	void			reset_bounded_by();

	void 			add_orientation( Anatomical_entity* norientation );
	Anatomical_entity*			 getNext_orientation();
	void			reset_orientation();

	void 			add_arterial_supply( Anatomical_entity* narterial_supply );
	Phys_Container<Anatomical_entity>	get_arterial_supply();
	void			reset_arterial_supply();

	void 			add_has_inherent_3_D_shape( Anatomical_entity* nhas_inherent_3_D_shape );
	Anatomical_entity*			 getNext_has_inherent_3_D_shape();
	void			reset_has_inherent_3_D_shape();

	void 			add_attributed_part( Anatomical_entity* nattributed_part );
	Phys_Container<Anatomical_entity>	 get_attributed_part();
	void			reset_attributed_part();

	void 			add_custom_partonomy_of( Anatomical_entity* ncustom_partonomy_of );
	Anatomical_entity*			 getNext_custom_partonomy_of();
	void			reset_custom_partonomy_of();

	void 			add_nerve_supply( Anatomical_entity* nnerve_supply );
	Phys_Container<Anatomical_entity>	get_nerve_supply();
	void			reset_nerve_supply();
protected:
	Phys_Container<Anatomical_entity>	regional_part_of;
	Phys_Container<Anatomical_entity>	constitutional_part;
	Phys_Container<Anatomical_entity>	location;
	Phys_Container<Anatomical_entity>	part;
	Phys_Container<Anatomical_entity>	constitutional_part_of;
	Phys_Container<Anatomical_entity>	inherent_3_D_shape;
	Phys_Container<Anatomical_entity>	custom_partonomy;
	Phys_Container<Anatomical_entity>	develops_from;
	Phys_Container<Anatomical_entity>	venous_drainage;
	Phys_Container<Anatomical_entity>	regional_part;
	Phys_Container<Anatomical_entity>	bounded_by;
	Phys_Container<Anatomical_entity>	orientation;
	Phys_Container<Anatomical_entity>	arterial_supply;
	Phys_Container<Anatomical_entity>	has_inherent_3_D_shape;
	Phys_Container<Anatomical_entity>	attributed_part;
	Phys_Container<Anatomical_entity>	custom_partonomy_of;
	Phys_Container<Anatomical_entity>	nerve_supply;

};

#endif