 # Library Management System
 A library management system implemented in C++. This program has three modes, user, donor, and librarian. All these modes represent the individual functions of a library user, donor, and librarian.
 ## Features
* A donor can donate a book, and the donor's information will be saved alongside other book data members to know who donated it.

* A user can see available books, borrow a book by entering isbn of the book, see how many books he/she has borrowed, retuen a book and also search a specific book by entering the book's category and sub category. 

* A Librarian can add, and remove a book. He/she can also see the users, donors and book information. 

* Both donors and users have to register for the first time by entering their email and name, but if you are already registered, you only have to enter your email. In the librarian's case, a password is required. The librarians are asked to enter their email and then tell the program whether they are registered or not. If not, then the program will ask the new librarian to add his name and password. Then the librarian has to log in again to use the features. If the librarian is already registered, he or she is asked to enter the password. If the password is correct, he or she can use the program; otherwise, the program shuts down.

## Functionality
The fucntionality of Library Management System is described below.
### Class Book:
The book class has six out of 12 data members that are used to explain a book completely. These data members are the ones that can be added once, and throughout the project, these will not change. These data members explain the ISBN (unique identity number of the book), title, authors, publishers, edition, and year (when the book was published). As in any book, all these members are always constant, so they are placed in the same class. Any other data member that may not be further used in the program can be added to this class so that we don't have to change the functionality of other class member functions.
#### Book.h file:
```
class Book
    public:
        Book();
        Book(string , string, string,
        string , string, int );
```
### Class Bookinfo:
Class Bookinfo is a child class of Book. This class explains the data members that explain the book and also they are used in other functions. Two data members of this class explain the category and sub-category of the book. These are used in a function where the user can search books by entering these parameters in the function. The data member date explains the date on which the book was added to the library. This data member is not used in any function currently but this can be used so that is why it is in this class. The data members that are used to explain the borrower, the donor, and the availability of book changes many times and these are used in various functions. So the parent class Book and child class Bookinfo combine to explain a complete book object. Some of the member functions are also defined in this class as the data members of this class are required in these functions. 
#### Bookinfo.h file:
```
class Bookinfo : public Book
    public:
        Bookinfo();
        Bookinfo(string,string,string, string , string ,    int,string,string,string ,string ,bool ,string);
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
```
### Class Person:
The class Person acts as a parent class for three classes i.e., user, librarian, and donor. As all these classes have some common attributes because persons are humans, this class explains the name and email of all these classes.
#### Person.h file:
```
class Person            
    public:
        Person(string name, string email);
        Person();
        void set_name(string);
        string get_name();
        string get_email();
        void set_email(string);
``` 
### Class Donor:
As a child class of Person, this class inherits the data members of class Person. This class is used to explain the functionality of donors.
#### Donor.h file:
```
class Donor : public Person
   public:
        Donor();
        Donor(string name,string email);  
        void write_in_file(string);
```

### Class User:
This class also inherits the data members of the class Person as its child class. As the user’s functionality is different from the donor, librarian, or any other person that may exist in the library. So this class is used to specifically explain the user’s functionality.
#### User.h file:
```
class User :  public Person
    public:
        User(string name, string email);
        User();
        void write_in_file(string);
```

### Class Librarian:
The class Librarian also extends the Person class. This class explains the functionality of a librarian in a library. But as a Librarian is someone who has the authority in the library this class also has another data member password which is used by librarians to register and login to the librarian mode. This class specifically explains the functionality of a librarian. 
#### Librarian.h file:
```
class Librarian : public Person
    public:
        Librarian();
        Librarian(string&,string&,string);
        string get_password();
        void set_password(string);
        void display_users();
        void display_donors();
        void all_Books_information();
        bool login(string);
```
### Class LibA:
This class explains all the functionality of the library management system. As the real world library has books. So in this class, the three functions related to books are defined. These functions are used by librarians and donors. Librarians can add or remove a book from the library and donors can donate a book to the library. 
#### LibA.h file:
    
``` 
   class LibA
    public:
	    LibA();
	    LibA(const string name);
	    void display_name(string name);
	    void add_book();
	    void remove_book(); 
	    void donate_book(Donor);
```
	
### Main:
The main is used to basically design the system. There is no fucntionality explained in the main just the styling of this Library Management System.


## Getting Started
These instruction will guide you on how to get a copy of this project up and running on your local machine. 
### Prerequisites
* A C++ compiler (I used Visual  Studio 2022).
* A github account to clone the repository.
### Installation
1. Clone the repository:


    >git@github.com:RanaMAtif/Library-Management-System.git

2. Pull the code


3. The relative paths of header files and csv files are used in the project so there is no need to change them. 
4. A single book is defined by two classes which are Book and Bookinfo. Book has the datamebers of a book that will stay as it is through out the program but the data members in Bookinfo class changes many times when the program runs. So any new datamembers can be added accordingly. 
## Usage
* Run the program on your compiller after pulling the code from the repository.

* Follow the on-screen instructions to navigate through the system.

## Acknowledgments
* Vector library is used as to store a book vector looked perfect for this project.
* sstream library is used whenever there is a need to read a record from the file sstream object is used to break a string containing a row of records in to the data members. 
* File system is used as a database. 






