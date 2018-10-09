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
        cout << "��� ";
        IC.Drive();
        cout << "�������� ";
        IC.Control();
        cout << "��������������... ";
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
    cout << " �� �������� ������" << endl;
}

void Passenger_Car::Control()
{
    cout << " �������� ������� " << endl;
}

void Passenger_Car::Stop()
{
    cout << " �����������" << endl;
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
    cout << " �� �������� ������" << endl;
}

void Truck_Car::Control()
{
    cout << " �������� ������� " << endl;
}

void Truck_Car::Stop()
{
    cout << " �����������" << endl;
}

int main(){

    setlocale(0,"");
    Truck_Car TC;
    Human human;
    human.Ride(TC); //��� �� �������� ... � ��.
    cout << "===========================\n";
    Passenger_Car PC;
    human.Ride(PC); //��� �� �������� ... � ��.
	return 0;
}
