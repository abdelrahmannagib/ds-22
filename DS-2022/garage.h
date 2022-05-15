#pragma once
#include<iostream>
using namespace std;
class garage
{
public:
	static int count_garage;
	int id;
	string name;
	string location;
	string phone_number;
	garage();
	void edit_garage();
	void edit_name();
	void edit_location();
	void edit_phone();
};

