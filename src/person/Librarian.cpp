#include"./Librarian.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include"./Person.h"
#include<vector>
using namespace std;

Librarian::Librarian () {} 
Librarian::Librarian(string& name, string& email,string password)
    : Person(name, email), password_(password) {}


string Librarian::get_password()
{
    return password_;
}
void Librarian::set_password(string password)
{
	password_ = password;
}
//void  Librarian::verify_pass(int password)
//{
//	
//
//	
//		if (password == 123)
//		{
//			cout << "Welcome ";
//
//		}
//		else
//		{
//			cout << "Incorrect Password" << endl;
//			
//		}
//	
//		
//	
//}

void Librarian::display_users()
{
    fstream file_in;
    file_in.open("csv_files/users.csv", ios::in);


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
                cout << field << "    "<<endl;
            }
            cout << endl;
        }
    }
    file_in.close();

}

void Librarian::display_donors()
{
    fstream file_in;
    file_in.open("csv_files/donors.csv", ios::in);


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
                cout << field << "    "<<endl;
            }
            cout << endl;
        }
    }
    
    file_in.close();

}
void Librarian::all_Books_information()
{
    fstream file_in;
    file_in.open("csv_files/books.csv", ios::in);


    if (file_in.is_open())
    {
        
        string line;
        while (getline(file_in, line))
        {
            stringstream s(line);
            string field;
            while (getline(s, field, ','))
            {
                cout << field << "    "<<endl;
            }
            cout << endl;
        }
    }
    file_in.close();
}

bool Librarian::login(string email)
{
    bool access = false;
        ifstream file_in("csv_files/librarians.csv");
        string line;
        bool email_found = false;
        int option;
        cout << "if you are registered then press 1, to register press 2: ";
        cin >> option;
        if (option == 1)
        {
            while (getline(file_in, line))
            {
                stringstream ss(line);
                vector<string> fields;
                string field;

                while (getline(ss, field, ','))
                {
                    fields.push_back(field);
                }

                if (fields.size() >= 3 && fields[1] == email) // Check if email matches
                {
                    email_found = true;
                }
                else
                {
                    email_found = false;
                }
                if (email_found==true)
                {
                    string password;
                    cin.ignore();
                    cout << "Enter password: ";
                    getline(cin, password);
                    system("cls");
                    if (fields.size() >= 3 && fields[2] == password) // Check if password matches
                    {
                        cout << "Welcome back, " << fields[0] << "!" << endl;
                        set_name(fields[0]);
                        cout << "Email: " << fields[1] << endl;
                        return access = true;
                    }
                    else
                    {
                        return access = false; // Exit the function if email is found
                    }
                }
            }



            file_in.close();
        }


        else if (option == 2)
        {
            string name,password;
            cin.ignore();
            cout << "Please enter your name: ";
            getline(cin, name);
            cin.ignore();
            cout << "Please enter your new password: ";
            getline(cin, password);


            ofstream file_append("csv_files/librarians.csv", ios_base::app); // Append mode to add new user record

            // Write the new user's record to the end of the file
            file_append << name << "," << email <<","<< password<<"\n";

            file_append.close();
            system("cls");
            cout << "Welcome, " << name << "! Your information has been added to the file." << endl;

        }
        else
        {
            cout << "Invalid choice!!!!";
            return access = false;
            exit(0);

        }
    }

