#include <iostream>

using namespace std;

namespace STL_BOOK {
    /// using MyClassValue = conditional_t<IsInt, int, double>;
    /// ��� � �����, ���������� ������������ ��� conditional_t<IsInt, int, double>;,
    /// �������� ������ using conditional_t<IsInt, int, double>; ������, ��� (�������������?)
    /// �.�. ����� MyClassValue �� ����� ���������� �  conditional_t<IsInt, int, double>;
    /// using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;
    /// conditional_t<IsInt, int, double> m_value1;
}

int main()
{
    return 0;
}
