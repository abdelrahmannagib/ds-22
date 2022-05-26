#pragma once
#include <string>
#include<vector>
#include<queue>
#include"buy_rent.h"
#include"car.h"
using namespace std;
class customer
{
public: 
	int ID;
	static int counter;
	string username;
	string pass;
	queue<car> reservedCar;
	customer();
	customer(string user, string pass);
};

