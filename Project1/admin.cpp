#include <iostream>

using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int num = 4, actual_num = 4;

struct schedule {
	int flight_num, num_of_available_seats, flight_date[3];
	string departure_city;
	int  taking_off_hour, taking_off_minute;
	string arrival_city;
	int  reaching_hour, reaching_minute;
}existing[500];

void add_schedule() {
	cout << "Enter the flight number\n";
	cin >> existing[num].flight_num;
	cout << "Enter the number of available seats\n";
	cin >> existing[num].num_of_available_seats;
	cout << "Enter the day of flight\n";
	cin >> existing[num].flight_date[0];
	cout << "Enter the month\n";
	cin >> existing[num].flight_date[1];
	cout << "Enter the year\n";
	cin >> existing[num].flight_date[2];
	cout << "Enter the departure city\n";
	cin >> existing[num].departure_city;
	cout << "Enter the taking off hour\n";
	cin >> existing[num].taking_off_hour;
	cout << "Enter the taking off minute\n";
	cin >> existing[num].taking_off_minute;
	cout << "Enter the arrival city\n";
	cin >> existing[num].arrival_city;
	cout << "Enter the reaching hour\n";
	cin >> existing[num].reaching_hour;
	cout << "Enter the reaching minute\n";
	cin >> existing[num++].reaching_minute;
	actual_num++;
}
void edit_schedule(int k) {
	bool found = 0;
	for (int u = 0; u < num; u++)
		if (k == existing[u].flight_num)
		{
			k = u, found = 1;
			break;
		}
	if (!found)
	{
		cout << "There isn't flight with this number\nif you want to try again, enter the number of flight you want to edit , else enter -1\n";
		cin >> k;
		if (k == -1)
			return;
		else
			edit_schedule(k);
	}
	cout << "How many things you want to edit ? and what do you want to edit ?\n1.the number of available seats\n2.the date of flight\n3.the departure city\n4.the time of taking off\n5.arrival city\n6.reaching time\n";
	int trials, operation;
	cin >> trials;
	while (trials--)
	{
		cout << "Enter the number which you want do its operation\n";
		cin >> operation;
		if (operation == 1)
		{
			cout << "Enter the new number\n";
			cin >> existing[k].num_of_available_seats;
		}
		else if (operation == 2)
		{
			cout << "Enter the day\n";
			cin >> existing[k].flight_date[0];
			cout << "Enter the month\n";
			cin >> existing[k].flight_date[1];
			cout << "Enter the year\n";
			cin >> existing[k].flight_date[2];
		}
		else if (operation == 3)
		{
			cout << "Enter the departure city";
			cin >> existing[k].departure_city;
		}
		else if (operation == 4)
		{
			cout << "Enter hour\n";
			cin >> existing[k].taking_off_hour;
			cout << "Enter minute\n";
			cin >> existing[k].taking_off_minute;
		}
		else if (operation == 5)
		{
			cout << "Enter the arrival city";
			cin >> existing[k].arrival_city;
		}
		else if (operation == 6)
		{
			cout << "Enter hour\n";
			cin >> existing[k].reaching_hour;
			cout << "Enter minute\n";
			cin >> existing[k].reaching_minute;
		}
		else
			cout << "Invalid number !\n";
	}
}
void Delete_Flight_Num(int q) {
	bool ok = false;
	for (int i = 0; i < num; ++i) {
		if (q == existing[i].flight_num) {
			q = i;
			ok = true;
			break;
		}
	}
	if (!ok) {
		cout << " Sorry Number Not found \n If you want to try again, Enter the flight number you want to delete , if you want to skip enter -1 \n";
		int ans;
		cin >> ans;
		if (ans == -1)
			return;
		else
			Delete_Flight_Num(ans);

	}
	existing[q] = { -1,-1,-1,-1,-1,"",-1,-1,"",-1,-1 };
	if (ok)
		cout << "Done!\n";
	actual_num--;
}
bool admin_access() {
	cout << "Choose the Operation you want to do !\n1.add new schedule\n2.edit an existing schudule\n3.delete an ecisting schedule\n";
	int i;
	cin >> i;
	while (i != 1 && i != 2 && i != 3)
	{
		cout << "Please write a correct number!\n";
		cin >> i;
	}
	if (i == 1)
		add_schedule();
	else if (i == 2)
	{
		int k;
		cout << "Enter the number of the flight\n";
		cin >> k;
		edit_schedule(k);
	}
	else if (i == 3) {
		if (actual_num < 1)
			cout << "There isn't any flight to delete!\n";
		else
		{
			cout << "How many flight you want to delete? \n";
			int t;
			cin >> t;
			while (t <= 0 || t > actual_num) {
				cout << "Invalid Number!\n Please Enter Number Between 1 and " << actual_num << " \n";
				cin >> t;
			}
			while (t--) {
				cout << "_________________________________________Enter Flight Number To Delete ______________________________________________\n";
				int q;
				cin >> q;
				Delete_Flight_Num(q);
			}
		}
	}
	cout << "If you want to do another operation enter 1 \nelse enter any other number.\n";
	int continu;
	cin >> continu;
	if (continu == 1)
		admin_access();
	else
		return 1;
}

//int main()
//{
//	existing[0] = { 1,100,7,2,2024,"Cairo",3,30,"Alex",4,30 };
//	existing[1] = { 2,80,18,2,2024,"Cairo",2,15,"Alex",4,0 };
//	existing[2] = { 3,70,15,2,2024,"Cairo",2,0,"Alex",4,0 };
//	existing[3] = { 4,150,1,2,2024,"Cairo",2,30,"Alex",4,0 };
//	fast
//		if (admin_access())
//			cout << "Thanks for your effort !";
//	return 0;
//}