#pragma once
using namespace std;
#include <string>
class customer
{
 
	int ID;
	static int counter;
	string username;
	string password;
public:
	customer();
	customer(string user, string pass);
};

