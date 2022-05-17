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

void Showroom::UpadateCar() {
	//car::Edit;
	
}