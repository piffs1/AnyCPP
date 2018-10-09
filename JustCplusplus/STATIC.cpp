/* STATIC TEST */
#include <iostream>
/// ���� ����������� ���� �� ��� ������. �.�. ���� �������� ���������� ������ static_test1,2,3. �� ����������
/// static ����� ���� � �� �� �� ���� �������
class static_test
{
public:
    static int a;
    int getB(){return b;}
    void setB(int b){this->b = b;}
private:
    int b;
};



int static_test::a = 0; ///������������� �����������!!! ����� �� ����� ��������.

class new_class
{
public:
    new_class()
    {
        count++;
    }
    ~new_class()
    {

    } ///������� static �� ����� ���������� � this. �.�. ����� � ��������� ������ ������.
    /// ������ ������� �� ����� ���������� � ���� ������� ��� �������� ������.
    /// ����� �� �� ����� ��������� �� ���������� �� ���� ������ �� ������ �������
    static int GetCount(){return count;} /// static int GetCount() ���������, ���� �� ����� ���������� � ������� �� ��������� � ������
    void ShowAddress(){std::cout << &this->count;}
    static void ChangeData(new_class &nc,int data);
    int getData(){return dataTemp;}
private:
    static int count;
    int dataTemp;
};

void new_class::ChangeData(new_class &nc,int data) ///�� ���������. ���� ������ ����������� static � �������� ������
{                                                  ///�� ������� �������� �� ����� ����� new_class::ChangeData()
    nc.dataTemp = data;
}

int new_class::count = 0;

int main(){
    setlocale(0,"");
    static_test::a = 5; ///����� ���������� ���� �� ���������� ������ �� �������� ��� �����
    std::cout << static_test::a;
    static_test st;
    std::cout << std::endl << st.a << std::endl;
    std::cout << "==========================";
    new_class nc;
    new_class nc1;
    new_class nc2;
    std::cout << "\n���� ������� " << nc.GetCount() << " ���������� ������ new_class\n";
    std::cout << "&nc.count = ";
    nc.ShowAddress();
    std::cout << "\n&nc1.count = ";
    nc1.ShowAddress();
    std::cout << "\n&nc2.count = ";
    nc2.ShowAddress();
    std::cout << '\n' << "���������� ����������� ������ new_class = " << new_class::GetCount() << '\n';
    std::cout << "old data = " << nc.getData() << '\n';
    new_class::ChangeData(nc,5);
    std::cout << "new data = " << nc.getData() << '\n';
    std::cout << "old data = " << nc1.getData() << '\n';
    new_class::ChangeData(nc1,3);
    std::cout << "new data = " << nc1.getData() << '\n'; /// ok

	return 0;
}
