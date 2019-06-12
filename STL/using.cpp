#include <iostream>

using namespace std;

namespace STL_BOOK {
    /// using MyClassValue = conditional_t<IsInt, int, double>;
    /// Как я понял, определяем пространство для conditional_t<IsInt, int, double>;,
    /// Объявить просто using conditional_t<IsInt, int, double>; нельзя, нет (спецификатора?)
    /// Т.е. через MyClassValue мы можем обратиться к  conditional_t<IsInt, int, double>;
    /// using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;
    /// conditional_t<IsInt, int, double> m_value1;
}

int main()
{
    return 0;
}
