#pragma once
#include "User.h"
#include <map>
#include <fstream>

class Authentication
{
	map<string, User> users;
public:
	//Конструктор и методы для аутентификации и получения 
	//логин, пароля из файла
	Authentication();
	bool authenticateUser(string username, string password);
	User getUser(string username)const;
	void loadFromFile();
};
