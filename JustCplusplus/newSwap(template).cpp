/*template functions */

#include <iostream>
template<class T>
void void_returns(T &a, T &b)
{
    a = 5;
    b = 6;
}

/*void void_returns(T *a, T *b)
{
    *a = 5;
    *b = 6;
}*/

void void_out(int a,int b)
{
    std::cout << "a = " << a << " b = " << b;
}
template<class T>
void my_swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a,b;
    void_returns(a,b);
    void_out(a,b);
    my_swap(a,b);
    std::cout << std::endl;
    void_out(a,b);
    std::cout << std::endl;

	return 0;
}
