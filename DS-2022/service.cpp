#include "Service.h"
int service::counter = 1;
service::service()
{
	Id = counter;
	counter++;
}

service::~service()
{
}

void service::Edit(double NewPrice)
{
	price = NewPrice;
}
