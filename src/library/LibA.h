#pragma once
#include"../book/Bookinfo.h"
#include<vector>
#include"../person/User.h"
#include"../person/Donor.h"


class LibA
{
public:
	LibA();
	LibA(const string name);
	void display_name(string name);
	void add_book();
	void remove_book(); 
	void donate_book(Donor);
	
	

private:
	vector<Bookinfo>books_;
	string lib_name;

};

