#include<bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    virtual void createVehicle() = 0;
};

class Car:public Vehicle
{
public:
    void createVehicle();
};

void Car::createVehicle()
{
    cout<<"Creating Car"<<endl;
}

class Bike:public Vehicle
{
public:
    void createVehicle();
};

void Bike::createVehicle()
{
    cout<<"Creating Bike"<<endl;
}

class vehicleFactory
{
public:
    static Vehicle* getVehicle(string type);
};

Vehicle* vehicleFactory::getVehicle(string type)
{
    Vehicle* vehicle;
    if(type == "Car")
    {
        vehicle = dynamic_cast<Vehicle*>(new Car());
    }
    else if(type == "Bike")
    {
        vehicle = dynamic_cast<Vehicle*>(new Bike());
    }
    else
    {
        cout<<"Invalid"<<endl;
        return nullptr;
    }

    return vehicle;
}

int main()
{
    string type;
    cin>>type;

    Vehicle* v = vehicleFactory::getVehicle(type);
    if(v != nullptr)
        v->createVehicle();


    return 0;
}
