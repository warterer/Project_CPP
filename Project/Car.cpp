#include "Car.h"

Car::Car()
{
    brand = "undefined";
    model = "undefined";
    year = 0;
    engineVolume = 0;
    price = 0;
    countryOfOrigin = "undefined";
    sellerName = "undefined";
    sellerPhoneNumber = "undefined";
    sellingLocation = "undefined";
}

Car::Car(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName, string sellerPhoneNumber, string sellingLocation)
{
    setBrand(brand);
    setModel(model);
    setYear(year);
    setEngineVolume(engineVolume);
    setPrice(price);
    setCountryOfOrigin(countryOfOrigin);
    setSellerName(sellerName);
    setSellerPhoneNumber(sellerPhoneNumber);
    setSellingLocation(sellingLocation);
}

Car::~Car()
{
}

string Car::getBrand() const
{
    return brand;
}

string Car::getModel() const
{
    return model;
}

Date Car::getYear() const
{
    return year;
}

float Car::getEngineVolume() const
{
    return engineVolume;
}

float Car::getPrice() const
{
    return price;
}

string Car::getCountryOfOrigin() const
{
    return countryOfOrigin;
}

string Car::getSellerName() const
{
    return sellerName;
}

string Car::getSellerPhoneNumber() const
{
    return sellerPhoneNumber;
}

string Car::getSellingLocation() const
{
    return sellingLocation;
}

void Car::setBrand(string brand)
{
    this->brand = brand;
}

void Car::setModel(string model)
{
    this->model = model;
}

void Car::setYear(Date year)
{
    this->year = year;
}

void Car::setEngineVolume(float engineVolume)
{
    this->engineVolume = engineVolume;
}

void Car::setPrice(float price)
{
    this->price = price;
}

void Car::setCountryOfOrigin(string countryOfOrigin)
{
    this->countryOfOrigin = countryOfOrigin;
}

void Car::setSellerName(string sellerName)
{
    this->sellerName = sellerName;
}

void Car::setSellerPhoneNumber(string sellerPhoneNumber)
{
    this->sellerPhoneNumber = sellerPhoneNumber;
}

void Car::setSellingLocation(string sellingLocation)
{
    this->sellingLocation = sellingLocation;
}
