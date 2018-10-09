/* pow function recur */


///File was created with help_create.bat
#include <iostream>

int pow(int x,int n){
    if(n==0) {std::cout << "END" << std::endl; return 1; }
    if(n%2!=0) {std::cout << "X = " << x << " N-1 = " << n-1 << std::endl; return pow(x,n-1)*x;}
    std::cout << "x = " << x << " n = " << n << std::endl;
    int z = pow(x,n/2);
    return z*z; ///Optimised from return pow(x,n/2) * pow(x,n/2)
}

int main()
{
    std::cout << pow(2,5);

    return 0;
}
