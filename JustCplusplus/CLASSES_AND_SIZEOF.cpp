#include <iostream>
using namespace std;

class A
{
public:
    int A;
};

class A_CLASS{
private:
    int privateData;
public:
    int publicData;
    void setPrivateData(int a){privateData = a;}
    int getPrivateData(){return privateData;}
protected:
    int protectedData;
};
/// ��������� �� ���� ���������� �� ������(��� � ������ � ���������), �� ���� �������� ����������� ������ ������������ ���������.
class B_CLASS : private A_CLASS{ ///���� ������������ �� ��������, �� ��� ������� � ���������� ������ ����������!!!
public:
    void setPublicData(int a){publicData = a;}
    int getPublicData(){return publicData;}
    void setProtectedData(int a){protectedData = a;}
    int getProtectedData(){return protectedData;}
    ///void setPrivateData(int a){privateData = a;} ERROR
    /// A_CLASS privateData = private
    /// publicData = private
    /// protectedData = private
};

class C_CLASS : public B_CLASS{
    ///void setPrivateData(int a){privateData = a;} ERROR
    /// privateData = private
    /// publicData = private
    /// protectedData = private
};

class D_CLASS : protected A_CLASS
{
public:
    void update(int a,int b)
    {
        publicData = a;
        protectedData = b;
    }
    void printMsg();
};

void D_CLASS::printMsg()
{
    cout << "PublicData = " << publicData << endl << "ProtectedData = " << protectedData << endl;
}

int main()
{
    A_CLASS a;
    a.setPrivateData(5);
    cout << a.getPrivateData() << endl;
    ///B_CLASS b;
    D_CLASS d;
    d.update(1,2);
    d.printMsg();
    ///b.setPrivateData(5);
    ///cout << d.publicData << endl;
    /// -- PREDICATOR SNACHALA -- POTOM DEISTVIE
    /// PREDICATOR -- SNACHALA DEISTVIE POTOM PREDICATOR
    cout << sizeof(C_CLASS);
    return 0;
}
