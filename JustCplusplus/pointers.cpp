/* pointer aryphmetic */

#include <iostream>

int main(){
    int a = 2;
    int &aref = a;
    int *pa = &a;
    std::cout << "&aref = " << &aref << "\taref =" << aref << std::endl;
    std::cout << "pa = " << pa << "\t*pa = " << *pa << std::endl;
    std::cout << "pa+2 = " << pa+2 << std::endl; ///��������� �����
    aref = 5;
    std::cout << "aref = 5, a = " << a << std::endl;
    /// int *p ok int &p error ����� ������������� => int &p = a ok
    int *paref = &aref; /// int *paref != aref!!! ��������� �� ������. ������ ����� ������
    std::cout << "a =" << a << std::endl;
    *paref = 10;
    std::cout << "a =" << a << std::endl;
	return 0;
}
