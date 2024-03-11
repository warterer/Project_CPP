#include "SpecialVehicle.h"

SpecialVehicle::SpecialVehicle()
{
    branch = "undefined";
    weight = 0;
    dimensions = "undefined";
}

SpecialVehicle::SpecialVehicle(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName, string sellerPhoneNumber, string sellingLocation, string branch, float weight, string dimensions)
    :Car(brand, model, year, engineVolume, price, countryOfOrigin, sellerName, sellerPhoneNumber, sellingLocation)
{
    setBranch(branch);
    setWeight(weight);
    setDimensions(dimensions);
}

SpecialVehicle::~SpecialVehicle()
{
}

string SpecialVehicle::getBranch() const
{
    return branch;
}

float SpecialVehicle::getWeight() const
{
    return weight;
}

string SpecialVehicle::getDimensions() const
{
    return dimensions;
}

void SpecialVehicle::setBranch(string branch)
{
    this->branch = branch;
}

void SpecialVehicle::setWeight(float weight)
{
    this->weight = weight;
}

void SpecialVehicle::setDimensions(string dimensions)
{
    this->dimensions = dimensions;
}

void SpecialVehicle::saveToFile(ofstream& file)const
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
    file << branch << "\n";
    file << weight << "\n";
    file << dimensions << "\n";
}

void SpecialVehicle::loadFromFile(ifstream& file)
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
    getline(file, branch);
    file >> weight;
    file.ignore();
    getline(file, dimensions);
}

void SpecialVehicle::show() const
{
    cout << "Type: " << type() << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Release Date: " << year << endl;
    cout << "Usage as: " << branch << endl;
    cout << "Weight: " << weight << endl;
    cout << "Dimensions: " << dimensions << endl;
    cout << "Engine Volume: " << engineVolume << "L" << endl;
    cout << "Price: $" << price << endl;
    cout << "Country of Origin: " << countryOfOrigin << endl;
    cout << "Seller Name: " << sellerName << endl;
    cout << "Seller Phone Number: " << sellerPhoneNumber << endl;
}

string SpecialVehicle::type() const
{
    return "Special Vehicle";
}

void SpecialVehicle::edit()
{
    int menu = 0;
    cout << "1. Edit Brand\n";
    cout << "2. Edit Model\n";
    cout << "3. Edit Release Date\n";
    cout << "4. Edit Branch\n";
    cout << "5. Edit Weight\n";
    cout << "6. Edit Dimensions\n";
    cout << "7. Edit Engine Volume\n";
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
        cout << "Enter new branch: ";
        cin.ignore();
        getline(cin, branch);
        break;
    }
    case 5:
    {
        cout << "Enter new weight: ";
        cin >> weight;
        break;
    }
    case 6:
    {
        cout << "Enter new dimensions: ";
        cin.ignore();
        getline(cin, dimensions);
        break;
    }
    case 7:
    {
        cout << "Enter new engine volume: ";
        cin >> engineVolume;
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
