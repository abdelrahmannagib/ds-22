#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
	map<string, vector<car>> reservedCar;
	map<string, int> map_rooms;
	map<string, int> map_garage;
	map<string, vector<buy_rent>> history_cust;
	map<string, pair<bool, int>>GarageSearch;
	map<string, bool> ServiceFound;
	map<string, pair<int, int>> ServiceGarageId;
	map<string, pair<bool,int> >Showroom_search;
	map<string, bool> car_found;
	map<string, pair<int, int>> car_room_ids;
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
	void insert_garage_from_file();
	void maptest();
	void SearchForGarage(string customerId);
	void SearchForService(string customerId);
	void search_Showrrom(string customerId);
	void search_car(string customerId);
	void reserveCar(string customerId,car c);
	void sellOrCancel(string rId, int cId, int BuyorCancel);
	
};

