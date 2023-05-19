#pragma once
#include<string>
#include"./Person.h"
using namespace std;
class User :  public Person
{
private:
   
public:
    User(string name, string email);
    User();
    void write_in_file(string);
    
   
    
};

