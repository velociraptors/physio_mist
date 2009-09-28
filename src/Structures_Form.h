#pragma once
#include "stdafx.h"


namespace Physio_MIST {

	/// <summary>
	/// Summary for Structures_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Structures_Form : public System::Windows::Forms::Form
	{
	public:
		Structures_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			tempStructures = gcnew System::Collections::Generic::List<AnatomicalStruct^>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Structures_Form()
		{
			if (components)
			{
				delete components;
			}
		}


	protected: 

	private: System::Windows::Forms::Button^  addStructButton;
	private: System::Windows::Forms::Label^  modelNameLabel;

	private: System::Windows::Forms::ListBox^  modelStructsListBox;

	private: System::Windows::Forms::Button^  removeStructButton;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::BindingSource^  structuresBindingSource;
	private: System::Windows::Forms::BindingSource^  customModelBindingSource;
	private: System::Windows::Forms::Label^  instructionsLabel;
	private: System::Windows::Forms::Button^  cancelButton;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->addStructButton = (gcnew System::Windows::Forms::Button());
			this->modelNameLabel = (gcnew System::Windows::Forms::Label());
			this->modelStructsListBox = (gcnew System::Windows::Forms::ListBox());
			this->structuresBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->customModelBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->removeStructButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->instructionsLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->structuresBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customModelBindingSource))->BeginInit();
			this->SuspendLayout();
			// 
			// addStructButton
			// 
			this->addStructButton->Location = System::Drawing::Point(140, 74);
			this->addStructButton->Name = L"addStructButton";
			this->addStructButton->Size = System::Drawing::Size(121, 36);
			this->addStructButton->TabIndex = 2;
			this->addStructButton->Text = L"Add Selected Structure";
			this->addStructButton->UseVisualStyleBackColor = true;
			// 
			// modelNameLabel
			// 
			this->modelNameLabel->AutoSize = true;
			this->modelNameLabel->Location = System::Drawing::Point(12, 9);
			this->modelNameLabel->Name = L"modelNameLabel";
			this->modelNameLabel->Size = System::Drawing::Size(39, 13);
			this->modelNameLabel->TabIndex = 3;
			this->modelNameLabel->Text = L"Model:";
			// 
			// modelStructsListBox
			// 
			this->modelStructsListBox->DataSource = this->structuresBindingSource;
			this->modelStructsListBox->DisplayMember = L"Name";
			this->modelStructsListBox->FormattingEnabled = true;
			this->modelStructsListBox->Location = System::Drawing::Point(12, 25);
			this->modelStructsListBox->Name = L"modelStructsListBox";
			this->modelStructsListBox->Size = System::Drawing::Size(120, 290);
			this->modelStructsListBox->TabIndex = 4;
			// 
			// structuresBindingSource
			// 
			this->structuresBindingSource->DataMember = L"Structures";
			this->structuresBindingSource->DataSource = this->customModelBindingSource;
			// 
			// customModelBindingSource
			// 
			this->customModelBindingSource->DataSource = CustomModel::typeid;
			// 
			// removeStructButton
			// 
			this->removeStructButton->Location = System::Drawing::Point(140, 137);
			this->removeStructButton->Name = L"removeStructButton";
			this->removeStructButton->Size = System::Drawing::Size(120, 36);
			this->removeStructButton->TabIndex = 5;
			this->removeStructButton->Text = L"Remove Selected Structure";
			this->removeStructButton->UseVisualStyleBackColor = true;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(140, 300);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 6;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(221, 300);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 7;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// instructionsLabel
			// 
			this->instructionsLabel->AutoSize = true;
			this->instructionsLabel->Location = System::Drawing::Point(141, 180);
			this->instructionsLabel->Name = L"instructionsLabel";
			this->instructionsLabel->Size = System::Drawing::Size(117, 13);
			this->instructionsLabel->TabIndex = 8;
			this->instructionsLabel->Text = L"Instructions for the user";
			// 
			// Structures_Form
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(310, 334);
			this->Controls->Add(this->instructionsLabel);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->removeStructButton);
			this->Controls->Add(this->modelStructsListBox);
			this->Controls->Add(this->modelNameLabel);
			this->Controls->Add(this->addStructButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Structures_Form";
			this->Text = L"Anatomical Structures";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->structuresBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->customModelBindingSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Collections::Generic::List<AnatomicalStruct^>^ tempStructures;
	};
}
