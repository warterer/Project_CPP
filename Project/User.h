#pragma once
#include <iostream>
#include <string>
using namespace std;
class User
{
public:
	//Поля находятся в public для того что бы доступиться к ним в Authentication
	string username;
	string password;
	bool isAdmin;
	//Конструкторы
	User();
	User(string username, string password, bool isAdmin);
};

