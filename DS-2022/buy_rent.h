#pragma once
#include<iostream>
#include<vector>
#include"customer.h"
#include"car.h"
using namespace std;
class buy_rent
{
	public:
	static int p_counter;
	int procees_id;
	string proceess_date;
	int customer_id;
	vector <car> procees_car;
	int money;
	buy_rent(int id, car c);
};

