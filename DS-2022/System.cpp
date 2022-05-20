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
	 while (true)
	 {


		 cout << "Enter 1 for admin, 2 for customer, 3 to stop program " << endl;
		 cin >> ad_or_cust;
		 if (ad_or_cust == 1)
		 {
			 goto_Admin();
		 }
		 else if (ad_or_cust == 2)
		 {
			 goto_customer();
		 }
		 else if (ad_or_cust == 3)
		 {
			 break;
		 }
	 }

}
void System::goto_customer()
{
	int n,num,num2;
	int choice;
	int choose;
	int choose2;
	while (true)
	{
		bool found_customer = false;
		string custmername;
		cout << "press 1 for new customer or 2 for exist" << endl;
		cin >> n;
		if (n == 1)
		{
			customer c;
			syscustomers.push_back(c);
			found_customer = true;
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
						found_customer = true;
						break;
					}
					else
					{
						cout << "Wrong password try agian" << endl;
						i--;
					}
				}
			}
		}
		else
		{
			cout << "Try to login again";
		}
		if (found_customer)
			break;
	}
	/////////////////////////////////////////////////
	
	while (true)
	{
		int ch;
		cout << "-Press 1 to go to shoowroom" << endl;
		cout << "-Press 2 to go to garage" << endl;
		cout << "-Press 3 to search for a car" << endl;
		cout << "-Press 4 to search for a service" << endl;
		cout << "-Press 5 to search for a showroom" << endl;
		cout << "-Press 6 to search for a garage" << endl;
		cout << "-Press 7 to exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < sysRoom.size(); i++)
			{
				cout <<"Name of showroom: " << sysRoom[i].Name << endl;
				for (int j = 0; j < sysRoom[i].AvalibleCAr.size(); j++)
				{
					cout << "(" << j + 1 <<")" << endl;
					sysRoom[i].AvalibleCAr[j].ShowCarData();
				}
				while (true)
				{


					cout << "press 1 to buy or rent a car, 2 to see other rooms:" << endl;
					cin >> choose;
					if (choose == 1)
					{
						cout << "press 1 to buy, 2 to rent: ";
						cin >> ch;
						if (ch == 1)
						{
							cout << "Enter number of choosen car: " << endl;
							cin >> num;
							sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + num);
							cout << "Car is sold." << endl;
							break;
						}
						else if (ch == 2)
						{
							cin >> num;
							sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + num);
							cout << "Enter number of choosen car: " << endl;
							cout << "Car is rented" << endl;
							break;
						}

					}
					else if (choose == 2)
					{
						break;
					}
					else
					{
						cout << "Invalid, please enter a valid choice." << endl;
					}

				}
			}
			cout << "That's all cars we have" << endl;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < sysGarage.size(); i++)
			{
				cout <<"Name : " << sysGarage[i].name << endl;
				for (int j = 0; j < sysGarage[i].gar_services.size(); j++)
				{
					sysGarage[i].gar_services[j].ShowServiceData();

				}
				while (true)
				{


					cout << "press 1 to choose service, 2 to see other garages, 3 to exit" << endl;

					cin >> choose2;
					if (choose2 == 1)
					{
						if (sysGarage[i].gar_services.size() > 0) {
							cout << "Enter number of choosen service: " << endl;
							cin >> n;
							if (n >= 0 && n < sysGarage[i].gar_services.size()) {
								sysGarage[i].gar_services.erase(sysGarage[i].gar_services.begin(), sysGarage[i].gar_services.begin() + n);
							}
							else {
								cout << "Invalid, please enter a valid choice." << endl;;
								/*i--;*/
							}
						}
					}
					else if (choose2 == 2)
					{
						continue;
					}
					else if (choose2 == 3)
					{
						break;
					}
					else
					{
						cout << "Invalid, please enter a valid choice" << endl;
					}
				}
			}
			cout << "That's all services we have" << endl;
		}
		else if (choice == 3)
		{
			search_car();
		}
		else if (choice == 4)
		{
			SearchForService();
		}
		else if (choice == 5)
		{
			search_Showrrom();
		}
		else if (choice == 6)
		{
			SearchForGarage();
		}
		else if (choice == 7)
		{
			break;
		}
		else
		{
			cout << "Invalid number, please enter a valid number.";
		}
	}
}



void System::goto_Admin() {
	int n;
	string user;
	int x;
	int input;
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
	while (true)
		{
			cout << "Welcome " << user << " press 1 for showrooms, 2 for garage, 3 to exit" << endl;
			cin >> x;
			if (x == 1)
			{	
				
					

					while (true)
					{
						cout << "Press 1 to Add showroom, 2 to Edit, 3 to Delete, 4 to show a showroom, 5 to exit: ";
						cin >> input;
						if (input == 1) // add showroom
						{
							Showroom ShowNew;
							sysRoom.push_back(ShowNew);

						}
						else if (input == 2) // edit showroom
						{
							int roomNo=0;
							int number=0;
							for (int i = 0; i < sysRoom.size(); i++)
							{
								sysRoom[i].ShowShowRoomData();
							}
							while (true)
							{


								cout << "press 1 to edit showroom, 2 to edit car, 3 to exit: " << endl;
								cin >> number;
								if (number == 1)
								{
									cout << "Which Room do you want to edit in?" << endl;
									cin >> roomNo;
									sysRoom[roomNo].EditShowRoom();

								}
								else if (number == 2)
								{
									int RoomNo=0, CarNo=0;
									cout << "enter showroom number and car number: " << endl;
									sysRoom[RoomNo].EditCar(CarNo);
								}
								else if (number == 3)
								{
									break;
								}
								else
								{
									cout << "Invalid number, please enter  a valid number" << endl;
								
								}
							}

						}
						else if (input == 3) // delete showroom
						{
							int n1=0;
							int n2=0;
							for (int i = 0; i < sysRoom.size(); i++)
							{
								sysRoom[i].ShowShowRoomData();
							}
							while (true)
							{


								cout << "Press 1 to delete a showroom, 2 to delete a car, 3 to exit: " << endl;
								cin >> n1;
								if (n1 == 1)
								{
									cout << "Which ShowRoom do you want to delete?" << endl;
									cin >> n2;
									sysRoom.erase(sysRoom.begin(), sysRoom.begin() + n2);
								}
								else if (n1 == 2)
								{
									int s1=0, car1=0;
									cout << "enter showroom number and car number:  " << endl;
									cin >> s1, car1;
									sysRoom[s1].AvalibleCAr.erase(sysRoom[s1].AvalibleCAr.begin(), sysRoom[s1].AvalibleCAr.begin() + car1);
								}
								else if (n1 == 3)
								{
									break;
								}
								else
								{
									cout << "Invalid number, please select a valid number." << endl;
								}

							}

						}
						else if (input == 4)
						{
							for (int i = 0; i < sysRoom.size(); i++)
							{
								sysRoom[i].ShowShowRoomData();
							}
						}
						else if (input == 5)
						{
							break;
						}
						else
						{
							cout << "Wrong number, please enter a valid number.";
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
			else if (x == 3)
			{
				break;
			}
			else
			{
				cout << "ERROR!" << endl;
			}
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

void System::SearchForGarage()
{
	string sG;
	int garageId;
	int ch2;
	int serviceTobuy;
	for (int i = 0; i < sysGarage.size(); i++)
	{
		GarageSearch[sysGarage[i].name].first = true;
		GarageSearch[sysGarage[i].name].second = i;
	}
	cout << "Enter the name of garage you want to search: ";
	cin >> sG;
	if (GarageSearch[sG].first == true)
	{
		cout << "Found" << endl;
		garageId = GarageSearch[sG].second;
		for (int i = 0; i < sysGarage[garageId].gar_services.size(); i++)
		{
			sysGarage[garageId].gar_services[i].ShowServiceData();
		}
		cout << "Press 1 to buy, 2 to exit: ";
		cin >> ch2;
		if (ch2 == 1)
		{
			cout << "Enter number of choosen service: ";
			cin >> serviceTobuy;

			sysGarage[garageId].gar_services.erase(sysGarage[garageId].gar_services.begin(), sysGarage[garageId].gar_services.begin()+serviceTobuy);
		}

	}
	else
		cout << "Not Found." << endl;
}
void System::SearchForService()
{
	string ser;
	int buy;
	int gar, s;
	for (int i = 0; i < sysGarage.size(); i++)
	{
		for (int j = 0; j < sysGarage[i].gar_services.size(); j++)
		{
			string m = sysGarage[i].gar_services[j].name;
			ServiceFound[m] = true;
			ServiceGarageId[m].first = i;
			ServiceGarageId[m].second = j;
		}
	}
	cout << "Enter the name of service you want to search: ";
	cin >> ser;
	if (ServiceFound[ser])
	{
		cout << "Press 1 to buy: ";
		cin >> buy;
		if (buy == 1)
		{
			gar = ServiceGarageId[ser].first;
			s = ServiceGarageId[ser].second;

			sysGarage[gar].gar_services.erase(sysGarage[gar].gar_services.begin(), sysGarage[gar].gar_services.begin()+s);
			cout << "service is sold.";
		}
	}
}
void System::search_Showrrom()
{
	for (int i = 0; i < sysRoom.size(); i++)
	{
		Showroom_search[sysRoom[i].Name].first = true;
		Showroom_search[sysRoom[i].Name].second = i;
	}
	cout << "Enter the name of garge you want to search"<<endl;
	string se;
	cin >> se;
	int roomid;
	if (Showroom_search[se].first == true)
	{
		cout << "Found" << endl;
		roomid = Showroom_search[se].second;
		for (int j = 0; j < sysRoom[roomid].AvalibleCAr.size(); j++)
		{
			cout << j << " " << sysRoom[roomid].AvalibleCAr[j].model << endl;
		}
		cout << "press 1 to buy a car or 2 to back" << endl;
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			int car_tobuy;
			cout << "Enter number of choosed car" << endl;
			cin >> car_tobuy;
			sysRoom[roomid].AvalibleCAr.erase(sysRoom[roomid].AvalibleCAr.begin(), sysRoom[roomid].AvalibleCAr.begin() + car_tobuy);
		}
	}
	else
		cout << "NOt found" << endl;
}
void System::search_car() {
	/*
	map<string, bool> car_found;
	map<string, pair<int, int>> car_room_ids;
	*/
	for (int i = 0; i < sysRoom.size(); i++)
	{
		for (int j = 0; j < sysRoom[i].AvalibleCAr.size(); j++)
		{
			string m= sysRoom[i].AvalibleCAr[j].make;
			car_found[m] = true;
			car_room_ids[m].first = i;
			car_room_ids[m].second = j;
		}
	}
	cout << "Enter the name of car you want to search" << endl;
	string se;
	cin >> se;
	if (car_found[se])
	{
		// show car data and ask to buy

		cout << "Press 1 if you want to buy else press any button" << endl;
		int c;
		cin >> c;
		if (c == 1)
		{
			int g, ca;
			g = car_room_ids[se].first;
			ca = car_room_ids[se].second;
			// sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + n);
			sysRoom[g].AvalibleCAr.erase(sysRoom[g].AvalibleCAr.begin(), sysRoom[g].AvalibleCAr.begin() + ca);
			cout << "Buy done" << endl;
		}
	}
}

