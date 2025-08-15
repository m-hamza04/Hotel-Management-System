#include "ViewDetails.h"
#include <string.h>
#include "BookRooms.h"
#include "CheckAvailability.h"

using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;


// LoadData() function banaya hai, jab yeh form load hoga tou saari details load ho jayengi DataGridView mein 

void ViewDetails::LoadData()
{

    try {

		/* Yahan hum ne DataGridView ko database se data load karne ka code likha hai.
		 Jaise hee form load hoga, tou DataGridView mein data load ho jaye ga */
     

        String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ conn = gcnew OleDbConnection(connString);
        conn->Open();

		// SQL Queries

        OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(
            "SELECT b.bookingID, b.checkinDate, bl.checkoutDate, c.firstName, c.lastName, " +
            "c.address, c.mobile, b.roomNo, c.gender, c.email, c.nationality, r.roomType " +
            "FROM ((bookings b " +
            "INNER JOIN (customers c INNER JOIN details d ON c.bookingID = d.bookingID) ON b.bookingID = c.bookingID) " +
            "INNER JOIN rooms r ON b.roomNo = r.roomNo) " +
            "LEFT JOIN bills bl ON b.bookingID = bl.bookingID",conn);


        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dataGridView1->DataSource = dt;
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }

    


}

void ViewDetails::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
    BookRooms^ bookRooms = gcnew BookRooms();
    bookRooms->Show();
    this->Hide();
}

void ViewDetails::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
    CheckAvailability^ checkAvailability = gcnew CheckAvailability();
    checkAvailability->Show();
    this->Hide();
}