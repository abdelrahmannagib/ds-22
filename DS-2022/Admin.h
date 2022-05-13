#pragma once
#include<iostream>
using namespace std;

class Admin
{
public:
	int Id;
	static int counter;
	string Username;
	string Password;

public:
	Admin();
	Admin(string s1,string s2);
};
