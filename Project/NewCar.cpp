#include "NewCar.h"

NewCar::NewCar()
{
    configuration = "undefined";
}

NewCar::NewCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName, string sellerPhoneNumber, string sellingLocation, string configuration)
    :Car(brand, model, year, engineVolume, price, countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation)
{
    setConfiguration(configuration);
}

NewCar::~NewCar()
{
}

string NewCar::getConfiguration() const
{
    return configuration;
}

void NewCar::setConfiguration(string configuration)
{
    this->configuration = configuration;
}

void NewCar::saveToFile(ofstream& file) const
{
    file << brand << "\n";
    file << model << "\n";
    file << year << "\n";
    file << engineVolume << "\n";
    file << price << "\n";
    file << countryOfOrigin << "\n";
    file << sellerName << "\n";
    file << sellerPhoneNumber << "\n";
    file << sellingLocation << "\n";
    file << configuration << "\n";
}

void NewCar::loadFromFile(ifstream& file)
{
    getline(file, brand);
    getline(file, model);
    file >> year;
    file >> engineVolume;
    file >> price;
    file.ignore();
    getline(file, countryOfOrigin);
    getline(file, sellerName);
    getline(file, sellerPhoneNumber);
    getline(file, sellingLocation);
    getline(file, configuration);
}

void NewCar::show() const
{
    cout << "Type: " << type() << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Release Date: " << year << endl;
    cout << "Engine Volume: " << engineVolume << "L" << endl;
    cout << "Configuration: " << configuration << endl;
    cout << "Price: $" << price << endl;
    cout << "Country of Origin: " << countryOfOrigin << endl;
    cout << "Seller Name: " << sellerName << endl;
    cout << "Seller Phone Number: " << sellerPhoneNumber << endl;
    cout << "Selling Location: " << sellingLocation << endl;
}

string NewCar::type() const
{
    return "Brand New Car";
}

void NewCar::edit()
{
    int menu = 0;
    cout << "1. Edit Brand\n";
    cout << "2. Edit Model\n";
    cout << "3. Edit Release Date\n";
    cout << "4. Edit Engine Volume\n";
    cout << "5. Edit Configuration\n";
    cout << "6. Edit Price\n";
    cout << "7. Edit Country Of Origin\n";
    cout << "8. Edit Seller`s Name\n";
    cout << "9. Edit Seller`s Phone Number\n";
    cout << "10. Edit Selling Location\n";
    cout << ">>>";
    cin >> menu;
    switch (menu)
    {
    case 1:
    {
        cout << "Enter new brand: ";
        cin.ignore();
        getline(cin, brand);
        break;
    }
    case 2:
    {
        cout << "Enter new model: ";
        cin.ignore();
        getline(cin, model);
        break;
    }
    case 3:
    {
        cout << "Enter new release date: ";
        cin >> year;
        break;
    }
    case 4:
    {
        cout << "Enter new engine volume: ";
        cin >> engineVolume;
        break;
    }
    case 5:
    {
        cout << "Enter new configuration: ";
        cin.ignore();
        getline(cin, configuration);
        break;
    }
    case 6:
    {
        cout << "Enter new price: ";
        cin >> price;
        break;
    }
    case 7:
    {
        cout << "Enter new country of origin: ";
        cin.ignore();
        getline(cin, countryOfOrigin);
        break;
    }
    case 8:
    {
        cout << "Enter new seller`s name: ";
        cin.ignore();
        getline(cin, sellerName);
        break;
    }
    case 9:
    {
        cout << "Enter new seller`s phone number: ";
        cin.ignore();
        getline(cin, sellerPhoneNumber);
        break;
    }
    case 10:
    {
        cout << "Enter new selling location: ";
        cin.ignore();
        getline(cin, sellingLocation);
        break;
    }
    default:
        cout << "Wrong input!\n";
        break;
    }
}
