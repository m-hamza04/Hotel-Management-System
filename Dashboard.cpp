#include "Dashboard.h"
#include "BookRooms.h"
#include "ViewDetails.h"
#include "CheckAvailability.h"
#include "GenerateBills.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HOTELMANAGEMENTSYSTEM;


/*BookRooms wale button ka event handler initialize kiya hai, agar BookRooms wala button click hoga, 
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::BookRoomsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    BookRooms^ bookRooms = gcnew BookRooms();
    bookRooms->Show();
    this->Hide();
}

/*ViewDetails wale button ka event handler initialize kiya hai, agar ViewDetails wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::ViewDetailsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    ViewDetails^ viewDetails = gcnew ViewDetails();
    viewDetails->Show();
    this->Hide();
}

/*CheckAvailability wale button ka event handler initialize kiya hai, agar CheckAvailability wala button 
click hoga, tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::CheckAvailabilityButton_Click(System::Object^ sender, System::EventArgs^ e) {
    CheckAvailability^ checkAvailability = gcnew CheckAvailability();
    checkAvailability->Show();
    this->Hide();
}

/*GenerateBills wale button ka event handler initialize kiya hai, agar GenerateBills wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::GenerateBillsButton_Click(System::Object^ sender, System::EventArgs^ e) {
    GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
    this->Hide();
}

/*Logout wale button ka event handler initialize kiya hai, agar Logoout wala button click hoga,
tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

void Dashboard::LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBoxIcon icon = MessageBoxIcon::Question;
	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
	if (MessageBox::Show("Are you sure you want to Logout?", "Logout", buttons, icon) == System::Windows::Forms::DialogResult::Yes)
	
    {
        
        Login^ login = gcnew Login();
        login->ShowDialog();
        this->Close();  // login form open hone k baad ye wala form close ho jaye ga

	}

	else
	{
		MessageBox::Show("Logout Cancelled");
	}

}

