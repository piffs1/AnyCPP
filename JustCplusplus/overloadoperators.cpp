#include <iostream>

class Class
{

public:
    int *ptr;
    Class(int sizeOfArray)
    {
        this->sizeOfArray = sizeOfArray;
        mas = new int[sizeOfArray];
        for(int i = 0; i < sizeOfArray; i++)
            mas[i] = i;
        ptr = mas;
    }

    Class &operator = (const Class &p) ///p �� ������ ��������� this ����
    {
        std::cout << "������ �������� ������������ " << this << std::endl;
        if(mas!=nullptr) delete[] mas;  ///���� � ��� ��� ������ mas. �������� ������� �� nullptr. ���� �� �� nullptr, �� �������
        this->mas = new int[p.sizeOfArray];
        for(int i = 0; i < p.sizeOfArray;i++)
            this->mas[i] = p.mas[i];
        return *this;
    }

    ~Class()
    {
        delete[] mas;
        std::cout << "\ndestructor " << this << std::endl;
    }
private:
    int sizeOfArray;
    int *mas;
};


int main(){
    setlocale(0,"");
    Class p(5);
    std::cout << "Class " << &p << std::endl;
    Class r(6);
    Class t(7);
    p = r = t;
	return 0;
}
