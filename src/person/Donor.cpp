#include "Donor.h"
#include<string>
#include"Person.h"
#include<fstream>

using namespace std;

Donor::Donor (){}

Donor::Donor(string name, string email) 
	: Person(name, email) {}

void Donor::write_in_file(string name, string email)
{
    fstream file_out;
    file_out.open("donors.csv", ios::out | ios::app);

    file_out << name << "," << email << endl;
    file_out.close();
}
