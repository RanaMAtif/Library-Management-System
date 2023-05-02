#include "Donor.h"
#include<string>
#include"Person.h"

using namespace std;

Donor::Donor (){}

Donor::Donor(string name, string email) 
	: Person(name, email) {}

