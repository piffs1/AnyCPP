/* inner class */

#include <iostream>
#include <string>
using namespace std;

class Image
{
public:

    void GetImageInfo()
    {
        for(int i = 0;i < LENGTH; i++)
            cout << '#' << i << '\t' << pixels[i].GetInfo() << endl;
    }
private:
    static const int LENGTH = 5;
    class Pixel
    {
    public:
        Pixel(int r,int g,int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        ~Pixel(){}
        string GetInfo()
        {
            return "Pixel: r =" + to_string(r) + "\tg = " + to_string(g)  + "\tb = " + to_string(b) ;
        }
    private:
        int r,g,b;
    };
    Pixel pixels[LENGTH]
    {
        Pixel(0,1,2),
        Pixel(3,4,2),
        Pixel(55,12,32),
        Pixel(12,421,13),
        Pixel(13,41,123),
    };
};



class new_outer_class
{
public:
    class new_inner_class
    {
    public:
        new_inner_class(int a,int b){this->a=a;this->b=b;}
        ~new_inner_class(){}
        void ShowHello(){cout << "Hello!!!I'm inner class of new_outer_class and i have data a = " << a << " b = " << b << endl;}
    private:
        int a;
        int b;
    };
    new_inner_class nic[2] ///объявление класса к которому будем обращаться в последущем
    {
        new_inner_class(3,4),
        new_inner_class(5,2),
    };
private:

};

int main(){
    Image img;
    img.GetImageInfo();
    new_outer_class::new_inner_class nic(1,2); /// Создания класса через вложенный public класс
    nic.ShowHello(); ///создали обычный new_inner_class. Нет ничего общего с new_outer_class
    new_outer_class noc; /// Создаем new_outer_class в котором описывается и создается new_inner_class под переменной nic к которой мы можем обращаться.
    noc.nic[0].ShowHello(); ///Обращение к функции.
    noc.nic[1].ShowHello();
	return 0;
}
