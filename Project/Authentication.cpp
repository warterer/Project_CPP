#include "Authentication.h"

Authentication::Authentication()
{
    //Данные загружаются из файла поэтому информация заккоментирована
    //users["admin"] = User("admin", "admin_qwerty", true);
    //users["buyer"] = User("buyer", "buyer_qwerty", false);
}

//Проверка есть ли пользователь с заданными логин, паролем
bool Authentication::authenticateUser(string username, string password)
{
    auto item = users.find(username);
    if (item != users.end() && item->second.password == password)
    {
        return true;
    }
    return false;
}

//Геттер для User
User Authentication::getUser(string username) const
{
    auto item = users.find(username);
    if (item != users.end()) 
    {
        return item->second;
    }
    return User();
}

//Загрузка логин, пароля из файла
void Authentication::loadFromFile()
{
    ifstream file("loginInfo.txt");
    if (!file.is_open()) 
    {
        cout << "Opening error." << endl;
        return;
    }
    string username, password;
    bool isAdmin;
    while (file >> username >> password >> isAdmin) 
    {
        users[username] = User(username, password, isAdmin);
    }
    file.close();
}
