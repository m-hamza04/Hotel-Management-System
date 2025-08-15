#include "Login.h"
#include "Dashboard.h"
#include <string>


using namespace System::Data::OleDb;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace HOTELMANAGEMENTSYSTEM;


int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    HOTELMANAGEMENTSYSTEM::Login form;
    Application::Run(% form);
}


void Login::CheckLogin(System::Object^ sender, System::EventArgs^ e)
{

    // textboxes k andar username aur password ko input lega

    String^ userName = textBoxUserName->Text;
    String^ password = textBoxPassword->Text;

    try {
        // Remember to paste your database path here
        String^ connection = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\Hamza\\Desktop\\Hotel-Management-System\\project resources\\database\\connection.accdb;";

        OleDbConnection^ conn = gcnew OleDbConnection(connection); //polymorphism
        conn->Open();

        String^ query = "SELECT COUNT(*) FROM users WHERE username = ? AND password= ?";

        OleDbCommand^ cmd = gcnew OleDbCommand(query, conn);
        cmd->Parameters->AddWithValue("?", userName);
        cmd->Parameters->AddWithValue("?", password);

        int userCount = Convert::ToInt32(cmd->ExecuteScalar());
        if (userCount > 0) {
            MessageBox::Show("Login Successful");
            this->Hide();
            Dashboard^ dashboard = gcnew Dashboard(); //Polymorphism
            dashboard->Show();
        }
        else {
            MessageBox::Show("Invalid Credentials", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        conn->Close();
    }

    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }

}
