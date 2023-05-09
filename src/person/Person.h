#pragma once
#include<string>
#include<fstream>
using namespace std;



class Person
{            
    public:
        Person(string name, string email);
        Person();
        void set_name(string);
        string get_name();
        string get_email();
        void set_email(string);
    
    protected:
        string name_;
        string email_;
};

