#pragma once
#include<iostream>
#include <vector>
#include"car.h"
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
	Showroom(string s1, string s2, string s3);
	void UpdateRoomName();
	void UpdateRoomLocation();
	void UpdateRoomPhone();
//	void AddRoom();
	void AddCar();
	void EditShowRoom();
	void ShowShowRoomData();
	void EditCar(int num);
};


