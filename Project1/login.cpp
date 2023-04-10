#include <iostream>
#include <string>
using namespace std;
void login();
void inputadmin();
void regis();


void admin();
void passenger();

struct s {
	string email;
	string	password;
}
people[100] = { "omar@gmail.com","123","ezz@gmail.com","123","abdullah@gmail.com","123","amr@gmail.com","123","reda@gmail.com","123" };
void menu()
{
	int choice;
	cout << "\n\n                    -----------------------" << endl << "                    WELCOME TO FCIS AIRLINE  " << endl << "                    -----------------------";
	cout << "\n\n\n";
	cout << "|press 1 to login as admin|";
	cout << "\n\n|press 2 to login as a passenger|";
	cout << "\n\n|press 3 to register a new account|";
	cout << "\n\nplease enter your choice  ";
	cin >> choice;
	switch (choice)
	{
	case 1: inputadmin(); break;
	case 2: login(); break;
	case 3: regis(); break;
	}
}
void login()
{
	int i = 0;
	bool  n = 0;
	string username, pass;
	cout << "Enter your email and password   ";
	while (n == 0)
	{
		cin >> username >> pass;
		for (int i = 1; i <= 99; i++)
			if (username == people[i].email && pass == people[i].password)
			{
				n = 1;
				break;
			}
		if (n == 0)
			cout << "invlalid email or password entered , please try again   " << endl;
		i++;
		if (i == 3)
		{
			cout << "sorry but you have failed too many attempts , you will retrun to main menu";
			menu();
		}
	}
	cout << "\nYou have logged in successfully";
	passenger();
}
void regis()
{
	cout << "Make an email and a password please *_*   " << endl;
	cin >> people[99].email >> people[99].password;
	for (int i = 0; i <= 98; i++)
		if (people[i].email == people[99].email)
		{
			cout << "email is in use , please enter another email   " << endl;
			cin >> people[99].email;
			break;
		}
	passenger();
}
void inputadmin()
{
	int i = 0;
	bool  n = 0;
	string username, pass;
	cout << "Enter your email and password   " << endl;
	while (n == 0)
	{
		cin >> username >> pass;
		if (username == people[0].email && pass == people[0].password)
		{
			n = 1;
			break;
		}
		if (n == 0)
			cout << "\ninvlalid email or password entered , please try again   ";
		i++;
		if (i == 3)
		{
			cout << "\nsorry but you have failed too many attempts , you will retrun to main menu";
			menu();
		}

	}
	cout << "\nYou have logged in successfully";
	admin();
}





void passenger()
{
	//ezz and abdullah and amr , your code goes here
}
void admin()
{
	//reda and khaled , your code goes here
}
//int main()
//{
//	menu();
//}
