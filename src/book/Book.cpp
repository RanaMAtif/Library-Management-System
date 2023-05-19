#include "./Book.h"
#include<iostream>
#include<string>
using namespace std;

Book::Book(){}

Book::Book(string isbn, string title, string authors,
    string publisher, string edition, int year)
    : isbn_(isbn), title_(title), authors_(authors), publisher_(publisher), edition_(edition), year_(year) {}




