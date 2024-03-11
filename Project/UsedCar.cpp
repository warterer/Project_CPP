#include "UsedCar.h"

UsedCar::UsedCar()
{
    mileage = 0;
    configuration = "undefined";
    numberOfOwners = 0;
}

UsedCar::UsedCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName, string sellerPhoneNumber, string sellingLocation, float mileage, string configuration, int numberOfOwners)
    :Car(brand, model, year, engineVolume, price, countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation)
{
    setMileage(mileage);
    setConfiguration(configuration);
    setNumberOfOwners(numberOfOwners);
}

UsedCar::~UsedCar()
{
}

float UsedCar::getMileage() const
{
    return mileage;
}

string UsedCar::getConfiguration() const
{
    return configuration;
}

int UsedCar::getNumberOfOwners() const
{
    return numberOfOwners;
}

void UsedCar::setMileage(float mileage)
{
    this->mileage = mileage;
}

void UsedCar::setConfiguration(string configuration)
{
    this->configuration = configuration;
}

void UsedCar::setNumberOfOwners(int numberOfOwners)
{
    this->numberOfOwners = numberOfOwners;
}

void UsedCar::saveToFile(ofstream& file)const
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
    file << mileage << "\n";
    file << configuration << "\n";
    file << numberOfOwners << "\n";
}

void UsedCar::loadFromFile(ifstream& file)
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
    file >> mileage;
    file.ignore();
    getline(file, configuration);
    file >> numberOfOwners;
    file.ignore();
}

void UsedCar::show() const
{
    cout << "Type: " << type() << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Release Date: " << year << endl;
    cout << "Mileage: " << mileage << " km" << endl;
    cout << "Number of Owners: " << numberOfOwners << endl;
    cout << "Engine Volume: " << engineVolume << "L" << endl;
    cout << "Configuration: " << configuration << endl;
    cout << "Price: $" << price << endl;
    cout << "Country of Origin: " << countryOfOrigin << endl;
    cout << "Seller Name: " << sellerName << endl;
    cout << "Seller Phone Number: " << sellerPhoneNumber << endl;
}

string UsedCar::type() const
{
    return "Used Car";
}

void UsedCar::edit()
{
    int menu = 0;
    cout << "1. Edit Brand\n";
    cout << "2. Edit Model\n";
    cout << "3. Edit Release Date\n";
    cout << "4. Edit Mileage\n";
    cout << "5. Edit Number Of Owners\n";
    cout << "6. Edit Engine Volume\n";
    cout << "7. Edit Configuration\n";
    cout << "8. Edit Price\n";
    cout << "9. Edit Country Of Origin\n";
    cout << "10. Edit Seller`s Name\n";
    cout << "11. Edit Seller`s Phone Number\n";
    cout << "12. Edit Selling Location\n";
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
        cout << "Enter new mileage: ";
        cin >> mileage;
        break;
    }
    case 5:
    {
        cout << "Enter new number of owners: ";
        cin >> numberOfOwners;
        break;
    }
    case 6:
    {
        cout << "Enter new engine volume: ";
        cin >> engineVolume;
        break;
    }
    case 7:
    {
        cout << "Enter new configuration: ";
        cin.ignore();
        getline(cin, configuration);
        break;
    }
    case 8:
    {
        cout << "Enter new price: ";
        cin >> price;
        break;
    }
    case 9:
    {
        cout << "Enter new country of origin: ";
        cin.ignore();
        getline(cin, countryOfOrigin);
        break;
    }
    case 10:
    {
        cout << "Enter new seller`s name: ";
        cin.ignore();
        getline(cin, sellerName);
        break;
    }
    case 11:
    {
        cout << "Enter new seller`s phone number: ";
        cin.ignore();
        getline(cin, sellerPhoneNumber);
        break;
    }
    case 12:
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
