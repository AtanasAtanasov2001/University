#pragma once
#include<iostream>
#include"Vehicle.cpp"

class Plane: public Vehicle
{
    private:
    double maxHeight;

    public:
    Plane();
    Plane(double , double , double , double);
    double getMazHeight();
    void printVehicle();
};
Plane::Plane():Vehicle()
{
    this->maxHeight = 0;
}
Plane::Plane(double weight_, double speed_, double price_, double maxHeight_) : Vehicle(weight_ , speed_ , price_)
{
  this->maxHeight = maxHeight_;
}
double Plane::getMazHeight()
{
    return this->maxHeight;
}
void Plane::printVehicle()
{
    std::cout<<"Airplane "<<" weight: "<<this->getWeight()<<" speed: "<<this->getSpeed()<<" price: "<<this->getPrice()<<" maxHeight: "<<this->getMazHeight()<<std::endl;

}
