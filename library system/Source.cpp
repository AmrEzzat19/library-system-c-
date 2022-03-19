#include <iostream>
#include<string>
#include<ctime>
using namespace std;

//structures
struct date {
	int day, month, year;
};


struct account {
	int id;
	string name;
	string email;
	string password;
	string account_type;
	date creationDate;
	int contactNumber[3];
};

struct books {
	string title;
	int productionYear;
	int NumberOfCopies;
	string category;
	string edition;
};

//global variables

account user[10];
books book[10];
date todayDate;

int i = 1;   //used in create account function
int todayDatecounter = 0; //to enter date one time only


//functions

void buy_book();
void book_search();
void report();
int createAccount();




int main()
{
	book[1] = { "One hundred years of solitude",2006,3,"Literature-Novel","MODERN CLASSICS EDITION" };
	book[2] = { "The brothers karmoz",2004,4,"Literature-Novel","" };
	book[3] = { "Who Moved My Cheese?",2007,2,"Self Developmentt-Business","" };
	book[4] = { "Love in the time of Cholera",2000,5,"Literature-Novel","" };
	book[5] = { "Emotional Intelligence",1996,6,"Psychology","paperback edition" };
	book[6] = { "Blink",2005,1,"Psychology","mass market paperback edition" };
	book[7] = { "Relativity",2000,2,"Science-physics","" };
	book[8] = { "the five people you meet in heaven",2003,3,"Literature-Novel","" };
	book[9] = { "Veronika decides to die",2000,1,"Literature-Novel","hardcover printing" };

	if (todayDatecounter == 0)
	{
		cout << "Enter today's date" << endl;
		cout << "Day: ";
		cin >> todayDate.day;
		cout << "Month: ";
		cin >> todayDate.month;
		cout << "Year: ";
		cin >> todayDate.year;
		system("CLS");
		todayDatecounter++;
	}

	while (true)
	{
		int choice;
		cout << "\t\t\t****WELCOME TO THE LIBRARRY SYSTEM****" << endl << endl;
		cout << "Please! choose from the menu below:\n\n";
		cout << "1-Create a user account " << endl << "2-Search for a book" << endl << "3-Buy a book" << endl << "4-Report of the new users" << endl << "5-Exit" << endl;
		cin >> choice;
		system("CLS");
		if (choice == 1)
		{
			createAccount();

		}
		else if (choice == 2)
		{

			book_search();

		}
		else if (choice == 3)
		{

			buy_book();

		}
		else if (choice == 4)
		{
			report();
		}
		else if (choice == 5)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid entry tryagain!" << endl;
			continue;

		}
	}
}

void book_search()
{


	while (true)
	{
		int counter = 0;
		int wayOfSearching;
		cout << "\n***Search Menu***\n\n";
		cout << "1-Search by Book Name" << endl << "2-Search by Production Year" << endl << "3-Back to Main Menu" << endl;
		cin >> wayOfSearching;
		system("CLS");

		if (wayOfSearching == 1)
		{
			cout << "Enter the full book name: ";
			string requiredBookName;
			cin.ignore();
			getline(cin, requiredBookName);
			bool isfound = false;
			int bookNumber = 0;
			for (int i = 1; i < 10; i++)
			{
				if (requiredBookName == book[i].title)
				{
					isfound = true;
					bookNumber = i;
					break;
				}

			}
			if (isfound == true)
			{
				cout << "Title: " << book[bookNumber].title << endl << "Production year: " << book[bookNumber].productionYear << endl << "Edition: " << book[bookNumber].edition << endl << "Category: " << book[bookNumber].category << endl << "Number of copies: " << book[bookNumber].NumberOfCopies << endl << endl;
			}
			else
			{
				cout << "NOT FOUND!" << endl;
				continue;

			}
		}
		if (wayOfSearching == 2)
		{
			cout << "Enter production year: ";
			int requiredBookyear;
			cin >> requiredBookyear;

			int bookNumber = 0;
			for (int i = 1; i < 10; i++)
			{
				if (requiredBookyear == book[i].productionYear)
				{
					cout << "Title: " << book[i].title << endl << "Production year: " << book[i].productionYear << endl << "Edition: " << book[i].edition << endl << "Category: " << book[i].category << endl << "Number of copies: " << book[i].NumberOfCopies << endl << endl;
					counter++;
				}
			}

			if (counter == 0)
			{
				cout << "NOT FOUND!" << endl;
				continue;
			}
		}

		if (wayOfSearching == 3)
		{
			main();
		}

	}

}

int createAccount()
{
	string UserName[4];
	UserName[0] = { "ahmed" };
	UserName[1] = { "mohamed" };
	UserName[2] = { "omar" };
	UserName[3] = { "osama" };
	string password[4];
	password[0] = { "a123456h" };
	password[1] = { "m1o2r3" };
	password[2] = { "omar1234" };
	password[3] = { "osos2000" };

	string admin;
	string adminPass;
	bool isfound = false;


	cout << "\n\t\t\tNOTE: Enter with admin's account to open the system" << endl;
	cout << "\nEnter Username: " << endl;
	cin >> admin;
	cout << "\nEnter password: " << endl;
	cin >> adminPass;

	system("CLS");

	int anotherUser;
	int accountType;

	cout << "\t\t\t***Create account***" << endl;

	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (admin == UserName[i] && adminPass == password[i])
			{
				isfound = true;
			}

		}
		if (isfound == true)
		{
			cout << "ID: ";
			srand(time(0));

			user[i].id = rand() % 10000;

			cout << user[i].id << endl;

			cout << endl << "Name: ";
			cin >> user[i].name;

			cout << endl << "Email: ";
			cin >> user[i].email;

			cout << endl << "Password: ";
			cin >> user[i].password;

			cout << endl << "Account type" << endl;
			cout << "1-Student" << endl << "2-Stuff" << endl << "3-Guest" << endl;
			cin >> accountType;
			if (accountType == 1)
				user[i].account_type = "Student";
			else if (accountType == 2)
				user[i].account_type = "Stuff";
			else if (accountType == 3)
				user[i].account_type = "Guest";

			cout << endl << "Creation date" << endl;
			cout << "Day: ";
			cin >> user[i].creationDate.day;
			cout << "Month: ";
			cin >> user[i].creationDate.month;
			cout << "Year: ";
			cin >> user[i].creationDate.year;

			for (int j = 1; j <= 3; j++)
			{
				cout << endl << "Contact number: ";

				cin >> user[i].contactNumber[j];

				if (j == 1 || j == 2)
				{
					cout << "\n***********************\n1-Enter another number" << endl << "2-Confirm" << endl;
					int choice;
					cin >> choice;
					if (choice == 1)
						continue;

					else if (choice == 2)
					{
						system("CLS");
						i++;
						main();
					}
				}
				else if (j == 3)
				{
					system("CLS");
					cout << "1-confirm" << endl;
					cin >> anotherUser;
					if (anotherUser == 1)
					{
						system("CLS");
						i++;
						main();
					}

				}
				i++;
			}

		}
		else
		{
			cout << "Invalid user name or password" << endl;
			cout << "1-Try again \n2-Exit" << endl;

			int tryagain;
			cin >> tryagain;
			system("CLS");

			if (tryagain == 1)
			{
				cout << "Enter User name: " << endl;
				cin >> admin;
				cout << "Enter password: " << endl;
				cin >> adminPass;
				system("CLS");

				continue;
			}
			else
				return 0;
		}
	}

}


void buy_book()
{
	int book_order;
	int anykey;
	int choice;
	int accountnumber = 0;
	bool isfound = false;
	bool bookFound = false;

	string wantedBook;
	string buyer_account;
	string buyer_password;
	cout << "Username: ";
	cin >> buyer_account;
	cout << "Password: ";
	cin >> buyer_password;


	while (true)
	{
		for (int i = 1; i < 10; i++)
		{
			if (buyer_account == user[i].name && buyer_password == user[i].password)
			{
				isfound = true;
				accountnumber = i;
			}
		}
		if (isfound == true)
		{
			if (user[accountnumber].account_type == "Guest" || user[accountnumber].account_type == "Student")
			{
				cout << "This feature is not permitted for this account!" << endl;
				cout << "press 1 to go to main menu";
				cin >> anykey;
				if (anykey == 1)
					system("CLS");
				main();
			}
			else if (user[accountnumber].account_type == "Stuff")
			{
				system("CLS");

				cout << "Avaliable books" << endl;
				for (int j = 1; j < 10; j++)
				{

					cout << j << "-" << book[j].title << " //	" << "Number of copies: " << book[j].NumberOfCopies << endl;

				}
				cout << "Enter the name of the book: ";
				cin.ignore();
				getline(cin, wantedBook);
				for (int k = 1; k <= 9; k++)
				{
					if (wantedBook == book[k].title)
					{
						bookFound = true;
						book_order = k;

					}
				}
				if (bookFound == true)
				{
					if (book[book_order].NumberOfCopies > 0)
					{
						system("CLS");

						cout << "1-Confirm purchase" << endl << "2-Back to main menu" << endl;
						cin >> anykey;
						if (anykey == 1)
						{
							system("CLS");

							book[book_order].NumberOfCopies -= 1;

							main();
						}
						else if (anykey == 2)
						{
							system("CLS");
							main();
						}
					}
					else if (book[book_order].NumberOfCopies == 0)
					{
						system("CLS");

						cout << "There is no copy avaliable of that book right now" << endl << "1-Choose anohter book" << endl << "2-Back to main menu" << endl;
						cin >> anykey;
						if (anykey == 1)
							continue;
						else if (anykey == 2)
							main();

					}
				}
				else
				{
					system("CLS");

					cout << "Can't find this book" << endl;
					cout << "1-Search for another Book" << endl << "2-Back to Main Menu";
					cin >> anykey;
					if (anykey == 1)
					{
						system("CLS");
						continue;
					}
					else if (anykey == 2)
					{
						system("CLS");
						main();
					}
				}

			}
		}
		else
		{
			system("CLS");
			cout << "Account is not found!" << endl << "1-Try again" << endl << "2-Create new account" << endl;
			cin >> choice;
			if (choice == 1)
			{
				system("CLS");
				cout << "Username: ";
				cin >> buyer_account;
				cout << "Password: ";
				cin >> buyer_password;
				continue;
			}
			else if (choice == 2)
				createAccount();
		}
	}
}



void report()
{
	int day, month, year;
	day = todayDate.day;
	month = todayDate.month;
	year = todayDate.year;
	int accountCounter = 0;//hy3d lw feh accounts wla la2 3shan lw mafeesh ycout no accounts created in the last 7 days


	if (day >= 7)
	{
		for (int i = 7; i > 0; i--)
		{
			for (int j = 1; j < 10; j++)
			{
				if (user[j].creationDate.day == day && user[j].creationDate.month == month && user[j].creationDate.year == year)
				{
					cout << "ID: " << user[j].id << endl;
					cout << "Name: " << user[j].name << endl;
					cout << "Email: " << user[j].email << endl;
					cout << "Account type: " << user[j].account_type << endl;
					cout << "Day: " << user[j].creationDate.day << endl;
					cout << "Month: " << user[j].creationDate.month << endl;
					cout << "Year: " << user[j].creationDate.year << endl << endl;
					cout << "Contact number: ";

					for (int k = 1; k <= 3; k++)
					{
						if (user[j].contactNumber[k] == 0)
							cout << k << "-" << "Not found" << endl;
						else
							cout << k << "-" << user[j].contactNumber[k] << endl;
					}
					accountCounter++;
				}

			}

			day--;
		}

	}
	else
	{
		for (int i = 7; i > 0; i--)
		{
			for (int j = 1; j < 10; j++)
			{
				if (user[j].creationDate.day == day && user[j].creationDate.month == month && user[j].creationDate.year == year)
				{
					cout << "ID: " << user[j].id << endl;
					cout << "Name: " << user[j].name << endl;
					cout << "Email: " << user[j].email << endl;
					cout << "Account type: " << user[j].account_type << endl;
					cout << "creation Date;" << endl;
					cout << "Day: " << user[j].creationDate.day << endl;
					cout << "Month: " << user[j].creationDate.month << endl;
					cout << "Year: " << user[j].creationDate.year << endl << endl;
					cout << "Contact number: " << endl;
					for (int k = 1; k <= 3; k++)
					{
						if (user[j].contactNumber[k] > 0)
							cout << k << "-" << user[j].contactNumber[k] << endl;
					}
					accountCounter++;
				}

			}

			if (day == 1)
			{
				if (month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 10)
				{
					month--;
					day = 32;

				}
				else if (month == 5 || month == 7 || month == 10 || month == 12)
				{
					month--;
					day = 31;

				}
				else if (month == 3)
				{
					month--;
					day = 29;
				}

			}
			if (month == 1 && day == 1)
			{
				year--;
			}
			day--;
		}
	}
	if (accountCounter == 0)
	{
		cout << "\nNo created accounts in the last 7 days" << endl;
	}
	cout << endl << "1-Back to main menu" << endl;
	int backtomainmenu;
	cin >> backtomainmenu;
	if (backtomainmenu == 1)
	{
		system("CLS");
		main();
	}
}
