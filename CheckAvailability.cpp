#include "Dashboard.h"
#include "CheckAvailability.h"
#include "GenerateBills.h"

using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;


// LoadData() function banaya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein 

void CheckAvailability::LoadData()
{

    try {

        /* Yahan hum ne DataGridView ko database se data load karne ka code likha hai.
         Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */


        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT rooms, type, price FROM rooms;", conn);

        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        TotalRoomsGridView->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }

    // Khud se apna layout set karke gridview mein fix ho jaye ga
	TotalRoomsGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

    try {

        /* Yahan hum ne DataGridView ko database se data load karne ka code likha hai.
         Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */


        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();
        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT roomNo FROM rooms;", conn);

        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        BookedRoomsGridView->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }

    // Khud se apna layout set karke gridview mein fix ho jaye ga
    BookedRoomsGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
	

}


void CheckAvailability::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
    Dashboard^ dashboard = gcnew Dashboard();
    dashboard->Show();
    this->Hide();
}

void CheckAvailability::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	GenerateBills^ generateBills = gcnew GenerateBills();
    generateBills->Show();
    this->Hide();
}