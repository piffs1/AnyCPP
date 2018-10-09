/*friend method of class */


#include <iostream>
#include <string>

using namespace std;

class Apple;
class Human
{
public:
    void TakeApple(Apple &apple);
};

class Apple
{
    ///friend class Human;
    friend void Human::TakeApple(Apple &apple);
private:
    int weight;
    string color;
public:
    Apple(int weight,string color){this->weight = weight; this->color = color;}
    void ShowApple(){cout << "weight = " << weight << " color = " << color << endl;}
};
// changing private fields of class Apple
void Human::TakeApple(Apple &apple)
{
    apple.color = "12";
    apple.weight = 12;
}


int main()
{
    Apple apple(40,"40");
    Human human;
    apple.ShowApple();
    human.TakeApple(apple);
    apple.ShowApple();

    return 0;
}
