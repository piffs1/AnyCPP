#include <iostream>
#include "include/allDrinks.h"
#include "include/allCondiments.h"
#include "include/allPortions.h"

/// REFACTOR DECORATOR'S GetCost();
/// REWRITE DECORATOR'S CONSTRUCTORS

using namespace std;

const string separator = "================================\n";

const unsigned short int SIZE = 5;

int main()
{
    /// BE CAREFUL WITH DELETING BASE = NEW ( NEW ( NEW ) )
    BeverageBase *drinks[SIZE];
    cout << separator;
    drinks[0] = new SmallPortion(new BlackTea());
    cout << separator;
    drinks[1] = new MediumPortion(new GreenTea());
    cout << separator;
    drinks[2] = new LargePortion(new Espresso());
    cout << separator;
    drinks[3] = new SmallPortion(new SugarCondiment(new MilkCondiment(new BlackTea())));
    cout << separator;
    drinks[4] = new MediumPortion(new SugarCondiment(new MilkCondiment(new ChocolateCondiment(new BlackTea()))));
    for(int i = SIZE-1; i >= 0; i--)
    {
        cout << separator;
        cout << "Beverage : " << drinks[i]->GetDiscription() << " Price : " << drinks[i]->GetCost() << endl;
        cout << separator;
        delete drinks[i];
    }
    cout << separator;
    ///SugarCondiment S(BlackTea()); /// OK
    ///SugarCondiment C; /// ERROR
    /*SugarCondiment *c = new SugarCondiment();
    delete c; ///ERROR
    */
    /// -
    return 0;
}
