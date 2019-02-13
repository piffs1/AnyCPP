/* My atoi realisation */

#include <iostream>

using namespace std;

int naturalPow10(const unsigned short &step)
{
    int result = 1; // pow for natural numbers. Error with <cmath> pow()
    for(int i = 0; i < step;i++)
        result*=10;
    return result;
}

int toInt(const char &c)
{
    switch(c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}

int MyAtoi(const char *str)
{
    int result = 0;
    int size;
    for(size = 0; str[size]!='\0'; size++){} // get size of str[]
    if(str[0]=='-'){
        for(int i=1; i < size; i++)
        {
            if(str[i] > '0' && str[i] < '9')
                result = result + toInt(str[i])*naturalPow10(size-i-1);
            else
                return 0;
        }
        return -result;
    }
    for(int i=0; i < size; i++)
    {
        if(str[i]>='0' && str[i] <='9')
            result = result + toInt(str[i])*naturalPow10(size-1-i);
        else
            return 0;
    }
    return result;
}

int main()
{
    int ma = MyAtoi("12");
    cout << ma;
    return 0;
}
