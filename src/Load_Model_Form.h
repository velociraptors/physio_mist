#ifndef _LOAD_MODEL_FORM_H
#define _LOAD_MODEL_FORM_H

#include "stdafx.h"
#include "mmlparser.h"
#include "Ontology_Tree_Form.h"
#include "UI_Variable.h"
#include "SlotData.h"

#using <mscorlib.dll>
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Physio_MIST {

	/// <summary>
	/// Summary for Load_Model_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Load_Model_Form : public System::Windows::Forms::Form
	{
	public:
		Load_Model_Form(void)
		{
			variables_list = gcnew System::Collections::Generic::List<UI_Variable ^>;
			parameters_list = gcnew System::Collections::Generic::List<UI_Variable ^>;			
			mml_parser = new MMLParser();
			InitializeComponent();
			
		}

		Load_Model_Form(System::String ^filename)
		{
			variables_list = gcnew System::Collections::Generic::List<UI_Variable ^>;
			parameters_list = gcnew System::Collections::Generic::List<UI_Variable ^>;
			mml_parser = new MMLParser();

			file_name = filename;			

			//load the model
			load_theModel(filename);

			InitializeComponent();
			dataGridView2->ContextMenuStrip = contextMenuStrip1;

		}

		
		
		void attach_anatomical_str(DataGridViewRow ^current_row);		
		void attach_anatomical_str_collection(DataGridViewSelectedRowCollection ^selected_rows);
		void load_theModel(System::String ^filename);
		void load_anatomical_information();
		void bindAttrToStructure(System::Collections::Generic::List<SlotData^> ^attributes , Anatomical_structure *str);


			 System::Collections::Generic::List<UI_Variable ^> ^variables_list;
			 System::Collections::Generic::List<UI_Variable ^> ^parameters_list;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  denemeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  modifyToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;










	private: System::Windows::Forms::BindingSource^  uIVariableBindingSource;
	private: System::Windows::Forms::BindingSource^  uIVariableBindingSource1;




















	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Button^  button1;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameDataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Formula;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueDataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  unitsDataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  descDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  varAnatStr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  unitsDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valueDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  parAnatStr;






	private: System::Windows::Forms::DataGridView^  dataGridView2;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Load_Model_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: MMLParser *mml_parser;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  parameters;
	private: System::Windows::Forms::TabPage^  variables;

	private: System::ComponentModel::IContainer^  components;



	private: System::String^ file_name;


	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: Managed_ParameterData ^parameter;
	
	


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->parameters = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->uIVariableBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->variables = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->nameDataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Formula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->valueDataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unitsDataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->varAnatStr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->uIVariableBindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->denemeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modifyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->nameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->unitsDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->valueDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->parAnatStr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->parameters->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->uIVariableBindingSource))->BeginInit();
			this->variables->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->uIVariableBindingSource1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->parameters);
			this->tabControl1->Controls->Add(this->variables);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(922, 373);
			this->tabControl1->TabIndex = 0;
			// 
			// parameters
			// 
			this->parameters->Controls->Add(this->dataGridView1);
			this->parameters->Location = System::Drawing::Point(4, 22);
			this->parameters->Name = L"parameters";
			this->parameters->Padding = System::Windows::Forms::Padding(3);
			this->parameters->Size = System::Drawing::Size(914, 347);
			this->parameters->TabIndex = 0;
			this->parameters->Text = L"Parameters";
			this->parameters->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->nameDataGridViewTextBoxColumn, 
				this->unitsDataGridViewTextBoxColumn, this->valueDataGridViewTextBoxColumn, this->parAnatStr});
			this->dataGridView1->DataSource = this->uIVariableBindingSource;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(908, 341);
			this->dataGridView1->TabIndex = 0;
			// 
			// uIVariableBindingSource
			// 
			//this->uIVariableBindingSource->DataSource = UI_Variable::typeid;
			this->uIVariableBindingSource->DataSource = parameters_list;
			// 
			// variables
			// 
			this->variables->Controls->Add(this->dataGridView2);
			this->variables->Location = System::Drawing::Point(4, 22);
			this->variables->Name = L"variables";
			this->variables->Padding = System::Windows::Forms::Padding(3);
			this->variables->Size = System::Drawing::Size(914, 347);
			this->variables->TabIndex = 1;
			this->variables->Text = L"Variables";
			this->variables->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoGenerateColumns = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->nameDataGridViewTextBoxColumn1, 
				this->Formula, this->valueDataGridViewTextBoxColumn1, this->unitsDataGridViewTextBoxColumn1, this->descDataGridViewTextBoxColumn, 
				this->varAnatStr});
			this->dataGridView2->DataSource = this->uIVariableBindingSource1;
			this->dataGridView2->Location = System::Drawing::Point(3, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(905, 324);
			this->dataGridView2->TabIndex = 0;
			// 
			// nameDataGridViewTextBoxColumn1
			// 
			this->nameDataGridViewTextBoxColumn1->DataPropertyName = L"Name";
			this->nameDataGridViewTextBoxColumn1->HeaderText = L"Name";
			this->nameDataGridViewTextBoxColumn1->Name = L"nameDataGridViewTextBoxColumn1";
			// 
			// Formula
			// 
			this->Formula->DataPropertyName = L"Formula";
			this->Formula->HeaderText = L"Formula";
			this->Formula->Name = L"Formula";
			this->Formula->Width = 300;
			// 
			// valueDataGridViewTextBoxColumn1
			// 
			this->valueDataGridViewTextBoxColumn1->DataPropertyName = L"Value";
			this->valueDataGridViewTextBoxColumn1->HeaderText = L"Value";
			this->valueDataGridViewTextBoxColumn1->Name = L"valueDataGridViewTextBoxColumn1";
			// 
			// unitsDataGridViewTextBoxColumn1
			// 
			this->unitsDataGridViewTextBoxColumn1->DataPropertyName = L"Units";
			this->unitsDataGridViewTextBoxColumn1->HeaderText = L"Units";
			this->unitsDataGridViewTextBoxColumn1->Name = L"unitsDataGridViewTextBoxColumn1";
			// 
			// descDataGridViewTextBoxColumn
			// 
			this->descDataGridViewTextBoxColumn->DataPropertyName = L"Desc";
			this->descDataGridViewTextBoxColumn->HeaderText = L"Desc";
			this->descDataGridViewTextBoxColumn->Name = L"descDataGridViewTextBoxColumn";
			// 
			// varAnatStr
			// 
			this->varAnatStr->DataPropertyName = L"str_name";
			this->varAnatStr->HeaderText = L"Anatomical Structure";
			this->varAnatStr->Name = L"varAnatStr";
			this->varAnatStr->ReadOnly = true;
			this->varAnatStr->Width = 150;
			// 
			// uIVariableBindingSource1
			// 
			//this->uIVariableBindingSource1->DataSource = UI_Variable::typeid;
			this->uIVariableBindingSource1->DataSource = variables_list;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->denemeToolStripMenuItem, 
				this->modifyToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(184, 48);
			// 
			// denemeToolStripMenuItem
			// 
			this->denemeToolStripMenuItem->Name = L"denemeToolStripMenuItem";
			this->denemeToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->denemeToolStripMenuItem->Text = L"Add Anatomical Assoc.";
			this->denemeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Load_Model_Form::denemeToolStripMenuItem_Click);
			// 
			// modifyToolStripMenuItem
			// 
			this->modifyToolStripMenuItem->Name = L"modifyToolStripMenuItem";
			this->modifyToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->modifyToolStripMenuItem->Text = L"Modify";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(16, 400);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load Anatomical Information";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Load_Model_Form::load_anatomical_inf_clicked);
			// 
			// nameDataGridViewTextBoxColumn
			// 
			this->nameDataGridViewTextBoxColumn->DataPropertyName = L"Name";
			this->nameDataGridViewTextBoxColumn->HeaderText = L"Name";
			this->nameDataGridViewTextBoxColumn->Name = L"nameDataGridViewTextBoxColumn";
			// 
			// unitsDataGridViewTextBoxColumn
			// 
			this->unitsDataGridViewTextBoxColumn->DataPropertyName = L"Units";
			this->unitsDataGridViewTextBoxColumn->HeaderText = L"Units";
			this->unitsDataGridViewTextBoxColumn->Name = L"unitsDataGridViewTextBoxColumn";
			// 
			// valueDataGridViewTextBoxColumn
			// 
			this->valueDataGridViewTextBoxColumn->DataPropertyName = L"Value";
			this->valueDataGridViewTextBoxColumn->HeaderText = L"Value";
			this->valueDataGridViewTextBoxColumn->Name = L"valueDataGridViewTextBoxColumn";
			// 
			// parAnatStr
			// 
			this->parAnatStr->DataPropertyName = L"str_name";
			this->parAnatStr->HeaderText = L"Anatomical Structure";
			this->parAnatStr->Name = L"parAnatStr";
			this->parAnatStr->ReadOnly = true;
			this->parAnatStr->Width = 150;
			// 
			// Load_Model_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 572);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Load_Model_Form";
			this->Text = L"Load_Model_Form";
			this->tabControl1->ResumeLayout(false);
			this->parameters->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->uIVariableBindingSource))->EndInit();
			this->variables->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->uIVariableBindingSource1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void denemeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				//this->attach_anatomical_str(this->dataGridView2->CurrentRow);
				this->attach_anatomical_str_collection(this->dataGridView2->SelectedRows);

			 }		 
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void load_anatomical_inf_clicked(System::Object^  sender, System::EventArgs^  e) {
			 this->load_anatomical_information();

		 }
};
}
#endif