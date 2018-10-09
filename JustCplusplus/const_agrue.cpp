#include <iostream>

void FillArray(int *a, const int size) ///�������� ������������ ������(�����).
{
    for(int i = 0;i < size; i++)
        a[i] = i;
}

void ShowArray(const int *a, const int size) /// ������� ������� ������. ������� �������� ����������, ���������� ������� ����������
{
    for(int i = 0; i < size; i++)
        std::cout << a[i] << ' ';
}

int main(){
    int a[10];
    FillArray(a,10);
    ShowArray(a,10);

	return 0;
}
