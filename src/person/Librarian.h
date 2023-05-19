#pragma once
#include"./Person.h"
#include<string>
using namespace std;
class Librarian : public Person
{
    public:
        Librarian();
        Librarian(string&,string&,string);
        string get_password();
        void set_password(string);
      /*  void verify_pass(int);*/
        void display_users();
        void display_donors();
        void all_Books_information();
        bool login(string);
    private:
       string password_;
 
};

