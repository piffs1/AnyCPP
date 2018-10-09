/* recursion factorial */

#include <iostream>

int factorial(int n)
{
    if (n==1) return 1;
    return factorial(n-1)*n;
}

int main(){
    int n;
    std::cout << "Input N = ";
    std::cin >> n;
    std::cout << "Factorial(" << n <<")=" << factorial(n);
	return 0;
}
