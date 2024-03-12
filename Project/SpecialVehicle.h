#pragma once
#include "Car.h"
//SpecialVehicle наследник  класса Car
class SpecialVehicle :
    public Car
{
protected:
    string branch;
    float weight;
    string dimensions;
public:
    //Конструкторы и деструктор
    SpecialVehicle();
    SpecialVehicle(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation, string branch, float weight, string dimensions);
    virtual ~SpecialVehicle();

    //get, set
    string getBranch()const;
    float getWeight()const;
    string getDimensions()const;
    void setBranch(string branch);
    void setWeight(float weight);
    void setDimensions(string dimensions);

    //Реализация абстрактных методов. Полиморфизм
    void saveToFile(ofstream& file)const override;
    void loadFromFile(ifstream& file) override;
    virtual void show()const override;
    virtual string type()const override;
    virtual void edit() override;
};

