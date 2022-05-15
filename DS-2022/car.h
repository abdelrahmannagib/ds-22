#pragma once
#include <string>
using namespace std;
class car
{
	
public :
	int id;
	static int counter;
	string make;
	string model;
	string year;
	double price;
	double install;

	car(string g);
	car(string ma, string mo, string ins, string year, string pr);
	~car();
    void edit_price();
	void edit_install();
	void Edit();
};

