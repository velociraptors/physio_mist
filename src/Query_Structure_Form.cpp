#include "stdafx.h"
#include "Query_Structure_Form.h"

/*! \brief Queries for related structures based on selected relationship type
 *
 * 1. Determine selected relationship type
 * 2. MAGIC
 * 3. Display results in the listbox
*/
void Physio_MIST::Query_Structure_Form::query(System::String ^strName){
	//! \todo Implement query functionality

	String^ selectedType;
	for each (RadioButton^ rb in relationshipPanel->Controls){
		if(rb->Checked){
			selectedType = rb->Text;
		}
	}
}
