#include "ShowRoom.h"
#include <iostream>
using namespace std;

int Showroom::RoomId=1;
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
}
void Showroom::AddRoom() {
	Showroom::Showroom();
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
	 car::car(void);
}
void Showroom::UpadateCar() {
	void car::Edit();
}



