#include "CarContainer.h"

void CarContainer::inputNewCar()
{
    string brand, model;
    Date year; 
    float engineVolume, price;
    string countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation, configuration;

    cout << "Enter brand: ";
    cin.ignore();
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter release date: ";
    cin >> year;
    cout << "Enter engine volume: ";
    cin >> engineVolume;
    cout << "Enter configuration: ";
    cin.ignore();
    getline(cin, configuration);
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter country of origin: ";
    cin.ignore();
    getline(cin, countryOfOrigin);
    cout << "Enter seller`s name: ";
    getline(cin, sellerName);
    cout << "Enter seller`s phone number: ";
    getline(cin, sellerPhoneNumber);
    cout << "Enter selling location: ";
    getline(cin, sellingLocation);

    addCar(new NewCar(brand, model, year, engineVolume, price, countryOfOrigin, sellerName, 
        sellerPhoneNumber, sellingLocation, configuration));
}

void CarContainer::inputSpecVeh()
{
    string brand, model;
    Date year;
    float engineVolume, price;
    string countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation;
    string branch;
    float weight;
    string dimensions;

    cout << "Enter brand: ";
    cin.ignore();
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter release date: ";
    cin >> year;
    cout << "Enter engine volume: ";
    cin >> engineVolume;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter country of origin: ";
    cin.ignore();
    getline(cin, countryOfOrigin);
    cout << "Enter seller's name: ";
    getline(cin, sellerName);
    cout << "Enter seller's phone number: ";
    getline(cin, sellerPhoneNumber);
    cout << "Enter selling location: ";
    getline(cin, sellingLocation);

    cout << "Enter branch: ";
    getline(cin, branch);
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter dimensions: ";
    cin.ignore();
    getline(cin, dimensions);

    addCar(new SpecialVehicle(brand, model, year, engineVolume, price, countryOfOrigin, sellerName,
        sellerPhoneNumber, sellingLocation, branch, weight, dimensions));
}

void CarContainer::inputUsedCar()
{
    string brand, model;
    Date year;
    float engineVolume, price;
    string countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation;
    float mileage;
    string configuration;
    int numberOfOwners;

    cout << "Enter brand: ";
    cin.ignore();
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter release date: ";
    cin >> year;
    cout << "Enter engine volume: ";
    cin >> engineVolume;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter country of origin: ";
    cin.ignore();
    getline(cin, countryOfOrigin);
    cout << "Enter seller's name: ";
    getline(cin, sellerName);
    cout << "Enter seller's phone number: ";
    getline(cin, sellerPhoneNumber);
    cout << "Enter selling location: ";
    getline(cin, sellingLocation);

    cout << "Enter mileage: ";
    cin >> mileage;
    cout << "Enter configuration: ";
    cin.ignore();
    getline(cin, configuration);
    cout << "Enter number of owners: ";
    cin >> numberOfOwners;

    addCar(new UsedCar(brand, model, year, engineVolume, price, countryOfOrigin, sellerName,
        sellerPhoneNumber, sellingLocation, mileage, configuration, numberOfOwners));
}

CarContainer::CarContainer()
{
}

CarContainer::~CarContainer()
{
    for (Car* car : cars)
    {
        delete car;
    }
}

void CarContainer::addCar(Car* car)
{
    cars.push_back(car);
}

void CarContainer::buyCar()
{
    try {
        if (cars.empty())
        {
            //Случай когда контейнер пустой
            throw new EmptyException();
        }
        int num;
        cout << "Enter the number of the car you want to buy: ";
        cin >> num;
        if (num >= 1 && num <= cars.size())
        {
            delete cars[num - 1];
            cars.erase(cars.begin() + num - 1);
            cout << "Car #" << num << " is bought.\n";
        }
        else
        {
            //Некорректный ввод номера
            throw new InputException();
        }
    }
    catch (const Exception* err)
    {
        cout << "Error: " << err->message() << endl;
    }
}

void CarContainer::editCar(int num)
{
    try
    {
        if (cars.empty())
        {
            //Случай когда контейнер пустой
            throw new EmptyException();
        }
        if (num >= 0 && num < cars.size())
        {
            cars[num-1]->edit();
            saveToFile();
        }
        else
        {
            //Некорректный ввод номера
            throw new InputException();
        }
    }
    catch (const Exception* err)
    {
        cout << "Error: " << err->message() << endl;
    }
    
}

void CarContainer::findCar()
{
    int menu;
    cout << "Choose search option: \n";
    cout << "1. Search by car type\n";
    cout << "2. Search by criteria\n";
    cout << ">>>";
    cin >> menu;
    
    if (menu == 1)
    {
        string carType;
        cout << "Enter the type of car (Brand New Car, Used Car, Special Vehicle): ";
        cin.ignore();
        getline(cin, carType);
        if (carType == "Brand New Car")
        {
            for (Car* car : cars)
            {
                if (car->type() == "Brand New Car")
                {
                    car->show();
                    cout << endl;
                    return;
                }
            }
        }
        else if (carType == "Used Car")
        {
            for (Car* car : cars)
            {
                if (car->type() == "Used Car")
                {
                    car->show();
                    cout << endl;
                    return;
                }
            }
        }
        else if (carType == "Special Vehicle")
        {
            for (Car* car : cars)
            {
                if (car->type() == "Special Vehicle")
                {
                    car->show();
                    cout << endl;
                    return;
                }
            }
        }
        else
        {
            cout << "Wrong input!\n";
            return;
        }
    }
    else if (menu == 2)
    {
        int a = 0;
        int choice;
        cout << "1. Search by brand\n";
        cout << "2. Search by model\n";
        cout << "3. Search by year\n";
        cout << "4. Search by engine volume\n";
        cout << "5. Search by price\n";
        cout << "6. Search by country of origin\n";
        cout << "7. Search by seller's name\n";
        cout << "8. Search by seller's phone number\n";
        cout << "9. Search by selling location\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string tmp;
            cout << "Enter brand to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getBrand() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 2:
        {
            string tmp;
            cout << "Enter model to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getModel() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 3:
        {
            Date tmp;
            cout << "Enter date to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getYear() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 4:
        {
            float tmp;
            cout << "Enter engine volume to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getEngineVolume() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 5:
        {
            float tmp;
            cout << "Enter price to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getPrice() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 6:
        {
            string tmp;
            cout << "Enter country to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getCountryOfOrigin() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 7:
        {
            string tmp;
            cout << "Enter seller`s name to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getSellerName() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 8:
        {
            string tmp;
            cout << "Enter seller`s phone number to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getSellerPhoneNumber() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        case 9:
        {
            string tmp;
            cout << "Enter seller`s location to search: ";
            cin >> tmp;
            for (Car* car : cars)
            {
                if (car->getSellingLocation() == tmp)
                {
                    car->show();
                    a++;
                    cout << endl;
                }
            }
            break;
        }
        default:
            cout << "Wrong input!\n";
            break;
        }
        if (a != 0)
        {
            return;
        }
    }
    else
    {
        cout << "Wrong input!\n";
        return;
    }
    cout << "Nothing Found!\n";
    return;
}

void CarContainer::sortCars()
{
    try {
        if (cars.empty())
        {
            //Случай когда контейнер пустой
            throw new EmptyException();
        }
        int menu;
        cout << "1. Sort by price\n";
        cout << "2. Sort by brand\n";
        cout << ">>>";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            int a1;
            cout << "1. Asc(1-9)\n";
            cout << "2. Desc(9-1)\n";
            cout << ">>>";
            cin >> a1;
            switch (a1)
            {
            case 1:
            {
                sort(cars.begin(), cars.end(), [](const Car* obj1, const Car* obj2) {
                    return obj1->getPrice() < obj2->getPrice();
                    });
                cout << "Successfully sorted!\n";
                break;
            }
            case 2:
            {
                sort(cars.begin(), cars.end(), [](const Car* obj1, const Car* obj2) {
                    return obj1->getPrice() > obj2->getPrice();
                    });
                cout << "Successfully sorted!\n";
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
            int a2;
            cout << "1. Asc(A-Z)\n";
            cout << "2. Desc(Z-A)\n";
            cout << ">>>";
            cin >> a2;
            switch (a2)
            {
            case 1:
            {
                sort(cars.begin(), cars.end(), [](const Car* obj1, const Car* obj2) {
                    return obj1->getBrand() < obj2->getBrand();
                    });
                cout << "Successfully sorted!\n";
                break;
            }
            case 2:
            {
                sort(cars.begin(), cars.end(), [](const Car* obj1, const Car* obj2) {
                    return obj1->getBrand() > obj2->getBrand();
                    });
                cout << "Successfully sorted!\n";
                break;
            }
            default:
                cout << "Wrong input!\n";
                break;
            }
            break;
        }
        default:
            cout << "Wrong input!\n";
            break;
        }
    }
    catch (const Exception* err)
    {
        cout << "Error: " << err->message() << endl;
    }
}

void CarContainer::show() const
{
    if (cars.empty())
    {
        cout << "List is empty!\n";
        return;
    }
    for (int i = 0; i < cars.size(); ++i)
    {
        cout << "Car #" << i + 1 << ":\n";
        cars[i]->show();
        cout << endl;
    }
}

void CarContainer::saveToFile() const
{
    ofstream file("car_data.txt");
    if (file.is_open())
    {
        for (Car* car : cars)
        {
            file << car->type() << "\n";
            car->saveToFile(file);
        }
        file.close();
        cout << "Car data saved to file.\n";
    }
    else
    {
        cout << "File opening error!\n";
    }
}

void CarContainer::loadFromFile()
{
    ifstream file("car_data.txt");

    if (file.is_open())
    {
        for (Car* car : cars)
        {
            delete car;
        }
        cars.clear();

        while (!file.eof())
        {
            string carType;
            getline(file, carType);
            if (carType == "Brand New Car")
            {
                NewCar* newCar = new NewCar();
                newCar->loadFromFile(file);
                addCar(newCar);
            }
            else if (carType == "Used Car")
            {
                UsedCar* usedCar = new UsedCar();
                usedCar->loadFromFile(file);
                addCar(usedCar);
            }
            else if (carType == "Special Vehicle")
            {
                SpecialVehicle* specialVehicle = new SpecialVehicle();
                specialVehicle->loadFromFile(file);
                addCar(specialVehicle);
            }
        }
        file.close();
        cout << "Car data loaded from file.\n";
    }
    else
    {
        cout << "File opening error!\n";
    }
}

bool CarContainer::isEmpty() const
{
    return cars.empty();
}
