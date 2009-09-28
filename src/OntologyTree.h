#pragma once

	


//! Data structure containing hierarchical anatomy
/*!
	Current data pulled from ontology.xml
	\note Should OntologyTree be a static class? Will it ever need to be instantiated?
*/
public ref class OntologyTree
{
public:
	//! Default constructor
	OntologyTree(void);

	//! Sucks data from xml file and populates TreeNode
	/*!
		\todo Document implementation/process
		\todo Remove hardcoded info such as rootNode.Text?
	*/
	System::Windows::Forms::TreeNode^ LoadOntology();

	//! \see LoadOntology()
	/*!
		Probably ought to replace LoadOntology() rather than hardcoding the file name
		\note Could set default fileName = "ontology.xml" and delete LoadOntology() ?
	*/
	System::Windows::Forms::TreeNode^ LoadOntology(System::String^ fileName);

private:
	System::String^ removePlusSigns(System::String^ str); /*!< replaces "+" with space, not currently used */
	System::String^ removeUnderscores(System::String^ str); /*!< replaces "_" with space */
};
