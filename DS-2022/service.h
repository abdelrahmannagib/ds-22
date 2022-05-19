#pragma once
#include<string>
using namespace std;


class service
{
	public:
	int Id;
	static int counter;
	string name;
	double price;
	service();
	service(string Name, string Price);
	~service();
	void Edit(double price);
};

