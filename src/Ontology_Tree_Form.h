#pragma once
//#include "stdafx.h"
#include "Query_Structure_Form.h"

namespace Physio_MIST {

	/// <summary>
	/// Summary for Ontology_Tree_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Ontology_Tree_Form : public System::Windows::Forms::Form
	{
	public:
		Ontology_Tree_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			 ontologyTreeView->BeginUpdate();
			 ontologyTreeView->Nodes->Clear();

			 ontology = gcnew OntologyTree();
			 rootNode = gcnew System::Windows::Forms::TreeNode;
			 rootNode = ontology->LoadOntology();
			 ontologyTreeView->Nodes->Add(rootNode);

			 ontologyTreeView->EndUpdate();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ontology_Tree_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TreeView^  ontologyTreeView;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  queryStructureMenuItem;

	private: Query_Structure_Form^ queryStructure;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ontologyTreeView = (gcnew System::Windows::Forms::TreeView());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->queryStructureMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// ontologyTreeView
			// 
			this->ontologyTreeView->ContextMenuStrip = this->contextMenuStrip;
			this->ontologyTreeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ontologyTreeView->Location = System::Drawing::Point(0, 0);
			this->ontologyTreeView->Name = L"ontologyTreeView";
			this->ontologyTreeView->Size = System::Drawing::Size(292, 666);
			this->ontologyTreeView->TabIndex = 0;
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->queryStructureMenuItem});
			this->contextMenuStrip->Name = L"contextMenuStrip";
			this->contextMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStrip->ShowImageMargin = false;
			this->contextMenuStrip->Size = System::Drawing::Size(186, 48);
			// 
			// queryStructureMenuItem
			// 
			this->queryStructureMenuItem->Name = L"queryStructureMenuItem";
			this->queryStructureMenuItem->Size = System::Drawing::Size(185, 22);
			this->queryStructureMenuItem->Text = L"Find Related Structures...";
			this->queryStructureMenuItem->Click += gcnew System::EventHandler(this, &Ontology_Tree_Form::queryStructureMenuItem_Click);
			// 
			// Ontology_Tree_Form
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(292, 666);
			this->Controls->Add(this->ontologyTreeView);
			this->Name = L"Ontology_Tree_Form";
			this->ShowInTaskbar = false;
			this->Text = L"Ontology";
			this->Load += gcnew System::EventHandler(this, &Ontology_Tree_Form::Ontology_Tree_Form_Load);
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private:
	OntologyTree^ ontology;
	System::Windows::Forms::TreeNode^ rootNode;
	private: System::Void Ontology_Tree_Form_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void queryStructureMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 queryStructure = gcnew Query_Structure_Form(ontologyTreeView->SelectedNode->Text);
				 //queryStructure->MdiParent = this;
				 queryStructure->ShowDialog();
			 }
	};
}
