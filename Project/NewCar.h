#pragma once
#include "Car.h"
//NewCar наследник класса Car
class NewCar :
    public Car
{
protected:
    string configuration;
public:
    //Конструкторы и деструктор
    NewCar();
    NewCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation, string configuration);
    virtual ~NewCar();

    //get, set
    string getConfiguration()const;
    void setConfiguration(string configuration);

    //Реализация абстрактных методов. Полиморфизм
    void saveToFile(ofstream& file)const override;
    void loadFromFile(ifstream& file) override;
    virtual void show()const override;
    virtual string type()const override;
    virtual void edit() override;
};

