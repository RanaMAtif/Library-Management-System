#include<iostream>
#include"Bookinfo.h"
#include"Book.h"
#include<string>
using namespace std;

Bookinfo::Bookinfo() {}
Bookinfo::Bookinfo(string isbn, string title, string authors, string publisher,
    string edition, int years, string category, string subcategory, string date, string borrower, bool available)
    : Book(isbn, title, authors, publisher, edition, years), category_(category),
    subcategory_(subcategory), date_(date), borrowerName_(borrower), isAvailable_(available)
{}      

string Bookinfo::get_isbn()
{
    return isbn_;
}
void Bookinfo::set_isbn(string isbn)
{
    isbn_ = isbn;
}
string Bookinfo::get_title() 
{
    return title_;
}
void Bookinfo::set_title(string title)
{
    title_ = title;
}
string Bookinfo::get_authors() 
{
    return authors_;
}
void Bookinfo::set_authors(string authors)
{
    authors_ = authors;
}
string Bookinfo::get_publisher()
{
    return publisher_;
}
void Bookinfo::set_publisher(string publisher)
{
    publisher_ = publisher;
}

string Bookinfo::get_edition()
{
    return edition_;
}
void Bookinfo::set_edition(string edition)
{
    edition_ = edition;
}
int Bookinfo::get_year()
{
    return year_;
}
void Bookinfo::set_year(int year)
{
    year_ = year;

}

const string& Bookinfo::get_category()
    {
        return category_;
    }
void Bookinfo::set_category(string category)
{
    category_ = category;
}
const string& Bookinfo::get_subcategory()
    {
        return subcategory_;
    }
void Bookinfo::set_sub_category(string subcategory)
{
    subcategory_ = subcategory;
}
const string& Bookinfo::get_added_date()
{
    return date_;
}
void Bookinfo::set_added_date(string date)
{
    date_ = date;
}
const string& Bookinfo::get_borrowerName()
{
    return borrowerName_;
}
void Bookinfo::set_borrowerName(string borrower)
{
    borrowerName_ = borrower;
}

bool Bookinfo::get_isAvailable()
{
    return isAvailable_;
}
void Bookinfo::set_isAvailable(bool flag)
{
    isAvailable_ = flag;
}



 