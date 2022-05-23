#pragma once
#include <string>
#include<vector>
#include"buy_rent.h"
using namespace std;
class customer
{
public: 
	int ID;
	static int counter;
	string username;
	string pass;
	customer();
	customer(string user, string pass);
};

