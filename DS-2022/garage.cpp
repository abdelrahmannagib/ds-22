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
void garage::edit_location() {
	cout << "enter the new location";
	string loc;
	cin >> loc;
}
void garage::edit_name() {
	cout << "enter the new name";
	string name;
	cin >> name;
}
void garage::edit_phone() {
	cout << "enter the new phone";
	string phone;
	cin >> phone;
}

void garage::edit_garage() {
	cout << "press 1 to edit name" << endl;
	cout << "press 2 to edit location" << endl;
	cout << "press 3 to edit phone" << endl;
	cout << "press 4 to edit service";
	int x;
	cin >> x;
	if (x == 1) {
		edit_name();
	}
	else if (x == 2) {
		edit_location();
	}
	else if (x == 3)
	{
		edit_phone();
	}
	else if (x == 4) {
		cout << "enter 1 to add service ";
		int z;
		cin >> z;
		if (z == 1) {

		}
	}
	else {
		cout << "enter a true number";
	}
}
