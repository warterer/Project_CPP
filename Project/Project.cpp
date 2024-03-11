#include "Lib.h"

int main()
{
    Authentication login;
    login.loadFromFile();
    CarContainer container;
    container.loadFromFile();
    User currentUser;
    do
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (login.authenticateUser(username, password))
        {
            currentUser = login.getUser(username);
            system("cls");
            cout << "Successfully logged in!\n";
            break;
        }
        else
        {
            cout << "Incorrect username or password!\n";
        }
    } while (true);

    if (currentUser.isAdmin)
    {
        int menu = 0;
        do
        {
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << "+\t\tMENU\t\t    +\n";
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << "+\t1. Add Car\t            +\n";
            cout << "+\t2. Delete Car\t            +\n";
            cout << "+\t3. Edit Car\t            +\n";
            cout << "+\t4. Find Car\t            +\n";
            cout << "+\t5. Sort Cars\t            +\n";
            cout << "+\t6. Show All Cars\t    +\n";
            cout << "+\t0. Exit\t                    +\n";
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << ">>>";
            cin >> menu;
            switch (menu)
            {
            case 1:
            {
                int k = 0;
                cout << "Select: \n";
                cout << "1. New Car\n";
                cout << "2. Special Vehicle\n";
                cout << "3. Used Car\n";
                cout << ">>>";
                cin >> k;
                switch (k)
                {
                case 1:
                {
                    container.inputNewCar();
                    container.saveToFile();
                    break;
                }
                case 2:
                {
                    container.inputSpecVeh();
                    container.saveToFile();
                    break;
                }
                case 3:
                {
                    container.inputUsedCar();
                    container.saveToFile();
                    break;
                }
                default:
                    cout << "Wrong input!\n";
                    break;
                }
                break;
            }
            case 2:
            {
                container.buyCar();
                container.saveToFile();
                break;
            }
            case 3:
            {
                int num;
                cout << "Enter number of car you want to edit: ";
                cin >> num;
                container.editCar(num);
                break;
            }
            case 4:
            {
                container.findCar();
                break;
            }
            case 5:
            {
                container.sortCars();
                break;
            }
            case 6:
            {
                container.show();
                break;
            }
            case 0:
            {
                cout << "Exiting...\n";
                return 0;
            }
            default:
                cout << "Wrong input!\n";
                break;
            }
        } while (menu != 0);
    }
    else
    {
        int menu = 0;
        do
        {
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << "+\t\tMENU\t\t    +\n";
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << "+\t1. Buy Car\t            +\n";
            cout << "+\t2. Find Car\t            +\n";
            cout << "+\t3. Sort Cars\t            +\n";
            cout << "+\t4. Show All Cars\t    +\n";
            cout << "+\t0. Exit\t                    +\n";
            cout << "+++++++++++++++++++++++++++++++++++++\n";
            cout << ">>>";
            cin >> menu;
            switch (menu)
            {
            case 1:
            {
                container.buyCar();
                break;
            }
            case 2:
            {
                container.findCar();
                break;
            }
            case 3:
            {
                container.sortCars();
                break;
            }
            case 4:
            {
                container.show();
                break;
            }
            case 0:
            {
                cout << "Exiting...\n";
                return 0;
            }
            default:
                cout << "Wrong input!\n";
                break;
            }
        } while (menu != 0);
    }
}