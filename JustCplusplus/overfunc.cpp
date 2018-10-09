/* Overload function */

#include <iostream>

struct new_struct{
    int a;
    int b;
};
int Sum(new_struct a){return a.a + a.b;};
int Sum(int a, int b){return a+b;}
int Sum(int a,int b, int c){return a+b+c;}
double Sum(double a,double b){return a+b;}

int main(){
    new_struct a;
    a.a = 2;
    a.b = 4;
    std::cout << Sum(a) << std::endl;
    std::cout << Sum(2,3) << std::endl;
    std::cout << Sum(2,3,4) << std::endl;
    std::cout << Sum(2.1,3.1) << std::endl;
	return 0;
}
