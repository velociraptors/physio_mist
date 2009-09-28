#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Physio_MIST {

	/// <summary>
	/// Summary for Model_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Model_Form : public System::Windows::Forms::Form
	{
	public:
		Model_Form(void)
		{
			InitializeComponent();
			modeldata = gcnew ModelData();

			paramBindingSource->DataSource = modeldata->paramList;
			varBindingSource->DataSource = modeldata->varList;
		}
		Model_Form(System::String^ filename)
		{
			//! \brief If the filename ends with ".xml", use ModelData::load_XMLfile to load the model.
			//! Otherwise, assume it's an MML text file and use ModelData::load_MMLfile to load it.

			InitializeComponent();
			modeldata = gcnew ModelData();

			int index = filename->LastIndexOf('.');
			String^ extension = filename->Substring(index);
			extension = extension->ToLower();
			if(extension == ".xml"){
				modeldata->load_XMLfile(filename);
                xmlserial(modeldata, filename);
			}
			else {
				modeldata->load_MMLfile(filename);
			}
			paramBindingSource->DataSource = modeldata->paramList;
			varBindingSource->DataSource = modeldata->varList;
		}

		void load_anatomical_information();

	private:
		void reset_UIvar(UI_Variable^ variable);
		UI_Variable^ create_UIvar();
        void xmlserial(ModelData^ model, String^ filename);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Model_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: MMLParser *mml_parser;
	private: Parameters_Form^ paramForm;
	private: Variables_Form^ varForm;
	public: ModelData^ modeldata;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;

	private: System::Windows::Forms::Button^  loadButton;

	private: System::Windows::Forms::GroupBox^  paramGroupBox;
	private: System::Windows::Forms::Button^  paramDeleteButton;
	private: System::Windows::Forms::Button^  paramEditButton;
	private: System::Windows::Forms::Button^  paramNewButton;
	private: System::Windows::Forms::DataGridView^  paramGridView;

	private: System::Windows::Forms::GroupBox^  varGroupBox;
	private: System::Windows::Forms::Button^  varDeleteButton;
	private: System::Windows::Forms::Button^  varEditButton;
	private: System::Windows::Forms::Button^  varNewButton;
	private: System::Windows::Forms::DataGridView^  varGridView;


	private: System::Windows::Forms::BindingSource^  varBindingSource;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varFormulaColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varValueColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varUnitsColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varStrColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varDescColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  paramNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  paramValueColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  paramUnitsColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  paramStrColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  paramDescColumn;

	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  buildToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  queryStructureMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  queryVariableMenuItem;
	private: System::Windows::Forms::BindingSource^  paramBindingSource;

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
			this->paramGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->paramDeleteButton = (gcnew System::Windows::Forms::Button());
			this->paramEditButton = (gcnew System::Windows::Forms::Button());
			this->paramNewButton = (gcnew System::Windows::Forms::Button());
			this->paramGridView = (gcnew System::Windows::Forms::DataGridView());
			this->paramNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->paramValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->paramUnitsColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->paramStrColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->paramDescColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->queryStructureMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->queryVariableMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paramBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->varGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->varDeleteButton = (gcnew System::Windows::Forms::Button());
			this->varEditButton = (gcnew System::Windows::Forms::Button());
			this->varNewButton = (gcnew System::Windows::Forms::Button());
			this->varGridView = (gcnew System::Windows::Forms::DataGridView());
			this->varNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varFormulaColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varUnitsColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varStrColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varDescColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buildToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paramGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramGridView))->BeginInit();
			this->contextMenuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramBindingSource))->BeginInit();
			this->varGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varBindingSource))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// paramGroupBox
			// 
			this->paramGroupBox->AutoSize = true;
			this->paramGroupBox->Controls->Add(this->paramDeleteButton);
			this->paramGroupBox->Controls->Add(this->paramEditButton);
			this->paramGroupBox->Controls->Add(this->paramNewButton);
			this->paramGroupBox->Controls->Add(this->paramGridView);
			this->paramGroupBox->Location = System::Drawing::Point(8, 35);
			this->paramGroupBox->Name = L"paramGroupBox";
			this->paramGroupBox->Size = System::Drawing::Size(586, 197);
			this->paramGroupBox->TabIndex = 0;
			this->paramGroupBox->TabStop = false;
			this->paramGroupBox->Text = L"Parameters";
			// 
			// paramDeleteButton
			// 
			this->paramDeleteButton->Location = System::Drawing::Point(168, 155);
			this->paramDeleteButton->Name = L"paramDeleteButton";
			this->paramDeleteButton->Size = System::Drawing::Size(75, 23);
			this->paramDeleteButton->TabIndex = 3;
			this->paramDeleteButton->Text = L"Delete";
			this->paramDeleteButton->UseVisualStyleBackColor = true;
			this->paramDeleteButton->Click += gcnew System::EventHandler(this, &Model_Form::paramDeleteButton_Click);
			// 
			// paramEditButton
			// 
			this->paramEditButton->Location = System::Drawing::Point(87, 155);
			this->paramEditButton->Name = L"paramEditButton";
			this->paramEditButton->Size = System::Drawing::Size(75, 23);
			this->paramEditButton->TabIndex = 2;
			this->paramEditButton->Text = L"Edit";
			this->paramEditButton->UseVisualStyleBackColor = true;
			this->paramEditButton->Click += gcnew System::EventHandler(this, &Model_Form::paramEditButton_Click);
			// 
			// paramNewButton
			// 
			this->paramNewButton->Location = System::Drawing::Point(6, 155);
			this->paramNewButton->Name = L"paramNewButton";
			this->paramNewButton->Size = System::Drawing::Size(75, 23);
			this->paramNewButton->TabIndex = 1;
			this->paramNewButton->Text = L"New";
			this->paramNewButton->UseVisualStyleBackColor = true;
			this->paramNewButton->Click += gcnew System::EventHandler(this, &Model_Form::paramNewButton_Click);
			// 
			// paramGridView
			// 
			this->paramGridView->AutoGenerateColumns = false;
			this->paramGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->paramGridView->ColumnHeadersHeight = 30;
			this->paramGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->paramGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->paramNameColumn, 
				this->paramValueColumn, this->paramUnitsColumn, this->paramStrColumn, this->paramDescColumn});
			this->paramGridView->ContextMenuStrip = this->contextMenuStrip;
			this->paramGridView->DataSource = this->paramBindingSource;
			this->paramGridView->Dock = System::Windows::Forms::DockStyle::Top;
			this->paramGridView->Location = System::Drawing::Point(3, 16);
			this->paramGridView->Name = L"paramGridView";
			this->paramGridView->Size = System::Drawing::Size(580, 130);
			this->paramGridView->TabIndex = 0;
			// 
			// paramNameColumn
			// 
			this->paramNameColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->paramNameColumn->DataPropertyName = L"Name";
			this->paramNameColumn->HeaderText = L"Name";
			this->paramNameColumn->Name = L"paramNameColumn";
			this->paramNameColumn->Width = 60;
			// 
			// paramValueColumn
			// 
			this->paramValueColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->paramValueColumn->DataPropertyName = L"Value";
			this->paramValueColumn->HeaderText = L"Value";
			this->paramValueColumn->Name = L"paramValueColumn";
			this->paramValueColumn->Width = 59;
			// 
			// paramUnitsColumn
			// 
			this->paramUnitsColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->paramUnitsColumn->DataPropertyName = L"Units";
			this->paramUnitsColumn->HeaderText = L"Units";
			this->paramUnitsColumn->Name = L"paramUnitsColumn";
			this->paramUnitsColumn->Width = 56;
			// 
			// paramStrColumn
			// 
			this->paramStrColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->paramStrColumn->DataPropertyName = L"str_name";
			this->paramStrColumn->HeaderText = L"Anatomical Structure";
			this->paramStrColumn->Name = L"paramStrColumn";
			this->paramStrColumn->Width = 130;
			// 
			// paramDescColumn
			// 
			this->paramDescColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->paramDescColumn->DataPropertyName = L"Desc";
			this->paramDescColumn->HeaderText = L"Description";
			this->paramDescColumn->Name = L"paramDescColumn";
			this->paramDescColumn->Width = 85;
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->queryStructureMenuItem, 
				this->queryVariableMenuItem});
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
			// 
			// queryVariableMenuItem
			// 
			this->queryVariableMenuItem->Name = L"queryVariableMenuItem";
			this->queryVariableMenuItem->Size = System::Drawing::Size(185, 22);
			this->queryVariableMenuItem->Text = L"Find Related Variables...";
			// 
			// paramBindingSource
			// 
			this->paramBindingSource->DataSource = UI_Variable::typeid;
			// 
			// loadButton
			// 
			this->loadButton->Location = System::Drawing::Point(16, 445);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(134, 23);
			this->loadButton->TabIndex = 2;
			this->loadButton->Text = L"Load Anatomical Data";
			this->loadButton->UseVisualStyleBackColor = true;
			this->loadButton->Click += gcnew System::EventHandler(this, &Model_Form::loadButton_Click);
			// 
			// varGroupBox
			// 
			this->varGroupBox->AutoSize = true;
			this->varGroupBox->Controls->Add(this->varDeleteButton);
			this->varGroupBox->Controls->Add(this->varEditButton);
			this->varGroupBox->Controls->Add(this->varNewButton);
			this->varGroupBox->Controls->Add(this->varGridView);
			this->varGroupBox->Location = System::Drawing::Point(8, 238);
			this->varGroupBox->Name = L"varGroupBox";
			this->varGroupBox->Size = System::Drawing::Size(586, 191);
			this->varGroupBox->TabIndex = 3;
			this->varGroupBox->TabStop = false;
			this->varGroupBox->Text = L"Variables";
			// 
			// varDeleteButton
			// 
			this->varDeleteButton->Location = System::Drawing::Point(168, 149);
			this->varDeleteButton->Name = L"varDeleteButton";
			this->varDeleteButton->Size = System::Drawing::Size(75, 23);
			this->varDeleteButton->TabIndex = 3;
			this->varDeleteButton->Text = L"Delete";
			this->varDeleteButton->UseVisualStyleBackColor = true;
			this->varDeleteButton->Click += gcnew System::EventHandler(this, &Model_Form::varDeleteButton_Click);
			// 
			// varEditButton
			// 
			this->varEditButton->Location = System::Drawing::Point(87, 149);
			this->varEditButton->Name = L"varEditButton";
			this->varEditButton->Size = System::Drawing::Size(75, 23);
			this->varEditButton->TabIndex = 2;
			this->varEditButton->Text = L"Edit";
			this->varEditButton->UseVisualStyleBackColor = true;
			this->varEditButton->Click += gcnew System::EventHandler(this, &Model_Form::varEditButton_Click);
			// 
			// varNewButton
			// 
			this->varNewButton->Location = System::Drawing::Point(6, 149);
			this->varNewButton->Name = L"varNewButton";
			this->varNewButton->Size = System::Drawing::Size(75, 23);
			this->varNewButton->TabIndex = 1;
			this->varNewButton->Text = L"New";
			this->varNewButton->UseVisualStyleBackColor = true;
			this->varNewButton->Click += gcnew System::EventHandler(this, &Model_Form::varNewButton_Click);
			// 
			// varGridView
			// 
			this->varGridView->AutoGenerateColumns = false;
			this->varGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->varGridView->ColumnHeadersHeight = 30;
			this->varGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->varGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->varNameColumn, 
				this->varFormulaColumn, this->varValueColumn, this->varUnitsColumn, this->varStrColumn, this->varDescColumn});
			this->varGridView->ContextMenuStrip = this->contextMenuStrip;
			this->varGridView->DataSource = this->varBindingSource;
			this->varGridView->Dock = System::Windows::Forms::DockStyle::Top;
			this->varGridView->Location = System::Drawing::Point(3, 16);
			this->varGridView->Name = L"varGridView";
			this->varGridView->Size = System::Drawing::Size(580, 124);
			this->varGridView->TabIndex = 0;
			// 
			// varNameColumn
			// 
			this->varNameColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varNameColumn->DataPropertyName = L"Name";
			this->varNameColumn->HeaderText = L"Name";
			this->varNameColumn->Name = L"varNameColumn";
			this->varNameColumn->Width = 60;
			// 
			// varFormulaColumn
			// 
			this->varFormulaColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varFormulaColumn->DataPropertyName = L"Formula";
			this->varFormulaColumn->HeaderText = L"Formula";
			this->varFormulaColumn->Name = L"varFormulaColumn";
			this->varFormulaColumn->Width = 69;
			// 
			// varValueColumn
			// 
			this->varValueColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varValueColumn->DataPropertyName = L"Value";
			this->varValueColumn->HeaderText = L"Initial Value";
			this->varValueColumn->Name = L"varValueColumn";
			this->varValueColumn->Width = 86;
			// 
			// varUnitsColumn
			// 
			this->varUnitsColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varUnitsColumn->DataPropertyName = L"Units";
			this->varUnitsColumn->HeaderText = L"Units";
			this->varUnitsColumn->Name = L"varUnitsColumn";
			this->varUnitsColumn->Width = 56;
			// 
			// varStrColumn
			// 
			this->varStrColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varStrColumn->DataPropertyName = L"str_name";
			this->varStrColumn->HeaderText = L"Anatomical Structure";
			this->varStrColumn->Name = L"varStrColumn";
			this->varStrColumn->Width = 130;
			// 
			// varDescColumn
			// 
			this->varDescColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->varDescColumn->DataPropertyName = L"Desc";
			this->varDescColumn->HeaderText = L"Description";
			this->varDescColumn->Name = L"varDescColumn";
			this->varDescColumn->Width = 85;
			// 
			// varBindingSource
			// 
			this->varBindingSource->DataSource = UI_Variable::typeid;
			// 
			// menuStrip
			// 
			this->menuStrip->AllowMerge = false;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->buildToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip->Size = System::Drawing::Size(606, 24);
			this->menuStrip->TabIndex = 5;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->saveToolStripMenuItem, 
				this->loadToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Model_Form::saveToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->loadToolStripMenuItem->Text = L"&Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Model_Form::loadToolStripMenuItem_Click);
			// 
			// buildToolStripMenuItem
			// 
			this->buildToolStripMenuItem->Name = L"buildToolStripMenuItem";
			this->buildToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->buildToolStripMenuItem->Text = L"Build";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// Model_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(606, 481);
			this->Controls->Add(this->menuStrip);
			this->Controls->Add(this->varGroupBox);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->paramGroupBox);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Model_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Model_Form";
			this->paramGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramGridView))->EndInit();
			this->contextMenuStrip->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paramBindingSource))->EndInit();
			this->varGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varBindingSource))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void loadButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->load_anatomical_information();
			 paramBindingSource->ResetBindings(false);
			 varBindingSource->ResetBindings(false);
		 }
private: System::Void paramNewButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 UI_Variable^ new_par = create_UIvar();
			 paramForm = gcnew Parameters_Form(new_par);
			 paramForm->MdiParent = this->MdiParent;
			 paramForm->Show();

			 paramBindingSource->Insert(paramBindingSource->Count, paramForm->Param);
			 paramBindingSource->ResetBindings(false);
			 paramBindingSource->MoveLast();
		 }
private: System::Void paramEditButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 paramForm = gcnew Parameters_Form((UI_Variable^)paramBindingSource->Current);
			 paramForm->MdiParent = this->MdiParent;
			 paramForm->Show();

			 paramBindingSource[paramBindingSource->IndexOf(paramBindingSource->Current)] = paramForm->Param;
			 paramGridView->Rows[paramBindingSource->IndexOf(paramBindingSource->Current)]->Selected = true;
			 paramBindingSource->ResetBindings(false);
			 paramGridView->Refresh();
		 }
private: System::Void paramDeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 paramBindingSource->RemoveCurrent();
			 paramBindingSource->ResetBindings(false);
		 }
private: System::Void varNewButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 UI_Variable^ new_var = create_UIvar();
			 paramForm = gcnew Parameters_Form(new_var);
			 varForm = gcnew Variables_Form(new_var);
			 varForm->MdiParent = this->MdiParent;
			 varForm->Show();

			 varBindingSource->Insert(varBindingSource->Count, varForm->Var);
			 varBindingSource->ResetBindings(false);
			 varBindingSource->MoveLast();
		 }
private: System::Void varEditButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 varForm = gcnew Variables_Form((UI_Variable^)varBindingSource->Current);
			 varForm->MdiParent = this->MdiParent;
			 varForm->Show();

			 varBindingSource[(varBindingSource->IndexOf(varBindingSource->Current))] = varForm->Var;
			 varBindingSource->ResetBindings(false);
			 varBindingSource->ResetCurrentItem();
		 }
private: System::Void varDeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 varBindingSource->RemoveCurrent();
			 varBindingSource->ResetBindings(false);
		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog = gcnew System::Windows::Forms::SaveFileDialog();
			 saveFileDialog->Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
			 saveFileDialog->FilterIndex = 1;
			 saveFileDialog->RestoreDirectory = true;
			 if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 modeldata->save_XMLfile(saveFileDialog->FileName);
			 }
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^current_dir = System::IO::Directory::GetCurrentDirectory();
			 openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
			 openFileDialog->Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
			 openFileDialog->FilterIndex = 1;
			 if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 //Physio_MIST::Model_Form::load_XMLfile(openFileDialog->FileName);
				 Physio_MIST::Model_Form::modeldata->load_XMLfile(openFileDialog->FileName);
				 System::IO::Directory::SetCurrentDirectory(current_dir);
				 paramBindingSource->ResetBindings(false);
				 varBindingSource->ResetBindings(false);
			 }
		 }
	};
}