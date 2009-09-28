#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Physio_MIST {

	/// <summary>
	/// Summary for Query_Variable_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Query_Variable_Form : public System::Windows::Forms::Form
	{
	public:
		Query_Variable_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Query_Variable_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  nameTextBox;
	protected: 
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::TextBox^  unitsTextBox;
	private: System::Windows::Forms::Label^  unitsLabel;
	private: System::Windows::Forms::TextBox^  descTextBox;
	private: System::Windows::Forms::Label^  descLabel;
	private: System::Windows::Forms::TextBox^  formulaTextBox;
	private: System::Windows::Forms::Label^  formulaLabel;
	private: System::Windows::Forms::TextBox^  initValTextBox;
	private: System::Windows::Forms::Label^  initValLabel;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Label^  relatedLabel;
	private: System::Windows::Forms::ListBox^  relatedListBox;


	protected: 















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->unitsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->unitsLabel = (gcnew System::Windows::Forms::Label());
			this->descTextBox = (gcnew System::Windows::Forms::TextBox());
			this->descLabel = (gcnew System::Windows::Forms::Label());
			this->formulaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->formulaLabel = (gcnew System::Windows::Forms::Label());
			this->initValTextBox = (gcnew System::Windows::Forms::TextBox());
			this->initValLabel = (gcnew System::Windows::Forms::Label());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->relatedLabel = (gcnew System::Windows::Forms::Label());
			this->relatedListBox = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(16, 25);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->ReadOnly = true;
			this->nameTextBox->Size = System::Drawing::Size(100, 20);
			this->nameTextBox->TabIndex = 16;
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(12, 9);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(38, 13);
			this->nameLabel->TabIndex = 24;
			this->nameLabel->Text = L"Name:";
			// 
			// unitsTextBox
			// 
			this->unitsTextBox->Location = System::Drawing::Point(122, 103);
			this->unitsTextBox->Name = L"unitsTextBox";
			this->unitsTextBox->ReadOnly = true;
			this->unitsTextBox->Size = System::Drawing::Size(100, 20);
			this->unitsTextBox->TabIndex = 19;
			// 
			// unitsLabel
			// 
			this->unitsLabel->AutoSize = true;
			this->unitsLabel->Location = System::Drawing::Point(118, 87);
			this->unitsLabel->Name = L"unitsLabel";
			this->unitsLabel->Size = System::Drawing::Size(34, 13);
			this->unitsLabel->TabIndex = 27;
			this->unitsLabel->Text = L"Units:";
			// 
			// descTextBox
			// 
			this->descTextBox->AcceptsReturn = true;
			this->descTextBox->AcceptsTab = true;
			this->descTextBox->Location = System::Drawing::Point(16, 142);
			this->descTextBox->Name = L"descTextBox";
			this->descTextBox->ReadOnly = true;
			this->descTextBox->Size = System::Drawing::Size(206, 20);
			this->descTextBox->TabIndex = 21;
			// 
			// descLabel
			// 
			this->descLabel->AutoSize = true;
			this->descLabel->Location = System::Drawing::Point(12, 126);
			this->descLabel->Name = L"descLabel";
			this->descLabel->Size = System::Drawing::Size(63, 13);
			this->descLabel->TabIndex = 30;
			this->descLabel->Text = L"Description:";
			// 
			// formulaTextBox
			// 
			this->formulaTextBox->Location = System::Drawing::Point(16, 64);
			this->formulaTextBox->Name = L"formulaTextBox";
			this->formulaTextBox->ReadOnly = true;
			this->formulaTextBox->Size = System::Drawing::Size(206, 20);
			this->formulaTextBox->TabIndex = 17;
			// 
			// formulaLabel
			// 
			this->formulaLabel->AutoSize = true;
			this->formulaLabel->Location = System::Drawing::Point(13, 48);
			this->formulaLabel->Name = L"formulaLabel";
			this->formulaLabel->Size = System::Drawing::Size(47, 13);
			this->formulaLabel->TabIndex = 25;
			this->formulaLabel->Text = L"Formula:";
			// 
			// initValTextBox
			// 
			this->initValTextBox->Location = System::Drawing::Point(16, 103);
			this->initValTextBox->Name = L"initValTextBox";
			this->initValTextBox->ReadOnly = true;
			this->initValTextBox->Size = System::Drawing::Size(100, 20);
			this->initValTextBox->TabIndex = 18;
			// 
			// initValLabel
			// 
			this->initValLabel->AutoSize = true;
			this->initValLabel->Location = System::Drawing::Point(13, 87);
			this->initValLabel->Name = L"initValLabel";
			this->initValLabel->Size = System::Drawing::Size(64, 13);
			this->initValLabel->TabIndex = 26;
			this->initValLabel->Text = L"Initial Value:";
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(93, 334);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 32;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(12, 334);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 31;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// relatedLabel
			// 
			this->relatedLabel->AutoSize = true;
			this->relatedLabel->Location = System::Drawing::Point(12, 165);
			this->relatedLabel->Name = L"relatedLabel";
			this->relatedLabel->Size = System::Drawing::Size(90, 13);
			this->relatedLabel->TabIndex = 33;
			this->relatedLabel->Text = L"Related Variables";
			// 
			// relatedListBox
			// 
			this->relatedListBox->FormattingEnabled = true;
			this->relatedListBox->Location = System::Drawing::Point(16, 181);
			this->relatedListBox->Name = L"relatedListBox";
			this->relatedListBox->Size = System::Drawing::Size(206, 147);
			this->relatedListBox->TabIndex = 34;
			// 
			// Query_Variable_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(238, 369);
			this->Controls->Add(this->relatedListBox);
			this->Controls->Add(this->relatedLabel);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->unitsTextBox);
			this->Controls->Add(this->unitsLabel);
			this->Controls->Add(this->descTextBox);
			this->Controls->Add(this->descLabel);
			this->Controls->Add(this->formulaTextBox);
			this->Controls->Add(this->formulaLabel);
			this->Controls->Add(this->initValTextBox);
			this->Controls->Add(this->initValLabel);
			this->Name = L"Query_Variable_Form";
			this->Text = L"Query_Variable_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


};
}
