#pragma once
#include "Book.h"
#include<string>
#include<iostream>
using namespace std;
class Bookinfo : public Book
{
public:
    Bookinfo();
    Bookinfo(string isbn,string title,string authors, string publisher, string edition,int years, string 
        category, string subcategory,string date,string borrower,bool available);
    
    string get_isbn();
    void set_isbn(string);
    const string& get_category();
    void set_category(string);
    const string& get_subcategory();
    void set_sub_category(string);
    const string& get_added_date();  
    void set_added_date(string);
    const string& get_borrowerName();
    void set_borrowerName(string);
    bool get_isAvailable();
    void set_isAvailable(bool);
    string get_title();
    void set_title(string);
    string get_authors();
    void set_authors(string);
    string get_edition();
    void set_edition(string);
    int get_year();
    void  set_year(int);
    string get_publisher();
    void set_publisher(string);
    
protected:
    Book book_;
    string category_;
    string subcategory_; 
    string date_;
    string borrowerName_;
    bool isAvailable_;
   
  
    
};

