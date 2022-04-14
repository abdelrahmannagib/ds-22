#include "garage.h"
int garage::count_garage = 1;
garage::garage()
{
	id = count_garage ;
	count_garage++;
	cout << "Enter name"<<endl;
	cin >> this->name;
	cout << "Enter location" << endl;
	cin >> this->location;
	cout << "Enter phone number" << endl;
	cin >> this->phone_number;

}
