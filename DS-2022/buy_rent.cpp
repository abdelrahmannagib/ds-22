#include "buy_rent.h"
int buy_rent::p_Counter = 0;

buy_rent::buy_rent(string cust_Id, string mon, string service)
{
	p_Id = p_Counter;
	p_Counter++;
	
	customer_Id = cust_Id;
	money = mon;
	choosen_service = service;
	
	cout << "Enter the Buy Date: " << endl;
	cin >> p_Date;
}
