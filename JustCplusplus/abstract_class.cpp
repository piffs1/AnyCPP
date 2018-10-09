/*
* Abstract class. Pure virtual method. Inheritance of abstract class.
*/

#include <iostream>

class Car
{
public:
    virtual void ShowTypeCar() = 0;
    //void SomeFunction();
    virtual ~Car(){};
};

class HeavyTruck : public Car
{
public:
    void ShowTypeCar() override
    {
        std::cout << carType << std::endl;
    }
private:
    std::string carType = "Heavy Truck";
};

class Jeep : public Car
{
public:
    void ShowTypeCar() override
    {
        std::cout << "Jeep" << std::endl;
    }
private:
    std::string carType = "Jeep";
};


class Driver
{
public:
    void ShowTypeCar(Car *car){std::cout << "My car is ";car->ShowTypeCar();}
};

int main(){
    //Car car; //error. Abstract class
    //car.ShowTypeCar();
    HeavyTruck heavyTruck; //creating HeavyTruck object
    heavyTruck.ShowTypeCar(); // ok. output: Heavy Truck

    Car *machine = &heavyTruck; // any parent can refer on son
    Car *newMachine = new Jeep;
    machine->ShowTypeCar(); // ok. output: Heavy Truck
    Driver driver;
	Jeep jeep;
	driver.ShowTypeCar(&heavyTruck); // ok. output: My car is Heavy Truck
	driver.ShowTypeCar(&jeep); // ok. output:  My car is Jeep
	driver.ShowTypeCar(machine); // ok. output:  My car is Heavy Truck
	driver.ShowTypeCar(newMachine); //ok. output:  My car is Jeep
	delete newMachine;
	return 0;
}
