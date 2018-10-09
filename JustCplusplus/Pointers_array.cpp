/* pointers ary v2 */
#include <iostream>

const char NEWLINE = '\n';
const int SIZE = 10;

int main(){
    setlocale(0,"");
    std::cout << "Указатели определяют жизнь объекта. Указатели очищаются вручную. Цикл жизни обычных переменных = времени исполнения функции. После завершения функции переменные очищаются.";
    int a[SIZE];
    for(int i = 0; i < SIZE; i++)
        a[i] = SIZE - 1 - i;
    std::cout << "Метод вывода массива *(a+i) a - обычный массив , i - шаг." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << *(a+i) << ' ';
    std::cout << NEWLINE << "Вывод массива через a[i] " << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << a[i] << ' ';
    std::cout << NEWLINE << "Вывод массива через указатель *pa = a. В нашем случае a - это указатель на a[0].Т.е. Эквивалент a = &a[0]" << NEWLINE;
    int *pa = a;
    for(int i = 0;i < SIZE; i++)
        std::cout << pa[i] << ' ';
    ///pa[i] == *(pa+i)
    std::cout << NEWLINE << "Вывод массива через *(pa+i)." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << *(pa+i) << ' ';
    int *paa = &a[0];
     std::cout << NEWLINE << "Вывод массива через указатель paa = &a[0]." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
    std::cout << *(paa+i) << ' ';
    std::cout << NEWLINE << "Вывод через *(pa+1),(1)[a],*(a+1) " << NEWLINE;
    std::cout << "a[1] = " << *(pa+1) <<  ",a[1] = " << (1)[a] << ",a[1] = " << *(a+1);
    std::cout << NEWLINE << "------------------------" << NEWLINE;
    std::cout << "a[]\t" << a << NEWLINE << "pa\t" << pa << NEWLINE << "A[0]\t" << &a[0];
    std::cout << NEWLINE << "------------------------" << NEWLINE;
    std::cout << "C++ прекрасен" << NEWLINE;
    return 0;
}
