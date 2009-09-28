//////////////////////////////////////////////////////
// Liver
//////////////////////////////////////////////////////
#ifndef CLASS_Liver
#define CLASS_Liver

#include "Lobular_organ.h"
#include "ListContainer.h"
class Liver: public Lobular_organ
{
public:
	static Liver* getInstance();


	void 			add_systemic_part_of( Anatomical_structure* nsystemic_part_of );
	Anatomical_structure*			 getNext_systemic_part_of();
	void			reset_systemic_part_of();

	void 			add_regional_part( Anatomical_structure* nregional_part );
	Anatomical_structure*			 getNext_regional_part();
	void			reset_regional_part();

	void 			add_part_of( Anatomical_structure* npart_of );
	Anatomical_structure*			 getNext_part_of();
	void			reset_part_of();

	void 			add_part( Anatomical_structure* npart );
	Anatomical_structure*			 getNext_part();
	void			reset_part();


	void 			set_member_of( Anatomical_structure* nmember_of );
	Anatomical_structure*			 get_member_of();

	void 			set_lymphatic_drainage( Anatomical_structure* nlymphatic_drainage );
	Anatomical_structure*			 get_lymphatic_drainage();

	void 			set_inherent_3_D_shape( Anatomical_structure* ninherent_3_D_shape );
	Anatomical_structure*			 get_inherent_3_D_shape();


	void 			set_develops_from( Anatomical_structure* ndevelops_from );
	Anatomical_structure*			 get_develops_from();

	void 			set_definition( char* ndefinition );
	char*			 get_definition();

	void 			set_contained_in( Anatomical_structure* ncontained_in );
	Anatomical_structure*			 get_contained_in();

	void 			add_constitutional_part( Anatomical_structure* nconstitutional_part );
	Anatomical_structure*			 getNext_constitutional_part();
	void			reset_constitutional_part();

	void 			add_clinical_part( Anatomical_structure* nclinical_part );
	Anatomical_structure*			 getNext_clinical_part();
	void			reset_clinical_part();

	void 			set_bounded_by( Anatomical_structure* nbounded_by );
	Anatomical_structure*			 get_bounded_by();

	/*virtual void 			set_venous_drainage( Phys_Container<Anatomical_structure>* nvenous_drainage );
	virtual Phys_Container<Anatomical_structure>*			 get_venous_drainage();

	virtual void 			set_nerve_supply( Phys_Container<Anatomical_structure>* nnerve_supply );
	virtual Phys_Container<Anatomical_structure>*			 get_nerve_supply();

	virtual void 			set_arterial_supply( Phys_Container<Anatomical_structure>* narterial_supply );
	virtual Phys_Container<Anatomical_structure>*			 get_arterial_supply();

*/
	
protected:
	Liver();
private:
	
	ListContainer<Anatomical_structure>	systemic_part_of;
	ListContainer<Anatomical_structure>	regional_part;
	ListContainer<Anatomical_structure>	part_of;
	ListContainer<Anatomical_structure>	part;
	
	Anatomical_structure	*member_of;
	Anatomical_structure	*lymphatic_drainage;
	Anatomical_structure	*inherent_3_D_shape;
	Anatomical_structure	*develops_from;
	Anatomical_structure	*contained_in;
	ListContainer<Anatomical_structure>	constitutional_part;
	ListContainer<Anatomical_structure>	clinical_part;
	Anatomical_structure	*bounded_by;
	
};

#endif