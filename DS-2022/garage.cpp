#include "garage.h"
#include"service.h"
#include<fstream>
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
	fstream garagee;

	garagee.open("garagee.txt", ios::app);
	garagee <<id << " " << name << " " << location << " " << phone_number << endl;

}

garage::garage(string s1, string s2, string s3)
{
	id = count_garage;
	name = s1;
	location = s2;
	phone_number = s3;
	count_garage++;
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
void garage::showGarageData()
{
	cout << "======Garage info======" << endl;
	cout << "ID: " << id << endl;
	cout << "Location: " << location << endl;
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone_number << endl;

	cout << "======== Services ========" << endl;
	for (int i = 0; i < gar_services.size(); i++)
	{
		cout << "Service's Name: " << gar_services[i].name  << endl;
		cout << "Service's Price: " << gar_services[i].price << endl;
	}
	
}
void garage::edit_garage() {
	bool edittt = true;
	while (edittt)
	{
		cout << "press 1 to edit name" << endl;
		cout << "press 2 to edit location" << endl;
		cout << "press 3 to edit phone" << endl;
		cout << "press 4 for services " << endl;
		cout << "press 5 to exit" << endl;
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
			cout << "Press 1 to add a service , 2 for edit a service , 3 to delete a service ";
			int y;
			cin >> y;
			if (y == 1)
			{
				string g_id = to_string(id);
				service s_new(g_id);
				gar_services.push_back(s_new);
			}
			else if (y == 2)
			{
				for (int i = 0; i < gar_services.size(); i++)
				{
					cout << i << " " << gar_services[i].name << " " << gar_services[i].price << endl;
				}
				cout << "Enter the number of service you want to edit";
				int hh;
				cin >> hh;
				if (hh >= 0 && hh < gar_services.size())
				{
					gar_services[hh].Edit();
				}
				else
				{
					continue;
				}
			}
			else if (y == 3)
			{
				cout << "Enter the service you want to delete : ";
				int hh;
				cin >> hh;
				if (hh >= 0 && hh < gar_services.size())
				{
					gar_services.erase(gar_services.begin(), gar_services.begin() + hh);
				}
				else
				{
					cout << "TRY again garage not found";
				}
			}
		}
		else if (x == 5)
		{
			break;

		}
		else 
		{
			cout << "Invalid, please enter a valid number." << endl;
		}
	}
}
