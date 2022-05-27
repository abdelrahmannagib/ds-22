#include "System.h"
#include<fstream>
#include<string>
#include<utility>

System::System() {
	// insert showrooms
	
	insert_admins_from_files();
	insert_customer_from_files();
	insert_rooms_of_garage_to_file();
	insert_garage_from_file();
     maptest();
	 insert_cars_from_files();
	 insert_services_from_files();
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
	else if (n == "2")
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

	// cout << "Gargee  " << sysGarage.size() << endl;
	 string ad_or_cust;
	 while (true)
	 {


		 cout << "Enter 1 for admin, 2 for customer, 3 to stop program " << endl;
		 cin >> ad_or_cust;
		 if (ad_or_cust == "1")
		 {
			 goto_Admin();
		 }
		 else if (ad_or_cust == "2")
		 {
			 goto_customer();
		 }
		 else if (ad_or_cust == "3")
		 {
			 break;
		 }
		 else {
			 cout << "enter a valid number please";
		 }
	 }

}
void System::goto_customer()
{
	int n, num;
	string new_choice;
	string choice;
	string choose;
	string choose2;
	string current_cust_id;
	bool found_customer = false;
	while (true)
	{
		string custmername;
		cout << "press 1 for new customer , 2 for exist or 3 to exit " << endl;
		cin >> new_choice;
		if (new_choice == "1")
		{
			customer c;
			current_cust_id = c.ID;
			syscustomers.push_back(c);
			found_customer = true;
		}
		else if (new_choice == "2")
		{
			//check the name and pass
			cout << "Enter your user name : ";
			cin >> custmername;
			for (int i = 0; i < syscustomers.size(); i++)
			{
				if (syscustomers[i].username == custmername)
				{
					current_cust_id = syscustomers[i].ID;
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
		else if (new_choice == "3")
		{
			break;
		}
		else
		{
			cout << "Try to login again"<<endl;
		}
		if (found_customer)
			break;
	}
	/////////////////////////////////////////////////

	while (true&&found_customer)
	{
		string ch;
		int c;

		int resORbuy;
		cout << "-Press 1 to go to shoowroom" << endl;
		cout << "-Press 2 to go to garage" << endl;
		cout << "-press 3 to search" << endl;		
		cout << "-Press 4 to exit" << endl;
		cin >> choice;
		if (choice == "1")
		{
			for (int i = 0; i < sysRoom.size(); i++)
			{
				cout << "Name of showroom: " << sysRoom[i].Name << endl;
				for (int j = 0; j < sysRoom[i].AvalibleCAr.size(); j++)
				{
					if (sysRoom[i].AvalibleCAr[j].appear == true)
					{
						cout << j << endl;
						sysRoom[i].AvalibleCAr[j].ShowCarData();
					}
					
				}
				while (true)
				{
					int buyres;
					string roomId;
					string carPrice;
					int carId;
					cout << "press 1 to buy or rent a car, 2 to see other rooms, 3 to show your reserved cars:" << endl;
					cin >> choose;
					if (choose == "1")
					{
						cout << "press 1 to buy or reserve, 2 to rent,3 to exit: ";
						cin >> ch;
						if (ch == "1")
						{


							cout << "Enter number of choosen car: " << endl;
							cin >> num;

							while (num < 0 && num >= sysRoom[i].AvalibleCAr.size())
							{
								cout << "Enter a valid number \n";
								cin >> num;

							}
							cout << "press 1 to immediate buy, 2 to reserve,3 to exit: " << endl;
							cin >> resORbuy;
							if (resORbuy == 1)
							{
								cout << "Price of car is: " << sysRoom[i].AvalibleCAr[num].price << endl;
								carPrice = sysRoom[i].AvalibleCAr[num].price;
								sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + num);
								cout << "Car is sold." << endl;
								buy_rent serProcess(current_cust_id, carPrice, "buy");
								history_cust[current_cust_id].push_back(serProcess);
								break;
							}
							else if (resORbuy == 2)
							{
								sysRoom[i].AvalibleCAr[num].appear = false;
								reserveCar(current_cust_id, sysRoom[i].AvalibleCAr[num]);
								cout << "reservation is done." << endl;
							}
							else if (resORbuy == 3)
							{
								break;
							}
							else {
								cout << "Invalid, please enter a valid number." << endl;
							}
						}
						else if (ch == "2")
						{
							cout << "Enter number of choosen car: " << endl;
							cin >> num;
							string carInstall = sysRoom[i].AvalibleCAr[num].install;
							cout << "Car Installment is: " << carInstall << endl;
						//	sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + num);
							cout << "Car is rented" << endl;
							buy_rent serProcess(current_cust_id, carInstall, "rent");
							history_cust[current_cust_id].push_back(serProcess);
							break;
						}
						else if (ch == "3")
						{
							break;
						}

					}
					else if (choose == "2")
					{
						break;
					}
					else if (choose == "3")
					{
						for (int i = 0; i < reservedCar[current_cust_id].size(); i++)
						{
							cout << i << endl;
							reservedCar[current_cust_id][i].ShowCarData();

							roomId = reservedCar[current_cust_id][i].belong;
							carId = reservedCar[current_cust_id][i].id;
							carPrice = reservedCar[current_cust_id][i].id;

							cout << "-----------------------------------------------" << endl;
							cout << "note: if you don't buy the car now, the reserve will be cancelled." << endl;
							cout << "-----------------------------------------------" << endl;
							cout << "press 1 to buy car, 2 to exit: " << endl;
							cin >> buyres;
							if (buyres == 1)
							{		
								buy_rent serProcess(current_cust_id, carPrice, "buy");
								history_cust[current_cust_id].push_back(serProcess);
								sellOrCancel(roomId, carId, 1);
							}
							else if (buyres == 2)
							{	
								sellOrCancel(roomId, carId, 2);
							}
							else
							{
								cout << "Invalid,please enter a valid number." << endl;
							}
						}
					}
					else
					{
						cout << "Invalid, please enter a valid choice." << endl;
					}

				}
			}
			cout << "That's all cars we have" << endl;
		}
		else if (choice == "2")
		{
			for (int i = 0; i < sysGarage.size(); i++)
			{
				cout << "Name : " << sysGarage[i].name << endl;
				for (int j = 0; j < sysGarage[i].gar_services.size(); j++)
				{
					sysGarage[i].gar_services[j].ShowServiceData();

				}
				while (true)
				{


					cout << "press 1 to choose service, 2 to see other garages, 3 to exit" << endl;

					cin >> choose2;
					if (choose2 == "1")
					{
						if (sysGarage[i].gar_services.size() > 0) {
							cout << "Enter number of choosen service: " << endl;
							cin >> n;
							while (n < 0 && n >= sysGarage[i].gar_services.size())
							{

								cout << "Enter a valid choice  \n";
								cin >> n;
							}
							string serPrice = sysGarage[i].gar_services[n].price;
							string serName = sysGarage[i].gar_services[n].name;
							buy_rent proc(current_cust_id, serPrice, serName);
							history_cust[current_cust_id].push_back(proc);
							cout << "Service done !!!! \n";


						}
						else if (choose2 == "2")
						{
							continue;
						}
						else if (choose2 == "3")
						{
							break;
						}
						else {
							cout << "enter a valid number"<<endl;
						}

					}
					else if (choose2 == "2")
					{
						continue;
					}
					else if (choose == "3")
					{
						break;
					}
					else
					{
						cout << "Invalid, please enter a valid number." << endl;
					}
				}
				cout << "That's all services we have" << endl;
			}
		}
		else if (choice == "3")
		{
			while (true)
			{


				cout << "======== Search Options ========" << endl;
				cout << "-Press 1 to search for a car" << endl;
				cout << "-Press 2 to search for a service" << endl;
				cout << "-Press 3 to search for a showroom" << endl;
				cout << "-Press 4 to search for a garage" << endl;
				cout << "press 5 to exit" << endl;
				cin >> c;
				if (c == 1)
				{
					search_car(current_cust_id);
				}
				else if (c == 2)
				{
					SearchForService(current_cust_id);
				}
				else if (c == 3)
				{
					search_Showrrom(current_cust_id);
				}
				else if (c == 4)
				{
					SearchForGarage(current_cust_id);
				}
				else if (c == 5)
				{
					break;
				}
				else
				{
					cout << "Invalid, please enter a valid number." << endl;
				}
			}
		}
		else if (choice == "4")
		{
			cout << "-----------------------------" << endl;
			cout << "History: " << endl;

			for (int i = 0; i < history_cust[current_cust_id].size(); i++)
			{
				cout << " =>  " << history_cust[current_cust_id][i].choosen_service << endl;
			}
			break;
		}
		else
		{
			cout <<  " enter a valid number."<<endl<<endl;
		}
	}
}
void System::goto_Admin() {
	string n;
	string user;
	int x;
	int input;
	bool admin_found = false;

	while (true)
	{
		cout << "New Admin press 1 or press 2 for old admin or 3 to go back : \n ";
		cin >> n;
		if (n == "1") {
			Admin A;
			sysAdmin.push_back(A);
			admin_found = true;
			break;
		}
		else if (n == "2")
		{
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
						i--;

					}
				}
			}
			if (admin_found)
				break;
		}
		else if (n == "3")
			break;

	}
	while (true&&admin_found)
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
									cout << "enter the numberof the room  you want to edit in?" << endl;
									cin >> roomNo;
									sysRoom[roomNo].EditShowRoom();

								}
								else if (number == 2)
								{
									int RoomNo=0, CarNo=0;
									cout << "enter showroom number and car number: " << endl;
									
									cin >> RoomNo >> CarNo;
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
								cout <<"INDEX " << i << endl;
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
									cin >> s1>> car1;
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
				goto_Garage();
			
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
void System::goto_Garage()
{
	bool garage_flag = true;
	char choice;
	while (garage_flag == true)
	{
			cout << "enter 1 to add garage" << endl;
			cout << "enter 2 to edit garage" << endl;
			cout << "enter 3 to delete garage" << endl;
			cout << "enter 4 if you want to exit";
			string y;
			cin >> y;
			if (y == "1") {
				garage g;
				sysGarage.push_back(g);
			}
			else if (y == "2")
			{
				for (int i = 0; i < sysGarage.size(); i++)
				{
					sysGarage[i].showGarageData();
					/*cout << "======Garage info======" << endl;
					cout << "ID :" << sysGarage[i].id << endl;
					cout << "Location :" << sysGarage[i].location << endl;
					cout << "Name :" << sysGarage[i].name << endl;
					cout << "Phone :" << sysGarage[i].phone_number << endl;*/
					cout << "if do you want to edit it or add a service press (x) " << endl;
					cin >> choice;
					if (choice == 'x' || choice == 'X')
					{
						sysGarage[i].edit_garage();
					}
					else
					{
						continue;
					}
				}
			}
			else if (y == "3")
			{
				cout << "Enter a number between 0 and " << sysGarage.size() - 1 << endl;
				int del_garage;
				cin >> del_garage;
				while (del_garage < 0 && del_garage >= sysGarage.size())
				{
					cout << "Wrong input try again: ";
					cin >> del_garage;
				}
				sysGarage.erase(sysGarage.begin(), sysGarage.begin() + del_garage);

			}
			else if (y == "4")
			{
				garage_flag=false;
			}
			else
			{
				cout << "Invalid, please enter a valid number." << endl;
			}
	}
	
}
void System::insert_rooms_of_garage_to_file() {

	fstream sroom;
	/*char room_id[70];
	char name[70];
	char location[70];
	char phone[70];
	*/
	string name, room_id, location, phone;
	sroom.open("showroom.txt", ios::in);
	while (!sroom.eof()) {
		/*sroom.getline(room_id, 70, ' ');
		sroom.getline(name, 70, ' ');
		sroom.getline(location, 70, ' ');
		sroom.getline(phone, 70, ' ');
		*/
		sroom >> room_id >> name >> location >> phone;
		Showroom sss(name,location,phone);
		sysRoom.push_back(sss);
	}
	sysRoom.pop_back();
}
void System::insert_garage_from_file()
{
	fstream garagee;
	char id[70];
	char name[70];
	char location[70];
	char phone_number[70];
	garagee.open("garagee.txt", ios::in);

	while (!garagee.eof())
	{
		garagee.getline(id, 70, ' ');
		garagee.getline(name, 70, ' ');
		garagee.getline(location, 70, ' ');
		garagee.getline(phone_number, 70);
		garage gg(name, location, phone_number);
		sysGarage.push_back(gg);
	}
	sysGarage.pop_back();
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
	//	fstream fcars;
		gar=map_rooms[fcar_g];
			//	fcars << id << " " << make << " " << model << " " << install << " " << year << " " << price << " " << g << endl;
				car xc(fcar_make, fcar_model, fcar_instt, fcar_year, fcar_price,fcar_g);
				 sysRoom[gar].AvalibleCAr.push_back(xc);
			
		
	}
}
void System::insert_services_from_files()
{
	fstream fservice;
	char fservice_id[70];
	char fservice_name[70];
	char fservice_price[70];
	char fserv_g[70];
	int gar=0;
	fservice.open("service.txt", ios::in);
	while (!fservice.eof())
	{
		fservice.getline(fservice_id, 70, ' ');
		fservice.getline(fservice_name, 70, ' ');
		fservice.getline(fservice_price, 70,' ');
		fservice.getline(fserv_g, 70);
		service servicce(fservice_name, fservice_price);
		sysService.push_back(servicce);
		gar = map_garage[fserv_g];
		sysGarage[gar].gar_services.push_back(servicce);
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
	for (int i = 0; i < sysGarage.size(); i++)
	{
		string keyy = to_string(i);
		map_garage[keyy] = i;
	}
}
void System::SearchForGarage(string customerId)
{
	string sG;
	int garageId;
	int ch2;
	int ch;
	int serviceTobuy;
	for (int i = 0; i < sysGarage.size(); i++)
	{
		GarageSearch[sysGarage[i].name].first = true;
		GarageSearch[sysGarage[i].name].second = i;

		sysGarage[i].showGarageData();
	}
	
	while (true)
	{
		cout << "press 1 to search, 2 to exit: " << endl;
		cin >> ch2;
		if (ch2 == 1)
		{
			cout << "Enter the name of garage you want to search: " << endl;
			cin >> sG;
		}
		else if (ch2 == 2)
		{
			break;
		}
		else
		{
			cout << "Invalid, please enter a valid number." << endl;
		}

		if (GarageSearch[sG].first == true)
		{
			cout << "Found" << endl;
			garageId = GarageSearch[sG].second;
			for (int i = 0; i < sysGarage[garageId].gar_services.size(); i++)
			{
				sysGarage[garageId].gar_services[i].ShowServiceData();
			}
			cout << "Press 1 to buy, 2 to exit: ";
			cin >> ch;
			if (ch == 1)
			{
				cout << "Enter number of choosen service: ";
				cin >> serviceTobuy;
				string serPrice = sysGarage[garageId].gar_services[serviceTobuy].price;
				string serName = sysGarage[garageId].gar_services[serviceTobuy].name;
				buy_rent process(customerId, serPrice, serName);
				history_cust[customerId].push_back(process);
				cout << "Purchase is done." << endl;
			}
			else if (ch == 2)
			{
				break;
			}
			else
			{
				cout << "Invalid, please enter a valid number." << endl;
			}

		}
		else
			cout << "Not Found." << endl;
	}
}
void System::SearchForService(string customerId)
{
	string ser;
	int buy;
	int ch2;
	int gar, s;
	for (int i = 0; i < sysGarage.size(); i++)
	{
		for (int j = 0; j < sysGarage[i].gar_services.size(); j++)
		{
			string m = sysGarage[i].gar_services[j].name;
			ServiceFound[m] = true;
			ServiceGarageId[m].first = i;
			ServiceGarageId[m].second = j;
			
			sysGarage[i].gar_services[i].ShowServiceData();
		}
	}
	
	while (true)
	{

		cout << "press 1 to search, 2 to exit: " << endl;
		cin >> ch2;
		if (ch2 == 1)
		{
			cout << "Enter the name of service you want to search: " << endl;
			cin >> ser;
		}
		else if (ch2 == 2)
		{
			break;
		}
		else
		{

			cout << "Invalid, please enter a valid number." << endl;
		}

		if (ServiceFound[ser])
		{
			cout << "Press 1 to buy: ";
			cin >> buy;

			if (buy == 1)
			{
				gar = ServiceGarageId[ser].first;
				s = ServiceGarageId[ser].second;
				string serPrice = sysGarage[gar].gar_services[buy].price;
				string serName = sysGarage[gar].gar_services[buy].name;
				buy_rent process(customerId, serPrice, serName);
				history_cust[customerId].push_back(process);
				cout << "Purchase is done." << endl;
			}
		}
		else
			cout << "Not found." << endl;
	}
}
void System::search_Showrrom(string customerId)
{
	string se;
	int ch;
	int ch2;
	int roomid;
	int car_tobuy;
	string rId;
	int cId;
	int buyres;
	string carPrice;
	for (int i = 0; i < sysRoom.size(); i++)
	{
		Showroom_search[sysRoom[i].Name].first = true;
		Showroom_search[sysRoom[i].Name].second = i;
		
		sysRoom[i].ShowShowRoomData();
	}
	while (true)
	{
		cout << "press 1 to search, 2 to exit: " << endl;
		cin >> ch2;
		if (ch2 == 1)
		{
			cout << "enter the name of showroom you want to search:" << endl;
			cin >> se;
		}
		else if (ch2 == 2)
		{
			break;
		}
		else
		{
			cout << "Invalid, please enter a valid number." << endl;
		}

		if (Showroom_search[se].first == true)
		{
			while (true)
			{

				cout << "Found" << endl;
				roomid = Showroom_search[se].second;
				for (int j = 0; j < sysRoom[roomid].AvalibleCAr.size(); j++)
				{
					cout << j << " " << sysRoom[roomid].AvalibleCAr[j].model << endl;
				}
				cout << "press 1 to buy or reserve a car,2 to rent, 3 to show reserved car, 4 to exit: " << endl;
				int choose;
				cin >> choose;
				if (choose == 1)
				{
					cout << "Enter number of choosen car" << endl;
					cin >> car_tobuy;
					cout << "press 1 to buy now, 2 to reserve a car, 3 to exit: " << endl;
					cin >> ch;
					if (ch == 1)
					{

						cout << "Price of car is: " << sysRoom[roomid].AvalibleCAr[car_tobuy].price << endl;
						string carPrice = sysRoom[roomid].AvalibleCAr[car_tobuy].price;
						sysRoom[roomid].AvalibleCAr.erase(sysRoom[roomid].AvalibleCAr.begin(), sysRoom[roomid].AvalibleCAr.begin() + car_tobuy);
						buy_rent process(customerId, carPrice, "buy");
						history_cust[customerId].push_back(process);
						cout << "buy done" << endl;
					}
					else if (ch == 2)
					{
						sysRoom[roomid].AvalibleCAr[car_tobuy].appear = false;
						reserveCar(customerId, sysRoom[roomid].AvalibleCAr[car_tobuy]);
						cout << "reservation is done." << endl;
					}
					else if (ch == 3)
					{
						break;
					}
					else
					{
						cout << "Invalid, please enter a valid number." << endl;
					}
				}
				else if (choose == 2)
				{
					int car_tobuy;
					cout << "Enter number of choosed car" << endl;
					cin >> car_tobuy;
					string carInstall = sysRoom[roomid].AvalibleCAr[car_tobuy].install;
					cout << "Car Installment is: " << carInstall << endl;
					buy_rent process(customerId, carInstall, "rent");
					history_cust[customerId].push_back(process);
					cout << "rent done" << endl;
				}
				else if (choose == 3)
				{
					for (int i = 0; i < reservedCar[customerId].size(); i++)
					{
						cout << i << endl;
						reservedCar[customerId][i].ShowCarData();

						rId = reservedCar[customerId][i].belong;
						cId = reservedCar[customerId][i].id;
						carPrice = reservedCar[customerId][i].id;

						cout << "-----------------------------------------------" << endl;
						cout << "note: if you don't buy the car now, the reserve will be cancelled." << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "press 1 to buy car, 2 to exit: " << endl;
						cin >> buyres;
						if (buyres == 1)
						{
							buy_rent serProcess(customerId, carPrice, "buy");
							history_cust[customerId].push_back(serProcess);
							sellOrCancel(rId, cId, 1);
						}
						else if (buyres == 2)
						{
							sellOrCancel(rId, cId, 2);
						}
						else
						{
							cout << "Invalid,please enter a valid number." << endl;
						}
					}
				}
				else if (choose == 4)
				{
					break;
				}
				else
				{
					cout << "Invalid, please enter a valid number." << endl;
				}

			}
		}
		else
			cout << "Not found" << endl;
	}
}
void System::search_car(string customerId)
{
	/*
	map<string, bool> car_found;
	map<string, pair<int, int>> car_room_ids;
	*/
	string se;
	int cho;
	int ch2;
	int g, ca;
	string roomId;
	int carId;
	int buyres;
	
	string carPrice;

	for (int i = 0; i < sysRoom.size(); i++)
	{
		for (int j = 0; j < sysRoom[i].AvalibleCAr.size(); j++)
		{
			string m= sysRoom[i].AvalibleCAr[j].make;
			car_found[m] = true;
			car_room_ids[m].first = i;
			car_room_ids[m].second = j;

			sysRoom[i].AvalibleCAr[j].ShowCarData();
		}
	}

	while (true)
	{


		cout << "press 1 to search, 2 to exit: " << endl;
		cin >> ch2;
		if (ch2 == 1)
		{
			cout << "enter the make of the car you want to search:" << endl;
			cin >> se;
		}
		else if (ch2 == 2)
		{
			break;
		}
		else
		{
			cout << "Invalid, please enter a valid number." << endl;
		}
		

		g = car_room_ids[se].first;				//which showroom
		ca = car_room_ids[se].second;			//which car(index)
		carPrice = sysRoom[g].AvalibleCAr[ca].price;

		if (car_found[se])
		{
			while (true)
			{


				cout << "Press 1 if you want to buy or reserve, 2 to rent, 3 to show your reserved cars,  4 to exit:" << endl;
				int c;
				cin >> c;

				if (c == 1)
				{
					cout << "press 1 to immediate buy, 2 to reserve car, 3 to exit:" << endl;

					cin >> cho;
					if (cho == 1)
					{
						cout << "Price of car is: " << sysRoom[g].AvalibleCAr[ca].price << endl;
						// sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + n);
						sysRoom[g].AvalibleCAr.erase(sysRoom[g].AvalibleCAr.begin(), sysRoom[g].AvalibleCAr.begin() + ca);
						buy_rent process(customerId, carPrice, "buy");
						history_cust[customerId].push_back(process);
						cout << "Buy done" << endl;
						car_found[se] = false;
					}
					else if (cho == 2)
					{
						sysRoom[g].AvalibleCAr[ca].appear = false;
						reserveCar(customerId, sysRoom[g].AvalibleCAr[ca]);
						cout << "reservation is done." << endl;
					}
					else if (cho == 3)
					{
						break;
					}
					else
					{
						cout << "Invalid, please enter a valid number." << endl;
					}
				}
				else if (c == 2)
				{
					int g, ca;
					g = car_room_ids[se].first;
					ca = car_room_ids[se].second;
					string carInstall = sysRoom[g].AvalibleCAr[ca].install;
					cout << "Car Installment is: " << carInstall << endl;
					// sysRoom[i].AvalibleCAr.erase(sysRoom[i].AvalibleCAr.begin(), sysRoom[i].AvalibleCAr.begin() + n);
					buy_rent process(customerId, carInstall, "rent");
					history_cust[customerId].push_back(process);
					cout << "rent done" << endl;
				}
				else if (c == 3)
				{
					for (int i = 0; i < reservedCar[customerId].size(); i++)
					{
						cout << i << endl;
						reservedCar[customerId][i].ShowCarData();

						roomId = reservedCar[customerId][i].belong;
						carId = reservedCar[customerId][i].id;
						carPrice = reservedCar[customerId][i].id;

						cout << "-----------------------------------------------" << endl;
						cout << "note: if you don't buy the car now, the reserve will be cancelled." << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "press 1 to buy car, 2 to exit: " << endl;
						cin >> buyres;
						if (buyres == 1)
						{
							buy_rent serProcess(customerId, carPrice, "buy");
							history_cust[customerId].push_back(serProcess);
							sellOrCancel(roomId, carId, 1);
						}
						else if (buyres == 2)
						{
							sellOrCancel(roomId, carId, 2);
						}
						else
						{
							cout << "Invalid,please enter a valid number." << endl;
						}
					}
				}
				else if (c == 4)
				{
					break;
				}
				else
				{
					cout << "Invalid, please enter a valid number." << endl;
				}

			}
		}
		else
		{
			cout << "Not found." << endl;
		}
	}
}
void System::reserveCar(string customerId, car c)
{
	
	reservedCar[customerId].push_back(c);


}
void System::sellOrCancel(string rId, int cId, int BuyorCancel)
{
	int x = map_rooms[rId];
	int carIndex = 0;
	for (int i = 0; i < sysRoom[x].AvalibleCAr.size(); i++)
	{
		if (sysRoom[x].AvalibleCAr[i].id == cId)
		{
			carIndex = i;
		}

	}
	if (BuyorCancel == 1)
		sysRoom[x].AvalibleCAr.erase(sysRoom[x].AvalibleCAr.begin(), sysRoom[x].AvalibleCAr.begin() + carIndex);
	else
		sysRoom[x].AvalibleCAr[carIndex].appear = true;
}
