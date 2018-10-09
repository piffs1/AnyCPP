/*
*
* Parent function
*
*/

#include <iostream>

using namespace std;

class First_Class
{
public:
    First_Class(string help){this->help = help;}
    virtual ~First_Class(){}
    virtual string GetHelp()
    {
        return help;
    }
private:
    string help;
};
class Second_Class : public First_Class
{
public:
    Second_Class(string help):First_Class(help)
    {cout << help << '\n';}
    ~Second_Class(){}
    string GetHelp() override
    {
        return "Вызвана функция GetHelp() из родительского класса First_Class\n->" + ::First_Class::GetHelp() + "<-";
    }
private:

};
class Third_Class
{
public:
    void Print(First_Class *first_class)
    {
        cout << first_class->GetHelp() << endl;
    }
private:

};


int main(){
    setlocale(0,"");
    First_Class first_class("Hello");
    Third_Class third;
    third.Print(&first_class);
    Second_Class second_class("Hi");
    third.Print(&second_class);
	return 0;
}
