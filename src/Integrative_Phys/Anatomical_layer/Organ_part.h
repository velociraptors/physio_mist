//////////////////////////////////////////////////////
// Organ_part
//////////////////////////////////////////////////////
#ifndef CLASS_Organ_part
#define CLASS_Organ_part

#include "Anatomical_structure.h"

class Organ_part: public Anatomical_structure
{
public:
	Organ_part();

	void 			add_systemic_part( Anatomical_entity* nsystemic_part );
	Anatomical_entity*			 getNext_systemic_part();
	void			reset_systemic_part();

	void 			add_lymphatic_drainage( Anatomical_entity* nlymphatic_drainage );
	Anatomical_entity*			 getNext_lymphatic_drainage();
	void			reset_lymphatic_drainage();

	void 			add_attaches_to( Anatomical_entity* nattaches_to );
	Anatomical_entity*			 getNext_attaches_to();
	void			reset_attaches_to();

	void 			add_member_of( Anatomical_entity* nmember_of );
	Anatomical_entity*			 getNext_member_of();
	void			reset_member_of();

	void 			add_continuous_with_proximally( Anatomical_entity* ncontinuous_with_proximally );
	Anatomical_entity*			 getNext_continuous_with_proximally();
	void			reset_continuous_with_proximally();

	void 			add_sends_output_to( Anatomical_entity* nsends_output_to );
	Anatomical_entity*			 getNext_sends_output_to();
	void			reset_sends_output_to();

	void 			add_continuous_with_distally( Anatomical_entity* ncontinuous_with_distally );
	Anatomical_entity*			 getNext_continuous_with_distally();
	void			reset_continuous_with_distally();

	void 			add_segmental_supply( Anatomical_entity* nsegmental_supply );
	Anatomical_entity*			 getNext_segmental_supply();
	void			reset_segmental_supply();

	void 			add_receives_input_from( Anatomical_entity* nreceives_input_from );
	Anatomical_entity*			 getNext_receives_input_from();
	void			reset_receives_input_from();
protected:
		Phys_Container<Anatomical_entity>	systemic_part;
	Phys_Container<Anatomical_entity>	lymphatic_drainage;
	Phys_Container<Anatomical_entity>	attaches_to;
	Phys_Container<Anatomical_entity>	member_of;
	Phys_Container<Anatomical_entity>	continuous_with_proximally;
	Phys_Container<Anatomical_entity>	sends_output_to;
	Phys_Container<Anatomical_entity>	continuous_with_distally;
	Phys_Container<Anatomical_entity>	segmental_supply;
	Phys_Container<Anatomical_entity>	receives_input_from;
};

#endif