#pragma once
#include<iostream>
#include "Vehicle.cpp"


enum Type
{
    car,
    truck,
    limo
};
class Car: public Vehicle
{
    private:
    Type carType;

    public:
    Car();
    Car(double , double , double , int);
    Type getType();
    void printVehicle();
};
Car::Car():Vehicle()
{
    this->carType = car;
}
Car::Car(double weight_, double speed_, double price_, int carType_) : Vehicle(weight_ , speed_ , price_)
{
    switch (carType_)
    {
        case 0: this->carType = car;
            break;
        case 1: this->carType = truck;
            break;
        case 2: this->carType = limo;
            break;

    }
}

Type Car::getType()
{
    return this->carType;
}
void Car::printVehicle()
{
    std::cout<<"Car "<<" weight: "<<this->getWeight()<<" speed: "<<this->getSpeed()<<" price: "<<this->getPrice()<<" ";
    switch (this->getType())
    {
        case 0: std::cout<<"car"<<std::endl;
            break;
        case 1: std::cout<<"truck"<<std::endl;
            break;
        case 2: std::cout<<"limo"<<std::endl;
            break;
    }

}