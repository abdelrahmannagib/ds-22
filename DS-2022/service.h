#pragma once
#include<string>
using namespace std;


class service
{
	int Id;
	static int counter;
	string name;
	string price;
public:
	service();
	service(string Name, string Price);
	~service();
	void Edit(string price);

};

