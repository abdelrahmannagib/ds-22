#include "car.h"
#include<fstream>
#include <iostream>
using namespace std;


int car::counter = 1;

car::car(string g)
{
	id = counter;
	counter++;
	cout << "Enter the make : \n";
	cin >> make;
	cout << "Enter the model \n";
	cin >> model;
	cout << "Enter the installments \n";
	cin >> install;
	cout << "Enter the year \n";
	cin >> year;
	edit_price();
	appear = true;
	belong = g;
	fstream fcars;
	fcars.open("cars.txt", ios::app);
	fcars << id << " " << make << " " << model << " "<<install<<" "<<year<<" "<<price<<" "<<g << endl;
}
car::car(string ma, string mo, string ins, string ye, string pr,string g)
{
	id = counter;
	counter++;
	make = ma;
	model = mo;
	install = ins;
	year = ye;
	price = pr;
	appear = true;
	belong = g;
}
 void car::edit_price()
{
	 cout << "Enter the new price \n";
	 cin >> price;
}
 
 void car::edit_install()
 {
	 cout << "Enter new installments";
	 cin >> install;
 }
 void car::Edit()
 {
	 cout << "To edit price press 1, to edit install press 2 \n ";
	 int x;
	 cin >> x;
	 if (x == 1)
	 {
		 edit_price();
	 }
	 else if (x == 2)
	 {
		 edit_install();
	 }
	 else
		 Edit();

 }
 void car::ShowCarData()
 {
	 cout << "======== Car Info ========" << endl;
	 cout << "Car's Model: " << model << endl;
	 cout << "Car's Make: " << make << endl;
	 cout << "Car's Price: " << price << endl;
	 cout << "Car's Year: " << year << endl;
	 cout << "Car's Install: " << install << endl;
	 cout << "/////////////////////////////////////////////////////////" << endl;

 }
 car :: ~car()
 {
	 cout << endl;
 }

