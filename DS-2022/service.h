#pragma once
#include<string>
using namespace std;


class service
{
	public:
	int Id;
	static int counter;
	string name;
	string price;
	service(string g_id);
	service(string Name, string Price);
	~service();
	void Edit();
	void ShowServiceData();
};

