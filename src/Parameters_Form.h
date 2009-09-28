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
	/// Summary for Parameters_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Parameters_Form : public System::Windows::Forms::Form
	{
	public:
		Parameters_Form(void)
		{
			InitializeComponent();
		}

		Parameters_Form(UI_Variable^ par)
		{
			InitializeComponent();

			Param = par;
			nameTextBox->Text = Param->Name;
			valueTextBox->Text = (Param->Value).ToString();
			unitsTextBox->Text = Param->Units;
			descTextBox->Text = Param->Desc;
			structureTextBox->Text = Param->str_name;

			// save original structure so it can be reset if the user cancels
			old_str = Param->structure;
		}

		void attach_structure();

		// validation
		bool validName(String^ name, [Out]interior_ptr<String^> errorMessage);
		bool validValue(String^ value, [Out]interior_ptr<String^> errorMessage);
		bool validUnits(String^ units, [Out]interior_ptr<String^> errorMessage);
		bool validDesc(String^ desc, [Out]interior_ptr<String^> errorMessage); // is this needed?

		property UI_Variable^ Param;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Parameters_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Anatomical_structure *old_str;

	private: System::Windows::Forms::Label^  valueLabel;
	private: System::Windows::Forms::TextBox^  valueTextBox;
	private: System::Windows::Forms::Label^  descLabel;
	private: System::Windows::Forms::TextBox^  descTextBox;
	protected: 










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
	private: System::Windows::Forms::ErrorProvider^  valueErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  unitsErrorProvider;
	private: System::Windows::Forms::ErrorProvider^  descErrorProvider;





	private: System::ComponentModel::IContainer^  components;

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
			this->valueLabel = (gcnew System::Windows::Forms::Label());
			this->valueTextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->valueErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->unitsErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->descErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nameErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->valueErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unitsErrorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->descErrorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// valueLabel
			// 
			this->valueLabel->AutoSize = true;
			this->valueLabel->Location = System::Drawing::Point(12, 48);
			this->valueLabel->Name = L"valueLabel";
			this->valueLabel->Size = System::Drawing::Size(37, 13);
			this->valueLabel->TabIndex = 9;
			this->valueLabel->Text = L"Value:";
			// 
			// valueTextBox
			// 
			this->valueTextBox->Location = System::Drawing::Point(15, 64);
			this->valueTextBox->Name = L"valueTextBox";
			this->valueTextBox->Size = System::Drawing::Size(100, 20);
			this->valueTextBox->TabIndex = 2;
			this->valueTextBox->Validated += gcnew System::EventHandler(this, &Parameters_Form::valueTextBox_Validated);
			this->valueTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Parameters_Form::valueTextBox_Validating);
			// 
			// descLabel
			// 
			this->descLabel->AutoSize = true;
			this->descLabel->Location = System::Drawing::Point(12, 155);
			this->descLabel->Name = L"descLabel";
			this->descLabel->Size = System::Drawing::Size(63, 13);
			this->descLabel->TabIndex = 13;
			this->descLabel->Text = L"Description:";
			// 
			// descTextBox
			// 
			this->descTextBox->AcceptsReturn = true;
			this->descTextBox->AcceptsTab = true;
			this->descTextBox->Location = System::Drawing::Point(15, 171);
			this->descTextBox->Multiline = true;
			this->descTextBox->Name = L"descTextBox";
			this->descTextBox->Size = System::Drawing::Size(100, 85);
			this->descTextBox->TabIndex = 5;
			this->descTextBox->Validated += gcnew System::EventHandler(this, &Parameters_Form::descTextBox_Validated);
			this->descTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Parameters_Form::descTextBox_Validating);
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(15, 271);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 6;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &Parameters_Form::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(96, 271);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 7;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &Parameters_Form::cancelButton_Click);
			// 
			// unitsLabel
			// 
			this->unitsLabel->AutoSize = true;
			this->unitsLabel->Location = System::Drawing::Point(136, 48);
			this->unitsLabel->Name = L"unitsLabel";
			this->unitsLabel->Size = System::Drawing::Size(34, 13);
			this->unitsLabel->TabIndex = 10;
			this->unitsLabel->Text = L"Units:";
			// 
			// unitsTextBox
			// 
			this->unitsTextBox->Location = System::Drawing::Point(139, 64);
			this->unitsTextBox->Name = L"unitsTextBox";
			this->unitsTextBox->Size = System::Drawing::Size(100, 20);
			this->unitsTextBox->TabIndex = 3;
			this->unitsTextBox->Validated += gcnew System::EventHandler(this, &Parameters_Form::unitsTextBox_Validated);
			this->unitsTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Parameters_Form::unitsTextBox_Validating);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(12, 9);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(38, 13);
			this->nameLabel->TabIndex = 8;
			this->nameLabel->Text = L"Name:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(15, 25);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(100, 20);
			this->nameTextBox->TabIndex = 1;
			this->nameTextBox->Validated += gcnew System::EventHandler(this, &Parameters_Form::nameTextBox_Validated);
			this->nameTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Parameters_Form::nameTextBox_Validating);
			// 
			// structureLabel
			// 
			this->structureLabel->AutoSize = true;
			this->structureLabel->Location = System::Drawing::Point(12, 87);
			this->structureLabel->Name = L"structureLabel";
			this->structureLabel->Size = System::Drawing::Size(108, 13);
			this->structureLabel->TabIndex = 11;
			this->structureLabel->Text = L"Anatomical Structure:";
			// 
			// structureTextBox
			// 
			this->structureTextBox->Location = System::Drawing::Point(15, 103);
			this->structureTextBox->Name = L"structureTextBox";
			this->structureTextBox->ReadOnly = true;
			this->structureTextBox->Size = System::Drawing::Size(224, 20);
			this->structureTextBox->TabIndex = 12;
			// 
			// structureButton
			// 
			this->structureButton->Location = System::Drawing::Point(15, 129);
			this->structureButton->Name = L"structureButton";
			this->structureButton->Size = System::Drawing::Size(180, 23);
			this->structureButton->TabIndex = 4;
			this->structureButton->Text = L"Associate Anatomical Structure";
			this->structureButton->UseVisualStyleBackColor = true;
			this->structureButton->Click += gcnew System::EventHandler(this, &Parameters_Form::structureButton_Click);
			// 
			// nameErrorProvider
			// 
			this->nameErrorProvider->ContainerControl = this;
			// 
			// valueErrorProvider
			// 
			this->valueErrorProvider->ContainerControl = this;
			// 
			// unitsErrorProvider
			// 
			this->unitsErrorProvider->ContainerControl = this;
			// 
			// descErrorProvider
			// 
			this->descErrorProvider->ContainerControl = this;
			// 
			// Parameters_Form
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(264, 307);
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
			this->Controls->Add(this->valueTextBox);
			this->Controls->Add(this->valueLabel);
			this->Name = L"Parameters_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Parameters_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nameErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->valueErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unitsErrorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->descErrorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void structureButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 attach_structure();
			 structureTextBox->Text = Param->str_name;
		 }
private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Param->Name = nameTextBox->Text;
			 Param->Value = Double::Parse(valueTextBox->Text);
			 Param->Units = unitsTextBox->Text;
			 Param->Desc = descTextBox->Text;

			 this->Close();
		 }
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Param->structure = old_str;
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
private: System::Void valueTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 String^ errorMsg;
			 if( !validValue(valueTextBox->Text, &errorMsg) ){
				 // cancel the event and select the text
				 e->Cancel = true;
				 valueTextBox->SelectAll();

				 // set the error message text
				 valueErrorProvider->SetError(valueTextBox, errorMsg);
			 }
		 }
private: System::Void valueTextBox_Validated(System::Object^  sender, System::EventArgs^  e) {
			 valueErrorProvider->SetError(valueTextBox, "");
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
