#include "Authentication.h"

Authentication::Authentication()
{
    //users["admin"] = User("admin", "admin_qwerty", true);
    //users["buyer"] = User("buyer", "buyer_qwerty", false);
}

bool Authentication::authenticateUser(string username, string password)
{
    auto item = users.find(username);
    if (item != users.end() && item->second.password == password)
    {
        return true;
    }
    return false;
}

User Authentication::getUser(string username) const
{
    auto item = users.find(username);
    if (item != users.end()) 
    {
        return item->second;
    }
    return User();
}

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
