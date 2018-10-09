#include <iostream>

class Car
{
public:
///!!!!Посмотреть что будет если убрать override и virtual если это указатели
    virtual void ShowTypeCar() /// Если есть ключевое слово override, и в перегружаемой функции нет ключевого слова virtual, то
    /// комплиятор выдаст ошибку.
    {
        std::cout << "usual lol" << std::endl; ///Можно сделать и абстрактный класс
    }
};

class HeavyTruck : public Car
{
public:
    void ShowTypeCar() override ///override помогает напомнить, что мы перегружаем функцию наследованную.
    { /// Если мы поменяем входящий аргумент, то у нас возникнет ошибка.
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
    machine1->ShowTypeCar(); /// Просто мысли. Если мы убираем virtual (override соответственно), то
    ///получается, что если мы вызваем одну и ту же функцию, разных классов(с условием что один класс наследован от другого)
    ///В нашем случае HeavyTruck : car. То если мы ссылаемся на объект класса heavytruck. У нас
    ///независимо от того определена ли функция в самом классе, она берет функцию отцовского класса.
    ///(Просто догадки) скорее всего она идет выше и выше(к примеру если класс1 : класс2 класс3 : класс 1
    /// То если так же функция ShowTypeCar() была определена во всех классах, то она брала бы из самого первого у которого эта функция есть(или к какой могла получить доступ)
	Driver driver;
	Jeep jeep;
	///driver.ShowTypeCar(machine); worked
	driver.ShowTypeCar(&heavyTruck);
	driver.ShowTypeCar(&car);
	driver.ShowTypeCar(&jeep);
	return 0;
}
