#include <iostream>

class MyBass
{
public:
    MyBass();
    ~MyBass();
    void print();
private:

};

MyBass::MyBass()
{

}

MyBass::~MyBass()
{

}

void MyBass::print()
{
    std::cout << "Hi everyone!!!" << std::endl;
}

int main(){
    MyBass mb;

    mb.print();
	return 0;
}
