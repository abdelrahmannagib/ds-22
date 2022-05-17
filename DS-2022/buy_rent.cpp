#include "buy_rent.h"
int buy_rent::p_counter = 0;
buy_rent::buy_rent(int id, car c) {
	cout << "hi we are at buyrent" << endl;
	procees_id = p_counter++;
	cout << "Enter date of buy" << endl;
	cin >> proceess_date;
	customer_id = id;
	procees_car.push_back(c);
	// money = c.price;
}

