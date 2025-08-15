#include "GenerateBills.h"
#include "Dashboard.h"
#include "ViewDetails.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;

namespace HOTELMANAGEMENTSYSTEM {

    
    void GenerateBills::LoadBookingDetails(String^ bookingID)
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";

        try {
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
            connection->Open();

            String^ query = "SELECT b.bookingID, b.checkinDate, b.roomNo, r.roomType, r.price "
                "FROM bookings b INNER JOIN rooms r ON r.roomNo = b.roomNo "
                "WHERE b.bookingID = @bookingID";

            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
            command->Parameters->AddWithValue("@bookingID", bookingID);

            OleDbDataReader^ reader = command->ExecuteReader();

            if (reader->Read())
            {
                bookingIDTextbox->Text = reader["bookingID"]->ToString();
                roomNumberComboBox->Text = reader["roomNo"]->ToString();
                roomTypeComboBox->Text = reader["roomType"]->ToString();

                String^ roomType = reader["roomType"]->ToString();
                if (roomType == "SUITE ($ 200.0)") {
                    roomPricePerNightComboBox->Text = "$ 200.0 (SUITE)";
                }
                else if (roomType == "DELUXE ($ 150.0)") {
                    roomPricePerNightComboBox->Text = "$ 150.0 (DELUXE)";
                }
                else {
                    roomPricePerNightComboBox->Text = "$ 100.0 (STANDARD)";
                }

                DateTime checkinDate;
                if (DateTime::TryParse(reader["checkinDate"]->ToString(), checkinDate)) {
                    checkInDatePicker->Value = checkinDate;
                }

                checkOutDatePicker->Value = DateTime::Now;
                CalculateDaysStayed();
            }
            else {
                MessageBox::Show("Booking ID not found!");
            }

            connection->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading booking details: " + ex->Message);
        }
    }

    void GenerateBills::CalculateDaysStayed()
    {
        DateTime checkinDate = checkInDatePicker->Value;
        DateTime checkoutDate = checkOutDatePicker->Value;

        if (checkoutDate < checkinDate) {
            MessageBox::Show("Check-out date cannot be before check-in date!");
            checkOutDatePicker->Value = checkinDate;
            return;
        }

        TimeSpan duration = checkoutDate - checkinDate;
        int daysStayed = duration.Days;
        if (daysStayed == 0) daysStayed = 1;

        daysStayedTextbox->Text = daysStayed.ToString();
        
    }

    void GenerateBills::CalculateTotalBill()
    {
        try
        {
            // Check if required fields are empty
            if (daysStayedTextbox->Text->Length == 0 || roomPricePerNightComboBox->Text->Length == 0)
                return;

            // Get days stayed
            int daysStayed = Convert::ToInt32(daysStayedTextbox->Text);
            if (daysStayed <= 0) daysStayed = 1; // Minimum 1 day

            // Extract price from comboBox text (e.g., "$ 200.0 (SUITE)" -> 200.0)
            String^ priceText = roomPricePerNightComboBox->Text;

            // Dollar sign ki position check kare ga
            int dollarPos = priceText->IndexOf("$");
            
            // Extract the numeric part after $
            String^ numericPart = priceText->Substring(dollarPos + 1)->Trim();

            // Find where the numeric part ends
            int spacePos = numericPart->IndexOf(" ");
            if (spacePos > 0)
            {
                numericPart = numericPart->Substring(0, spacePos);
            }

            
            // Convert to double using invariant culture
            double pricePerNight = Convert::ToDouble(numericPart, System::Globalization::CultureInfo::InvariantCulture);

            // Calculate and display total bill
            double totalBill = daysStayed * pricePerNight;
            TotalBillLabel->Text = "YOUR TOTAL BILL : $" + totalBill.ToString("F2");
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error calculating bill: " + ex->Message +
                "\n Please check the room price format.",
                "Calculation Error",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error);
        }
    }

    void GenerateBills::SaveBillToDatabase()
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";

        try {
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
            connection->Open();

            // Same wahi ooper wala tareeqa use kiya hai
            String^ priceText = roomPricePerNightComboBox->Text;
            int dollarPos = priceText->IndexOf("$");
            String^ numericPart = priceText->Substring(dollarPos + 1)->Trim();
            int spacePos = numericPart->IndexOf(" ");
            if (spacePos > 0)
            {
                numericPart = numericPart->Substring(0, spacePos);
            }
            double pricePerNight = Convert::ToDouble(numericPart, System::Globalization::CultureInfo::InvariantCulture);

            int daysStayed = Convert::ToInt32(daysStayedTextbox->Text);
            double totalAmount = daysStayed * pricePerNight;

            String^ query = "INSERT INTO bills (bookingID, roomNo, roomType, checkinDate, checkoutDate, daysStayed, pricePerNight, totalAmount) "
                "VALUES (@bookingID, @roomNo, @roomType, @checkinDate, @checkoutDate, @daysStayed, @pricePerNight, @totalAmount)";

            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
            command->Parameters->AddWithValue("@bookingID", bookingIDTextbox->Text);
            command->Parameters->AddWithValue("@roomNo", roomNumberComboBox->Text);
            command->Parameters->AddWithValue("@roomType", roomTypeComboBox->Text);
            command->Parameters->AddWithValue("@checkinDate", checkInDatePicker->Value.ToString("MM/dd/yyyy"));
            command->Parameters->AddWithValue("@checkoutDate", checkOutDatePicker->Value.ToString("MM/dd/yyyy"));
            command->Parameters->AddWithValue("@daysStayed", daysStayed);
            command->Parameters->AddWithValue("@pricePerNight", pricePerNight);
            command->Parameters->AddWithValue("@totalAmount", totalAmount);

            command->ExecuteNonQuery();
            connection->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error saving bill: " + ex->Message);
        }
    }

    Void GenerateBills::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
        // Clear any existing total
        TotalBillLabel->Text = "YOUR TOTAL BILL : $0.00";

        // Only process if we have at least 1 character that's a digit
        if (bookingIDTextbox->Text->Length > 0 && Char::IsDigit(bookingIDTextbox->Text[0]))
        {
            LoadBookingDetails(bookingIDTextbox->Text);
        }
    }

    Void GenerateBills::dateTimePicker2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
    {
        CalculateDaysStayed();
    }

    Void GenerateBills::GenerateBillButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (bookingIDTextbox->Text->Length == 0 || roomNumberComboBox->Text->Length == 0 ||
            roomTypeComboBox->Text->Length == 0 || checkInDatePicker->Text->Length == 0 ||
            checkOutDatePicker->Text->Length == 0 || daysStayedTextbox->Text->Length == 0) {
            MessageBox::Show("Please fill all fields!");
            return;
        }
        if (daysStayedTextbox->Text->Length == 0) {
            CalculateDaysStayed();
        }

        // Total bill calculate kar k display karwaya hai, then database mein save karwaya hai

        CalculateTotalBill();
        SaveBillToDatabase();
        MessageBox::Show("Bill generated successfully!");

        // Jaise hee checkout ho jaye ga, usi waqt checkoutDate store ho jaye gi database mein

        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Summer\\Hotel-Management-System-master\\connection.accdb;";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        String^ bookingID = bookingIDTextbox->Text; // Hamara wala input lega

		// Check-out date ko update karne ki query
        String^ bookingQuery = "UPDATE bookings SET checkoutDate = @checkoutDate WHERE bookingID = @bookingID";

        OleDbCommand^ bookingCommand = gcnew OleDbCommand(bookingQuery, connection);

		bookingCommand->Parameters->AddWithValue("@checkoutDate", checkOutDatePicker->Value.ToString("MM/dd/yyyy"));

        try {
            connection->Open();

            MessageBox::Show("Checkout has been done successfully!\n Thank You!");
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error deleting record: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    Void GenerateBills::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ViewDetails^ viewDetails = gcnew ViewDetails();
        viewDetails->Show();
        this->Hide();
    }

    Void GenerateBills::HomeButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Dashboard^ dashboard = gcnew Dashboard();
        dashboard->Show();
        this->Hide();
    }
}