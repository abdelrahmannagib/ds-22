#include "Admin.h"
#include<fstream>
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
	fstream admin;
	/*char admin_id[70];
	char username[70];
	char password[70];
	*/
	admin.open("admin.txt", ios::app);
	admin << Id << " " << Username << " " << Password << endl;
}
Admin::Admin(string s1, string s2)
{
	Id = counter;
	counter++;
	Username = s1;
	Password = s2;
}
