/* copy dynamic arrays */

#include <iostream>
#include <cstdlib>
#include <ctime>
const char NEWLINE = '\n';
const int SIZE = 10;
const char TABULATION[] = "        "; 
const char SEPARATOR[] = "=========================================================================================================="; /// STID BLYAT
template<class T>
void FillArray(T *a, const int size)
{
    for(int i = 0; i < size;i++){
        a[i] = rand() % 10;
        std::cout << &a[i] << ' ';
    }

}
template<class T>
void ShowArray(const T *a, const int size)
{
    for(int i = 0;i < size; i++)
        std::cout << a[i] << TABULATION;
}
template<class T>
void ShowArrayAddress(const T *a, const int size)
{
    for(int i = 0;i < size; i++)
        std::cout << &a[i] << ' ';
}

int main(){
    srand(time(NULL));
    int *mas1 = new int[SIZE];
    int *mas2 = new int[SIZE];
    std::cout << "Address =\t";
    FillArray(mas1,SIZE);
    std::cout << NEWLINE << "Mas1 = \t\t";
    ShowArray(mas1,SIZE);
    std::cout << NEWLINE << "Address =\t";
    FillArray(mas2,SIZE);
    std::cout << NEWLINE << "Mas2 = \t\t";
    ShowArray(mas2,SIZE);
    std::cout << NEWLINE << SEPARATOR;
    delete[] mas1;
    mas1 = nullptr;
    mas1 = new int[SIZE];
    ///mas1 = mas2;
    for(int i = 0;i < SIZE;i++) ///WORKS
        mas1[i] = mas2[i];
    std::cout << NEWLINE << "Address =\t";
    ShowArrayAddress(mas1,SIZE);
    std::cout << NEWLINE << "Mas1 = \t\t";
    ShowArray(mas1,SIZE);
    std::cout << NEWLINE << "Address =\t";
    ShowArrayAddress(mas2,SIZE);
    std::cout << NEWLINE << "Mas2 = \t\t";
    ShowArray(mas2,SIZE);
    std::cout << NEWLINE << SEPARATOR;
    delete[] mas1;
    delete[] mas2;
    return 0;
}
