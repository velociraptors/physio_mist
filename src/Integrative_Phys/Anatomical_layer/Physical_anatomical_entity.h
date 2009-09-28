//////////////////////////////////////////////////////
// Physical_anatomical_entity
//////////////////////////////////////////////////////
#ifndef CLASS_Physical_anatomical_entity
#define CLASS_Physical_anatomical_entity

#include "Anatomical_entity.h"

class Physical_anatomical_entity: public Anatomical_entity
{
public:
	Physical_anatomical_entity();

	void 			set_has_boundary( bool nhas_boundary );
	bool			 get_has_boundary();

	void 			set_dimension( DimensionType ndimension );
	DimensionType			 get_dimension();

	void 			add_has_dimension( Anatomical_entity* nhas_dimension );
	Anatomical_entity*			 getNext_has_dimension();
	void			reset_has_dimension();
protected:
		bool	has_boundary;
	DimensionType	dimension;
	Phys_Container<Anatomical_entity>	has_dimension;
};

#endif