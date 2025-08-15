#pragma once
#include "GenerateBills.h"
#include "Dashboard.h"
#include "ViewDetails.h"

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GenerateBills
	/// </summary>
	public ref class GenerateBills : public System::Windows::Forms::Form
	{
	public:
		GenerateBills(void)
		{
			InitializeComponent();
            // In InitializeComponent() or form constructor
            this->roomPricePerNightComboBox->Items->Clear();
            this->roomPricePerNightComboBox->Items->AddRange(gcnew array<String^> {
                 "$200.00 (SUITE)",
                 "$150.00 (DELUXE)",
                 "$100.00 (STANDARD)"
                  });
          
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GenerateBills()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::DateTimePicker^ checkInDatePicker;
    protected:
    private: System::Windows::Forms::ComboBox^ roomNumberComboBox;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::ComboBox^ roomTypeComboBox;



    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::Label^ label1;

    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::Label^ label5;


    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::DateTimePicker^ checkOutDatePicker;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ daysStayedTextbox;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::ComboBox^ roomPricePerNightComboBox;
    private: System::Windows::Forms::Button^ GenerateBillButton;

    private: System::Windows::Forms::Label^ TotalBillLabel;

    private: System::Windows::Forms::Button^ HomeButton;

    private: System::Windows::Forms::Button^ BackButton;
    private: System::Windows::Forms::TextBox^ bookingIDTextbox;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		// Declare UI components
        // Helper methods
        void LoadBookingDetails(String^ bookingID);
        void CalculateDaysStayed();
        void CalculateTotalBill();
        void SaveBillToDatabase();


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
	{
            this->checkInDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->roomNumberComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->roomTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->checkOutDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->daysStayedTextbox = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->roomPricePerNightComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->GenerateBillButton = (gcnew System::Windows::Forms::Button());
            this->TotalBillLabel = (gcnew System::Windows::Forms::Label());
            this->HomeButton = (gcnew System::Windows::Forms::Button());
            this->BackButton = (gcnew System::Windows::Forms::Button());
            this->bookingIDTextbox = (gcnew System::Windows::Forms::TextBox());
            this->panel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // dateTimePicker1
            // 
            this->checkInDatePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->checkInDatePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->checkInDatePicker->Location = System::Drawing::Point(754, 488);
            this->checkInDatePicker->Name = L"dateTimePicker1";
            this->checkInDatePicker->Size = System::Drawing::Size(319, 29);
            this->checkInDatePicker->TabIndex = 92;
            // 
            // comboBox4
            // 
            this->roomNumberComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomNumberComboBox->FormattingEnabled = true;
            this->roomNumberComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
                L"101 ", L"102 ", L"103 ", L"104 ", L"105 ", L"106 ",
                    L"107 ", L"108 "
            });
            this->roomNumberComboBox->Location = System::Drawing::Point(754, 336);
            this->roomNumberComboBox->Margin = System::Windows::Forms::Padding(2);
            this->roomNumberComboBox->Name = L"comboBox4";
            this->roomNumberComboBox->Size = System::Drawing::Size(319, 30);
            this->roomNumberComboBox->TabIndex = 90;
            // 
            // label13
            // 
            this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label13->Location = System::Drawing::Point(527, 334);
            this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(136, 32);
            this->label13->TabIndex = 89;
            this->label13->Text = L"ROOM NO";
            // 
            // comboBox3
            // 
            this->roomTypeComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomTypeComboBox->FormattingEnabled = true;
            this->roomTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"SUITE ($ 200.0)", L"DELUXE ($ 150.0)", L"STANDARD ($ 100.0)" });
            this->roomTypeComboBox->Location = System::Drawing::Point(754, 268);
            this->roomTypeComboBox->Margin = System::Windows::Forms::Padding(2);
            this->roomTypeComboBox->Name = L"comboBox3";
            this->roomTypeComboBox->Size = System::Drawing::Size(319, 30);
            this->roomTypeComboBox->TabIndex = 88;
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
            this->panel1->TabIndex = 83;
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
            // label2
            // 
            this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(660, 44);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(281, 26);
            this->label2->TabIndex = 1;
            this->label2->Text = L"CHECK-OUT / BILL DETAILS";
            this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label14->Location = System::Drawing::Point(527, 490);
            this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(174, 26);
            this->label14->TabIndex = 91;
            this->label14->Text = L"CHECK-IN DATE";
            // 
            // label1
            // 
            this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label1->Location = System::Drawing::Point(527, 268);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(136, 32);
            this->label1->TabIndex = 84;
            this->label1->Text = L"ROOM TYPE";
            // 
            // textBox3
            // 
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox3->Location = System::Drawing::Point(217, 27);
            this->textBox3->Margin = System::Windows::Forms::Padding(2);
            this->textBox3->Multiline = true;
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(262, 31);
            this->textBox3->TabIndex = 68;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label5->Location = System::Drawing::Point(37, 29);
            this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(156, 26);
            this->label5->TabIndex = 67;
            this->label5->Text = L"ROLL NUMBER";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label3->Location = System::Drawing::Point(527, 203);
            this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(142, 26);
            this->label3->TabIndex = 63;
            this->label3->Text = L"BOOKING ID";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label6->Location = System::Drawing::Point(527, 570);
            this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(193, 26);
            this->label6->TabIndex = 93;
            this->label6->Text = L"CHECK-OUT DATE";
            // 
            // dateTimePicker2
            // 
            this->checkOutDatePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->checkOutDatePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->checkOutDatePicker->Location = System::Drawing::Point(754, 570);
            this->checkOutDatePicker->Name = L"dateTimePicker2";
            this->checkOutDatePicker->Size = System::Drawing::Size(319, 29);
            this->checkOutDatePicker->TabIndex = 94;
            this->checkOutDatePicker->ValueChanged += gcnew System::EventHandler(this, &GenerateBills::dateTimePicker2_ValueChanged_1);
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label9->Location = System::Drawing::Point(532, 104);
            this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(541, 65);
            this->label9->TabIndex = 95;
            this->label9->Text = L"BILLING / PAYMENTS";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label4->Location = System::Drawing::Point(527, 655);
            this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(150, 26);
            this->label4->TabIndex = 96;
            this->label4->Text = L"DAYS STAYED";
            // 
            // textBox2
            // 
            this->daysStayedTextbox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->daysStayedTextbox->Location = System::Drawing::Point(754, 649);
            this->daysStayedTextbox->Margin = System::Windows::Forms::Padding(2);
            this->daysStayedTextbox->Multiline = true;
            this->daysStayedTextbox->Name = L"textBox2";
            this->daysStayedTextbox->Size = System::Drawing::Size(319, 32);
            this->daysStayedTextbox->TabIndex = 97;
            // 
            // label7
            // 
            this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->label7->Location = System::Drawing::Point(527, 405);
            this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(150, 61);
            this->label7->TabIndex = 98;
            this->label7->Text = L"ROOM PRICE PER NIGHT";
            this->label7->UseCompatibleTextRendering = true;
            // 
            // comboBox1
            // 
            this->roomPricePerNightComboBox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomPricePerNightComboBox->FormattingEnabled = true;
            this->roomPricePerNightComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"$ 200.0 (SUITE)", L"$ 150.0 (DELUXE)", L"$ 100.0 (STANDARD)" });
            this->roomPricePerNightComboBox->Location = System::Drawing::Point(754, 405);
            this->roomPricePerNightComboBox->Margin = System::Windows::Forms::Padding(2);
            this->roomPricePerNightComboBox->Name = L"comboBox1";
            this->roomPricePerNightComboBox->Size = System::Drawing::Size(319, 30);
            this->roomPricePerNightComboBox->TabIndex = 99;
            // 
            // GenerateBillButton
            // 
            this->GenerateBillButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->GenerateBillButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->GenerateBillButton->ForeColor = System::Drawing::SystemColors::Control;
            this->GenerateBillButton->Location = System::Drawing::Point(494, 719);
            this->GenerateBillButton->Margin = System::Windows::Forms::Padding(2);
            this->GenerateBillButton->Name = L"GenerateBillButton";
            this->GenerateBillButton->Size = System::Drawing::Size(235, 75);
            this->GenerateBillButton->TabIndex = 100;
            this->GenerateBillButton->Text = L"GENERATE BILL";
            this->GenerateBillButton->UseVisualStyleBackColor = false;
            this->GenerateBillButton->Click += gcnew System::EventHandler(this, &GenerateBills::GenerateBillButton_Click_1);
            // 
            // label10
            // 
            this->TotalBillLabel->AutoSize = true;
            this->TotalBillLabel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->TotalBillLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->TotalBillLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TotalBillLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->TotalBillLabel->Location = System::Drawing::Point(806, 745);
            this->TotalBillLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->TotalBillLabel->Name = L"label10";
            this->TotalBillLabel->Size = System::Drawing::Size(204, 28);
            this->TotalBillLabel->TabIndex = 101;
            this->TotalBillLabel->Text = L"YOUR TOTAL BILL : ";
            // 
            // HomeButton
            // 
            this->HomeButton->BackColor = System::Drawing::Color::Crimson;
            this->HomeButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->HomeButton->ForeColor = System::Drawing::SystemColors::Control;
            this->HomeButton->Location = System::Drawing::Point(1383, 719);
            this->HomeButton->Margin = System::Windows::Forms::Padding(2);
            this->HomeButton->Name = L"HomeButton";
            this->HomeButton->Size = System::Drawing::Size(159, 75);
            this->HomeButton->TabIndex = 103;
            this->HomeButton->Text = L"HOME";
            this->HomeButton->UseVisualStyleBackColor = false;
            this->HomeButton->Click += gcnew System::EventHandler(this, &GenerateBills::HomeButton_Click_1);
            // 
            // BackButton
            // 
            this->BackButton->BackColor = System::Drawing::Color::Crimson;
            this->BackButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BackButton->ForeColor = System::Drawing::SystemColors::Control;
            this->BackButton->Location = System::Drawing::Point(1179, 717);
            this->BackButton->Margin = System::Windows::Forms::Padding(2);
            this->BackButton->Name = L"BackButton";
            this->BackButton->Size = System::Drawing::Size(159, 75);
            this->BackButton->TabIndex = 104;
            this->BackButton->Text = L"BACK";
            this->BackButton->UseVisualStyleBackColor = false;
            this->BackButton->Click += gcnew System::EventHandler(this, &GenerateBills::BackButton_Click_1);
            // 
            // textBox1
            // 
            this->bookingIDTextbox->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->bookingIDTextbox->Location = System::Drawing::Point(754, 197);
            this->bookingIDTextbox->Margin = System::Windows::Forms::Padding(2);
            this->bookingIDTextbox->Multiline = true;
            this->bookingIDTextbox->Name = L"textBox1";
            this->bookingIDTextbox->Size = System::Drawing::Size(319, 32);
            this->bookingIDTextbox->TabIndex = 105;
            this->bookingIDTextbox->TextChanged += gcnew System::EventHandler(this, &GenerateBills::textBox1_TextChanged_1);
            // 
            // GenerateBills
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1604, 881);
            this->Controls->Add(this->bookingIDTextbox);
            this->Controls->Add(this->BackButton);
            this->Controls->Add(this->HomeButton);
            this->Controls->Add(this->TotalBillLabel);
            this->Controls->Add(this->GenerateBillButton);
            this->Controls->Add(this->roomPricePerNightComboBox);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->daysStayedTextbox);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->checkOutDatePicker);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->checkInDatePicker);
            this->Controls->Add(this->roomNumberComboBox);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->roomTypeComboBox);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label14);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label3);
            this->Name = L"GenerateBills";
            this->Text = L"GenerateBills";
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        
    
      public:
        // Event handlers
        Void GenerateBillButton_Click(System::Object^ sender, System::EventArgs^ e);
        Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
        Void HomeButton_Click(System::Object^ sender, System::EventArgs^ e);
        Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
        Void dateTimePicker2_ValueChanged(System::Object^ sender, System::EventArgs^ e);


        private: System::Void GenerateBillButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
			GenerateBillButton_Click(sender, e);
        }


        private: System::Void BackButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
	        BackButton_Click(sender, e);
        }
        
        private: System::Void HomeButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
	        HomeButton_Click(sender, e);
        }

        private: System::Void dateTimePicker2_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	        dateTimePicker2_ValueChanged(sender, e);
        }


        private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	        textBox1_TextChanged(sender, e);
        }
};

}

