#include<iostream>
#include<string>
#include<vector>
#include"./src/library/LibA.h"
#include"./src/book/Bookinfo.h"
#include"./src/person/Person.h"
#include"./src/book/Book.h"
#include"./src/person/User.h"
#include "./LMS.h"
#include"./src/person/Donor.h"
#include"./src/person/Librarian.h"

using namespace std;
int main()
{
	int main_while_condition{0};
	do
	{
		LibA library_obj;
		library_obj.display_name("Powersoft Library");
		Bookinfo book;
		

		int choice{0};
		cout << "Enter 1 if you are a user, Enter 2 if you want to donate books, or Enter 3 if you are a Librarian:";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			string user_email{};
			User user_obj;
			cin.ignore();
			cout << "Enter your email: ";
			getline(cin,user_email);
			user_obj.set_email(user_email);
			system("cls");
			user_obj.write_in_file(user_email);
			int switch_choice{0}, loop_condition{0};
			do
			{
				cout << "Press 1 to see available books, press 2 to borrow a book,press 3 to see how many books you have borrowed, press 4 to return a book, or press 5 to search a book : ";
				cin >> switch_choice;
				switch (switch_choice)
				{
				case 1:
				{
					system("cls");
					book.display_Available_Books();
					break;

				}
				case 2:
				{
					system("cls");
					book.borrow_Book(user_obj);
					break;
				}
				case 3:
				{
					system("cls");
					book.display_borrowed_Books(user_obj);
					break;
				}
				case 4:
				{
					book.return_book();
					break;
				}
				case 5:
				{
					system("cls");
					book.search_Books();
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
			string donor_email{};
			Donor donor_obj;
			cin.ignore();
			cout << "Enter your email:";
			getline(cin, donor_email);
			donor_obj.set_email(donor_email);
			
			system("cls");
			
			donor_obj.write_in_file(donor_email);
			
			int donor_while_condition{0};
			do
			{
				
				cout << "Enter the details of the book that you want to donate";
			   library_obj.donate_book(donor_obj);
			   
		    
			cout << "Press -1 if you are done or any other key to donate another book:";
				cin >> donor_while_condition; 
				

			} while (donor_while_condition != -1);
			

		}
		if (choice == 3)
		{
			string librarian_email{};
		
			Librarian librarian_obj;
			cin.ignore();
			cout << "Enter your email: ";
			getline(cin, librarian_email);
			librarian_obj.set_email(librarian_email);
			system("cls");
			bool access = librarian_obj.login(librarian_email);
			
			int librarian_switch_choice{0}, librarian_while_condition{0};
			if (access == true)
			{
				do
				{

					cout << "Press 1 to add book, press 2 to remove book, press 3 for users information, press 4 for donors infomation, press 5 for books information  : ";
					cin >> librarian_switch_choice;
					system("cls");
					switch (librarian_switch_choice)
					{
					case 1:
					{
						cout << "Enter the deatils of the book that you want to add!" << endl;
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
						librarian_obj.display_users();
						break;
					}
					case 4:
					{
						librarian_obj.display_donors();
						break;
					}
					case 5:
					{
						librarian_obj.all_Books_information();
						break;
					}
					default:
					{
						cout << "Invalid choice";
					}
					}
					cout << "Press any key to contiue(-1 to exit Librarian mode):";
					cin >> librarian_while_condition;
				} while (librarian_while_condition != -1);
			}
			else if (access==false)
			{
				exit(0);
			}
		}
		cout << "Press any number to continue (-1 to exit library)";
			cin >> main_while_condition;
			system("cls");
	} 
	while (main_while_condition != -1);
	return (0);
}
