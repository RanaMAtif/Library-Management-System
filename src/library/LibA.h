#pragma once
#include"/Users/Lenovo/source/repos/LMS/LMS/src/book/Bookinfo.h"
#include<vector>
#include"/Users/Lenovo/source/repos/LMS/LMS/src/person/User.h"


class LibA
{
public:
	LibA();
	LibA(const string name);
	void display_name(string name);
	void display_AllBooks();
	void add_book();
	void remove_book();
	void lend_book();
	void return_book();
	void borrow_book(User);
	void donate_book();
	void search_book();
	void show_borrowed_books(User);

private:
	std::vector<Bookinfo>books_;
	std::string lib_name;

};

