#include "User.h"

User::User()
{
	username = "undefined";
	password = "undefined";
	isAdmin = false;
}

User::User(string username, string password, bool isAdmin)
{
	this->username = username;
	this->password = password;
	this->isAdmin = isAdmin;
}
