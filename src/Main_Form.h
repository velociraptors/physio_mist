#pragma once

#include "FMA_Reader.h"
#include "stdafx.h"
#include "Phy_MIST_Manager.h"




namespace Physio_MIST {


	/// <summary>
	/// Summary for Main_Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Main_Form : public System::Windows::Forms::Form
	{
	public:
		Main_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//manager = Phy_MIST_Manager::getInstance();
			//
			//fillOntologyTree();
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	

	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newModelToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  integrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ontologyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  buildToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  runSimulationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  manualToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  testReadToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	//private: Load_Model_Form ^loaded_model;
	private: Model_Form ^test_model;





	private: System::ComponentModel::IContainer^  components;
			 
	//public: Phy_MIST_Manager *manager;

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
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->integrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testReadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ontologyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buildToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runSimulationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manualToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileToolStripMenuItem, 
				this->viewToolStripMenuItem, this->buildToolStripMenuItem, this->windowToolStripMenuItem, this->toolsToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->MdiWindowListItem = this->windowToolStripMenuItem;
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip->Size = System::Drawing::Size(706, 24);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->newToolStripMenuItem, 
				this->toolStripSeparator1, this->saveToolStripMenuItem, this->loadToolStripMenuItem, this->importToolStripMenuItem, this->exportToolStripMenuItem, 
				this->exitToolStripMenuItem, this->testReadToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->newModelToolStripMenuItem, 
				this->integrationToolStripMenuItem});
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->newToolStripMenuItem->Text = L"New";
			// 
			// newModelToolStripMenuItem
			// 
			this->newModelToolStripMenuItem->Name = L"newModelToolStripMenuItem";
			this->newModelToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->newModelToolStripMenuItem->Text = L"Model";
			this->newModelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Form::newModelClick);
			// 
			// integrationToolStripMenuItem
			// 
			this->integrationToolStripMenuItem->Name = L"integrationToolStripMenuItem";
			this->integrationToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->integrationToolStripMenuItem->Text = L"Integration";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Form::saveModel);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Form::load_Model);
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->importToolStripMenuItem->Text = L"Import";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Form::importToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"&Exit";
			// 
			// testReadToolStripMenuItem
			// 
			this->testReadToolStripMenuItem->Name = L"testReadToolStripMenuItem";
			this->testReadToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->testReadToolStripMenuItem->Text = L"test read";
			this->testReadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_Form::test_fma_read);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ontologyToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// ontologyToolStripMenuItem
			// 
			this->ontologyToolStripMenuItem->Checked = true;
			this->ontologyToolStripMenuItem->CheckOnClick = true;
			this->ontologyToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ontologyToolStripMenuItem->Name = L"ontologyToolStripMenuItem";
			this->ontologyToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->ontologyToolStripMenuItem->Text = L"Ontology";
			this->ontologyToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &Main_Form::ontologyToolStripMenuItem_CheckedChanged);
			// 
			// buildToolStripMenuItem
			// 
			this->buildToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->compileToolStripMenuItem, 
				this->runSimulationToolStripMenuItem});
			this->buildToolStripMenuItem->Name = L"buildToolStripMenuItem";
			this->buildToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->buildToolStripMenuItem->Text = L"Build";
			// 
			// compileToolStripMenuItem
			// 
			this->compileToolStripMenuItem->Name = L"compileToolStripMenuItem";
			this->compileToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->compileToolStripMenuItem->Text = L"Compile";
			// 
			// runSimulationToolStripMenuItem
			// 
			this->runSimulationToolStripMenuItem->Name = L"runSimulationToolStripMenuItem";
			this->runSimulationToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->runSimulationToolStripMenuItem->Text = L"Run Simulation";
			// 
			// windowToolStripMenuItem
			// 
			this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
			this->windowToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->windowToolStripMenuItem->Text = L"&Window";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->optionsToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->aboutToolStripMenuItem, 
				this->manualToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// manualToolStripMenuItem
			// 
			this->manualToolStripMenuItem->Name = L"manualToolStripMenuItem";
			this->manualToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->manualToolStripMenuItem->Text = L"Manual";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// Main_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 397);
			this->Controls->Add(this->menuStrip);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Main_Form";
			this->Text = L"Physio_MIST";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Main_Form::Main_Form_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: Ontology_Tree_Form^ ontologyForm;


private: System::Void Main_Form_Load(System::Object^  sender, System::EventArgs^  e) {
			    ontologyForm = gcnew Ontology_Tree_Form();
				ontologyForm->MdiParent = this;
				ontologyForm->Show();				 

			 }
private: System::Void ontologyToolStripMenuItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(ontologyToolStripMenuItem->Checked == false)
			 {
				 ontologyForm->Hide();
			 }
			 else
			 {
				 ontologyForm->Show();
			 }
		 }

private: System::Void load_Model(System::Object^  sender, System::EventArgs^  e){
			String ^current_dir = System::IO::Directory::GetCurrentDirectory();
			 openFileDialog2 = gcnew System::Windows::Forms::OpenFileDialog();
			 if(openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 test_model = gcnew Model_Form(openFileDialog2->FileName);
				 System::IO::Directory::SetCurrentDirectory(current_dir);
				 test_model->MdiParent = this;
				 test_model->Show();
			 }
		 }

private: System::Void saveModel(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog = gcnew System::Windows::Forms::SaveFileDialog();
			 saveFileDialog->Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
			 saveFileDialog->FilterIndex = 1;
			 saveFileDialog->RestoreDirectory = true;
			 if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 Phy_MIST_Manager::getInstance()->create_XML_file(saveFileDialog->FileName);
			 }	 
		 }

private: System::Void test_fma_read(System::Object^  sender, System::EventArgs^  e) {
 String ^path = System::IO::Directory::GetCurrentDirectory();			
			 FMA_Reader ^reader = gcnew FMA_Reader(".\\Classdefs\\fmapins-A.txt");
			 reader->read_structure("Anterior+bronchopulmonary+segment");
		 }
private: System::Void newModelClick(System::Object^  sender, System::EventArgs^  e) {
			 test_model = gcnew Model_Form();
			 test_model->MdiParent = this;
			 test_model->Show();
		 }
private: System::Void importToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //String ^current_dir =  System::IO::Directory::GetCurrentDirectory();
			 //openFileDialog1 = gcnew System::Windows::Forms::OpenFileDialog();
			 //if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				//loaded_model = gcnew Load_Model_Form(openFileDialog1->FileName);
				//System::IO::Directory::SetCurrentDirectory(current_dir);
				//loaded_model->MdiParent = this;
				//loaded_model->Show();
			 //}
		 }
	};

}

