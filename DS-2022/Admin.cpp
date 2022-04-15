#include "Admin.h"

int Admin::counter = 1;

Admin::Admin()
{

	string user;
	string pass;
	Id = counter;
	counter++;
	cout << "enter username: ";
	cin >> Username;
	cout << "enter pass: ";
	cin >> Password;
}
