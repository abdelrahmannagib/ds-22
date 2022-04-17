#include "System.h"

System::System() {
	/// we could make a loop to ask again?
	
	int n;
	cout << "enter 1 to creat room , press 2 to creat garage : ";
	cin >> n;
	if (n == 1) {
		Showroom s;
		sysRoom.push_back(s);
	}
	else if(n==2)
	{
		garage g;
		sysGarage.push_back(g);
	}
	else
	{
		cout << "ERROR!"<<endl;
		//break from the loop
	}
	cout << "Enter 1 for admin or 2 for customer : ";
	cin >> n;
	if (n == 1) {
		goto_Admin();
	}
	else if (n == 2) {
		
	}
	else
	{
		cout << "ERROR!"<<endl;
	}
}
void System::goto_Admin() {
	int n;
	cout << "New Admin press (1) , press (2) if your old : ";
	cin >> n;
	if (n == 1) {
		Admin A;
		sysAdmin.push_back(A);
	}
	else if (n == 2)
	{

		for (int i = 0; i < sysRoom.size(); i++)
		{
			int x;
			cout << "=========Room info============" << endl;
			cout << "ID :" << sysRoom[i].ID << endl;
			cout << "Name :" << sysRoom[i].Name << endl;
			cout << "Location :" << sysRoom[i].Location << endl;
			cout << "Phone :" << sysRoom[i].Phone << endl;
			cout << "Add Car press(1),press any button to skip :";
			cin >> x;
			if (x == 1)
			{
				cout << "====Car info======" << endl;
				sysRoom[i].AddCar();
			}
			else
			{
				break;
			}
		}

	}
	else
	{
		cout << "ERROR!" <<endl;
	}
	int AccessGarage;
	cout << "press(1) to show your garage : ";
		cin >> AccessGarage;
		if (AccessGarage == 1) {
			goto_Garage();
	    }
		else
		{
			cout << "ERROR!" <<endl;
		}
}
	
void System::goto_Garage() {
	for (int i = 0; i < sysGarage.size(); i++)
	{
		cout << "======Garage info======" << endl;
		cout << "ID :" <<sysGarage[i].id << endl;
		cout << "Location :" << sysGarage[i].location << endl;
		cout << "Name :" << sysGarage[i].name << endl;
		cout << "Phone :" << sysGarage[i].phone_number << endl;

	}
}
