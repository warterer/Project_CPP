#pragma once
#include "Car.h"
class NewCar :
    public Car
{
protected:
    string configuration;
public:
    NewCar();
    NewCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation, string configuration);
    virtual ~NewCar();

    string getConfiguration()const;
    void setConfiguration(string configuration);

    void saveToFile(ofstream& file)const override;
    void loadFromFile(ifstream& file) override;

    virtual void show()const override;
    virtual string type()const override;
    virtual void edit() override;
};

