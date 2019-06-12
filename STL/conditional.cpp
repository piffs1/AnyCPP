#include <iostream>
#include <typeinfo>

using namespace std;

namespace STL_BOOK {

/// conditional<true, if true, if false>

template<bool IsInt>
class MyClass
{
public:
    MyClass(){}
    using MyClassValue = conditional_t<IsInt, int, double>;
    /// typedef conditional<IsInt, int, double>::type m_value1; /// Error
    /// using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;
    conditional_t<IsInt, int, double> m_value1;
    MyClassValue m_value;
};
}

int main()
{
    typedef conditional<true, int, double>::type Type1;
    cout << typeid(Type1).name() << endl; /// int

    typedef conditional<false, int, double>::type Type2;
    cout << typeid(Type2).name() << endl; /// double


    STL_BOOK::MyClass<true> MyClass1;
    cout << typeid(MyClass1.m_value).name() << endl; /// int
    cout << typeid(MyClass1.m_value1).name() << endl; /// int


    STL_BOOK::MyClass<false> MyClass2;
    cout << typeid(MyClass2.m_value).name() << endl; /// double
    cout << typeid(MyClass2.m_value1).name() << endl; /// double

    return 0;
}
