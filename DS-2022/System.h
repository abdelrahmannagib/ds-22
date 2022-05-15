#pragma once
#include<iostream>
#include<vector>
#include "ShowRoom.h"
#include"customer.h"
#include"buy_rent.h"
#include"Admin.h"
#include"garage.h"
#include"service.h"
using namespace std;
class System
{
public:

	vector<Showroom> sysRoom;
	vector<customer> syscustomers;
	vector<Admin> sysAdmin;
	vector<garage> sysGarage;
	vector<service> sysService;
	System();
	void goto_customer();
	void goto_Admin();
	void goto_Garage();
	void insert_rooms_of_garage_to_file();
	void insert_admins_from_files();
	void insert_cars_from_files();
	void insert_services_from_files();
	void insert_customer_from_files();
	void insert_process_from_file();
};

