#include "Service.h"
#include<iostream>
int service::counter = 1;
using namespace std;
service::service()
{
	Id = counter;
	counter++;
	cout << "Enter service name : ";
	cin >> name;
	cout << "Enter srevice price : ";
	cin >> price;

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

void service::Edit()
{
	while (true)
	{
		int y;
		cout << "Press 1 to edit name ,2 to edit price or 3 to stop edit";
		cin >> y;
		if (y==1)
		{
			cout << "Enter the new name";
			cin >> name;
		}
		else if (y == 2)
		{
			cout << "Enter the new price";
			cin >> price;
		}
		else
		{
			break;
		}
	}
}
