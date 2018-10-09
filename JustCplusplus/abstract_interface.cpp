/*
* Interface.
*/

#include <iostream>

using namespace std;


class Interface_Car
{
public:
    virtual void Drive() = 0;
    virtual void Control() = 0;
    virtual void Stop() = 0;
    virtual ~Interface_Car(){};
};

class Human
{
public:
    void Ride(Interface_Car &IC) // any parent can refer on son
    {
        cout << "≈ду ";
        IC.Drive();
        cout << "”правл€ю ";
        IC.Control();
        cout << "ќстанавливаюсь... ";
        IC.Stop();
    }
};

class Passenger_Car : public Interface_Car
{
public:
    void Drive() override;
    void Control() override;
    void Stop() override;
};

void Passenger_Car::Drive()
{
    cout << " на легковой машине" << endl;
}

void Passenger_Car::Control()
{
    cout << " легковой машиной " << endl;
}

void Passenger_Car::Stop()
{
    cout << " ќстановилс€" << endl;
}

class Truck_Car : public Interface_Car
{
public:
    void Drive() override;
    void Control() override;
    void Stop() override;
};

void Truck_Car::Drive()
{
    cout << " на грузовой машине" << endl;
}

void Truck_Car::Control()
{
    cout << " грузовой машиной " << endl;
}

void Truck_Car::Stop()
{
    cout << " ќстановилс€" << endl;
}

int main(){

    setlocale(0,"");
    Truck_Car TC;
    Human human;
    human.Ride(TC); //еду на грузовой ... и тд.
    cout << "===========================\n";
    Passenger_Car PC;
    human.Ride(PC); //еду на легковой ... и тд.
	return 0;
}
