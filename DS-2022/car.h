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
	string price;
	string install;
	string belong;
	bool appear;
	car(string g);
	car(string ma, string mo, string ins, string year, string pr,string);
	~car();
    void edit_price();
	void edit_install();
	void Edit();
	void ShowCarData();
};

