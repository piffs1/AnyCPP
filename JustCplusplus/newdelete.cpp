/* newdelete */

#include <iostream>

using namespace std;

/// ���� ����� new ����������� ����� delete. ������ ���������� ����� ���������.
/// ������� ������� ���������, ����� ����������� nullptr. ���� ������� ��������, �� �������� �����, �� ������ ���������.
int main(){
    int *pa = new int;
    delete pa;
    pa = nullptr; /// pa = NULL -std=+11C
	return 0;
}
