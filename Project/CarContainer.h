#pragma once
#include <vector>
#include "Car.h"
#include "NewCar.h"
#include "SpecialVehicle.h"
#include "UsedCar.h"
#include <fstream>
#include <algorithm>
#include "Exception.h"
using namespace std;

class CarContainer
{
    vector<Car*> cars;
public:
    void inputNewCar();
    void inputSpecVeh();
    void inputUsedCar();
    CarContainer();
    ~CarContainer();
    void addCar(Car* car);
    void buyCar(); 
    void editCar(int num);
    void findCar();
    void sortCars();
    void show()const;
    void saveToFile()const;
    void loadFromFile();
};

