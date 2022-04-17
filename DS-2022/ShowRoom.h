#pragma once
#include<iostream>
#include <vector>
using namespace std;
class Showroom
{
	
public:
	static int RoomId;
	int ID;
	string Name;
	string Location;
	string Phone;

	vector <car> AvalibleCAr;

	Showroom();
	void UpdateRoomName();
	void UpdateRoomLocation();
	void UpdateRoomPhone();
	void AddRoom();
	void AddCar();
	void UpadateCar();

	
	

};


