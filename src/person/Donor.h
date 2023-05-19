#pragma once
#include "./Person.h"
#include<string>
using namespace std;
class Donor : public Person
{
private:
   
public:
        Donor();
        Donor(string name,string email);  
        void write_in_file(string);
};


