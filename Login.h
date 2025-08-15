#pragma once

namespace HOTELMANAGEMENTSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ClearButton;
	protected:

	private: System::Windows::Forms::Button^ LoginButton;
	protected:

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ ShowPasswordButton;
	private: System::Windows::Forms::Button^ HidePasswordButton;



	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel1;





	private: System::Windows::Forms::TextBox^ textBoxPassword;
		   void CheckLogin(System::Object^ sender, System::EventArgs^ e);
		   

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::TextBox^ textBoxUserName;

	private: System::Windows::Forms::Label^ label4;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->ShowPasswordButton = (gcnew System::Windows::Forms::Button());
			this->HidePasswordButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ClearButton
			// 
			this->ClearButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->ClearButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClearButton->Location = System::Drawing::Point(1212, 750);
			this->ClearButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(291, 57);
			this->ClearButton->TabIndex = 13;
			this->ClearButton->Text = L"CLEAR";
			this->ClearButton->UseVisualStyleBackColor = false;
			this->ClearButton->Click += gcnew System::EventHandler(this, &Login::ClearButton_Click);
			// 
			// LoginButton
			// 
			this->LoginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->LoginButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LoginButton->Location = System::Drawing::Point(1212, 620);
			this->LoginButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->Size = System::Drawing::Size(291, 57);
			this->LoginButton->TabIndex = 12;
			this->LoginButton->Text = L"LOGIN AS ADMIN";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click += gcnew System::EventHandler(this, &Login::LoginButton_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Controls->Add(this->ShowPasswordButton);
			this->panel4->Controls->Add(this->HidePasswordButton);
			this->panel4->Controls->Add(this->pictureBox2);
			this->panel4->Controls->Add(this->textBoxPassword);
			this->panel4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel4->Location = System::Drawing::Point(1037, 465);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(641, 79);
			this->panel4->TabIndex = 10;
			// 
			// ShowPasswordButton
			// 
			this->ShowPasswordButton->BackColor = System::Drawing::Color::White;
			this->ShowPasswordButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShowPasswordButton.BackgroundImage")));
			this->ShowPasswordButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ShowPasswordButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowPasswordButton->ForeColor = System::Drawing::Color::Black;
			this->ShowPasswordButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShowPasswordButton.Image")));
			this->ShowPasswordButton->Location = System::Drawing::Point(551, 10);
			this->ShowPasswordButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShowPasswordButton->Name = L"ShowPasswordButton";
			this->ShowPasswordButton->Size = System::Drawing::Size(71, 58);
			this->ShowPasswordButton->TabIndex = 9;
			this->ShowPasswordButton->UseVisualStyleBackColor = false;
			this->ShowPasswordButton->Click += gcnew System::EventHandler(this, &Login::ShowPasswordButton_Click);
			// 
			// HidePasswordButton
			// 
			this->HidePasswordButton->BackColor = System::Drawing::Color::White;
			this->HidePasswordButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HidePasswordButton->ForeColor = System::Drawing::Color::Black;
			this->HidePasswordButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"HidePasswordButton.Image")));
			this->HidePasswordButton->Location = System::Drawing::Point(551, 10);
			this->HidePasswordButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HidePasswordButton->Name = L"HidePasswordButton";
			this->HidePasswordButton->Size = System::Drawing::Size(71, 58);
			this->HidePasswordButton->TabIndex = 8;
			this->HidePasswordButton->UseVisualStyleBackColor = false;
			this->HidePasswordButton->Visible = false;
			this->HidePasswordButton->Click += gcnew System::EventHandler(this, &Login::HidePasswordButton_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(5, 10);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(65, 58);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPassword->Location = System::Drawing::Point(76, 10);
			this->textBoxPassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxPassword->Multiline = true;
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(544, 57);
			this->textBoxPassword->TabIndex = 2;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Controls->Add(this->pictureBox4);
			this->panel3->Controls->Add(this->textBoxUserName);
			this->panel3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel3->Location = System::Drawing::Point(1037, 326);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(641, 79);
			this->panel3->TabIndex = 9;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(5, 11);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(65, 58);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(5, 11);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(65, 58);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// textBoxUserName
			// 
			this->textBoxUserName->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxUserName->Location = System::Drawing::Point(76, 11);
			this->textBoxUserName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxUserName->Multiline = true;
			this->textBoxUserName->Name = L"textBoxUserName";
			this->textBoxUserName->Size = System::Drawing::Size(544, 57);
			this->textBoxUserName->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->label4->Location = System::Drawing::Point(1029, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(616, 68);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Login To Your Account";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(88, 570);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(355, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"WELCOME TO THE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(44, 657);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(433, 47);
			this->label2->TabIndex = 1;
			this->label2->Text = L"HOTEL MANAGEMENT";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(185, 750);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 47);
			this->label3->TabIndex = 2;
			this->label3->Text = L"SYSTEM";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(97, 201);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(371, 250);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(569, 1084);
			this->panel1->TabIndex = 14;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2004, 1084);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->LoginButton);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label4);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Login";
			this->Text = L"Login";
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		/* Is file mein ooper top se (#pragma once) lekar neeche bottom (#pragma endregion) tak
		jo code likha hua hai, ye Microsoft Visual Studio ka Automatically generated code hota hai,
		yani jo UI hum tool-box se drag and drop k through design karte hain, usi ko Microsoft Visual
		Studio apne aap hee se automatically, code mein convert kar deta hai.

		Is liye #pragma once se lekar #pragma endregion tak ka code hamare samajhne k liye nahi hai, ye
		just UI form k design ko automatically coding ki language mein convert kar deta hai.*/



		/* Yahan hum ne Login.h wale forms par saare buttons k event handlers banaye hain. */
		 

	// LoginButton ka event handler

private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e) {

	CheckLogin(sender, e); // Login.cpp file mein jo "CheckLogin" naam ka function banaya hai, usko call kiya hai.
}
	// ClearButton ka event handler

private: System::Void ClearButton_Click(System::Object^ sender, System::EventArgs^ e) {

	textBoxUserName->Clear(); // username mit jaye ga
	textBoxPassword->Clear(); // password mit jaye ga
}

	// Show and Hide PasswordButtons k event handlers

private: System::Void HidePasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {

	HidePasswordButton->Hide();
	ShowPasswordButton->Show();
	textBoxPassword->UseSystemPasswordChar = false; // password show ho jaye ga
}

private: System::Void ShowPasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {

	ShowPasswordButton->Hide();
	HidePasswordButton->Show();
	textBoxPassword->UseSystemPasswordChar = true; // password hide ho jaye ga
}
};
}
