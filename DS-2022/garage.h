#pragma once
#include<iostream>
#include"service.h"
#include<vector>
using namespace std;
class garage
{
public:
	static int count_garage;
	int id;
	string name;
	string location;
	string phone_number;
	vector<service> gar_services;
	
	garage();
	garage(string, string, string);
	void edit_garage();
	void edit_name();
	void edit_location();
	void edit_phone();
};

