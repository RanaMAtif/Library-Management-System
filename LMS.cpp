#include<iostream>
#include<string>
#include<vector>
#include"LibA.h"
#include"Bookinfo.h"
#include"Librarian.h"
#include"Book.h"
#include"User.h"
#include "LMS.h"
#include"Donor.h"
using namespace std;
int main()
{
	int main_while_condition{0};
	do
	{
		LibA library_obj;
		library_obj.display_name("Powersoft Library");
		

		int choice{0};
		cout << "Enter 1 if you are a user, Enter 2 if you want to donate books, or Enter 3 if you are a Librarian:";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			string user_name{}, user_email{};
			User user_obj;
			cin.ignore();
			cout << "User please Enter your name: ";
			getline(cin, user_name);
			user_obj.set_name(user_name);
			cin.ignore();
			cout << "Enter your email: ";
			getline(cin,user_email);
			user_obj.set_email(user_email);
			system("cls");
			cout << "Welcome " << user_obj.get_name() << " your email is :" << user_obj.get_email() << endl;
			int switch_choice{0}, loop_condition{0};
			do
			{


				cout << "Press 1 to search a book, press 2 to borrow a book, press 3 to see how many books you have borrowed, and press 4 to return a book : ";
				cin >> switch_choice;
				switch (switch_choice)
				{
				case 1:
				{
					library_obj.search_book();
					


					break;

				}
				case 2:
				{
					library_obj.borrow_book(user_obj);
					break;
				}
				case 3:
				{
					library_obj.show_borrowed_books(user_obj);
					break;
				}
				case 4:
				{
					library_obj.return_book();
					break;
				}

				default:
				{
					cout << "Invalid Choice"<<endl;
				}
				}
				cout << "Enter any key to continue(-1 if you are done):";
				cin >> loop_condition;
				
			}
			while (loop_condition != -1);
			system("cls");
		}
		if (choice == 2)
		{
			string donor_name{};
			string donor_email{};
			Donor donor_obj;
			cin.ignore();
			cout << "Donor please Enter your name:";
			getline(cin, donor_name);
			donor_obj.set_name(donor_name);
			cin.ignore();
			cout << "Enter your email:";
			getline(cin, donor_email);
			donor_obj.set_email(donor_email);
			system("cls");
			cout << "Welcome  " << donor_obj.get_name() << " your email is :" << donor_obj.get_email() << endl;

			
			int donor_while_condition{0};
			do
			{
				cout << "Enter the details of the book that you want to donate";
			   library_obj.donate_book();
		    
			cout << "Press any key to continue(-1 if you are done.):";
				cin >> donor_while_condition;
			} while (donor_while_condition != -1);
			

		}
		if (choice == 3)
		{
			string librarian_name{}, librarian_email{};
			int librarian_password;
			Librarian librarian_obj;
			cin.ignore();
			cout << "Librarian please Enter your name: ";
			getline(cin, librarian_name);
			librarian_obj.set_name(librarian_name);
			cin.ignore();
			cout << "Enter your email: ";
			getline(cin, librarian_email);
			librarian_obj.set_email(librarian_email);
			system("cls");
			
			
				
				cout << "Enter Pasword: ";//Pasword = 123
				cin >> librarian_password;
				system("cls");
				librarian_obj.set_pasword(librarian_password);
				librarian_obj.verify_pass(librarian_password);
				
			
			
			cout << librarian_obj.get_name()<<endl;
			int librarian_switch_choice{0}, librarian_while_condition{0};
			do
			{

			
				cout << "To add a book press 1, to remove a book press 2, to lend a book press 3 :";
				cin >> librarian_switch_choice;
				system("cls");
				switch (librarian_switch_choice)
					{
					case 1:
					{
						cout << "Enter the deatils of the book that you want to add!!" << endl;
						library_obj.add_book();
						break;
					}
					case 2:
					{
						library_obj.remove_book();
						break;
					}			
					case 3:
					{
						library_obj.lend_book();
						break;
					}
					default:
					{
						cout << "Invalid choice";
					}
					}
			cout << "Press any key to contiue(-1 to exit Librarian mode):";
			cin >> librarian_while_condition;
			} 
			while (librarian_while_condition != -1);
		}
		cout << "Press any number to continue (-1 to exit library)";
			cin >> main_while_condition;
			system("cls");
	} 
	while (main_while_condition != -1);
	
}
