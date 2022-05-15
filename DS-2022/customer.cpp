#include "customer.h"
using namespace std;
#include<iostream>
#include<fstream>
int customer::counter = 1;


customer::customer() {
	cout << "enter your name please" << endl;
	cin >> username;
	cout << "enter your password please" << endl;
	cin >> password;
	ID = counter;
	counter++;

	fstream customer;
	customer.open("customer.text", ios::app);
	customer << ID << username << password << endl;
}

customer::customer(string user, string pass)
{
	ID = counter;
	counter++;
	username = user;
	password = pass;
}

