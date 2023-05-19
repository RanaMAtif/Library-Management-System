#include "LibA.h"
#include"../book/Bookinfo.h"
#include<string>
#include"../person/User.h"
#include"../person/Person.h"
#include"../person/Donor.h"
#include<fstream>
#include<sstream>


using namespace std;

LibA::LibA()
{}
		
LibA::LibA(const std::string lname) : lib_name{ lname }
{}
void LibA::display_name(std::string name)
{
	cout << "Library name: " << name << endl;
}


void LibA::add_book()
{
    system("cls");
    string isbn{}, title{}, author{}, publisher{}, edition{}, category{}, subcategory{}, date{}, borrower{ "none" }, donor{ "none" };
    int year{ 0 };
    bool is_Available = true;
    cin.ignore();
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, title);
    cin.ignore();
    cout << "Enter book author: ";
    getline(cin, author);
    cin.ignore();
    cout << "Enter Publisher: ";
    getline(cin, publisher);
    cin.ignore();
    cout << "Enter Edition: ";
    getline(cin, edition);
    cin.ignore();
    cout << "Enter Year: ";
    cin.ignore();
    cin >> year;
    cin.ignore();
    cout << "Enter book category: ";
    getline(cin, category);
    cin.ignore();
    cout << "Enter book subcategory: ";
    getline(cin, subcategory);
    cin.ignore();
    cout << "Enter Date:";
    getline(cin, date);
    fstream file_out;
    file_out.open("csv_files/books.csv", ios::out | ios::app);
    file_out << isbn << "," << title << "," << author << "," << publisher << "," << edition << ","
        << year << "," << category << "," << subcategory << "," << date << "," << borrower << "," << is_Available <<","<< donor <<endl;
    file_out.close();
    system("cls");
    cout << "The book " << title << " has been added to the Library" << endl;


}
void LibA::remove_book()
{
    system("cls");
    cout << "Remove book by entering ISBN" << endl;
    cin.ignore();
    string isbntoremove;
    cout << "Enter ISBN of book you want to remove : ";
    getline(cin, isbntoremove);

    ifstream file;

    file.open("csv_files/books.csv", ios::in);
    if (!file)
    {
        cerr << "\nFile not found ";

    }
    ofstream tempFile;
    tempFile.open("csv_files/temp.csv",ios::out);
    if (!tempFile) 
    {
        cerr << "Failed to create temporary file\n";
        file.close();
    }
    string line;
    bool bookFound = false;
    while (getline(file, line)) 
    {
        string isbn = line.substr(0, line.find(','));
        if (isbn != isbntoremove) 
        {
            tempFile << line << '\n';
        }
        else {
            bookFound = true;
        }
    }
    file.close();
    tempFile.close();
    if (bookFound) 
    {
       
       remove("csv_files/books.csv");

        
        rename("csv_files/temp.csv", "csv_files/books.csv");

        cout << "Book removed successfully.\n";
    }
    else 
    {
        cout << "Book not found.\n";
    }
   
 
}

void LibA::donate_book(Donor obj)
{
   
    string isbn{}, title{}, author{}, publisher{}, edition{}, category{}, subcategory{}, date{}, borrower{ "none" }, donor{ "none" };
    int year{ 0 };
    bool is_Available = true;
    cin.ignore();
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, title);
    cin.ignore(); 
    cout << "Enter book author: ";
    getline(cin, author);
    cin.ignore();
    cout << "Enter Publisher: ";
    getline(cin, publisher);
    cin.ignore();
    cout << "Enter Edition: ";
    getline(cin, edition);
    cin.ignore();
    cout << "Enter Year: ";
    cin.ignore();
    cin >> year;
    cin.ignore();
    cout << "Enter book category: ";
    getline(cin, category);
    cin.ignore();
    cout << "Enter book subcategory: ";
    getline(cin, subcategory);
    cin.ignore();
    cout << "Enter Date:";
    getline(cin, date);
    donor = obj.get_email();
    fstream file_out;
    file_out.open("csv_files/books.csv", ios::out | ios::app);
    file_out << isbn << "," << title << "," << author << "," << publisher << "," << edition << "," << year << "," 
        << category << "," << subcategory << "," << date<<"," << borrower << "," << is_Available << "," << donor << endl;
    file_out.close();
    system("cls");
    cout << "The book " <<title<< " has been donated to the Library"<<endl;

}



