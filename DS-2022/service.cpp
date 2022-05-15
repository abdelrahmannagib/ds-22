#include "Service.h"
#include<fstream>
int service::counter = 1;
service::service()
{
	Id = counter;
	counter++;
	price = "";
	name = "";

	fstream service;
	service.open("service.text", ios::app);
	service << Id << name << price << endl;
}

service::service(string Name, string Price)
{
	Id = counter;
	counter++;

	name = Name;
	price = Price;
}

service::~service()
{
}

void service::Edit(string NewPrice)
{
	price = NewPrice;
}
