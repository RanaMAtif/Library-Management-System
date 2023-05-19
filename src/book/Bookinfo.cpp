#include<iostream>
#include"./Bookinfo.h"
#include"./Book.h"
#include"../person/User.h"
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

Bookinfo::Bookinfo() {}
Bookinfo::Bookinfo(string isbn, string title, string authors, string publisher,
    string edition, int years, string category, string subcategory, string date, string borroweremail, bool available, string donor_email)
    : Book(isbn, title, authors, publisher, edition, years), category_(category),
    subcategory_(subcategory), date_(date), borrower_Email_(borroweremail), isAvailable_(available), donor_Email_(donor_email)
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
const string& Bookinfo::get_borroweremail()
{
    return borrower_Email_;
}
void Bookinfo::set_borroweremail(string borrower)
{
    borrower_Email_ = borrower;
}

bool Bookinfo::get_isAvailable()
{
    return isAvailable_;
}
void Bookinfo::set_isAvailable(bool flag)
{
    isAvailable_ = flag;
}    
string Bookinfo::get_donor_Email()
{
    return donor_Email_;
}
void Bookinfo::set_donor_Email(string email)
{
    donor_Email_ = email;
}
void Bookinfo::display_Available_Books()

    {
        fstream file_in;
        file_in.open("csv_files/books.csv", ios::in);

        if (file_in.is_open())
        {
            string line;
            while (getline(file_in, line))
            {
                stringstream ss(line);
                vector<string> fields;
                string field;

                while (std::getline(ss, field, ','))
                {
                    fields.push_back(field);
                }

                if (fields.size() >= 12 && fields[10] == "1") 
                {

                    
                    for (const auto& field : fields)
                    {
                        
                        cout<< field << "    " << endl;
                      
                    }
                    cout << endl;
                }
            }
        }

        file_in.close();
    }



void Bookinfo::display_borrowed_Books(User obj)

{
    fstream file_in;
    file_in.open("csv_files/books.csv", ios::in);

    if (file_in.is_open())
    {
        string line;
        while (getline(file_in, line))
        {
            stringstream ss(line);
            vector<string> fields;
            string field;

            while (getline(ss, field, ','))
            {
                fields.push_back(field);
            }

            if (fields.size() >= 12 && fields[9] == obj.get_email())
            {


                for (const auto& field : fields)
                {

                    cout << field << "    " << endl;

                }
                cout << endl;
            }
            
        }
    }

    file_in.close();
}
void Bookinfo::search_Books()

{
    fstream file_in;
    file_in.open("csv_files/books.csv", ios::in);
    string category{ 0 }, sub_category{ 0 };
    cin.ignore();
    cout<<"Enter Category of the book you want to search: ";
    getline(cin, category);
    cin.ignore();
    cout << "Enter Subcategory of the book you want to search: ";
    getline(cin, sub_category);
    system("cls");

    if (file_in.is_open())
    {
        string line;
        while (getline(file_in, line))
        {
            stringstream ss(line);
            vector<string> fields;
            string field;

            while (getline(ss, field, ','))
            {
                fields.push_back(field);
            }

            if (fields.size() >= 12 && fields[6] == category && fields[7]== sub_category)
            {


                for (const auto& field : fields)
                {

                    cout << field << "    " << endl;

                }
                cout << endl;
            }
        }
    }

    file_in.close();
}

void Bookinfo::return_book()
{
    ifstream file_in("csv_files/books.csv");
    ofstream file_out("csv_files / temp.csv"); 
    string line{0}, isbn{ 0 };
    bool book_found = false;
    cin.ignore();
    cout << "Enter ISBN of the book you want to return: ";
    getline(cin, isbn);
    

    while (getline(file_in, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;

        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        if (fields.size() >= 12 && fields[0] == isbn)
        {
            fields[9] = "none"; 
            fields[10] = "1";  

            book_found = true;
        }

       
        for (size_t i = 0; i < fields.size(); ++i)
        {
            file_out << fields[i];

            if (i < fields.size() - 1)
            {
                file_out << ",";
            }
        }

        file_out << "\n";
    }

    file_in.close();
    file_out.close();

    if (book_found)
    {
        
        remove("csv_files/books.csv");


        rename("csv_files/temp.csv", "csv_files/books.csv");

        cout << "Book with ISBN " << isbn << " has been returned." << endl;
    }
    else
    {
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }
}
void Bookinfo::borrow_Book(User obj)
{
    fstream file_in("csv_files/books.csv");
    ofstream file_out("csv_files / temp.csv"); 
    string line{ 0 }, isbn{ 0 };
    bool book_found = false;
    cin.ignore();
    cout << "Enter ISBN of the book you want to borrow: ";
    getline(cin, isbn);

    while (getline(file_in, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;

        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        if (fields.size() >= 11 && fields[0] == isbn) 
        {
            fields[9] = obj.get_email();
            fields[10] = "-1";   

            book_found = true;
        }

        
        for (size_t i = 0; i < fields.size(); ++i)
        {
            file_out << fields[i];

            if (i < fields.size() - 1)
            {
                file_out << ",";
            }
        }

        file_out << "\n";
    }

    file_in.close();
    file_out.close();

    if (book_found)
    {
       
        remove("csv_files/books.csv");


        rename("csv_files/temp.csv", "csv_files/books.csv");

        cout << "Book with ISBN " << isbn << " has been borrowed by "<<obj.get_email() << endl;
    }
    else
    {
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }

}
 