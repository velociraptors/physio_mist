
#ifndef _CIRCULATORY_SYSTEM_H
#define _CIRCULATORY_SYSTEM_H

#include "Link_layer.h"
#include "Semantic_Converter.h"
#include "factory.h"

namespace link_layer{


	
	class Circulatory_Mediator:public Mediator{
	public:

		void set_extrinsic_mediator(Mediator *ext_med);
		void set_intrinsic_mediator(Mediator* intr_med);
		void remove_component(Link_layer_Component* component);


		Mediator* get_extrinsic_mediator(){return extrinsic_mediator;};
		Mediator* get_intrinsic_mediator(){return intrinsic_mediator;};

		virtual Phys_Container<FMAID>* get_arterial_supply(){return NULL;};
		virtual Phys_Container<FMAID>* get_venous_drainage(){return NULL;};
		virtual Phys_Container<FMAID>* get_nerve_supply(){return NULL;};

		Component* get_blood_stream_component(Component *receiving_component,char *variable_name);


		Circulatory_Mediator();
		virtual ~Circulatory_Mediator();

	private:

		void add_component(Link_layer_Component *component);
		Mediator* extrinsic_mediator;
		Mediator* intrinsic_mediator;

	};

}

#endif
