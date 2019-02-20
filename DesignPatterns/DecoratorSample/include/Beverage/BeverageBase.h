#ifndef BEVERAGEBASE_H
#define BEVERAGEBASE_H
#include <string>
#include <iostream>
class BeverageBase
{
    public:
        BeverageBase();
        std::string GetDiscription();
        virtual double GetCost() = 0;
        virtual ~BeverageBase();
    protected:
        std::string _description;
        double _cost;
    private:
};

#endif // BEVERAGEBASE_H
