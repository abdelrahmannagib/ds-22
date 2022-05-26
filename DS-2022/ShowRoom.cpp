#include "ShowRoom.h"
#include"car.h"
#include <iostream>
#include<fstream>
using namespace std;

int Showroom::RoomId = 1;
Showroom::Showroom()
{
	ID = RoomId;
	RoomId++;
	cout << "Enter Room Name : ";
	cin >> Name;
	cout << "Enter Room Location : ";
	cin >> Location;
	cout << "Enter Room Phone Number : ";
	cin >> Phone;
	fstream sroom;
	sroom.open("showroom.txt", ios::app);
	sroom << ID << " " << Name << " " << Location << " " << Phone << endl;
}
Showroom::Showroom(string s1,string s2,string s3)
{
	ID = RoomId;
	RoomId++;
	Name = s1;
	Location = s2;
	Phone = s3;
}
void Showroom::UpdateRoomName() {
	cout << "Enter the new Name : ";
	cin >> Name;
}
void Showroom::UpdateRoomLocation() {
	cout << "Enter the new Location : ";
	cin >> Location;
}
void Showroom::UpdateRoomPhone() {
	cout << "Enter the new Phone : ";
	cin >> Phone;
}
void Showroom::AddCar() {
	 string s_id = to_string (ID);
	 car c(s_id);
	 AvalibleCAr.push_back(c);
}

void Showroom::EditShowRoom() {
	int in;
	while (true)
	{
		cout << "Press 1 to Edit Name, 2 to Edit Location, 3 to Edit Phone, 4 to add car ,5 to Exit: ";
		cin >> in;

		if (in == 1)
			UpdateRoomName();
		else if (in == 2)
			UpdateRoomLocation();
		else if (in == 3)
			UpdateRoomPhone();
		else if (in == 4)
			AddCar();
		else if (in == 5)
			break;
		else
			cout << "Invalid number, please enter a valid number" << endl;
	}
}

void Showroom::ShowShowRoomData()
{
	cout << "Room:" << ID << endl;
	cout << "Name:" << Name << endl;
	cout << "Location: " << Location << endl;
	cout << "Phone: " << Phone << endl;

	cout << "Cars Available in Room: " << endl;
	for (int i = 0; i < AvalibleCAr.size(); i++)
	{
		cout << "Car number: " << i << endl;
		cout << "Id: " << AvalibleCAr[i].id << endl;
		cout << "Model: " << AvalibleCAr[i].model << endl;
		cout << "Make: " << AvalibleCAr[i].make << endl;
		cout << "Price: " << AvalibleCAr[i].price << endl;
		cout << "Year: " << AvalibleCAr[i].year << endl;
		cout << "Install: " << AvalibleCAr[i].install << endl;
	}
}

void Showroom::EditCar(int num)
{
	int selector;
	while (true)
	{
		cout << "press 1 to edit model, 2 to edit make, 3 to edit price, 4 edit year, 5 to edit install, 6 to exit" << endl;
		cin >> selector;
		if (selector == 1)
		{
			string NewModel;
			cout << "enter  the new model :" << endl;
			AvalibleCAr[num].model = NewModel;
		}
		else if (selector == 2)
		{
			string NewMake;
			cout << "enter  the new Make :" << endl;
			AvalibleCAr[num].make = NewMake;
		}
		else if (selector == 3)
		{
			string NewPrice;
			cout << "enter  the new price :" << endl;
			AvalibleCAr[num].price = NewPrice;
		}
		else if (selector == 4)
		{
			string NewYear;
			cout << "enter  the new year :" << endl;
			AvalibleCAr[num].year = NewYear;
		}
		else if (selector == 5)
		{
			string NewInstall;
			cout << "enter  the new Install :" << endl;
			AvalibleCAr[num].install = NewInstall;
		}
		else if (selector == 6)
		{
			break;
		}
		else
		{
			cout << "Invalid number, please enter valid number." << endl;
		}
	}
}
