#include <iostream>
class A
{
public:
    void fake_function(int,int)
    {
        std::cout << "Полное название функции с аргументами: " << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "Название функции: " << __func__ << std::endl;
    }
};

int main(){
    setlocale(0,"");
    std::cout << "Версия компилятора: " << __VERSION__ << std::endl;
    std::cout << "Дата: " << __DATE__ << std::endl;
    std::cout << "Время: " << __TIME__ << std::endl;
    std::cout << "Название файла: " << __FILE__ << std::endl;
    std::cout << "Время последнего изменения файла: " << __TIMESTAMP__ << std::endl;
    std::cout << "Номер строки: " << __LINE__ << std::endl;
    A a;
    a.fake_function(1,2);
    std::cout << "Название функции: " << __FUNCTION__ << std::endl;
    std::cout << "Счетчик: " << __COUNTER__ << std::endl;
    std::cout << "Счетчик: " << __COUNTER__ << std::endl;
    std::cout << "Счетчик: " << __COUNTER__ << std::endl;
    std::cout << "Счетчик: " << __COUNTER__ << std::endl;
    return 0;
}
