#pragma once
#include<string>
using namespace std;


class service
{
	int Id;
	static int counter;
	string name;
	double price;
public:
	service();
	~service();
	void Edit(double price);
};

