#pragma once
#include <iostream>
#include <string>
using namespace std;
class User
{
public:
	string username;
	string password;
	bool isAdmin;
	User();
	User(string username, string password, bool isAdmin);
};

