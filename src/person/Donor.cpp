#include "./Donor.h"
#include<string>
#include"./Person.h"
#include<fstream>
#include<vector>
#include<sstream>
#include <iostream>

using namespace std;

Donor::Donor (){}

Donor::Donor(string name, string email) 
	: Person(name, email) {}

void Donor::write_in_file(string email)
{
    ifstream file_in("csv_files/donors.csv");
    string line;
    bool email_found = false;

    while (getline(file_in, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;

        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        if (fields.size() >= 2 && fields[1] == email) // Check if email matches
        {
            email_found = true;
            system("cls");
            cout << "Welcome back, " << fields[0] << "!" << endl;
            cout << "Name: " << fields[0] << endl;
            cout << "Email: " << fields[1] << endl;

            break; // Exit the function if email is found
        }
    }

    file_in.close();

    if (!email_found)
    {
        string name;
        cout << "Email not found. Please enter your name: ";
        getline(cin, name);

        ofstream file_append("csv_files/donors.csv",ios_base::app); // Append mode to add new user record

        // Write the new user's record to the end of the file
        file_append << name << "," << email << "\n";

        file_append.close();

        cout << "Welcome, " << name << "! Your information has been added to the file." << endl;
    }
}