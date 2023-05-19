#include "./Person.h"
#include<string>
#include<iostream>
using namespace std;

Person::Person(string name, string email) : name_(name), email_(email) 
{}
Person::Person() {}
void Person::set_name(string name)
{
	name_ = name;
}
string Person::get_name()
{
	return name_;
}
string Person::get_email()
{
	return email_;
}
void Person::set_email(string email)
{
	email_ = email;
}