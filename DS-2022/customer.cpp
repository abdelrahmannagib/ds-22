#include "customer.h"
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
}
customer::customer(string user, string pass)
{
	ID = counter;
	counter++;
	username = user;
	this->pass = pass;
}

