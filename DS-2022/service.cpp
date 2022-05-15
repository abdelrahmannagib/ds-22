#include "Service.h"
int service::counter = 1;
service::service()
{
	Id = counter;
	counter++;
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

void service::Edit(double NewPrice)
{
	price = NewPrice;
}
