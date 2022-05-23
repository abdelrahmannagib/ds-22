#include "customer.h"
#include"buy_rent.h"
#include<fstream>
using namespace std;
#include<iostream>
int customer::counter = 1;


customer::customer() {
	cout << "enter your name please" << endl;
	cin >> username;
	cout << "enter your password please" << endl;
	cin >> pass;
	ID = counter;
	counter++;
	fstream fcustomer;
	fcustomer.open("customer.txt", ios::app);
	fcustomer << ID << " " << username << " " << pass << endl;
}
customer::customer(string user, string pass)
{
	ID = counter;
	counter++;
	username = user;
	this->pass = pass;
}
