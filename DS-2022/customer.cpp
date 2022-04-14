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

