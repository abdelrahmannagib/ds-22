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

	car();
	~car();
    void edit_price();
	void edit_install();
	void Edit();
};

