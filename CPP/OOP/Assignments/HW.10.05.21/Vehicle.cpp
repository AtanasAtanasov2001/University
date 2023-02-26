#pragma once
#include<iostream>

class Vehicle
{
    protected:

    double weight;
    double speed;
    double price;

    public:

    Vehicle();
    Vehicle(double , double , double);

    double getWeight()const;
    double getSpeed() const;
    double getPrice() const;
    virtual void printVehicle() = 0;
};

Vehicle::Vehicle()
{
    this->weight = 0 ;
    this->speed = 0;
    this->price = 0;

}

Vehicle::Vehicle(double weight_, double speed_, double price_):weight(weight_) , speed(speed_) , price(price_){}

double Vehicle::getWeight() const
{
    return this->weight;
}
double Vehicle::getSpeed() const
{
    return this->speed;
}
double Vehicle::getPrice() const
{
    return this->price;
}