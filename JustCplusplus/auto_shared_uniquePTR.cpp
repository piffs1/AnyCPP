#include <iostream>
#include <string>
#include <memory>

/*
*
* smart pointers
*
*/

using namespace std;



int main(){

    auto_ptr<int> ap1(new int(10));
    cout << ap1.get() << endl; // OK. ADDRESS EXISTS
    // auto_ptr::get taking pointer
    //cout << ap1.release() << endl; // returns address and ap1=0
    //cout << ap1.get();
    // ap1.reset(); delete ap1
    auto_ptr<int> ap2(ap1);  ///����� ����������� ������ ��������� �� �� �� ������� ������
    /// �� ��������� ������� ������ �������� �� �� ������� ������ ����������.

    unique_ptr<int> up1(new int(20));
    /// unique_ptr<int> up2(up1); ���������� ���������.
    ///up2 = move(up1); /// ������������ ��������� up1 � up2 � ������ ��������� ����������. ����� � �������
    ///up2.swap(p1);

    int *p = new int(5);
    unique_ptr<int> up2(p);
    ///up2.reset - ������� ������
    ///up2.release - ������� ��� ����
    shared_ptr<int> sp1(new int(3));
    shared_ptr<int> sp2(sp1);
    /// shared_ptr - � ����������� ����� ����������� ������� ����������. � ���� �������� ���������� >1 �� ��
    /// ��������� ��������(������� ���������� �� ������ ������� ������) � ������� ������� ��.
    /// ���� �� ��������� 1 ��������� �� ������� ������. ����� ���� �� �������� ������� ������. � ����� ���������
	return 0;
}
