//////////////////////////////////////////////////////
// Material_physical_anatomical_entity
//////////////////////////////////////////////////////
#ifndef CLASS_Material_physical_anatomical_entity
#define CLASS_Material_physical_anatomical_entity

#include "Physical_anatomical_entity.h"

class Material_physical_anatomical_entity: public Physical_anatomical_entity
{
public:
	Material_physical_anatomical_entity();

	void 			set_has_boundary( bool nhas_boundary );
	bool			 get_has_boundary();

	void 			set_physical_state( Physical_State_Type nphysical_state );
	Physical_State_Type			 get_physical_state();

	void 			add_attributed_continuous_with( Anatomical_entity* nattributed_continuous_with );
	Anatomical_entity*			 getNext_attributed_continuous_with();
	void			reset_attributed_continuous_with();

	void 			set_dimension( DimensionType ndimension );
	DimensionType			 get_dimension();

	void 			set_has_mass( bool nhas_mass );
	bool			 get_has_mass();

	void 			add_has_shape( Anatomical_entity* nhas_shape );
	Anatomical_entity*			 getNext_has_shape();
	void			reset_has_shape();

	void 			add_continuous_with( Anatomical_entity* ncontinuous_with );
	Anatomical_entity*			 getNext_continuous_with();
	void			reset_continuous_with();
protected:
		bool	has_boundary;
	Physical_State_Type	physical_state;
	Phys_Container<Anatomical_entity>	attributed_continuous_with;
	DimensionType	dimension;
	bool	has_mass;
	Phys_Container<Anatomical_entity>	has_shape;
	Phys_Container<Anatomical_entity>	continuous_with;
};

#endif