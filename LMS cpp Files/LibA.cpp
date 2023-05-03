#include "LibA.h"
#include"Bookinfo.h"
#include<string>
#include"User.h"
#include"Person.h"


LibA::LibA()
{
	books_.push_back(Bookinfo("9780143127550", "Sapiens: A Brief History of Humankind", "Yuval Noah Harari",
		            "1st Edition", "Penguin Random House", 2015, "History", "World History","24/11/2022","",true));
		        books_.push_back(Bookinfo("9780061120084", "To Kill a Mockingbird", "Harper Lee",
		            "50th Anniversary Edition", "HarperCollins Publishers", 2010, "Fiction", "Classic Literature", "2/07/2022", "", true));
		        books_.push_back(Bookinfo("9781491954461", "Python for Data Analysis", "Wes McKinney", "2nd Edition",
		            "O'Reilly Media, Inc.", 2017, "Computer Science", "Data Science", "6/02/2021", "", true));
}
		
LibA::LibA(const std::string lname) : lib_name{ lname }
{}
void LibA::display_name(std::string name)
{
	cout << "Library name: " << name << endl;
}
void LibA::display_AllBooks() 
{

	for (int i{ 0 }; i < books_.size();++i)
		    {
		cout << "Book No. : " << i + 1 << endl;
		        cout << "ISBN : " << books_[i].get_isbn() << endl;
		        cout << "Title : " << books_[i].get_title() << endl;
		        cout << "Authors : " << books_[i].get_authors() << endl;
		        cout << "Publishers : " << books_[i].get_publisher() << endl;
		        cout << "Edition : " << books_[i].get_edition() << endl;
		        cout << "Year : " << books_[i].get_year() << endl;
		        cout << "Category : " << books_[i].get_category() << endl;
		        cout << "Sub-Category : " << books_[i].get_subcategory() << endl;
		        cout << "Date : " << books_[i].get_added_date() << endl;
		    }
}
void LibA::add_book()
{
    system("cls");
    string isbn{}, title{}, author{}, publisher{}, edition{}, category{}, subcategory{}, date{};
    int year{ 0 };
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
    books_.push_back(Bookinfo(isbn, title, author, publisher, edition, year, category, subcategory, date, "", true));
    system("cls");
    cout << "The book " << title << " has been added to the Library" << endl;


}
void LibA::remove_book()
{
    system("cls");
    cout << "Remove book by entering ISBN"<<endl;
    cin.ignore();
    string isbn;
    cout << "Enter ISBN of book you want to remove";
    getline(cin,isbn);
    for (int i = 0; i < books_.size(); i++) 
    {
        if (books_[i].get_isbn() == isbn) 
        {
            books_.erase(books_.begin() + i);
            cout << "Book removed successfully." << endl;
            return;
        }
    }
    cout << "Book not found in library." << endl;
}
void LibA::lend_book()
{ 
    system("cls");
    cin.ignore();
        string isbn;
        
        cout << "Enter ISBN to lend book : ";
        getline(cin, isbn);

        for (int i = 0; i < books_.size(); i++) 
        {
            if (books_[i].get_isbn() == isbn) 
            {
                if (books_[i].get_isAvailable()) 
                {
                    string borrowerName;
                    cout << "Enter borrower name: ";
                    getline(cin, borrowerName);
                    books_[i].set_isAvailable(false);
                    books_[i].set_borrowerName(borrowerName);
                    cout <<books_[i].get_title() <<" lent to " << borrowerName << " successfully." << endl;
                    return;
                }
                else {
                    cout << "Book is not available for lending." << endl;
                    return;
                }
            }
        }
        cout << "Book not found in library." << endl;
}

void LibA::donate_book()
{
   
    string isbn{}, title{}, author{}, publisher{}, edition{}, category{}, subcategory{}, date{};
    int year{ 0 };
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
    books_.push_back(Bookinfo(isbn, title, author, publisher, edition, year, category, subcategory, date, "", true));
    
    system("cls");
    cout << "The book " <<title<< " has been donated to the Library"<<endl;

}
void LibA::search_book()
{
    system("cls");
        string category, subcategory;
        cin.ignore();
        cout << "Enter book category: ";
        getline(cin, category);
        cin.ignore();
            cout << "Enter book subcategory: ";
        getline(cin, subcategory);
        system("cls");
        cout << "Books in " << category << " / " << subcategory << ":";
        bool foundBooks = false;
        for (int i = 0; i < books_.size(); i++) {
            if (books_[i].get_category() == category && books_[i].get_subcategory() == subcategory) 
            {
                cout << books_[i].get_title() << " by " << books_[i].get_authors() << " (" << (books_[i].get_isAvailable() ? "Available" : "Not available") << ")" << endl;
                foundBooks = true;
            }
        }
        if (!foundBooks) {
            cout << "No books found in library." << endl;
           
        }
}

void LibA::show_borrowed_books(User name)

{
    system("cls");
    int count{0};
    
    for (int i{ 0 }; i < books_.size();++i)
    {
        if (books_[i].get_borrowerName() == name.get_name())
        {
            cout << "ISBN : " << books_[i].get_isbn() << endl;
            cout << "Title : " << books_[i].get_title() << endl;
            cout << "Authors : " << books_[i].get_authors() << endl;
            cout << "Publishers : " << books_[i].get_publisher() << endl;
            cout << "Edition : " << books_[i].get_edition() << endl;
            cout << "Year : " << books_[i].get_year() << endl;
            cout << "Category : " << books_[i].get_category() << endl;
            cout << "Sub-Category : " << books_[i].get_subcategory() << endl;
            cout << "Date : " << books_[i].get_added_date() << endl;
            count++;
            
        }
        
    }
    if (count == 0)
    {
        cout << "You didn't borrow any book"<<endl;
        
    }
    else
    {
        cout <<name.get_name()<<" borrowed "<< count << " no. of Book/books. "<<endl;

    }
}
void LibA::return_book()
{
    cout << "Enter ISBN of the book you want to return :";
    cin.ignore();
    string isbn{};
    getline(cin, isbn);

    bool foundBooks = false;
    for (int i = 0; i < books_.size(); i++)
    {
        if (books_[i].get_isbn() == isbn)
        {
            
            books_[i].set_isAvailable("true");
            cout << books_[i].get_title() << " by " << books_[i].get_authors() << " is returned by " << books_[i].get_borrowerName() << endl;
            books_[i].set_borrowerName("");
            foundBooks = true;

        }


    }
    if (!foundBooks)
    {
        cout << "You didn't borrow this book." << endl;

    }
   


}
void LibA::borrow_book(User name)
{
    cout << "Enter ISBN of the book you want to borrow :";
    cin.ignore();
    string isbn{};
    getline(cin, isbn);

    bool foundBooks = false;
    for (int i = 0; i < books_.size(); i++) 
    {         
        if (books_[i].get_isbn() == isbn)
        {
            books_[i].set_borrowerName(name.get_name());
            books_[i].set_isAvailable("false");
            cout << books_[i].get_title() << " by " << books_[i].get_authors() <<" is borrowed by "<<books_[i].get_borrowerName()<<endl;
            foundBooks = true;
           
        }
       
        
    }
    if (!foundBooks) {
        cout << "No books found in library." << endl;

    }
   
}


