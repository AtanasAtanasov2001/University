#include<iostream>
#include<vector>
#include"Vehicle.cpp"
#include"Car.cpp"
#include"Plane.cpp"
#include"Ship.cpp"
#include"Helper_class.cpp"




int main()
{
    Car car1(750.0 , 165.0 , 2500.0 , 0);//golf 4
    Plane airpl(2400.0 , 430.0 , 10000.50 , 199);// MC-21
    Ship ship1(6000.0 , 70.0 , 30000.50 , 40.7);//Севастопол

    Car car2(4000.0 , 200.0 , 20000.0 , 2);//linkln
    Plane airpl2(2500.0 , 450.0 , 9900.50 , 201);// MC-21
    Ship ship2(8400.0 , 100.0 , 45000.50 , 60.0);//Севастопол

    Additional vehicles;
    vehicles.addVehicle(&car1);
    vehicles.addVehicle(&airpl);
    vehicles.addVehicle(&ship1);
    vehicles.addVehicle(&car2);
    vehicles.addVehicle(&airpl2);
    vehicles.addVehicle(&ship2);

    vehicles.printVehicles();
    std::cout<< '\n' <<"max speed:"<<std::endl;
    vehicles.maxSpeedVehicles();
    std::cout<< '\n' <<"sorted by price :"<<std::endl;
    vehicles.sortByPrice();
    vehicles.printVehicles();

    return 0;
}
