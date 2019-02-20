#include <iostream>
#include "Hero.h"
#include "DragonFactory.h"
#include "WarriorFactory.h"

using namespace std;

int main()
{
    Hero *dragon = new Hero(new DragonFactory);
    cout << "=================================\n";
    dragon->Hit();
    cout << "=================================\n";
    dragon->Run();
    cout << "=================================\n";
    delete dragon;
    cout << "=================================\n";
    Hero *warrior = new Hero(new WarriorFactory);
    cout << "=================================\n";
    warrior->Hit();
    cout << "=================================\n";
    warrior->Run();
    cout << "=================================\n";
    delete warrior;

    return 0;
}
