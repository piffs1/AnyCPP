#include <iostream>
class A
{
public:
    void fake_function(int,int)
    {
        std::cout << "������ �������� ������� � �����������: " << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "�������� �������: " << __func__ << std::endl;
    }
};

int main(){
    setlocale(0,"");
    std::cout << "������ �����������: " << __VERSION__ << std::endl;
    std::cout << "����: " << __DATE__ << std::endl;
    std::cout << "�����: " << __TIME__ << std::endl;
    std::cout << "�������� �����: " << __FILE__ << std::endl;
    std::cout << "����� ���������� ��������� �����: " << __TIMESTAMP__ << std::endl;
    std::cout << "����� ������: " << __LINE__ << std::endl;
    A a;
    a.fake_function(1,2);
    std::cout << "�������� �������: " << __FUNCTION__ << std::endl;
    std::cout << "�������: " << __COUNTER__ << std::endl;
    std::cout << "�������: " << __COUNTER__ << std::endl;
    std::cout << "�������: " << __COUNTER__ << std::endl;
    std::cout << "�������: " << __COUNTER__ << std::endl;
    return 0;
}
