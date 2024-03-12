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
    //Методы для ввода нужного типа авто
    void inputNewCar();
    void inputSpecVeh();
    void inputUsedCar();

    //Конструктор и деструктор
    CarContainer();
    ~CarContainer();

    //Добавление авто в контейнер
    void addCar(Car* car);

    //Методы для работы с контейнером авто
    //(удаление, редактирование, поиск, сортировка, вывод на экран)
    void buyCar(); 
    void editCar(int num);
    void findCar();
    void sortCars();
    void show()const;

    //Сохранение и выгрузка из текстового файла
    void saveToFile()const;
    void loadFromFile();

    //Проверка на наличие элементов в контейнере
    bool isEmpty()const;
};

