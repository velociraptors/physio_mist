#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Physio_MIST {

	/// <summary>
	/// Summary for Integration_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Integration_Form : public System::Windows::Forms::Form
	{
	public:
		Integration_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			modelList = gcnew List<ModelData^>();
			integrationBindingSource->DataSource = modelList;
		}
		Integration_Form(List<ModelData^>^ models)
		{
			InitializeComponent();

			modelList = models;
			integrationBindingSource->DataSource = modelList;
		}

		property List<ModelData^>^ modelList;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Integration_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::BindingSource^  integrationBindingSource;
	private: System::Windows::Forms::DataGridView^  modelGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  modelColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  formulaColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  unitsColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  structureColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  descColumn;

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
			this->integrationBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->modelGridView = (gcnew System::Windows::Forms::DataGridView());
			this->modelColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->formulaColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->valueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unitsColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->structureColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->integrationBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->modelGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// integrationBindingSource
			// 
			this->integrationBindingSource->DataSource = UI_Variable::typeid;
			// 
			// modelGridView
			// 
			this->modelGridView->AllowUserToAddRows = false;
			this->modelGridView->AllowUserToDeleteRows = false;
			this->modelGridView->AutoGenerateColumns = false;
			this->modelGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->modelGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->modelColumn, 
				this->nameColumn, this->formulaColumn, this->valueColumn, this->unitsColumn, this->structureColumn, this->descColumn});
			this->modelGridView->DataSource = this->integrationBindingSource;
			this->modelGridView->Location = System::Drawing::Point(13, 13);
			this->modelGridView->Name = L"modelGridView";
			this->modelGridView->ReadOnly = true;
			this->modelGridView->Size = System::Drawing::Size(766, 311);
			this->modelGridView->TabIndex = 0;
			// 
			// modelColumn
			// 
			this->modelColumn->HeaderText = L"Model";
			this->modelColumn->Name = L"modelColumn";
			this->modelColumn->ReadOnly = true;
			// 
			// nameColumn
			// 
			this->nameColumn->DataPropertyName = L"Name";
			this->nameColumn->HeaderText = L"Name";
			this->nameColumn->Name = L"nameColumn";
			this->nameColumn->ReadOnly = true;
			// 
			// formulaColumn
			// 
			this->formulaColumn->DataPropertyName = L"Formula";
			this->formulaColumn->HeaderText = L"Formula";
			this->formulaColumn->Name = L"formulaColumn";
			this->formulaColumn->ReadOnly = true;
			// 
			// valueColumn
			// 
			this->valueColumn->DataPropertyName = L"Value";
			this->valueColumn->HeaderText = L"Value";
			this->valueColumn->Name = L"valueColumn";
			this->valueColumn->ReadOnly = true;
			// 
			// unitsColumn
			// 
			this->unitsColumn->DataPropertyName = L"Units";
			this->unitsColumn->HeaderText = L"Units";
			this->unitsColumn->Name = L"unitsColumn";
			this->unitsColumn->ReadOnly = true;
			// 
			// structureColumn
			// 
			this->structureColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->structureColumn->DataPropertyName = L"str_name";
			this->structureColumn->HeaderText = L"Structure Name";
			this->structureColumn->Name = L"structureColumn";
			this->structureColumn->ReadOnly = true;
			this->structureColumn->Width = 97;
			// 
			// descColumn
			// 
			this->descColumn->DataPropertyName = L"Desc";
			this->descColumn->HeaderText = L"Description";
			this->descColumn->Name = L"descColumn";
			this->descColumn->ReadOnly = true;
			// 
			// Integration_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 566);
			this->Controls->Add(this->modelGridView);
			this->Name = L"Integration_Form";
			this->Text = L"Integration_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->integrationBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->modelGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
