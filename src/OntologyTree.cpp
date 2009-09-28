#include "StdAfx.h"
#include "OntologyTree.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Xml;
OntologyTree::OntologyTree(void)
{
}

String^ OntologyTree::removePlusSigns(String ^str)
{
	String^ str2 = str->Replace("+", " ");
	return str2;
}

String^ OntologyTree::removeUnderscores(String ^str)
{
	String^ str2 = str->Replace("_", " ");
	return str2;
}

TreeNode^ OntologyTree::LoadOntology(String ^fileName)
{
	XmlReaderSettings^ settings = gcnew XmlReaderSettings();
	settings->IgnoreWhitespace = true;
	XmlReader^ reader = XmlReader::Create(fileName, settings);

	TreeNode^ rootNode = gcnew TreeNode("ontology");

	TreeNode^ currentNode = gcnew TreeNode;
	currentNode = rootNode;
	String^ nodeText = "";

	while( reader->Read() )
	{
		if(reader->NodeType == XmlNodeType::XmlDeclaration)
		{
			reader->Read();
		}

		nodeText = removeUnderscores(reader->Name);
		TreeNode^ newNode = gcnew TreeNode(nodeText);
		if( nodeText == "ontology")
		{
			currentNode = rootNode;
		}
		else
		{
			if( reader->IsStartElement() )
			{
				if(reader->IsEmptyElement)
				{
					currentNode->Nodes->Insert(currentNode->Nodes->Count, newNode);
					currentNode = newNode->Parent;
				}
				else
				{
					currentNode->Nodes->Insert(currentNode->Nodes->Count, newNode);
					currentNode = currentNode->Nodes[currentNode->Nodes->IndexOf(newNode)];
				}
			}
			else if(reader->NodeType == XmlNodeType::EndElement)
			{
				if(currentNode->Parent == nullptr)
				{
					currentNode = rootNode;
				}
				else
				{
					currentNode = currentNode->Parent;
				}
			}
			else
			{
				rootNode->Nodes->Insert(rootNode->Nodes->Count, newNode);
				currentNode = rootNode->Nodes[rootNode->Nodes->IndexOf(newNode)];
			}
		}
	}
	reader->Close();

	return rootNode;
}

TreeNode^ OntologyTree::LoadOntology()
{
	String^ fileName = "ontology.xml";

	XmlReaderSettings^ settings = gcnew XmlReaderSettings();
	settings->IgnoreWhitespace = true;
	XmlReader^ reader = XmlReader::Create(fileName, settings);

	TreeNode^ rootNode = gcnew TreeNode("ontology");

	TreeNode^ currentNode = gcnew TreeNode;
	currentNode = rootNode;
	String^ nodeText = "";

	while( reader->Read() )
	{
		if(reader->NodeType == XmlNodeType::XmlDeclaration)
		{
			reader->Read();
		}

		nodeText = removeUnderscores(reader->Name);
		TreeNode^ newNode = gcnew TreeNode(nodeText);
		if( nodeText == "ontology")
		{
			currentNode = rootNode;
		}
		else
		{
			if( reader->IsStartElement() )
			{
				if(reader->IsEmptyElement)
				{
					currentNode->Nodes->Insert(currentNode->Nodes->Count, newNode);
					currentNode = newNode->Parent;
				}
				else
				{
					currentNode->Nodes->Insert(currentNode->Nodes->Count, newNode);
					currentNode = currentNode->Nodes[currentNode->Nodes->IndexOf(newNode)];
				}
			}
			else if(reader->NodeType == XmlNodeType::EndElement)
			{
				if(currentNode->Parent == nullptr)
				{
					currentNode = rootNode;
				}
				else
				{
					currentNode = currentNode->Parent;
				}
			}
			else
			{
				rootNode->Nodes->Insert(rootNode->Nodes->Count, newNode);
				currentNode = rootNode->Nodes[rootNode->Nodes->IndexOf(newNode)];
			}
		}
	}
	reader->Close();

	return rootNode;
}