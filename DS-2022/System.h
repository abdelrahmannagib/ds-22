#pragma once
#include<iostream>
#include<vector>
#include "ShowRoom.h"
#include "Admin.h"
#include "car.h"
#include "garage.h"
using namespace std;
class System
{
public:

	vector<Showroom> sysRoom;
	vector<Admin> sysAdmin;
	vector<garage> sysGarage;
	System();
	void goto_Admin();
	void goto_Garage();
};

