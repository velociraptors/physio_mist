#pragma once
#include "stdafx.h"
#include "Structures_Form.h"
#include "Parameters_Form.h"
#include "Variables_Form.h"
#include "OntologyTree.h"



namespace Physio_MIST {

	/// <summary>
	/// Summary for Custom_Model_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Custom_Model_Form : public System::Windows::Forms::Form
	{
	public:
		Custom_Model_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			Model = gcnew CustomModel();
			testData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Custom_Model_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 



	private: System::Windows::Forms::Label^  structuresLabel;

	private: System::Windows::Forms::Button^  structsButton;
	private: System::Windows::Forms::Label^  parametersLabel;
	private: System::Windows::Forms::ListBox^  parametersListBox;
	private: System::Windows::Forms::Button^  parametersButton;
	private: System::Windows::Forms::Label^  variablesLabel;

	private: System::Windows::Forms::ListBox^  variablesListBox;
	private: System::Windows::Forms::Button^  variablesButton;

	private: System::Windows::Forms::BindingSource^  customModelBindingSource;
	private: System::Windows::Forms::ListBox^  structuresListBox;
	private: System::Windows::Forms::BindingSource^  structuresBindingSource;
	private: System::Windows::Forms::BindingSource^  paramListBindingSource;

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
			this->structuresLabel = (gcnew System::Windows::Forms::Label());
			this->customModelBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->structsButton = (gcnew System::Windows::Forms::Button());
			this->parametersLabel = (gcnew System::Windows::Forms::Label());
			this->parametersListBox = (gcnew System::Windows::Forms::ListBox());
			this->paramListBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->structuresBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->parametersButton = (gcnew System::Windows::Forms::Button());
			this->variablesLabel = (gcnew System::Windows::Forms::Label());
			this->variablesListBox = (gcnew System::Windows::Forms::ListBox());
			this->variablesButton = (gcnew System::Windows::Forms::Button());
			this->structuresListBox = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customModelBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramListBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->structuresBindingSource))->BeginInit();
			this->SuspendLayout();
			// 
			// structuresLabel
			// 
			this->structuresLabel->AutoSize = true;
			this->structuresLabel->Location = System::Drawing::Point(13, 28);
			this->structuresLabel->Name = L"structuresLabel";
			this->structuresLabel->Size = System::Drawing::Size(55, 13);
			this->structuresLabel->TabIndex = 1;
			this->structuresLabel->Text = L"Structures";
			// 
			// customModelBindingSource
			// 
			this->customModelBindingSource->DataSource = CustomModel::typeid;
			// 
			// structsButton
			// 
			this->structsButton->Location = System::Drawing::Point(13, 300);
			this->structsButton->Name = L"structsButton";
			this->structsButton->Size = System::Drawing::Size(120, 23);
			this->structsButton->TabIndex = 3;
			this->structsButton->Text = L"Edit Structures";
			this->structsButton->UseVisualStyleBackColor = true;
			this->structsButton->Click += gcnew System::EventHandler(this, &Custom_Model_Form::editStructuresClick);
			// 
			// parametersLabel
			// 
			this->parametersLabel->AutoSize = true;
			this->parametersLabel->Location = System::Drawing::Point(140, 28);
			this->parametersLabel->Name = L"parametersLabel";
			this->parametersLabel->Size = System::Drawing::Size(60, 13);
			this->parametersLabel->TabIndex = 4;
			this->parametersLabel->Text = L"Parameters";
			// 
			// parametersListBox
			// 
			this->parametersListBox->DataSource = this->paramListBindingSource;
			this->parametersListBox->DisplayMember = L"Name";
			this->parametersListBox->FormattingEnabled = true;
			this->parametersListBox->Location = System::Drawing::Point(140, 45);
			this->parametersListBox->Name = L"parametersListBox";
			this->parametersListBox->Size = System::Drawing::Size(120, 251);
			this->parametersListBox->TabIndex = 5;
			this->parametersListBox->ValueMember = L"Name";
			// 
			// paramListBindingSource
			// 
			this->paramListBindingSource->DataSource = this->structuresBindingSource;
			// 
			// structuresBindingSource
			// 
			this->structuresBindingSource->DataMember = L"Structures";
			this->structuresBindingSource->DataSource = this->customModelBindingSource;
			this->structuresBindingSource->CurrentChanged += gcnew System::EventHandler(this, &Custom_Model_Form::structuresBindingSource_CurrentChanged);
			// 
			// parametersButton
			// 
			this->parametersButton->Location = System::Drawing::Point(139, 300);
			this->parametersButton->Name = L"parametersButton";
			this->parametersButton->Size = System::Drawing::Size(120, 23);
			this->parametersButton->TabIndex = 6;
			this->parametersButton->Text = L"Edit Parameters";
			this->parametersButton->UseVisualStyleBackColor = true;
			this->parametersButton->Click += gcnew System::EventHandler(this, &Custom_Model_Form::editParametersClick);
			// 
			// variablesLabel
			// 
			this->variablesLabel->AutoSize = true;
			this->variablesLabel->Location = System::Drawing::Point(266, 28);
			this->variablesLabel->Name = L"variablesLabel";
			this->variablesLabel->Size = System::Drawing::Size(50, 13);
			this->variablesLabel->TabIndex = 7;
			this->variablesLabel->Text = L"Variables";
			// 
			// variablesListBox
			// 
			this->variablesListBox->FormattingEnabled = true;
			this->variablesListBox->Location = System::Drawing::Point(266, 45);
			this->variablesListBox->Name = L"variablesListBox";
			this->variablesListBox->Size = System::Drawing::Size(120, 251);
			this->variablesListBox->TabIndex = 8;
			// 
			// variablesButton
			// 
			this->variablesButton->Location = System::Drawing::Point(265, 300);
			this->variablesButton->Name = L"variablesButton";
			this->variablesButton->Size = System::Drawing::Size(120, 23);
			this->variablesButton->TabIndex = 9;
			this->variablesButton->Text = L"Edit Variables";
			this->variablesButton->UseVisualStyleBackColor = true;
			this->variablesButton->Click += gcnew System::EventHandler(this, &Custom_Model_Form::editVariablesClick);
			// 
			// structuresListBox
			// 
			this->structuresListBox->DataSource = this->structuresBindingSource;
			this->structuresListBox->DisplayMember = L"Name";
			this->structuresListBox->FormattingEnabled = true;
			this->structuresListBox->Location = System::Drawing::Point(13, 45);
			this->structuresListBox->Name = L"structuresListBox";
			this->structuresListBox->Size = System::Drawing::Size(120, 251);
			this->structuresListBox->TabIndex = 2;
			this->structuresListBox->ValueMember = L"Name";
			this->structuresListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Custom_Model_Form::structuresListBox_SelectedIndexChanged);
			// 
			// Custom_Model_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 340);
			this->Controls->Add(this->variablesButton);
			this->Controls->Add(this->variablesListBox);
			this->Controls->Add(this->variablesLabel);
			this->Controls->Add(this->parametersButton);
			this->Controls->Add(this->parametersListBox);
			this->Controls->Add(this->parametersLabel);
			this->Controls->Add(this->structsButton);
			this->Controls->Add(this->structuresListBox);
			this->Controls->Add(this->structuresLabel);
			this->Name = L"Custom_Model_Form";
			this->Text = L"Custom Model";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customModelBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramListBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->structuresBindingSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void editStructuresClick(System::Object^  sender, System::EventArgs^  e) {
			 Structures_Form^ ontologyDialog = gcnew Structures_Form();
			 ontologyDialog->ShowDialog();
		 }
private: System::Void editParametersClick(System::Object^  sender, System::EventArgs^  e) {
			 Parameters_Form^ parametersDialog = gcnew Parameters_Form();
			 parametersDialog->ShowDialog();
		 }
private: System::Void editVariablesClick(System::Object^  sender, System::EventArgs^  e) {
			 Variables_Form^ variablesDialog = gcnew Variables_Form();
			 variablesDialog->ShowDialog();
		 }
private: System::Void structuresListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 selectedStruct = (AnatomicalStruct^)structuresListBox->SelectedItem;
			 //parametersListBox->DataSource = selectedStruct->ParamList;
			 parametersListBox->DisplayMember = "Name";
			 //variablesListBox->DataSource = selectedStruct->VarsList;
			 variablesListBox->DisplayMember = "Name";
		 }

public:
	property CustomModel^ Model;
private:
	AnatomicalStruct^ selectedStruct;

private:
	void Custom_Model_Form::testData()
	{
		AnatomicalStruct ^ str1 = gcnew AnatomicalStruct();
		AnatomicalStruct ^ str2 = gcnew AnatomicalStruct();
		str1->Name = "A";
		str2->Name = "B";

		UI_Variable^ var1 = gcnew UI_Variable();
		var1->Name = "v1";
		UI_Variable^ var2 = gcnew UI_Variable();
		var2->Name = "v2";
		UI_Variable^ var3 = gcnew UI_Variable();
		var3->Name = "v2";
		UI_Variable^ var4 = gcnew UI_Variable();
		var4->Name = "v4";
		UI_Variable^ var5 = gcnew UI_Variable();
		var5->Name = "v5";

/*		str1->addVar(var1);
		str1->addVar(var2);
		str1->addVar(var3);
		str2->addVar(var1);
		str2->addVar(var4);
		str2->addVar(var5);
		str1->addParam(var1);
		str2->addParam(var2);*/

		Model->addStructure(str1);
		Model->addStructure(str2);

		this->structuresBindingSource->DataSource = Model->Structures;

		//OntologyTree^ ontology = gcnew OntologyTree();
		//TreeNode^ root = gcnew TreeNode;
		//root = ontology->LoadOntology();
	}
private: System::Void structuresBindingSource_CurrentChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
