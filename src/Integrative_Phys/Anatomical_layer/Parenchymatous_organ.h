//////////////////////////////////////////////////////
// Parenchymatous_organ
//////////////////////////////////////////////////////
#ifndef CLASS_Parenchymatous_organ
#define CLASS_Parenchymatous_organ

#include "Solid_organ.h"

class Parenchymatous_organ: public Solid_organ
{
public:
	Parenchymatous_organ();

	void 			add_orientation( FMAID* norientation );
	FMAID*			 getNext_orientation();
	void			reset_orientation();

	void 			add_location( FMAID* nlocation );
	FMAID*			 getNext_location();
	void			reset_location();
protected:
		Phys_Container<FMAID>	orientation;
	Phys_Container<FMAID>	location;
};

#endif