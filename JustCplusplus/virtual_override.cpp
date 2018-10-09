#include <iostream>

class Car
{
public:
///!!!!���������� ��� ����� ���� ������ override � virtual ���� ��� ���������
    virtual void ShowTypeCar() /// ���� ���� �������� ����� override, � � ������������� ������� ��� ��������� ����� virtual, ��
    /// ���������� ������ ������.
    {
        std::cout << "usual lol" << std::endl; ///����� ������� � ����������� �����
    }
};

class HeavyTruck : public Car
{
public:
    void ShowTypeCar() override ///override �������� ���������, ��� �� ����������� ������� �������������.
    { /// ���� �� �������� �������� ��������, �� � ��� ��������� ������.
        std::cout << "Heavy Truck " << std::endl;
    }

};

class Jeep : public Car
{
public:
    void ShowTypeCar() override
    {
        std::cout << "Jeep" << std::endl;
    }
};


class Driver
{
public:
    void ShowTypeCar(Car *car){std::cout << "My car is ";car->ShowTypeCar();}
};

int main(){
    Car car;
    car.ShowTypeCar();
    HeavyTruck heavyTruck;
    heavyTruck.ShowTypeCar();

    Car *machine = &heavyTruck; ///???
    machine->ShowTypeCar();
    Car *machine1 = &car;
    machine1->ShowTypeCar(); /// ������ �����. ���� �� ������� virtual (override ��������������), ��
    ///����������, ��� ���� �� ������� ���� � �� �� �������, ������ �������(� �������� ��� ���� ����� ���������� �� �������)
    ///� ����� ������ HeavyTruck : car. �� ���� �� ��������� �� ������ ������ heavytruck. � ���
    ///���������� �� ���� ���������� �� ������� � ����� ������, ��� ����� ������� ���������� ������.
    ///(������ �������) ������ ����� ��� ���� ���� � ����(� ������� ���� �����1 : �����2 �����3 : ����� 1
    /// �� ���� ��� �� ������� ShowTypeCar() ���� ���������� �� ���� �������, �� ��� ����� �� �� ������ ������� � �������� ��� ������� ����(��� � ����� ����� �������� ������)
	Driver driver;
	Jeep jeep;
	///driver.ShowTypeCar(machine); worked
	driver.ShowTypeCar(&heavyTruck);
	driver.ShowTypeCar(&car);
	driver.ShowTypeCar(&jeep);
	return 0;
}
