#include "MyForm.h"
#include "Person.h"
#include "Notebook.h"
#include <msclr/marshal_cppstd.h> 

using namespace System;
using namespace System::Windows::Forms;

Notebook notebook1("first.bin");
Notebook notebook2("second.bin");

[STAThreadAttribute]
int main(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);	
	Application::EnableVisualStyles();
	lab7::MyForm from;
	Application::Run(% from);
}

System::Void lab7::MyForm::add_first_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ dateofbirth1 = date_first->Text->TrimEnd();
	String^ fullname1 = fullname_first->Text->TrimEnd();
	String^ phonenumb1 = phone_first->Text->TrimEnd();

	std::string fullname = msclr::interop::marshal_as<std::string>(fullname1);
	std::string phonenumb = msclr::interop::marshal_as<std::string>(phonenumb1);
	std::string dateofbirth = msclr::interop::marshal_as<std::string>(dateofbirth1);

	Person person(fullname.c_str(), dateofbirth.c_str(), phonenumb.c_str());

	try {
		if (String::IsNullOrWhiteSpace(fullname1) || String::IsNullOrWhiteSpace(dateofbirth1) || String::IsNullOrWhiteSpace(phonenumb1)) {
			throw std::invalid_argument("Field error: not all fields are filled!");
		}
			notebook1.isValidName(person.getName());
			notebook1.isValidPhoneNumber(person.getPhoneNumber());
			notebook1.isValidDateOfBirth(person.getDateOfBirth());

			date_first->Clear();
			fullname_first->Clear();
			phone_first->Clear();

			notebook1.addPerson(person);
	}
	catch (const std::exception& e) {
		    MessageBox::Show(gcnew String(e.what()), "Error");
	}
	return System::Void();
}

System::Void lab7::MyForm::show_first_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string fileContents = notebook1.getFileContents();
	String^ output = gcnew String(fileContents.c_str());
	outp_first->Text = output;
}

System::Void lab7::MyForm::add_second_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ dateofbirth2 = date_second->Text->TrimEnd();
	String^ fullname2 = fullname_second->Text->TrimEnd();
	String^ phonenumb2 = phone_second->Text->TrimEnd();

	std::string fullname = msclr::interop::marshal_as<std::string>(fullname2);
	std::string phonenumb = msclr::interop::marshal_as<std::string>(phonenumb2);
	std::string dateofbirth = msclr::interop::marshal_as<std::string>(dateofbirth2);

	Person person(fullname.c_str(), dateofbirth.c_str(), phonenumb.c_str());

	try {
		if (String::IsNullOrWhiteSpace(fullname2) || String::IsNullOrWhiteSpace(dateofbirth2) || String::IsNullOrWhiteSpace(phonenumb2)) {
			throw std::invalid_argument("Field error: not all fields are filled!");
		}
		notebook2.isValidName(person.getName());
		notebook2.isValidPhoneNumber(person.getPhoneNumber());
		notebook2.isValidDateOfBirth(person.getDateOfBirth());
		
		date_second->Clear();
		fullname_second->Clear();
		phone_second->Clear();

		notebook2.addPerson(person);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew String(e.what()), "Error");
	}
	return System::Void();
}

System::Void lab7::MyForm::show_second_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string fileContents = notebook2.getFileContents();
	String^ output = gcnew String(fileContents.c_str());
	outp_second->Text = output;
}

System::Void lab7::MyForm::show_sim_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string filedubl = notebook1.checkDuplicatePeople(notebook2);
	String^ outputs = gcnew String(filedubl.c_str());
	outp_sim->Text = outputs;
}