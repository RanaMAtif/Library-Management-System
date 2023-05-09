#pragma once
#include "Person.h"
#include<string>
using namespace std;
class Librarian : public Person
{
    public:
        Librarian();
        Librarian(string&,string&,int);
        int get_password();
        void set_pasword(int);
        void verify_pass(int);
        void display_users();
        void display_donors();
        
         
    private:
        int password_;
 
};

