#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Exception.h"
using namespace std;

class Car 
{
protected:
    string brand;
    string model;
    Date year;
    float engineVolume;
    float price;
    string countryOfOrigin;
    string sellerName;
    string sellerPhoneNumber;
    string sellingLocation;
public:
    //Конструкторы и деструктор
    Car();
    Car(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation);
    virtual ~Car();

    //Аксессоры
    string getBrand()const;
    string getModel()const;
    Date getYear()const;
    float getEngineVolume()const;
    float getPrice()const;
    string getCountryOfOrigin()const;
    string getSellerName()const;
    string getSellerPhoneNumber()const;
    string getSellingLocation()const;
    void setBrand(string brand);
    void setModel(string model);
    void setYear(Date year);
    void setEngineVolume(float engineVolume);
    void setPrice(float price);
    void setCountryOfOrigin(string countryOfOrigin);
    void setSellerName(string sellerName);
    void setSellerPhoneNumber(string sellerPhoneNumber);
    void setSellingLocation(string sellingLocation);

    //Виртуальные абстрактные методы для сохранения, загрузки
    //вывода и редактирования авто
    virtual void saveToFile(ofstream& file)const = 0;
    virtual void loadFromFile(ifstream& file) = 0;
    virtual void show()const = 0;
    virtual string type()const = 0;
    virtual void edit() = 0;
};