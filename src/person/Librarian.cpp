#include "Librarian.h"
#include<iostream>
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
	
		if (password == 123)
		{
			cout << "Welcome ";
			
		}
		else
		{
			cout << "Incorrect Password";
			
		}
	
}



