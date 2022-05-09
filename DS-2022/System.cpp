#include "System.h"
#include<fstream>
#include<string>
System::System() {
	/// we could make a loop to ask again?
	insert_rooms_of_garage_to_file();
	//cout<<sysRoom[0].Name;
	int n;
	cout << "enter 1 to creat room , press 2 to creat garage : ";
	cin >> n;
	if (n == 1) {
		Showroom s;
		sysRoom.push_back(s);
	}
	else if (n == 2)
	{
		garage g;
		sysGarage.push_back(g);
	}
	else
	{
		cout << "ERROR!" << endl;
		//break from the loop
	}
	/*sysRoom[0].AddCar();
	cout << "Enter 1 for admin or 2 for customer"<<endl;
	cin >> n;
	if (n == 1)
	{
		goto_Admin();
	}
	else if (n == 2)
	{
		goto_customer();
	}
	*/

}
void System::goto_customer()
{
	int n;
	cout << "press 1 for new customer or 2 for exist" << endl;
	cin >> n;
	if (n == 1)
	{
		customer c;
		syscustomers.push_back(c);
	}
	else if (n == 2)
	{
		for (int i = 0; i < sysRoom.size(); i++)
		{
			cout << sysRoom[i].Name << endl;
			int carsof_rooms = sysRoom[i].AvalibleCAr.size();
			for (int j = 0; j < carsof_rooms; j++)
			{
				cout << i<<" " << sysRoom[i].AvalibleCAr[j].model << endl;
			}
			cout << "press 1 to buy a car or 2 to see other rooms" << endl;
			int choose;
			cin >> choose;
			if (choose == 1)
			{
				cout << "Enter number of choosed car" << endl;
				cin >> n;
				// we need to edit id
				buy_rent buy(5,sysRoom[i].AvalibleCAr[n]);
			}
			else if(choose==2)
			{
				continue;
			}
		}
		cout << "That's all cars we have" << endl;
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
		cout << "ERROR!" << endl;
	}
	int AccessGarage;
	cout << "press(1) to show your garage : ";
	cin >> AccessGarage;
	if (AccessGarage == 1) {
		goto_Garage();
	}
	else
	{
		cout << "ERROR!" << endl;
	}
}

void System::goto_Garage() {
	for (int i = 0; i < sysGarage.size(); i++)
	{
		cout << "======Garage info======" << endl;
		cout << "ID :" << sysGarage[i].id << endl;
		cout << "Location :" << sysGarage[i].location << endl;
		cout << "Name :" << sysGarage[i].name << endl;
		cout << "Phone :" << sysGarage[i].phone_number << endl;

	}
}
// from file to vector
void System::insert_rooms_of_garage_to_file() {

	fstream sroom;
	char car_id[70];
	char name[70];
	char location[70];
	char phone[70];
	sroom.open("showroom.txt", ios::in);
	while (!sroom.eof()) {
		sroom.getline(car_id, 70, ' ');
		sroom.getline(name, 70, ' ');
		sroom.getline(location, 70, ' ');
		sroom.getline(phone, 70, ' ');
		Showroom sss(name,location,phone);
		sysRoom.push_back(sss);
	}
}