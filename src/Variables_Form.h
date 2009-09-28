#pragma once

#include "stdafx.h"
#include "FMA_Reader.h"

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using namespace System::Text::RegularExpressions;


namespace Physio_MIST {

	/// <summary>
	/// Summary for Variables_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Variables_Form : public System::Windows::Forms::Form
	{
	public:
		Variables_Form(void)
		{
			InitializeComponent();
		}

		Variables_Form(UI_Variable^ input_var)
		{
			InitializeComponent();

			Var = input_var;			
			nameTextBox->Text = Var->Name;
			formulaTextBox->Text = Var->Formula;
			initValTextBox->Text = (Var->Value).ToString();
			unitsTextBox->Text = Var->Units;
			descTextBox->Text = Var->Desc;
			structureTextBox->Text = Var->str_name;

			// save original structure so it can be reset if the user cancels
			old_str = Var->structure;
		}

		void attach_structure();

		// validation
		bool validName(String^ name, [Out]interior_ptr<String^> errorMessage);
		bool validFormula(String^ formula, [Out]interior_ptr<String^> errorMessage);
		bool validInitVal(String^ value, [Out]interior_ptr<String^> errorMessage);
		bool validUnits(String^ units, [Out]interior_ptr<String^> errorMessage);
		bool validDesc(String^ desc, [Out]interior_ptr<String^> errorMessage);

		property UI_Variable^ Var;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Variables_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Anatomical_structure *old_str;

	private: System::Windows::Forms::Label^  initValLabel;
	private: System::Windows::Forms::TextBox^  initValTextBox;
	private: System::Windows::Forms::Label^  formulaLabel;
	private: System::Windows::Forms::TextBox^  formulaTextBox;
	private: System::Windows::Forms::Label^  descLabel;
	private: System::Windows::Forms::TextBox^  descTextBox;


	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Label^  unitsLabel;
	private: System::Windows::Forms::TextBox^  unitsTextBox;


	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::Label^  structureLabel;
	private: System::Windows::Forms::TextBox^  structureTextBox;
	private: System::Windows::Forms::Button^  structureButton;
	private: System::Windows::Forms::ErrorProvider^  nameErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  formulaErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  initValErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  unitsErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  descErrorProvider;






	private: System::ComponentModel::IContainer^  components;


	protected: 

	protected: 

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
			this->initValLabel = (gcnew System::Windows::Forms::Label());
			this->initValTextBox = (gcnew System::Windows::Forms::TextBox());
			this->formulaLabel = (gcnew System::Windows::Forms::Label());
			this->formulaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->descLabel = (gcnew System::Windows::Forms::Label());
			this->descTextBox = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->unitsLabel = (gcnew System::Windows::Forms::Label());
			this->unitsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->structureLabel = (gcnew System::Windows::Forms::Label());
			this->structureTextBox = (gcnew System::Windows::Forms::TextBox());
			this->structureButton = (gcnew System::Windows::Forms::Button());
			this->nameErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->formulaErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->initValErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->unitsErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->descErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nameErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->formulaErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->initValErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unitsErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->descErrorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// initValLabel
			// 
			this->initValLabel->AutoSize = true;
			this->initValLabel->Location = System::Drawing::Point(10, 92);
			this->initValLabel->Name = L"initValLabel";
			this->initValLabel->Size = System::Drawing::Size(64, 13);
			this->initValLabel->TabIndex = 11;
			this->initValLabel->Text = L"Initial Value:";
			// 
			// initValTextBox
			// 
			this->initValTextBox->Location = System::Drawing::Point(12, 108);
			this->initValTextBox->Name = L"initValTextBox";
			this->initValTextBox->Size = System::Drawing::Size(100, 20);
			this->initValTextBox->TabIndex = 3;
			this->initValTextBox->Validated += gcnew System::EventHandler(this, &Variables_Form::initValTextBox_Validated);
			this->initValTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Variables_Form::initValTextBox_Validating);
			// 
			// formulaLabel
			// 
			this->formulaLabel->AutoSize = true;
			this->formulaLabel->Location = System::Drawing::Point(10, 53);
			this->formulaLabel->Name = L"formulaLabel";
			this->formulaLabel->Size = System::Drawing::Size(47, 13);
			this->formulaLabel->TabIndex = 10;
			this->formulaLabel->Text = L"Formula:";
			// 
			// formulaTextBox
			// 
			this->formulaTextBox->Location = System::Drawing::Point(12, 69);
			this->formulaTextBox->Name = L"formulaTextBox";
			this->formulaTextBox->Size = System::Drawing::Size(230, 20);
			this->formulaTextBox->TabIndex = 2;
			this->formulaTextBox->Validated += gcnew System::EventHandler(this, &Variables_Form::formulaTextBox_Validated);
			this->formulaTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Variables_Form::formulaTextBox_Validating);
			// 
			// descLabel
			// 
			this->descLabel->AutoSize = true;
			this->descLabel->Location = System::Drawing::Point(9, 204);
			this->descLabel->Name = L"descLabel";
			this->descLabel->Size = System::Drawing::Size(63, 13);
			this->descLabel->TabIndex = 15;
			this->descLabel->Text = L"Description:";
			// 
			// descTextBox
			// 
			this->descTextBox->AcceptsReturn = true;
			this->descTextBox->AcceptsTab = true;
			this->descTextBox->Location = System::Drawing::Point(12, 220);
			this->descTextBox->Multiline = true;
			this->descTextBox->Name = L"descTextBox";
			this->descTextBox->Size = System::Drawing::Size(100, 94);
			this->descTextBox->TabIndex = 6;
			this->descTextBox->Validated += gcnew System::EventHandler(this, &Variables_Form::descTextBox_Validated);
			this->descTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Variables_Form::descTextBox_Validating);
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(12, 331);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 7;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &Variables_Form::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(93, 331);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 8;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &Variables_Form::cancelButton_Click);
			// 
			// unitsLabel
			// 
			this->unitsLabel->AutoSize = true;
			this->unitsLabel->Location = System::Drawing::Point(139, 92);
			this->unitsLabel->Name = L"unitsLabel";
			this->unitsLabel->Size = System::Drawing::Size(34, 13);
			this->unitsLabel->TabIndex = 12;
			this->unitsLabel->Text = L"Units:";
			// 
			// unitsTextBox
			// 
			this->unitsTextBox->Location = System::Drawing::Point(142, 108);
			this->unitsTextBox->Name = L"unitsTextBox";
			this->unitsTextBox->Size = System::Drawing::Size(100, 20);
			this->unitsTextBox->TabIndex = 4;
			this->unitsTextBox->Validated += gcnew System::EventHandler(this, &Variables_Form::unitsTextBox_Validated);
			this->unitsTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Variables_Form::unitsTextBox_Validating);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(9, 14);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(38, 13);
			this->nameLabel->TabIndex = 9;
			this->nameLabel->Text = L"Name:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(13, 30);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(100, 20);
			this->nameTextBox->TabIndex = 1;
			this->nameTextBox->Validated += gcnew System::EventHandler(this, &Variables_Form::nameTextBox_Validated);
			this->nameTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Variables_Form::nameTextBox_Validating);
			// 
			// structureLabel
			// 
			this->structureLabel->AutoSize = true;
			this->structureLabel->Location = System::Drawing::Point(9, 136);
			this->structureLabel->Name = L"structureLabel";
			this->structureLabel->Size = System::Drawing::Size(108, 13);
			this->structureLabel->TabIndex = 13;
			this->structureLabel->Text = L"Anatomical Structure:";
			// 
			// structureTextBox
			// 
			this->structureTextBox->Location = System::Drawing::Point(12, 152);
			this->structureTextBox->Name = L"structureTextBox";
			this->structureTextBox->ReadOnly = true;
			this->structureTextBox->Size = System::Drawing::Size(230, 20);
			this->structureTextBox->TabIndex = 14;
			// 
			// structureButton
			// 
			this->structureButton->Location = System::Drawing::Point(12, 178);
			this->structureButton->Name = L"structureButton";
			this->structureButton->Size = System::Drawing::Size(184, 23);
			this->structureButton->TabIndex = 5;
			this->structureButton->Text = L"Associate Anatomical Structure";
			this->structureButton->UseVisualStyleBackColor = true;
			this->structureButton->Click += gcnew System::EventHandler(this, &Variables_Form::structureButton_Click);
			// 
			// nameErrorProvider
			// 
			this->nameErrorProvider->ContainerControl = this;
			// 
			// formulaErrorProvider
			// 
			this->formulaErrorProvider->ContainerControl = this;
			// 
			// initValErrorProvider
			// 
			this->initValErrorProvider->ContainerControl = this;
			// 
			// unitsErrorProvider
			// 
			this->unitsErrorProvider->ContainerControl = this;
			// 
			// descErrorProvider
			// 
			this->descErrorProvider->ContainerControl = this;
			// 
			// Variables_Form
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(270, 374);
			this->Controls->Add(this->structureButton);
			this->Controls->Add(this->structureTextBox);
			this->Controls->Add(this->structureLabel);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->unitsTextBox);
			this->Controls->Add(this->unitsLabel);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->descTextBox);
			this->Controls->Add(this->descLabel);
			this->Controls->Add(this->formulaTextBox);
			this->Controls->Add(this->formulaLabel);
			this->Controls->Add(this->initValTextBox);
			this->Controls->Add(this->initValLabel);
			this->Name = L"Variables_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Variables_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nameErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->formulaErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->initValErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unitsErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->descErrorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void structureButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 attach_structure();
			 structureTextBox->Text = Var->str_name;
		 }
private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Var->Name = nameTextBox->Text;
			 //! TODO: \todo add formula validation?
			 Var->Formula = formulaTextBox->Text;
			 Var->Value = Double::Parse(initValTextBox->Text);
			 Var->Units = unitsTextBox->Text;
			 Var->Desc = descTextBox->Text;

			 this->Close();
		 }
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Var->structure = old_str;
			 this->Close();
		 }
private: System::Void nameTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validName(nameTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 nameTextBox->SelectAll();

				 // set the error message text
				 nameErrorProvider->SetError(nameTextBox, errorMsg);
			 }
		 }
private: System::Void nameTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 nameErrorProvider->SetError(nameTextBox, "");
		 }
private: System::Void formulaTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validFormula(formulaTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 formulaTextBox->SelectAll();

				 // set the error message text
				 formulaErrorProvider->SetError(formulaTextBox, errorMsg);
			 }
		 }
private: System::Void formulaTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 formulaErrorProvider->SetError(formulaTextBox, "");
		 }
private: System::Void initValTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validInitVal(initValTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 initValTextBox->SelectAll();

				 // set the error message text
				 initValErrorProvider->SetError(initValTextBox, errorMsg);
			 }
		 }
private: System::Void initValTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 initValErrorProvider->SetError(initValTextBox, "");
		 }
private: System::Void unitsTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validUnits(unitsTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 unitsTextBox->SelectAll();

				 // set the error message text
				 unitsErrorProvider->SetError(unitsTextBox, errorMsg);
			 }
		 }
private: System::Void unitsTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 unitsErrorProvider->SetError(unitsTextBox, "");
		 }
private: System::Void descTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validDesc(descTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 descTextBox->SelectAll();

				 // set the error message text
				 descErrorProvider->SetError(descTextBox, errorMsg);
			 }
		 }
private: System::Void descTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 descErrorProvider->SetError(descTextBox, "");
		 }

	};
}
