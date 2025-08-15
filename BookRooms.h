#pragma once
#include "BookRooms.h"
#include "ViewDetails.h"
#include "Login.h"
#include "GenerateBills.h"
#include "CheckAvailability.h"
#include "Dashboard.h"

using namespace System::Data;
using namespace System::Data::OleDb;

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookRooms
	/// <summary>
	public ref class BookRooms : public System::Windows::Forms::Form
	{
	public:
		BookRooms(void)
		{
			InitializeComponent();
			
			/* LoadData() function call kiya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein */

			LoadData();
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &BookRooms::dataGridView1_SelectionChanged);
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->MultiSelect = false;
		}

        // Helper function k zariye se saari values lenge

		/*  Line number 44 se 85 tak, app ko user friendly bananay ka code hai
		DataGridView ki jis row pe click karen ge, uski details, textboxes mein show ho jayen gi*/

        String^ GetCellValue(DataGridViewRow^ selectedRow, String^ columnName) {
        if (selectedRow->Cells[columnName]->Value == nullptr)
        return String::Empty;
        return selectedRow->Cells[columnName]->Value->ToString();
        }

        System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
        // Clear controls if no row is selected
        if (dataGridView1->SelectedRows->Count == 0) {
        FisrtNameTextBox->Clear();
        LastNameTextBox->Clear();
        ResidentialAddressBox->Clear();
        EmailTextBox->Clear();
        ContactNumberTextBox->Clear();
        NationalityComboBox->SelectedIndex = -1;
        GenderComboBox->SelectedIndex = -1;
        RoomTypeComboBox->SelectedIndex = -1;
        RoomNoComboBox->SelectedIndex = -1;
        dateTimePicker1->Value = DateTime::Now;
        return;
        }

        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

        // Update textboxes
        FisrtNameTextBox->Text = GetCellValue(selectedRow, "firstName");
        LastNameTextBox->Text = GetCellValue(selectedRow, "lastName");
        ResidentialAddressBox->Text = GetCellValue(selectedRow, "address");
        EmailTextBox->Text = GetCellValue(selectedRow, "email");
        ContactNumberTextBox->Text = GetCellValue(selectedRow, "mobile");

        // Update comboboxes
        NationalityComboBox->Text = GetCellValue(selectedRow, "nationality");
        GenderComboBox->Text = GetCellValue(selectedRow, "gender");
        RoomTypeComboBox->Text = GetCellValue(selectedRow, "roomType");
        RoomNoComboBox->Text = GetCellValue(selectedRow, "roomNo");

        // Update datetimepicker
        DateTime checkinDate;
        if (DateTime::TryParse(GetCellValue(selectedRow, "checkinDate"), checkinDate)) {
        dateTimePicker1->Value = checkinDate;
        }
        }
	
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookRooms()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
		void LoadData();

		

	private: System::Windows::Forms::TextBox^ ResidentialAddressBox;
	protected:
	private: System::Windows::Forms::TextBox^ ContactNumberTextBox;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ NextButton;


	private: System::Windows::Forms::Button^ DeleteButton;

	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ HomeButton;





	private: System::Windows::Forms::TextBox^ EmailTextBox;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ label4;






	private: System::Windows::Forms::TextBox^ FisrtNameTextBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::TextBox^ LastNameTextBox;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::ComboBox^ RoomNoComboBox;
	private: System::Windows::Forms::ComboBox^ RoomTypeComboBox;
	private: System::Windows::Forms::ComboBox^ GenderComboBox;
	private: System::Windows::Forms::ComboBox^ NationalityComboBox;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::Label^ label3;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->ResidentialAddressBox = (gcnew System::Windows::Forms::TextBox());
			this->ContactNumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->HomeButton = (gcnew System::Windows::Forms::Button());
			this->EmailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->FisrtNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LastNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->RoomNoComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->RoomTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GenderComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->NationalityComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// ResidentialAddressBox
			// 
			this->ResidentialAddressBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResidentialAddressBox->Location = System::Drawing::Point(217, 534);
			this->ResidentialAddressBox->Margin = System::Windows::Forms::Padding(2);
			this->ResidentialAddressBox->Multiline = true;
			this->ResidentialAddressBox->Name = L"ResidentialAddressBox";
			this->ResidentialAddressBox->Size = System::Drawing::Size(271, 31);
			this->ResidentialAddressBox->TabIndex = 49;
			// 
			// ContactNumberTextBox
			// 
			this->ContactNumberTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ContactNumberTextBox->Location = System::Drawing::Point(217, 672);
			this->ContactNumberTextBox->Margin = System::Windows::Forms::Padding(2);
			this->ContactNumberTextBox->Multiline = true;
			this->ContactNumberTextBox->Name = L"ContactNumberTextBox";
			this->ContactNumberTextBox->Size = System::Drawing::Size(271, 31);
			this->ContactNumberTextBox->TabIndex = 48;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label12->Location = System::Drawing::Point(51, 532);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(136, 56);
			this->label12->TabIndex = 47;
			this->label12->Text = L"RESIDENTIAL ADDRESS";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label11->Location = System::Drawing::Point(16, 677);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(177, 26);
			this->label11->TabIndex = 46;
			this->label11->Text = L"PHONE NUMBER";
			// 
			// NextButton
			// 
			this->NextButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->NextButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextButton->ForeColor = System::Drawing::SystemColors::Control;
			this->NextButton->Location = System::Drawing::Point(1369, 691);
			this->NextButton->Margin = System::Windows::Forms::Padding(2);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(205, 75);
			this->NextButton->TabIndex = 44;
			this->NextButton->Text = L"NEXT";
			this->NextButton->UseVisualStyleBackColor = false;
			this->NextButton->Click += gcnew System::EventHandler(this, &BookRooms::NextButton_Click_1);
			// 
			// DeleteButton
			// 
			this->DeleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteButton->ForeColor = System::Drawing::SystemColors::Control;
			this->DeleteButton->Location = System::Drawing::Point(798, 691);
			this->DeleteButton->Margin = System::Windows::Forms::Padding(2);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(205, 75);
			this->DeleteButton->TabIndex = 43;
			this->DeleteButton->Text = L"DELETE";
			this->DeleteButton->UseVisualStyleBackColor = false;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &BookRooms::DeleteButton_Click_1);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->AddButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddButton->ForeColor = System::Drawing::SystemColors::Control;
			this->AddButton->Location = System::Drawing::Point(512, 691);
			this->AddButton->Margin = System::Windows::Forms::Padding(2);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(205, 75);
			this->AddButton->TabIndex = 42;
			this->AddButton->Text = L"ADD";
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &BookRooms::AddButton_Click_1);
			// 
			// HomeButton
			// 
			this->HomeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->HomeButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HomeButton->ForeColor = System::Drawing::SystemColors::Control;
			this->HomeButton->Location = System::Drawing::Point(1084, 691);
			this->HomeButton->Margin = System::Windows::Forms::Padding(2);
			this->HomeButton->Name = L"HomeButton";
			this->HomeButton->Size = System::Drawing::Size(205, 75);
			this->HomeButton->TabIndex = 41;
			this->HomeButton->Text = L"HOME";
			this->HomeButton->UseVisualStyleBackColor = false;
			this->HomeButton->Click += gcnew System::EventHandler(this, &BookRooms::HomeButton_Click_1);
			// 
			// EmailTextBox
			// 
			this->EmailTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EmailTextBox->Location = System::Drawing::Point(217, 605);
			this->EmailTextBox->Margin = System::Windows::Forms::Padding(2);
			this->EmailTextBox->Multiline = true;
			this->EmailTextBox->Name = L"EmailTextBox";
			this->EmailTextBox->Size = System::Drawing::Size(271, 31);
			this->EmailTextBox->TabIndex = 37;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label9->Location = System::Drawing::Point(77, 605);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 42);
			this->label9->TabIndex = 36;
			this->label9->Text = L"EMAIL";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label7->Location = System::Drawing::Point(68, 325);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 26);
			this->label7->TabIndex = 34;
			this->label7->Text = L"GENDER";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label6->Location = System::Drawing::Point(45, 255);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(148, 26);
			this->label6->TabIndex = 33;
			this->label6->Text = L"NATIONALITY";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label4->Location = System::Drawing::Point(55, 119);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 26);
			this->label4->TabIndex = 30;
			this->label4->Text = L"FIRST NAME";
			// 
			// FisrtNameTextBox
			// 
			this->FisrtNameTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FisrtNameTextBox->Location = System::Drawing::Point(217, 113);
			this->FisrtNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->FisrtNameTextBox->Multiline = true;
			this->FisrtNameTextBox->Name = L"FisrtNameTextBox";
			this->FisrtNameTextBox->Size = System::Drawing::Size(271, 32);
			this->FisrtNameTextBox->TabIndex = 30;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label1->Location = System::Drawing::Point(51, 396);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 32);
			this->label1->TabIndex = 54;
			this->label1->Text = L"ROOM TYPE";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label5->Location = System::Drawing::Point(37, 14);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(156, 26);
			this->label5->TabIndex = 31;
			this->label5->Text = L"ROLL NUMBER";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(706, 44);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(190, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ROOM BOOKING";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(676, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(265, 26);
			this->label8->TabIndex = 3;
			this->label8->Text = L"THE GALAXY HOTEL";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1604, 79);
			this->panel1->TabIndex = 51;
			// 
			// LastNameTextBox
			// 
			this->LastNameTextBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LastNameTextBox->Location = System::Drawing::Point(217, 183);
			this->LastNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->LastNameTextBox->Multiline = true;
			this->LastNameTextBox->Name = L"LastNameTextBox";
			this->LastNameTextBox->Size = System::Drawing::Size(271, 32);
			this->LastNameTextBox->TabIndex = 56;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label10->Location = System::Drawing::Point(55, 189);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(127, 26);
			this->label10->TabIndex = 57;
			this->label10->Text = L"LAST NAME";
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label13->Location = System::Drawing::Point(51, 464);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(136, 32);
			this->label13->TabIndex = 59;
			this->label13->Text = L"ROOM NO";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label14->Location = System::Drawing::Point(19, 740);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(174, 26);
			this->label14->TabIndex = 61;
			this->label14->Text = L"CHECK-IN DATE";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(217, 739);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(271, 27);
			this->dateTimePicker1->TabIndex = 62;
			// 
			// RoomNoComboBox
			// 
			this->RoomNoComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RoomNoComboBox->FormattingEnabled = true;
			this->RoomNoComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"101 - DELUXE", L"102 - DELUXE", L"103 - SUITE",
					L"104 - SUITE", L"105 - SUITE", L"106 - STANDARD", L"107 - STANDARD", L"108 - STANDARD"
			});
			this->RoomNoComboBox->Location = System::Drawing::Point(217, 464);
			this->RoomNoComboBox->Margin = System::Windows::Forms::Padding(2);
			this->RoomNoComboBox->Name = L"RoomNoComboBox";
			this->RoomNoComboBox->Size = System::Drawing::Size(271, 30);
			this->RoomNoComboBox->TabIndex = 60;
			// 
			// RoomTypeComboBox
			// 
			this->RoomTypeComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RoomTypeComboBox->FormattingEnabled = true;
			this->RoomTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"SUITE ($ 200.0)", L"DELUXE ($ 150.0)",
					L"STANDARD ($ 100.0)"
			});
			this->RoomTypeComboBox->Location = System::Drawing::Point(217, 395);
			this->RoomTypeComboBox->Margin = System::Windows::Forms::Padding(2);
			this->RoomTypeComboBox->Name = L"RoomTypeComboBox";
			this->RoomTypeComboBox->Size = System::Drawing::Size(271, 31);
			this->RoomTypeComboBox->TabIndex = 58;
			// 
			// GenderComboBox
			// 
			this->GenderComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenderComboBox->FormattingEnabled = true;
			this->GenderComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MALE", L"FEMALE" });
			this->GenderComboBox->Location = System::Drawing::Point(217, 325);
			this->GenderComboBox->Margin = System::Windows::Forms::Padding(2);
			this->GenderComboBox->Name = L"GenderComboBox";
			this->GenderComboBox->Size = System::Drawing::Size(271, 30);
			this->GenderComboBox->TabIndex = 39;
			// 
			// NationalityComboBox
			// 
			this->NationalityComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NationalityComboBox->FormattingEnabled = true;
			this->NationalityComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"PAKISTAN", L"INDIA", L"BANGLADESH",
					L"SRI LANKA", L"AFGHANISTAN", L"ENGLAND", L"CHINA", L"OTHER"
			});
			this->NationalityComboBox->Location = System::Drawing::Point(217, 255);
			this->NationalityComboBox->Margin = System::Windows::Forms::Padding(2);
			this->NationalityComboBox->Name = L"NationalityComboBox";
			this->NationalityComboBox->Size = System::Drawing::Size(271, 30);
			this->NationalityComboBox->TabIndex = 55;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(512, 189);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 90;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1062, 458);
			this->dataGridView1->TabIndex = 50;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label3->Location = System::Drawing::Point(765, 113);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(580, 44);
			this->label3->TabIndex = 4;
			this->label3->Text = L"ROOM BOOKING INFORMATION";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// BookRooms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1604, 881);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->RoomNoComboBox);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->RoomTypeComboBox);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->LastNameTextBox);
			this->Controls->Add(this->NationalityComboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FisrtNameTextBox);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->ResidentialAddressBox);
			this->Controls->Add(this->ContactNumberTextBox);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->HomeButton);
			this->Controls->Add(this->GenderComboBox);
			this->Controls->Add(this->EmailTextBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Name = L"BookRooms";
			this->Text = L"BookRooms";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		/* Yahan hum ne BookRooms.h wale forms par saare buttons k event handlers banaye hain.
		 In sab buttons ki implementation BookRooms.cpp file mein likhi hai */


		void AddButton_Click(System::Object^ sender, System::EventArgs^ e);

		void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e);

		void HomeButton_Click(System::Object^ sender, System::EventArgs^ e);

		void NextButton_Click(System::Object^ sender, System::EventArgs^ e);


	
		/*Yahan hum ne BookRooms.h wale forms par saare buttons k event handlers initialize kiye hain,
		aur har button k event handler ko initialize karte hue us button ka respective function call
		kiya hua hai, har button k functions BookRooms.cpp file mein banay hain, wahan se call kiye hain.*/

	private: System::Void AddButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		AddButton_Click(sender, e);
	}
	private: System::Void DeleteButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		DeleteButton_Click(sender, e);
	}

	private: System::Void HomeButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		HomeButton_Click(sender, e);
	}

	private: System::Void NextButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		NextButton_Click(sender, e);
	}
	
	


};
}