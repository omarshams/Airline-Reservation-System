#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct schedule {
	int flight_num, available_seats, flight_date[3];

	string departure_city;
	int  taking_off_hour, taking_off_minute;

	string arrival_city;
	int  reaching_hour, reaching_minute;
};
struct ticket {
	int number, passenger_ID;
	int flight_date[3], flight_num;
}tickets[100] =
{ 1000,400,{3,9,2023},888,
1001,401,{4,4,2023},103,
1002,402,{2,2,2023},132,
1003,403,{2,2,2023},132 };

void S_A_F(schedule arr[]);
void Add(ticket arr[], schedule ar[]);


const int schedule_size = 10;
const int ticket_size = 10;

schedule schedules[schedule_size]
= {
	{132,200,{2,2,2023},"Tokyo",12,40,"Cairo",16,10},
	{888,10,{3,9,2023},"Berlin",7,00,"Sydney",14,40},
	{103,500,{4,4,2023},"Polanda",23,10,"Dammam",7,50},
	{101,500,{5,4,2023},"Mekkah",23,10,"Dammam",7,10},
	{102,500,{7,4,2023},"Mekkah",7,0,"Dammam",11,20},
	{},
	{741,130,{9,3,2023},"Kuwait",2,50,"Alex",16,10}
};


//int main()
//{
//	S_A_F(schedules);
//	cout << tickets[2].flight_num;
//}
void Add(ticket arr[], schedule ar[])
{
	string ID;
	char answer;
	int F_N, index;
	cout << "Are u want to add a reservation ? " << endl;
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		cout << "Enter a Flight Number: " << endl;
		cin >> F_N;
		for (int o = 0; o < schedule_size; o++)
		{
			if (ar[o].flight_num == F_N)
				index = o;
		}
		ar[index].available_seats--;
		for (int i = 0; i < schedule_size; i++)
		{
			if (F_N == schedules[i].flight_num)
			{
				tickets[i + 4].passenger_ID = i + 1004;
				tickets[i + 4].number = i + 1004;
				tickets[i + 4].flight_date[0] = (rand() % 30) + 1;
				tickets[i + 4].flight_date[1] = (rand() % 12) + 1;
				tickets[i + 4].flight_date[2] = 2003;
				tickets[i + 4].flight_num = schedules[i].flight_num;
			}
		}
	}
	else
		return;
}
void S_A_F(schedule arr[])
{
	string Arrival_place, Take_off_Place;
	cout << "From where are you going ?" << endl;
	cin >> Take_off_Place;
	cout << "To Where are you going ?" << endl;
	cin >> Arrival_place;
	for (int i = 0; i < schedule_size; i++)
	{
		if (Arrival_place == arr[i].arrival_city && Take_off_Place == arr[i].departure_city && arr[i].available_seats != 0)
		{
			cout << endl << "Airplane" << i + 1 << endl;
			cout << "Flight Number: " << arr[i].flight_num << endl
				<< "Available seat: " << arr[i].available_seats << endl
				<< "Departure City  " << arr[i].departure_city << endl
				<< "Taking of Hour: " << arr[i].taking_off_hour << endl
				<< "Taking of Minute: " << arr[i].taking_off_minute << endl
				<< "Reaching Hour: " << arr[i].reaching_hour << endl
				<< "Reaching Minute: " << arr[i].reaching_minute << endl
				<< "Flight Date  ";
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i].flight_date[j];
				if (j < 2)
					cout << "/";
			}
			cout << endl << endl;
		}
	}
	Add(tickets, schedules);
}
