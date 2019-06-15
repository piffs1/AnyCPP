#include <iostream>
#include <typeinfo>

using namespace std;

namespace STL_BOOK {

// typename. Явно указываем комплиятору что это тип
// typename нужен для облегчения задачи компилятору при парсинге загадочных выражений вроде следующего:
// template<class T> void f() { T::x * p; ... } 

// Выражение T::x * p может означать две вещи. 
// Первая: x - это имя некого типа, а все выражение есть объявление указателя p. 
// Вторая: x - это статическая переменная, а * - это знак умножения. Тогда p - это тоже какая-то переменная. 
// В нашем случае это первый вариант

}

int main()
{
    /// using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;

    return 0;
}
