//////////////////////////////////////////////////////
// Organ
//////////////////////////////////////////////////////
#ifndef CLASS_Organ
#define CLASS_Organ

#include "Anatomical_structure.h"

class Organ: public Anatomical_structure
{
public:
	Organ();

	void 			set_physical_state( Physical_State_Type nphysical_state );
	Physical_State_Type			 get_physical_state();

	void 			add_attributed_continuous_with( Anatomical_entity* nattributed_continuous_with );
	Anatomical_entity*			 getNext_attributed_continuous_with();
	void			reset_attributed_continuous_with();

	void 			add_lymphatic_drainage( Anatomical_entity* nlymphatic_drainage );
	Anatomical_entity*			 getNext_lymphatic_drainage();
	void			reset_lymphatic_drainage();

	void 			add_location( Anatomical_entity* nlocation );
	Anatomical_entity*			 getNext_location();
	void			reset_location();

	void 			add_member_of( Anatomical_entity* nmember_of );
	Anatomical_entity*			 getNext_member_of();
	void			reset_member_of();

	void 			add_segmental_supply( Anatomical_entity* nsegmental_supply );
	Anatomical_entity*			 getNext_segmental_supply();
	void			reset_segmental_supply();

	void 			add_bounded_by( Anatomical_entity* nbounded_by );
	Anatomical_entity*			 getNext_bounded_by();
	void			reset_bounded_by();

	void 			add_systemic_part( Anatomical_entity* nsystemic_part );
	Anatomical_entity*			 getNext_systemic_part();
	void			reset_systemic_part();

	void 			set_dimension( DimensionType ndimension );
	DimensionType			 get_dimension();

	void 			add_surrounded_by( Anatomical_entity* nsurrounded_by );
	Anatomical_entity*			 getNext_surrounded_by();
	void			reset_surrounded_by();

	void 			add_systemic_part_of( Anatomical_entity* nsystemic_part_of );
	Anatomical_entity*			 getNext_systemic_part_of();
	void			reset_systemic_part_of();

	void 			add_contained_in( Anatomical_entity* ncontained_in );
	Anatomical_entity*			 getNext_contained_in();
	void			reset_contained_in();

	void 			add_innervation( Anatomical_entity* ninnervation );
	Anatomical_entity*			 getNext_innervation();
	void			reset_innervation();

	void 			add_attributed_part( Anatomical_entity* nattributed_part );
	Anatomical_entity*			 getNext_attributed_part();
	void			reset_attributed_part();

	void 			add_nerve_supply( Anatomical_entity* nnerve_supply );
	Anatomical_entity*			 getNext_nerve_supply();
	void			reset_nerve_supply();

	void 			add_primary_site_of( Anatomical_entity* nprimary_site_of );
	Anatomical_entity*			 getNext_primary_site_of();
	void			reset_primary_site_of();
protected:
		
	Physical_State_Type	physical_state;
	Phys_Container<Anatomical_entity>	attributed_continuous_with;
	Phys_Container<Anatomical_entity>	lymphatic_drainage;
	Phys_Container<Anatomical_entity>	location;
	Phys_Container<Anatomical_entity>	member_of;
	Phys_Container<Anatomical_entity>	segmental_supply;
	Phys_Container<Anatomical_entity>	bounded_by;
	Phys_Container<Anatomical_entity>	systemic_part;
	DimensionType	dimension;
	Phys_Container<Anatomical_entity>	surrounded_by;
	Phys_Container<Anatomical_entity>	systemic_part_of;
	Phys_Container<Anatomical_entity>	contained_in;
	Phys_Container<Anatomical_entity>	innervation;
	Phys_Container<Anatomical_entity>	attributed_part;
	Phys_Container<Anatomical_entity>	nerve_supply;
	Phys_Container<Anatomical_entity>	primary_site_of;
};

#endif