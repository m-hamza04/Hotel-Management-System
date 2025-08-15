#include "BookRooms.h"
#include "Dashboard.h"
#include "ViewDetails.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;


namespace HOTELMANAGEMENTSYSTEM {

    void BookRooms::LoadData() {

        // Yahan hum ne MS Access connect kiya hai

        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        try {
            connection->Open();

            // SQL Queries
			// "bookings", "customers", "details", and "rooms" tables
            // "POORI APPLICATION KA MOST IMPORTANT PART HAI YEH WALI QUERY KYUN KE IS MEIN INNER JOINS BHI HAIN " 

            String^ query = "SELECT b.bookingID, b.checkinDate, c.firstName, c.lastName, c.address, c.mobile, b.roomNo, c.gender, "
                "c.email, c.nationality, r.roomType "
                "FROM ((bookings b INNER JOIN customers c ON c.bookingID = b.bookingID) "
                "INNER JOIN details d ON (d.bookingID = b.bookingID AND d.roomNo = b.roomNo))"
                "INNER JOIN rooms r ON r.roomNo = b.roomNo";

            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
            OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(command);
            DataTable^ dataTable = gcnew DataTable();
            adapter->Fill(dataTable);

            // Saara data, DataGridView mein fit hojaye ga

            dataGridView1->DataSource = dataTable;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading data: " + ex->Message);
        }

        finally {
            connection->Close();
        }
    }

    /* "ADD" button ka event handler initialize kiya hai, jab ADD wala button click hoga,
    tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/

    void BookRooms::AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

        // Agar koi aik field bhi khaali chhor di tou yeh message box show hoga
        if (FisrtNameTextBox->Text->Length == 0 || LastNameTextBox->Text->Length == 0 ||
            NationalityComboBox->SelectedIndex == -1 || GenderComboBox->SelectedIndex == -1 || RoomTypeComboBox->SelectedIndex == -1 ||
            RoomNoComboBox->SelectedIndex == -1 || ResidentialAddressBox->Text->Length == 0 || EmailTextBox->Text->Length == 0 ||
            ContactNumberTextBox->Text->Length == 0)
        {
            MessageBox::Show("Please fill all fields!");
            return;
        }

        // Yahan room type pe relevant room number select karne ki validation lagayi hai

        // SUITE wale rooms ki validation
        if ((RoomTypeComboBox->SelectedIndex == 0) && (RoomNoComboBox->SelectedIndex == 0 || RoomNoComboBox->SelectedIndex == 1 || RoomNoComboBox->SelectedIndex == 5 || RoomNoComboBox->SelectedIndex == 6 || RoomNoComboBox->SelectedIndex == 7))
        {
            MessageBox::Show("Please select the relevant room number for the selected room type!");
            return;
        }

        // DELUXE wale rooms ki validation
        if ((RoomTypeComboBox->SelectedIndex == 1) && (RoomNoComboBox->SelectedIndex == 2 || RoomNoComboBox->SelectedIndex == 3 || RoomNoComboBox->SelectedIndex == 4 || RoomNoComboBox->SelectedIndex == 5 || RoomNoComboBox->SelectedIndex == 6 || RoomNoComboBox->SelectedIndex == 7))
        {
            MessageBox::Show("Please select the relevant room number for the selected room type!");
            return;
        }

        // STANDARD wale rooms ki validation
        if ((RoomTypeComboBox->SelectedIndex == 2) && (RoomNoComboBox->SelectedIndex == 0 || RoomNoComboBox->SelectedIndex == 1 || RoomNoComboBox->SelectedIndex == 2 || RoomNoComboBox->SelectedIndex == 3 || RoomNoComboBox->SelectedIndex == 4))
        {
            MessageBox::Show("Please select the relevant room number for the selected room type!");
            return;
        }

        // Yahan email pe validation lagayi hui hai
        if (!EmailTextBox->Text->Contains("@") || !EmailTextBox->Text->Contains(".com"))
        {
            MessageBox::Show("Please enter a valid email address!");
            return;
        }

        // Yahan hum ne MS Access connect kiya hai
        String^ connections =
            "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ connection = gcnew OleDbConnection(connections);

        try {
            connection->Open();

            // First check if room is already booked
            String^ checkRoomQuery = "SELECT COUNT(*) FROM bookings WHERE roomNo = @roomNo";
            OleDbCommand^ checkCommand = gcnew OleDbCommand(checkRoomQuery, connection);
            checkCommand->Parameters->AddWithValue("@roomNo", RoomNoComboBox->Text);
            int roomCount = Convert::ToInt32(checkCommand->ExecuteScalar());

            if (roomCount > 0) {
                MessageBox::Show("This room is already booked. Please select another room.");
                connection->Close();
                return;
            }

			// rooms table mein room number aur room type insert karne ki query

			String^ roomsQuery = "INSERT INTO rooms (roomNo, roomType) VALUES (@roomNo, @roomType)";
            OleDbCommand^ roomsCommand = gcnew OleDbCommand(roomsQuery, connection);
			roomsCommand->Parameters->AddWithValue("@roomNo", RoomNoComboBox->Text);
			roomsCommand->Parameters->AddWithValue("@roomType", RoomTypeComboBox->Text);
			roomsCommand->ExecuteNonQuery();


            OleDbTransaction^ transaction = connection->BeginTransaction();

            try {
                // 1. Insert into bookings table
                String^ bookingQuery = "INSERT INTO bookings (checkinDate, roomNo) VALUES (@checkinDate, @roomNo)";
                OleDbCommand^ bookingCommand = gcnew OleDbCommand(bookingQuery, connection, transaction);

                bookingCommand->Parameters->AddWithValue("@checkinDate", dateTimePicker1->Value.ToString("MM/dd/yyyy"));
                bookingCommand->Parameters->AddWithValue("@roomNo", RoomNoComboBox->Text);
                bookingCommand->ExecuteNonQuery();

                // auto-generated bookingID ko lega
                bookingCommand->CommandText = "SELECT @@IDENTITY";
                int bookingID = Convert::ToInt32(bookingCommand->ExecuteScalar());

                // 2. Insert into customers table
                String^ customerQuery = "INSERT INTO customers (bookingID, firstName, lastName, address, mobile, gender, email, nationality) "
                    "VALUES (@bookingID, @firstName, @lastName, @address, @mobile, @gender, @email, @nationality)";
                OleDbCommand^ customerCommand = gcnew OleDbCommand(customerQuery, connection, transaction);
                customerCommand->Parameters->AddWithValue("@bookingID", bookingID);
                customerCommand->Parameters->AddWithValue("@firstName", FisrtNameTextBox->Text);
                customerCommand->Parameters->AddWithValue("@lastName", LastNameTextBox->Text);
                customerCommand->Parameters->AddWithValue("@address", ResidentialAddressBox->Text);
                customerCommand->Parameters->AddWithValue("@mobile", ContactNumberTextBox->Text);
                customerCommand->Parameters->AddWithValue("@gender", GenderComboBox->Text);
                customerCommand->Parameters->AddWithValue("@email", EmailTextBox->Text);
                customerCommand->Parameters->AddWithValue("@nationality", NationalityComboBox->Text);
                customerCommand->ExecuteNonQuery();

                // 3. Insert into details table
                String^ detailsQuery = "INSERT INTO details (bookingID, roomNo) VALUES (@bookingID, @roomNo)";
                OleDbCommand^ detailsCommand = gcnew OleDbCommand(detailsQuery, connection, transaction);
                detailsCommand->Parameters->AddWithValue("@bookingID", bookingID);
                detailsCommand->Parameters->AddWithValue("@roomNo", RoomNoComboBox->Text);
                detailsCommand->ExecuteNonQuery();

                // Saare operations successful hone par, commit kar do
                transaction->Commit();

                // Jaise hee LoadData function call hoga, tou DataGridView update hojaye ga
                LoadData();

                // Saare boxes clear ho jayen ge
                FisrtNameTextBox->Clear();
                LastNameTextBox->Clear();
                NationalityComboBox->SelectedIndex = -1;
                GenderComboBox->SelectedIndex = -1;
                RoomTypeComboBox->SelectedIndex = -1;
                RoomNoComboBox->SelectedIndex = -1;
                ResidentialAddressBox->Clear();
                EmailTextBox->Clear();
                ContactNumberTextBox->Clear();

                MessageBox::Show("Booking added successfully!");
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                MessageBox::Show("Error adding booking: " + ex->Message);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Database connection error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

   
    /* "DELETE" button ka event handler initialize kiya hai, jab DELETE wala button click hoga,
    tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/


    void BookRooms::DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a booking to delete!");
            return;
        }

        int bookingID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["bookingID"]->Value);
        String^ roomNo = dataGridView1->SelectedRows[0]->Cells["roomNo"]->Value->ToString();

        // Yahan bhi MS Access connect karne ka hee code likha hai

        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        try {
            connection->Open();
            OleDbTransaction^ transaction = connection->BeginTransaction();

            try {
                // 1. customers table mein se delete karen ge

                String^ customerQuery = "DELETE FROM customers WHERE bookingID = @bookingID";
                OleDbCommand^ customerCommand = gcnew OleDbCommand(customerQuery, connection, transaction);
                customerCommand->Parameters->AddWithValue("@bookingID", bookingID);
                customerCommand->ExecuteNonQuery();

                // 2. details table mein se delete karen ge

                String^ detailsQuery = "DELETE FROM details WHERE bookingID = @bookingID";
                OleDbCommand^ detailsCommand = gcnew OleDbCommand(detailsQuery, connection, transaction);
                detailsCommand->Parameters->AddWithValue("@bookingID", bookingID);
                detailsCommand->ExecuteNonQuery();

                // 3. bookings table mein se delete karen ge

                String^ bookingQuery = "DELETE FROM bookings WHERE bookingID = @bookingID";
                OleDbCommand^ bookingCommand = gcnew OleDbCommand(bookingQuery, connection, transaction);
                bookingCommand->Parameters->AddWithValue("@bookingID", bookingID);
                bookingCommand->ExecuteNonQuery();
                
				// agar saare operations successful hojayen ge, tou commit kar do

                transaction->Commit();

                // Jaise hee LoadData function call hoga, tou DataGridView refresh hojaye ga

                LoadData();

                MessageBox::Show("Booking deleted successfully!");
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                MessageBox::Show("Error deleting booking: " + ex->Message);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Database connection error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }



    /* "HOME" button ka event handler initialize kiya hai, jab HOME wala button click hoga,
    tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/



    void BookRooms::HomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBoxIcon icon = MessageBoxIcon::Question;
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        if (MessageBox::Show("Are you sure you want to go back to dashboard?", "Confirm", buttons, icon) == System::Windows::Forms::DialogResult::Yes) {
            Dashboard^ dashboard = gcnew Dashboard();
            dashboard->Show();
            this->Hide();
        }
    }


    /* "NEXT" button ka event handler initialize kiya hai, jab NEXT wala button click hoga,
    tou curly brackets k andar likhi hui saari cheezen step by step execute hongi.*/


    void BookRooms::NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Go to \"View Details\"");
        ViewDetails^ viewDetails = gcnew ViewDetails();
        viewDetails->Show();
        this->Hide();
    }
}
