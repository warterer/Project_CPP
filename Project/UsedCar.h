#pragma once
#include "Car.h"
//UsedCar наследник класса Car
class UsedCar :
    public Car
{
protected:
    float mileage;
    string configuration;
    int numberOfOwners;
public:
    //Конструкторы и деструктор
    UsedCar();
    UsedCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation, float mileage, string configuration, int numberOfOwners);
    virtual ~UsedCar();

    //get, set
    float getMileage()const;
    string getConfiguration()const;
    int getNumberOfOwners()const;
    void setMileage(float mileage);
    void setConfiguration(string configuration);
    void setNumberOfOwners(int numberOfOwners);

    //Реализация абстрактных методов. Полиморфизм
    void saveToFile(ofstream& file)const override;
    void loadFromFile(ifstream& file) override;
    virtual void show()const override;
    virtual string type()const override;
    virtual void edit() override;
};

