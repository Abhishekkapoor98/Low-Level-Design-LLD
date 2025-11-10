#include<bits/stdc++.h>
using namespace std;

class DriveStrategy{
public:
	virtual void drive()=0;
};

class PassengerCarDriveStrategy: public DriveStrategy{
public:
    void drive() override{
        cout<<"Driving passenger car with Passenger Drive Strategy."<<endl;
    }
};

class SportsCarDriveStrategy: public DriveStrategy{
public:
	void drive() override{
        cout<<"Driving sports car with Sports Drive Strategy."<<endl;
    }
};

class vehicle{
public:
	DriveStrategy *drivestrategy;

    vehicle(DriveStrategy *drivestrategy){
        this->drivestrategy=drivestrategy;
    }

    virtual void drive()=0;
};

class PassengerCar: public vehicle{
public:
	PassengerCar(DriveStrategy *strategy): vehicle(strategy) {}

    void drive() override {
        drivestrategy->drive();
    }
};

class SportsCar: public vehicle{
public:
    SportsCar(DriveStrategy *strategy): vehicle(strategy) {}

    void drive() override{
        drivestrategy->drive();
    }
};

int main(){
    DriveStrategy *passengerStrategy = new PassengerCarDriveStrategy();
    vehicle *passengerCar = new PassengerCar(passengerStrategy);
    passengerCar->drive();

    DriveStrategy *sportsStrategy = new SportsCarDriveStrategy();
    vehicle *sportsCar = new SportsCar(sportsStrategy);
    sportsCar->drive();

    delete passengerCar;
    delete sportsCar;
    delete passengerStrategy;
    delete sportsStrategy;

    return 0;
}