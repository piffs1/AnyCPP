/*Creating my exception */

#include <iostream>
#include <string>

using namespace std;

class MyException : public exception
{
public:
    MyException(char *msg,int dataState){this->msg = msg; this->dataState = dataState;} ///class MyException(char *msg) : exception(msg) ����������� ����������
    /// �� ������ IDE �� ��������� ������� ��������, ������� �� �� ����� �������� msg
    ~MyException(){}
    int GetDataState(){return dataState;}
    string what()
    {
        return msg;
    }
private:
    int dataState;
    string msg;
};

void Foo(int value)
{
    if(value<0)
        throw MyException("Error. Value < 10.",value);
    cout << "���������� = " << value << endl;
}

int main(){
    setlocale(0,"");
    try
    {
        Foo(-55);
    }
    /*catch(exception &ex)
    {
        cout << "Block 0. " << ex.what() << endl;
    }*/
    catch(MyException &ex) ///���������� ���� ������ ����. ���� �� ������� ������� ���������� �������, �� �� ������ ���. ���� ������ ���������.
    ///������� ������� ���������� ����� �������
    {
        cout << "Block 1. " << ex.what() << endl;
        cout << "��������� ������ " << ex.GetDataState() << endl;
    }
    catch(exception &ex)
    {
        cout << "Block 0. " << ex.what() << endl;
    }
	return 0;
}
