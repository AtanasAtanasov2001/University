#include<iostream>
#include"Vehicle.cpp"
#include"Car.cpp"
#include"Ship.cpp"
#include"Plane.cpp"
#include<vector>

class Additional
{
    private:
    std::vector<Vehicle*> allVehicles;
    void destroy();

    public:
    ~Additional();
    void sortByPrice();
    void addVehicle(Vehicle* );
    void maxSpeedVehicles();
    void printVehicles();

};
void Additional::destroy()
{
    int size = this->allVehicles.size();
    for (int i = 0; i < size; i++)
    {

       delete this->allVehicles[i];
    }

}
Additional::~Additional()
{
    this->destroy();
}
void Additional::sortByPrice()
{
    int  size = this->allVehicles.size();
    Vehicle* helper;
    for(int  i = 0 ; i< size - 1 ; ++i)
    {
        for(int  j = 0 ;j < size - i -1 ; ++j)
        {
            if(allVehicles[j]->getPrice() > allVehicles[j+1]->getPrice())
            {
                helper = allVehicles[j];
                allVehicles[j] = allVehicles[j+1];
                allVehicles[j+1] = helper;

            }
        }
    }
}
void Additional::addVehicle(Vehicle* vh )
{
     this->allVehicles.push_back(vh);
}
void Additional::maxSpeedVehicles()
{
    int  size = this->allVehicles.size();
    for(int i =0 ; i < size ;i++)
    {
        if(this->allVehicles[i]->getSpeed() > 200.0)
        {
           this->allVehicles[i]->printVehicle();
        }
    }
}
void Additional::printVehicles()
{
    int size = this->allVehicles.size();
    for (int i = 0; i < size; i++)
    {

        this->allVehicles[i]->printVehicle();
    }
}