#include "Librarian.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include"Person.h"
using namespace std;

Librarian::Librarian () {} 
Librarian::Librarian(string& name, string& email,int password)
    : Person(name, email), password_(password) {}


int Librarian::get_password()
{
	return password_;
}
void Librarian::set_pasword(int password)
{
	password_ = password;
}
void  Librarian::verify_pass(int password)
{
	int choice{ 0 };

	
		if (password == 123)
		{
			cout << "Welcome ";

		}
		else
		{
			cout << "Incorrect Password" << endl;
			cout << "Press any key to enter password again (-1 to exit) :";
			cin >> choice;
		}
	
		
	
}

void Librarian::display_users()
{
    fstream file_in;
    file_in.open("/Users/Lenovo/source/repos/LMS/LMS/csv_files/users.csv", ios::in);


    if (file_in.is_open())
    {
        cout << "User" << setw(12) << "Email" << endl;
        string line;
        while (getline(file_in, line))
        {
            stringstream s(line);
            string field;
            while (getline(s, field, ','))
            {
                cout << field << "    ";
            }
            cout << endl;
        }
    }
    file_in.close();

}

void Librarian::display_donors()
{
    fstream file_in;
    file_in.open("donors.csv", ios::in);


    if (file_in.is_open())
    {
        cout << "Donor" << setw(12) << "Email" << endl;
        string line;
        while (getline(file_in, line))
        {
            stringstream s(line);
            string field;
            while (getline(s, field, ','))
            {
                cout << field << "    ";
            }
            cout << endl;
        }
    }
    file_in.close();

}
