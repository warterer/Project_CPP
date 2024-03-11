#pragma once
#include "User.h"
#include <map>
#include <fstream>
class Authentication
{
	map<string, User> users;
public:
	Authentication();
	bool authenticateUser(string username, string password);
	User getUser(string username)const;
	void loadFromFile();
};
