/*
*
* sending array in function.
*
*/


#include <iostream>

 const int SIZE = 10;

 void fillArray(int* a)
 {
     std::cout << "FUCNTION &" << a << std::endl;
     for (int i = 0; i < SIZE ; i++)
        a[i] = i;
 }
 void printArray(const int *a) // const int *a. Guarantee constancy variable a[]
 {
     for (int i = 0;i < SIZE; i++)
        std::cout << a[i] << std::endl;
 }

int main(){
// some code..
    int *a = new int[SIZE];
    int b[SIZE];
    std::cout << "a = new int[] " << a << std::endl; // a - pointer of a[0]
    fillArray(a);
    std::cout << "b[] " << b << std::endl; // b - pointer of b[0]
    fillArray(b);
    printArray(a);
    std::cout << "/--------------------/" << std::endl;
    printArray(b);
    delete[] a;
	return 0;
}
