/*Creating my exception */

#include <iostream>
#include <string>

using namespace std;

class MyException : public exception
{
public:
    MyException(char *msg,int dataState){this->msg = msg; this->dataState = dataState;} ///class MyException(char *msg) : exception(msg) конструктор исключения
    /// на данной IDE не принимает никаких значений, поэтому мы не можем передать msg
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
    cout << "Переменная = " << value << endl;
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
    catch(MyException &ex) ///Компиляция идет сверху вниз. Если мы сделаем обычное исключение вначале, то он примет его. Если методы позволяют.
    ///поэтому сначала наследники потом потомки
    {
        cout << "Block 1. " << ex.what() << endl;
        cout << "Состояние данных " << ex.GetDataState() << endl;
    }
    catch(exception &ex)
    {
        cout << "Block 0. " << ex.what() << endl;
    }
	return 0;
}
