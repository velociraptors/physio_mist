//////////////////////////////////////////////////////
// Solid_organ
//////////////////////////////////////////////////////
#ifndef CLASS_Solid_organ
#define CLASS_Solid_organ

#include "Organ.h"

class Solid_organ: public Organ
{
public:
	Solid_organ();

	void 			add_attributed_continuous_with( FMAID* nattributed_continuous_with );
	FMAID*			 getNext_attributed_continuous_with();
	void			reset_attributed_continuous_with();

	void 			add_location( FMAID* nlocation );
	FMAID*			 getNext_location();
	void			reset_location();

	void 			add_sends_output_to( FMAID* nsends_output_to );
	FMAID*			 getNext_sends_output_to();
	void			reset_sends_output_to();

	void 			add_bounded_by( FMAID* nbounded_by );
	FMAID*			 getNext_bounded_by();
	void			reset_bounded_by();

	void 			add_receives_input_from( FMAID* nreceives_input_from );
	FMAID*			 getNext_receives_input_from();
	void			reset_receives_input_from();
protected:
		
	Phys_Container<FMAID>	attributed_continuous_with;
	Phys_Container<FMAID>	location;
	Phys_Container<FMAID>	sends_output_to;
	Phys_Container<FMAID>	bounded_by;
	Phys_Container<FMAID>	receives_input_from;
};

#endif