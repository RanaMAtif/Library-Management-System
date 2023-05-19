#pragma once
#include "./Book.h"
#include<string>
#include<iostream>
#include"../person/User.h"
using namespace std;
class Bookinfo : public Book
{
public:
    Bookinfo();
    Bookinfo(string,string,string, string , string ,int , string 
        , string,string ,string ,bool ,string);
    
    string get_isbn();
    void set_isbn(string);
    const string& get_category();
    void set_category(string);
    const string& get_subcategory();
    void set_sub_category(string);
    const string& get_added_date();  
    void set_added_date(string);
    const string& get_borroweremail();
    void set_borroweremail(string);
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
    string get_donor_Email();
    void set_donor_Email(string);
    void display_Available_Books();

    void display_borrowed_Books(User);
    void search_Books();
    void return_book();
    void borrow_Book(User);
protected:
    Book book_;
    string category_;
    string subcategory_; 
    string date_;
    string borrower_Email_;
    bool isAvailable_;
    string donor_Email_; 
};

