/* functors */

#include <iostream>
#include <string>

using namespace std;

class MyFunctor ///Функциональный объект - функтор
{
public:
    void operator ()()
    {
        cout <<"i'm functor. I called " << count << " times" << endl;
        count++;
    }
    int operator ()(int a,int b)
    {
        cout << "Sum a + b = ";
        return a+b;
    }
private:
    int count = 1;
};

class EvenFunctor
{
public:
    void operator ()(int a)
    {
        if(a%2 == 0)
        {
            evenSum = evenSum + a;
            evenCount++;
        }
    }
    void ShowEvenSum()
    {
        cout << "Сумма четных чисел = " << evenSum << endl;
    }
    void ShowEvenCount()
    {
        cout << "Количество четных чисел = " << evenCount << endl;
    }
private:
    int evenSum = 0;
    int evenCount = 0;
};

int main(){
    setlocale(0,"");
    int b;
    MyFunctor MF;
    EvenFunctor EF;
    for(int i = 1; i <= 10; i++)
    {
        cout << "Введите " << i << "-ое число ";
        cin >> b;
        EF(b);
    }
    EF.ShowEvenCount();
    EF.ShowEvenSum();
	return 0;
}
