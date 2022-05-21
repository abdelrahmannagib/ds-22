#pragma once
#include<iostream>
#include<vector>
#include"customer.h"
#include"car.h"
using namespace std;
class buy_rent
{
public:
	static int p_Counter;
	int p_Id;
	string p_Date;
	string customer_Id;
	string money;
	string choosen_service;
	buy_rent(string cust_Id, string mon, string service);
};

