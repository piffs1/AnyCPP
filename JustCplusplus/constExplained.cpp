// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
    const char *pChar1 = "Word";
    /// pChar1 is pointer at constant char
    /// pChar1[0] = 'B'; /// ERROR
    pChar1 = "Some";
    char *const pChar2  ="Boriska the Cat";
    /// pChar2 is const pointer at char
    /// ������ ������ ������,
    /// �������� ����� ����� ���������
    /// char | pChar2 const
    /// ��� ��� ����� - ��� ������� (const pointer)
    /// ��� ��� ������ ��� ��������� (char)
    pChar2[0] = 'W';
    /// pChar2 = "BBBB"; /// ERROR
    const char *const pChar3  = "Boriska krutoi cat";
    /// pChar3 is const pointer at const char
    /// pChar3[0] = "W"; //ERROR
    /// pChar3 = "CVC"; /// ERROR 
    const int *arr = new int[10];
    /// arr[0] = 1; /// Error const int
    arr = nullptr; /// pointer not const
    int *const arr1 = new int[5];
    arr1[0] = 2; /// ok
    /// arr1 = nullptr; /// error
    /// const pointer at int. ��������� �� �������, ������ �������
    const int arr2[10] = {0};

    
}
