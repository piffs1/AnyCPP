/* template second max realisation */

#include <iostream>

using std::cout;
using std::endl;

const int SIZE = 10;
template<typename T>
void findMax2(const T &a)
{
    //.first - самый большой максимум, .second - второй максимум после первого
    if(SIZE<2) return;
    if(SIZE==2)
    {
        if(a[0]>a[1])
            cout << a[0] << ' ' << a[1];
        else
            cout << a[1] << ' ' << a[0];
        return;
    }
    int maxFirst = a[0];
    int maxSecond = a[1];
    if(maxSecond>maxFirst) std::swap(maxSecond,maxFirst);
    for(int i = 2; i < SIZE; i++)
    {
        if(maxFirst<a[i])
        {
            maxSecond = maxFirst;
            maxFirst = a[i];
        }
        if(maxSecond<a[i] && a[i]<maxFirst)
        {
            maxSecond = a[i];
        }
    }
    cout << maxFirst << ' ' << maxSecond;
}

int main()
{
    int a[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        a[i] = rand()%10;
        cout << a[i] << ' ';
    }
    cout << endl;
    findMax2(a);
    return 0;
}
