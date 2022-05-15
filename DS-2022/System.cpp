#include "System.h"
#include<fstream>
#include<string>
System::System() {
	// insert showrooms
	insert_rooms_of_garage_to_file();
	insert_admins_from_files();
	//cout<<sysRoom[0].Name;
	cout << sysAdmin.size() << endl;
	for (int i = 0; i < sysRoom.size(); i++)
	{
		cout << sysAdmin[i].Username << " " << sysAdmin[i].Password << endl;
	}
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
	 */
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
	string user;
	cout << "New Admin press (1) , press (2) if your old : ";
	cin >> n;
	if (n == 1) {
		Admin A;
		sysAdmin.push_back(A);
	}
	else if (n == 2)
	{
		bool found_admin = false;
		cin >> user;
		for (int i = 0; i < sysAdmin.size(); i++)
		{
			if (sysAdmin[i].Username == user)
			{
				string pass;
				cout << "Enter your pass" << endl;
				cin >> pass;
				if (sysAdmin[i].Password == pass)
					found_admin = true;
				else
				{
					cout << "Wrong pass please try again"<<endl;
					i = -1;
				}
			}
		}
		if (!found_admin)
		{
			cout << "User not found Try again" << endl;
			goto_Admin();
		}
	
	}
	else
	{
		cout << "ERROR!" << endl;
	}
	int x;
	cout << "Welcome " << user << " press 1 for showrooms or 2 for garage" << endl;
	cin >> x;
	if (x == 1)
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
	else if (x == 2)
	{
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
// from file to vector of rooms
void System::insert_rooms_of_garage_to_file() {

	fstream sroom;
	char room_id[70];
	char name[70];
	char location[70];
	char phone[70];
	sroom.open("showroom.txt", ios::in);
	while (!sroom.eof()) {
		sroom.getline(room_id, 70, ' ');
		sroom.getline(name, 70, ' ');
		sroom.getline(location, 70, ' ');
		sroom.getline(phone, 70, ' ');
		Showroom sss(name,location,phone);
		sysRoom.push_back(sss);
	}
}
void System::insert_admins_from_files()
{
	fstream fadmin;
	char fadmin_id[70];
	char fusername[70];
	char fpassword[70];
	fadmin.open("admin.txt", ios::in);
	while (!fadmin.eof())
	{
		fadmin.getline(fadmin_id, 70, ' ');
		fadmin.getline(fusername, 70, ' ');
		fadmin.getline(fpassword, 70);
		// ------------
		Admin aa(fusername, fpassword);
		sysAdmin.push_back(aa);
	}
}
// to be edited 
void System::insert_cars_from_files()
{
	fstream fcars;
	char fcar_id[70];
	char fcar_make[70];
	char fcar_model[70];
	char fcar_year[70];
	char fcar_price[70];
	char fcar_instt[70];
	fcars.open("cars.text", ios::in);
	while (!fcars.eof())
	{
		fcars.getline(fcar_id, 70, ' ');
		fcars.getline(fcar_make, 70, ' ');
		fcars.getline(fcar_model, 70, ' ');
		fcars.getline(fcar_year, 70, ' ');
		fcars.getline(fcar_price, 70, ' ');
		fcars.getline(fcar_instt, 70, ' ');

	}
}
void System::insert_services_from_files()
{
	fstream fservice;
	char fservice_id[70];
	char fservice_name[70];
	char fservice_price[70];
	fservice.open("service.txt", ios::in);
	while (!fservice.eof())
	{
		fservice.getline(fservice_id, 70, ' ');
		fservice.getline(fservice_name, 70, ' ');
		fservice.getline(fservice_price, 70);

		service service(fservice_name, fservice_price);
		sysService.push_back(service);
	}
}
void System::insert_customer_from_files()
{
	fstream customerf;
	char customer_id[70];
	char customer_username[70];
	char customer_pass[70];
	customerf.open("customer.txt", ios::in);
	while (!customerf.eof())
	{
		customerf.getline(customer_id, 70, ' ');
		customerf.getline(customer_username, 70, ' ');
		customerf.getline(customer_pass, 70);
		
		customer customer(customer_username, customer_pass);
		syscustomers.push_back(customer);
	}
}
void System::insert_process_from_file()
{
	fstream fprocess;
	char fprocess_id[70];
	char fcar_id[70];
	char fdate[70];
	char fmoney[70];
	char fchosen_service[70];
	fprocess.open("process.txt", ios::in);
	while (!fprocess.eof())
	{

		fprocess.getline(fprocess_id, 70, ' ');
		fprocess.getline(fcar_id, 70, ' ');
		fprocess.getline(fdate, 70, ' ');
		fprocess.getline(fmoney, 70, ' ');
		fprocess.getline(fchosen_service, 70);




	}



}