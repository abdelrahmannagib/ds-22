#pragma once
using namespace std;
#include <string>
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

