#pragma once
#include<iostream>
#include"Vehicle.cpp"

class Ship : public Vehicle
{
    private:
    double displacement;

    public:
    Ship();
    Ship(double , double , double , double);
    double getDisplacement();
    void printVehicle();
};
Ship::Ship():Vehicle()
{
    this->displacement = 0;
}
Ship::Ship(double weight_, double speed_, double price_, double displacement_) : Vehicle(weight_ , speed_ , price_)
{
    this->displacement = displacement_;
}
double Ship::getDisplacement()
{
    return this->displacement;
}

void Ship::printVehicle()
{
    std::cout<<"Ship "<<"weight: "<<this->getWeight()<<" speed: "<<this->getSpeed()<<" price: "<<this->getPrice()<<" displacement: "<<this->getDisplacement()<<std::endl;
}