/* pointers ary v2 */
#include <iostream>

const char NEWLINE = '\n';
const int SIZE = 10;

int main(){
    setlocale(0,"");
    std::cout << "��������� ���������� ����� �������. ��������� ��������� �������. ���� ����� ������� ���������� = ������� ���������� �������. ����� ���������� ������� ���������� ���������.";
    int a[SIZE];
    for(int i = 0; i < SIZE; i++)
        a[i] = SIZE - 1 - i;
    std::cout << "����� ������ ������� *(a+i) a - ������� ������ , i - ���." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << *(a+i) << ' ';
    std::cout << NEWLINE << "����� ������� ����� a[i] " << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << a[i] << ' ';
    std::cout << NEWLINE << "����� ������� ����� ��������� *pa = a. � ����� ������ a - ��� ��������� �� a[0].�.�. ���������� a = &a[0]" << NEWLINE;
    int *pa = a;
    for(int i = 0;i < SIZE; i++)
        std::cout << pa[i] << ' ';
    ///pa[i] == *(pa+i)
    std::cout << NEWLINE << "����� ������� ����� *(pa+i)." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
        std::cout << *(pa+i) << ' ';
    int *paa = &a[0];
     std::cout << NEWLINE << "����� ������� ����� ��������� paa = &a[0]." << NEWLINE;
    for(int i = 0; i < SIZE; i++)
    std::cout << *(paa+i) << ' ';
    std::cout << NEWLINE << "����� ����� *(pa+1),(1)[a],*(a+1) " << NEWLINE;
    std::cout << "a[1] = " << *(pa+1) <<  ",a[1] = " << (1)[a] << ",a[1] = " << *(a+1);
    std::cout << NEWLINE << "------------------------" << NEWLINE;
    std::cout << "a[]\t" << a << NEWLINE << "pa\t" << pa << NEWLINE << "A[0]\t" << &a[0];
    std::cout << NEWLINE << "------------------------" << NEWLINE;
    std::cout << "C++ ���������" << NEWLINE;
    return 0;
}
