#pragma once
#include "BookRooms.h"
#include "CheckAvailability.h"
#include "ViewDetails.h"
#include "GenerateBills.h"
#include "Login.h"

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace HOTELMANAGEMENTSYSTEM;
	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label7;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox5;




	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Button^ BookRoomsButton;

	private: System::Windows::Forms::Button^ GenerateBillsButton;



	private: System::Windows::Forms::Button^ ViewDetailsButton;
	private: System::Windows::Forms::Button^ CheckAvailabilityButton;
	private: System::Windows::Forms::Button^ LogoutButton;
	private: System::Windows::Forms::Label^ label2;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->BookRoomsButton = (gcnew System::Windows::Forms::Button());
			this->GenerateBillsButton = (gcnew System::Windows::Forms::Button());
			this->ViewDetailsButton = (gcnew System::Windows::Forms::Button());
			this->CheckAvailabilityButton = (gcnew System::Windows::Forms::Button());
			this->LogoutButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// panel7
			// 
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(200, 100);
			this->panel7->TabIndex = 51;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(0, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 23);
			this->label7->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1605, 105);
			this->panel1->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 45, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(298, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(978, 70);
			this->label1->TabIndex = 0;
			this->label1->Text = L"WELCOME TO THE GALAXY HOTEL";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(879, 225);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(240, 186);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 39;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(366, 510);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(246, 186);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 34;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(366, 225);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 186);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 45;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(879, 510);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(246, 186);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 40;
			this->pictureBox6->TabStop = false;
			// 
			// BookRoomsButton
			// 
			this->BookRoomsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->BookRoomsButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BookRoomsButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->BookRoomsButton->Location = System::Drawing::Point(366, 415);
			this->BookRoomsButton->Margin = System::Windows::Forms::Padding(2);
			this->BookRoomsButton->Name = L"BookRoomsButton";
			this->BookRoomsButton->Size = System::Drawing::Size(246, 57);
			this->BookRoomsButton->TabIndex = 46;
			this->BookRoomsButton->Text = L"BOOK ROOM";
			this->BookRoomsButton->UseVisualStyleBackColor = false;
			this->BookRoomsButton->Click += gcnew System::EventHandler(this, &Dashboard::BookRoomsButton_Click);
			// 
			// GenerateBillsButton
			// 
			this->GenerateBillsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->GenerateBillsButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenerateBillsButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GenerateBillsButton->Location = System::Drawing::Point(879, 700);
			this->GenerateBillsButton->Margin = System::Windows::Forms::Padding(2);
			this->GenerateBillsButton->Name = L"GenerateBillsButton";
			this->GenerateBillsButton->Size = System::Drawing::Size(246, 57);
			this->GenerateBillsButton->TabIndex = 47;
			this->GenerateBillsButton->Text = L"GENERATE BILL";
			this->GenerateBillsButton->UseVisualStyleBackColor = false;
			this->GenerateBillsButton->Click += gcnew System::EventHandler(this, &Dashboard::GenerateBillsButton_Click);
			// 
			// ViewDetailsButton
			// 
			this->ViewDetailsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->ViewDetailsButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ViewDetailsButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ViewDetailsButton->Location = System::Drawing::Point(879, 415);
			this->ViewDetailsButton->Margin = System::Windows::Forms::Padding(2);
			this->ViewDetailsButton->Name = L"ViewDetailsButton";
			this->ViewDetailsButton->Size = System::Drawing::Size(240, 57);
			this->ViewDetailsButton->TabIndex = 48;
			this->ViewDetailsButton->Text = L"VIEW DETAILS";
			this->ViewDetailsButton->UseVisualStyleBackColor = false;
			this->ViewDetailsButton->Click += gcnew System::EventHandler(this, &Dashboard::ViewDetailsButton_Click);
			// 
			// CheckAvailabilityButton
			// 
			this->CheckAvailabilityButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->CheckAvailabilityButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckAvailabilityButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->CheckAvailabilityButton->Location = System::Drawing::Point(366, 700);
			this->CheckAvailabilityButton->Margin = System::Windows::Forms::Padding(2);
			this->CheckAvailabilityButton->Name = L"CheckAvailabilityButton";
			this->CheckAvailabilityButton->Size = System::Drawing::Size(246, 57);
			this->CheckAvailabilityButton->TabIndex = 49;
			this->CheckAvailabilityButton->Text = L"CHECK AVAILABILITY";
			this->CheckAvailabilityButton->UseVisualStyleBackColor = false;
			this->CheckAvailabilityButton->Click += gcnew System::EventHandler(this, &Dashboard::CheckAvailabilityButton_Click);
			// 
			// LogoutButton
			// 
			this->LogoutButton->BackColor = System::Drawing::Color::Crimson;
			this->LogoutButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogoutButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LogoutButton->Location = System::Drawing::Point(1301, 225);
			this->LogoutButton->Margin = System::Windows::Forms::Padding(2);
			this->LogoutButton->Name = L"LogoutButton";
			this->LogoutButton->Size = System::Drawing::Size(158, 60);
			this->LogoutButton->TabIndex = 50;
			this->LogoutButton->Text = L"LOGOUT";
			this->LogoutButton->UseVisualStyleBackColor = false;
			this->LogoutButton->Click += gcnew System::EventHandler(this, &Dashboard::LogoutButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label2->Location = System::Drawing::Point(589, 135);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(320, 58);
			this->label2->TabIndex = 1;
			this->label2->Text = L"DASHBOARD";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1604, 881);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->LogoutButton);
			this->Controls->Add(this->CheckAvailabilityButton);
			this->Controls->Add(this->ViewDetailsButton);
			this->Controls->Add(this->GenerateBillsButton);
			this->Controls->Add(this->BookRoomsButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel7);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
		/* Yahan hum ne Dashboard.h wale forms par saare buttons k event handlers banaye hain.
		 In sab buttons ki implementation Dashboard.cpp file mein likhi hai */

		void BookRoomsButton_Click(System::Object^ sender, System::EventArgs^ e);

		void ViewDetailsButton_Click(System::Object^ sender, System::EventArgs^ e);

		void CheckAvailabilityButton_Click(System::Object^ sender, System::EventArgs^ e);

		void GenerateBillsButton_Click(System::Object^ sender, System::EventArgs^ e);
		
		void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e); 

};
}