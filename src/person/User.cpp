#include "User.h"
#include"Person.h"
#include<iostream>
#include <string>

using namespace std;
User::User() {}
User::User(string name, string email) : Person(name, email) {}
void User::write_in_file(string name, string email)
{
    fstream file_out;
    file_out.open("users.csv", ios::out | ios::app);

    file_out << name << "," << email << endl;
    file_out.close();
}




 