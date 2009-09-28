//////////////////////////////////////////////////////
// Lobular_organ
//////////////////////////////////////////////////////
#ifndef CLASS_Lobular_organ
#define CLASS_Lobular_organ

#include "Parenchymatous_organ.h"

class Lobular_organ: public Parenchymatous_organ
{
public:
	Lobular_organ();

	void 			add_location( FMAID* nlocation );
	FMAID*			 getNext_location();
	void			reset_location();

	void 			add_clinical_part( FMAID* nclinical_part );
	FMAID*			 getNext_clinical_part();
	void			reset_clinical_part();

	void 			add_attributed_regional_part( FMAID* nattributed_regional_part );
	FMAID*			 getNext_attributed_regional_part();
	void			reset_attributed_regional_part();

	void 			add_clinical_part_of( FMAID* nclinical_part_of );
	FMAID*			 getNext_clinical_part_of();
	void			reset_clinical_part_of();
protected:
		Phys_Container<FMAID>	location;
	Phys_Container<FMAID>	clinical_part;
	Phys_Container<FMAID>	attributed_regional_part;
	Phys_Container<FMAID>	clinical_part_of;
};

#endif