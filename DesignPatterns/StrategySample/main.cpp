#include <iostream>
#include "ExoticDuck.h"
#include "SimpleDuck.h"
#include "WoodenDuck.h"


using namespace std;

int main()
{
    cout << "================================\n";
    BaseDuck *ducks[3] = {new SimpleDuck(),new WoodenDuck(), new ExoticDuck()};
    cout << "================================\n";
    for(int i = 0; i < 3; i++)
    {
        ducks[i]->Drive();
        ducks[i]->Fly();
        ducks[i]->Quack();
        ducks[i]->Swim();
        cout << "================================\n";
    }
    for(int i = 0; i < 3;  i++)
        delete ducks[i];
    cout << "================================\n";
    return 0;
}
