#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

class IAction
{
public:
    virtual void Action() = 0;
};

class DogAction : public IAction
{
    virtual void Action() override
    {
        cout << "GAV GAV" << endl;
    }
};

class CatAction : public IAction
{
public:
    virtual void Action() override
    {
        cout << "MEOW-MEOW" << endl;
    }
};

int main(){
    IAction *arr[] =
    {
        &DogAction(),
        &CatAction()
    };
    srand(time(NULL));
    random_shuffle(begin(arr),end(arr));
    for (&element : arr)
    {
        element->Action();
    }
	return 0;
}
