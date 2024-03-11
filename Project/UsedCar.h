#pragma once
#include "Car.h"
class UsedCar :
    public Car
{
protected:
    float mileage;
    string configuration;
    int numberOfOwners;
public:
    UsedCar();
    UsedCar(string brand, string model, Date year, float engineVolume, float price, string countryOfOrigin, string sellerName,
        string sellerPhoneNumber, string sellingLocation, float mileage, string configuration, int numberOfOwners);
    virtual ~UsedCar();

    float getMileage()const;
    string getConfiguration()const;
    int getNumberOfOwners()const;

    void setMileage(float mileage);
    void setConfiguration(string configuration);
    void setNumberOfOwners(int numberOfOwners);

    void saveToFile(ofstream& file)const override;
    void loadFromFile(ifstream& file) override;

    virtual void show()const override;
    virtual string type()const override;
    virtual void edit() override;
};

