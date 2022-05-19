#include "System.h"
#include<fstream>
#include<string>
System::System() {
	// insert showrooms
	insert_rooms_of_garage_to_file();
	insert_admins_from_files();
	 insert_cars_from_files();
	 insert_customer_from_files();
	 maptest();
	//cout<<sysRoom[0].Name;
	// sysRoom[0].AddCar();
	/*cout << sysAdmin.size() << endl;
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
	 int ad_or_cust;
	cout << "Enter 1 for admin or 2 for customer"<<endl;
	cin >> ad_or_cust;
	if (ad_or_cust == 1)
	{
		goto_Admin();
	}
	else if (ad_or_cust == 2)
	{
		goto_customer();
	}
	

}
void System::goto_customer()
{
	int n;
	while (true)
	{
		bool found_custeomer = false;
		string custmername;
		cout << "press 1 for new customer or 2 for exist" << endl;
		cin >> n;
		if (n == 1)
		{
			customer c;
			syscustomers.push_back(c);
			found_custeomer = true;
		}
		else if (n == 2)
		{
			//check the name and pass
			cout << "Enter your user name : ";
			cin >> custmername;
			for (int i = 0; i < syscustomers.size(); i++)
			{
				if (syscustomers[i].username == custmername)
				{
					string customerpass;
					cout << "Enter youe password : ";
					cin >> customerpass;
					if (syscustomers[i].pass == customerpass)
					{
						found_custeomer = true;
						break;
					}
					else
					{
						cout << "Wrong password try agian" << endl;
						i --;
					}
				}
			}
		}
		else
		{
			cout << "Try to login again";
		}
		if (found_custeomer)
			break;
	}
		/////////////////////////////////////////////////
		for (int i = 0; i < sysRoom.size(); i++)
		{
			cout << sysRoom[i].Name << endl;
			int carsof_rooms = sysRoom[i].AvalibleCAr.size();
			for (int j = 0; j < carsof_rooms; j++)
			{
				cout << j << " " << sysRoom[i].AvalibleCAr[j].model << endl;
			}
			cout << "press 1 to buy a car or 2 to see other rooms" << endl;
			int choose;
			cin >> choose;
			if (choose == 1)
			{
				cout << "Enter number of choosed car" << endl;
				cin >> n;
				sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + n);
			}
			else if (choose == 2)
			{
				continue;
			}
		}
		cout << "That's all cars we have" << endl;
}


void System::goto_Admin() {
	int n;
	string user;
	while (true)
	{
		cout << "New Admin press 1 or press 2 for old admin : \n ";
		cin >> n;
		if (n == 1) {
			Admin A;
			sysAdmin.push_back(A);
			break;
		}
		else if (n == 2)
		{
			bool admin_found = false;
			cout << "Enter your username : ";
			cin >> user;
			for (int i = 0; i < sysAdmin.size(); i++)
			{
				if (sysAdmin[i].Username == user)
				{
					string pass;
					cout << "Enter your pass" << endl;
					cin >> pass;
					if (sysAdmin[i].Password == pass)
					{
						admin_found = true;
						break;
					}
					else
					{
						cout << "Wrong pass please try again" << endl;
						i --;

					}
				}
			}
			if (admin_found)
				break;
		}

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
				i--;
			}
			else
			{
				continue;
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
	bool garage_flag=true;
	while (garage_flag == true)
	{
		cout << "enter 1 to add garage" << endl;
		cout << "enter 2 to edit garage" << endl;
		cout << "enter 3 to delete garage" << endl;
		cout << "enter 4 if you want to exit";
		int y;
		cin >> y;
		if (y == 1) {
			garage g;
			sysGarage.push_back(g);
		}
		else if (y == 2) {
			for (int i = 0; i < sysGarage.size(); i++)
			{
				char choice;
				cout << "======Garage info======" << endl;
				cout << "ID :" << sysGarage[i].id << endl;
				cout << "Location :" << sysGarage[i].location << endl;
				cout << "Name :" << sysGarage[i].name << endl;
				cout << "Phone :" << sysGarage[i].phone_number << endl;
				cout << "if do you want to edit it or add a service press x ";
				cin >> choice;
				if (choice == 'x' || choice == 'X')
				{
					sysGarage[i].edit_garage();
				}
			}
		}
		else if (y == 3)
		{
			cout << "Enter a number between 0 and " << sysGarage.size() - 1 << endl;
			int del_garage;
			cin >> del_garage;
			if (y >= 0 && y < sysGarage.size())
			{
				// 				sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + n);
				sysGarage.erase(sysGarage.begin(), sysGarage.begin() + del_garage);
			}
			else
			{
				cout << "Try again";
				continue;
			}
		}
		else if (y== 4)
		{
			garage_flag = false;
		}
		else {
			cout << "enter correct number";
		}

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
void System::insert_cars_from_files()
{
	fstream fcars;
	char fcar_id[70];
	char fcar_make[70];
	char fcar_model[70];
	char fcar_year[70];
	char fcar_price[70];
	char fcar_instt[70];
	char fcar_g[70];
	int gar=0;
	fcars.open("cars.txt", ios::in);
	while (!fcars.eof())
	{
		fcars.getline(fcar_id, 70, ' ');
		fcars.getline(fcar_make, 70, ' ');
		fcars.getline(fcar_model, 70, ' ');
		fcars.getline(fcar_instt, 70, ' ');
		fcars.getline(fcar_year, 70, ' ');
		fcars.getline(fcar_price, 70, ' ');
		fcars.getline(fcar_g, 70);
	//	string ssss = fcar_g;
	//	gar = stoi(ssss);
		fstream fcars;
		gar=map_rooms[fcar_g];
			//	fcars << id << " " << make << " " << model << " " << install << " " << year << " " << price << " " << g << endl;
				car xc(fcar_make, fcar_model, fcar_instt, fcar_year, fcar_price);
				 sysRoom[gar].AvalibleCAr.push_back(xc);
			
		
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
		customer cust(customer_username, customer_pass);
		syscustomers.push_back(cust);
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
void System::maptest()
{
	for (int i = 0; i < sysRoom.size(); i++)
	{
		string keyy = to_string(i);
		map_rooms[keyy] = i;
	}
}