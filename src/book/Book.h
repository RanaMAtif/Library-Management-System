#pragma once
#include<iostream>
#include<string>

using namespace std;
class Book
{
public:
    Book();
    Book(string isbn, string title, string authors,
        string publisher, string edition, int year);
    
    
    
protected:
    string isbn_;
    string title_;
    string authors_;
    string publisher_;
    string edition_;
    int year_;
};


