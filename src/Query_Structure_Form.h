#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Physio_MIST {

	/// <summary>
	/// Summary for Query_Structure_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Query_Structure_Form : public System::Windows::Forms::Form
	{
	public:
		Query_Structure_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Query_Structure_Form(System::String^ structureName)
		{
			InitializeComponent();

			this->strNameLabel->Text = structureName;
		}

		void run_query(String^ strName);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Query_Structure_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  strLabel;
	private: System::Windows::Forms::Label^  strNameLabel;
	private: System::Windows::Forms::Panel^  relationshipPanel;
	private: System::Windows::Forms::Panel^  resultsPanel;
	private: System::Windows::Forms::Label^  relationshipLabel;
	private: System::Windows::Forms::Label^  resultsLabel;
	private: System::Windows::Forms::Button^  runQueryButton;
	private: System::Windows::Forms::ListBox^  resultsListBox;
	private: System::Windows::Forms::RadioButton^  boundedRadioButton;
	private: System::Windows::Forms::RadioButton^  developsRadioButton;
	private: System::Windows::Forms::RadioButton^  nerveSupplyRadioButton;
	private: System::Windows::Forms::RadioButton^  venousDrainageRadioButton;
	private: System::Windows::Forms::RadioButton^  arterialSupplyRadioButton;
	private: System::Windows::Forms::RadioButton^  attributedPartRadioButton;
	private: System::Windows::Forms::RadioButton^  regionalPartOfRadioButton;
	private: System::Windows::Forms::RadioButton^  regionalPartRadioButton;
	private: System::Windows::Forms::RadioButton^  partRadioButton;
	private: System::Windows::Forms::RadioButton^  customPartonomyOfRadioButton;
	private: System::Windows::Forms::RadioButton^  customPartonomyRadioButton;
	private: System::Windows::Forms::RadioButton^  constitutionalPartOfRadioButton;
	private: System::Windows::Forms::RadioButton^  constitutionalPartRadioButton;

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
			this->strLabel = (gcnew System::Windows::Forms::Label());
			this->strNameLabel = (gcnew System::Windows::Forms::Label());
			this->arterialSupplyRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->venousDrainageRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->nerveSupplyRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->developsRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->boundedRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->relationshipPanel = (gcnew System::Windows::Forms::Panel());
			this->regionalPartOfRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->regionalPartRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->partRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->customPartonomyOfRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->customPartonomyRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->constitutionalPartOfRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->constitutionalPartRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->attributedPartRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->relationshipLabel = (gcnew System::Windows::Forms::Label());
			this->runQueryButton = (gcnew System::Windows::Forms::Button());
			this->resultsPanel = (gcnew System::Windows::Forms::Panel());
			this->resultsListBox = (gcnew System::Windows::Forms::ListBox());
			this->resultsLabel = (gcnew System::Windows::Forms::Label());
			this->relationshipPanel->SuspendLayout();
			this->resultsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// strLabel
			// 
			this->strLabel->AutoSize = true;
			this->strLabel->Location = System::Drawing::Point(12, 9);
			this->strLabel->Name = L"strLabel";
			this->strLabel->Size = System::Drawing::Size(53, 13);
			this->strLabel->TabIndex = 0;
			this->strLabel->Text = L"Structure:";
			// 
			// strNameLabel
			// 
			this->strNameLabel->AutoSize = true;
			this->strNameLabel->Location = System::Drawing::Point(71, 9);
			this->strNameLabel->Name = L"strNameLabel";
			this->strNameLabel->Size = System::Drawing::Size(158, 13);
			this->strNameLabel->TabIndex = 1;
			this->strNameLabel->Text = L"[Selected Structure Name Here]";
			// 
			// arterialSupplyRadioButton
			// 
			this->arterialSupplyRadioButton->AutoSize = true;
			this->arterialSupplyRadioButton->Location = System::Drawing::Point(7, 30);
			this->arterialSupplyRadioButton->Name = L"arterialSupplyRadioButton";
			this->arterialSupplyRadioButton->Size = System::Drawing::Size(92, 17);
			this->arterialSupplyRadioButton->TabIndex = 0;
			this->arterialSupplyRadioButton->TabStop = true;
			this->arterialSupplyRadioButton->Text = L"Arterial Supply";
			this->arterialSupplyRadioButton->UseVisualStyleBackColor = true;
			// 
			// venousDrainageRadioButton
			// 
			this->venousDrainageRadioButton->AutoSize = true;
			this->venousDrainageRadioButton->Location = System::Drawing::Point(7, 53);
			this->venousDrainageRadioButton->Name = L"venousDrainageRadioButton";
			this->venousDrainageRadioButton->Size = System::Drawing::Size(107, 17);
			this->venousDrainageRadioButton->TabIndex = 1;
			this->venousDrainageRadioButton->TabStop = true;
			this->venousDrainageRadioButton->Text = L"Venous Drainage";
			this->venousDrainageRadioButton->UseVisualStyleBackColor = true;
			// 
			// nerveSupplyRadioButton
			// 
			this->nerveSupplyRadioButton->AutoSize = true;
			this->nerveSupplyRadioButton->Location = System::Drawing::Point(7, 76);
			this->nerveSupplyRadioButton->Name = L"nerveSupplyRadioButton";
			this->nerveSupplyRadioButton->Size = System::Drawing::Size(89, 17);
			this->nerveSupplyRadioButton->TabIndex = 2;
			this->nerveSupplyRadioButton->TabStop = true;
			this->nerveSupplyRadioButton->Text = L"Nerve Supply";
			this->nerveSupplyRadioButton->UseVisualStyleBackColor = true;
			// 
			// developsRadioButton
			// 
			this->developsRadioButton->AutoSize = true;
			this->developsRadioButton->Location = System::Drawing::Point(7, 99);
			this->developsRadioButton->Name = L"developsRadioButton";
			this->developsRadioButton->Size = System::Drawing::Size(96, 17);
			this->developsRadioButton->TabIndex = 3;
			this->developsRadioButton->TabStop = true;
			this->developsRadioButton->Text = L"Develops From";
			this->developsRadioButton->UseVisualStyleBackColor = true;
			// 
			// boundedRadioButton
			// 
			this->boundedRadioButton->AutoSize = true;
			this->boundedRadioButton->Location = System::Drawing::Point(7, 122);
			this->boundedRadioButton->Name = L"boundedRadioButton";
			this->boundedRadioButton->Size = System::Drawing::Size(83, 17);
			this->boundedRadioButton->TabIndex = 4;
			this->boundedRadioButton->TabStop = true;
			this->boundedRadioButton->Text = L"Bounded By";
			this->boundedRadioButton->UseVisualStyleBackColor = true;
			// 
			// relationshipPanel
			// 
			this->relationshipPanel->AutoScroll = true;
			this->relationshipPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->relationshipPanel->Controls->Add(this->regionalPartOfRadioButton);
			this->relationshipPanel->Controls->Add(this->regionalPartRadioButton);
			this->relationshipPanel->Controls->Add(this->partRadioButton);
			this->relationshipPanel->Controls->Add(this->customPartonomyOfRadioButton);
			this->relationshipPanel->Controls->Add(this->customPartonomyRadioButton);
			this->relationshipPanel->Controls->Add(this->constitutionalPartOfRadioButton);
			this->relationshipPanel->Controls->Add(this->constitutionalPartRadioButton);
			this->relationshipPanel->Controls->Add(this->attributedPartRadioButton);
			this->relationshipPanel->Controls->Add(this->relationshipLabel);
			this->relationshipPanel->Controls->Add(this->boundedRadioButton);
			this->relationshipPanel->Controls->Add(this->arterialSupplyRadioButton);
			this->relationshipPanel->Controls->Add(this->developsRadioButton);
			this->relationshipPanel->Controls->Add(this->venousDrainageRadioButton);
			this->relationshipPanel->Controls->Add(this->nerveSupplyRadioButton);
			this->relationshipPanel->Location = System::Drawing::Point(13, 36);
			this->relationshipPanel->Name = L"relationshipPanel";
			this->relationshipPanel->Size = System::Drawing::Size(156, 338);
			this->relationshipPanel->TabIndex = 2;
			// 
			// regionalPartOfRadioButton
			// 
			this->regionalPartOfRadioButton->AutoSize = true;
			this->regionalPartOfRadioButton->Location = System::Drawing::Point(7, 312);
			this->regionalPartOfRadioButton->Name = L"regionalPartOfRadioButton";
			this->regionalPartOfRadioButton->Size = System::Drawing::Size(103, 17);
			this->regionalPartOfRadioButton->TabIndex = 12;
			this->regionalPartOfRadioButton->TabStop = true;
			this->regionalPartOfRadioButton->Text = L"Regional Part Of";
			this->regionalPartOfRadioButton->UseVisualStyleBackColor = true;
			// 
			// regionalPartRadioButton
			// 
			this->regionalPartRadioButton->AutoSize = true;
			this->regionalPartRadioButton->Location = System::Drawing::Point(7, 288);
			this->regionalPartRadioButton->Name = L"regionalPartRadioButton";
			this->regionalPartRadioButton->Size = System::Drawing::Size(89, 17);
			this->regionalPartRadioButton->TabIndex = 11;
			this->regionalPartRadioButton->TabStop = true;
			this->regionalPartRadioButton->Text = L"Regional Part";
			this->regionalPartRadioButton->UseVisualStyleBackColor = true;
			// 
			// partRadioButton
			// 
			this->partRadioButton->AutoSize = true;
			this->partRadioButton->Location = System::Drawing::Point(7, 264);
			this->partRadioButton->Name = L"partRadioButton";
			this->partRadioButton->Size = System::Drawing::Size(44, 17);
			this->partRadioButton->TabIndex = 10;
			this->partRadioButton->TabStop = true;
			this->partRadioButton->Text = L"Part";
			this->partRadioButton->UseVisualStyleBackColor = true;
			// 
			// customPartonomyOfRadioButton
			// 
			this->customPartonomyOfRadioButton->AutoSize = true;
			this->customPartonomyOfRadioButton->Location = System::Drawing::Point(7, 240);
			this->customPartonomyOfRadioButton->Name = L"customPartonomyOfRadioButton";
			this->customPartonomyOfRadioButton->Size = System::Drawing::Size(127, 17);
			this->customPartonomyOfRadioButton->TabIndex = 9;
			this->customPartonomyOfRadioButton->TabStop = true;
			this->customPartonomyOfRadioButton->Text = L"Custom Partonomy Of";
			this->customPartonomyOfRadioButton->UseVisualStyleBackColor = true;
			// 
			// customPartonomyRadioButton
			// 
			this->customPartonomyRadioButton->AutoSize = true;
			this->customPartonomyRadioButton->Location = System::Drawing::Point(7, 217);
			this->customPartonomyRadioButton->Name = L"customPartonomyRadioButton";
			this->customPartonomyRadioButton->Size = System::Drawing::Size(113, 17);
			this->customPartonomyRadioButton->TabIndex = 8;
			this->customPartonomyRadioButton->TabStop = true;
			this->customPartonomyRadioButton->Text = L"Custom Partonomy";
			this->customPartonomyRadioButton->UseVisualStyleBackColor = true;
			// 
			// constitutionalPartOfRadioButton
			// 
			this->constitutionalPartOfRadioButton->AutoSize = true;
			this->constitutionalPartOfRadioButton->Location = System::Drawing::Point(7, 193);
			this->constitutionalPartOfRadioButton->Name = L"constitutionalPartOfRadioButton";
			this->constitutionalPartOfRadioButton->Size = System::Drawing::Size(124, 17);
			this->constitutionalPartOfRadioButton->TabIndex = 7;
			this->constitutionalPartOfRadioButton->TabStop = true;
			this->constitutionalPartOfRadioButton->Text = L"Constitutional Part Of";
			this->constitutionalPartOfRadioButton->UseVisualStyleBackColor = true;
			// 
			// constitutionalPartRadioButton
			// 
			this->constitutionalPartRadioButton->AutoSize = true;
			this->constitutionalPartRadioButton->Location = System::Drawing::Point(7, 170);
			this->constitutionalPartRadioButton->Name = L"constitutionalPartRadioButton";
			this->constitutionalPartRadioButton->Size = System::Drawing::Size(110, 17);
			this->constitutionalPartRadioButton->TabIndex = 6;
			this->constitutionalPartRadioButton->TabStop = true;
			this->constitutionalPartRadioButton->Text = L"Constitutional Part";
			this->constitutionalPartRadioButton->UseVisualStyleBackColor = true;
			// 
			// attributedPartRadioButton
			// 
			this->attributedPartRadioButton->AutoSize = true;
			this->attributedPartRadioButton->Location = System::Drawing::Point(7, 146);
			this->attributedPartRadioButton->Name = L"attributedPartRadioButton";
			this->attributedPartRadioButton->Size = System::Drawing::Size(92, 17);
			this->attributedPartRadioButton->TabIndex = 5;
			this->attributedPartRadioButton->TabStop = true;
			this->attributedPartRadioButton->Text = L"Atrributed Part";
			this->attributedPartRadioButton->UseVisualStyleBackColor = true;
			// 
			// relationshipLabel
			// 
			this->relationshipLabel->AutoSize = true;
			this->relationshipLabel->Location = System::Drawing::Point(4, 4);
			this->relationshipLabel->Name = L"relationshipLabel";
			this->relationshipLabel->Size = System::Drawing::Size(92, 13);
			this->relationshipLabel->TabIndex = 0;
			this->relationshipLabel->Text = L"Relationship Type";
			// 
			// runQueryButton
			// 
			this->runQueryButton->Location = System::Drawing::Point(21, 382);
			this->runQueryButton->Name = L"runQueryButton";
			this->runQueryButton->Size = System::Drawing::Size(75, 23);
			this->runQueryButton->TabIndex = 4;
			this->runQueryButton->Text = L"Run Query";
			this->runQueryButton->UseVisualStyleBackColor = true;
			this->runQueryButton->Click += gcnew System::EventHandler(this, &Query_Structure_Form::runQueryButton_Click);
			// 
			// resultsPanel
			// 
			this->resultsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->resultsPanel->Controls->Add(this->resultsListBox);
			this->resultsPanel->Controls->Add(this->resultsLabel);
			this->resultsPanel->Location = System::Drawing::Point(186, 36);
			this->resultsPanel->Name = L"resultsPanel";
			this->resultsPanel->Size = System::Drawing::Size(200, 338);
			this->resultsPanel->TabIndex = 3;
			// 
			// resultsListBox
			// 
			this->resultsListBox->FormattingEnabled = true;
			this->resultsListBox->HorizontalScrollbar = true;
			this->resultsListBox->Location = System::Drawing::Point(7, 21);
			this->resultsListBox->Name = L"resultsListBox";
			this->resultsListBox->Size = System::Drawing::Size(180, 303);
			this->resultsListBox->TabIndex = 1;
			// 
			// resultsLabel
			// 
			this->resultsLabel->AutoSize = true;
			this->resultsLabel->Location = System::Drawing::Point(4, 5);
			this->resultsLabel->Name = L"resultsLabel";
			this->resultsLabel->Size = System::Drawing::Size(42, 13);
			this->resultsLabel->TabIndex = 0;
			this->resultsLabel->Text = L"Results";
			// 
			// Query_Structure_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 417);
			this->Controls->Add(this->resultsPanel);
			this->Controls->Add(this->runQueryButton);
			this->Controls->Add(this->relationshipPanel);
			this->Controls->Add(this->strNameLabel);
			this->Controls->Add(this->strLabel);
			this->Name = L"Query_Structure_Form";
			this->Text = L"Query_Structure_Form";
			this->relationshipPanel->ResumeLayout(false);
			this->relationshipPanel->PerformLayout();
			this->resultsPanel->ResumeLayout(false);
			this->resultsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void runQueryButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 run_query(strNameLabel->Text);
		 }
	};
}
