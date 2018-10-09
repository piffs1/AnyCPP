#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> b= {0,1}; /// (20,55) - 20 ���������� ���������, 55 �������� ���� 20 ���������
    b.push_back(1);
    b.push_back(2);
    try
    {
        cout << b.at(4) << endl;
    }
    catch(const std::out_of_range &ex)
    {
        cout << ex.what() << endl;
    }
    b.clear(); ///��������
    cout << "Capacity = " << b.capacity() << endl;
    ///� ������� ������ ���������� � �������
    ///���� �������� 10 � ���� 4, �� ���� ��� 6 ��������� ����� ������� ��������� �����
    b.reserve(12); /// ������ capacity
    cout << "Capacity = " << b.capacity() << endl;
    b.shrink_to_fit(); ///���� �� ��������������� �� ����� �������� ��������, ��
    ///shrink_to_fit() ������� ��� �������� �� ������ size
    cout << "Capacity = " << b.capacity() << endl;
    b.resize(13,66); /// ���������� � 20 55
    for(auto it = b.begin(); it!=b.end(); it++)
    {
        cout << *it << endl;
    }
    vector<int>::iterator it;
    ///cbegin/cend const iterator
    int index = 0;
    for(auto i = b.begin(); i!= b.end(); i++)
    {
        *i = index++;
    }
    auto i = b.begin();
    b.erase(i+1,i+3); ///������� ������ �������, ��������� ����.
    for(auto i = b.cbegin(); i!=b.cend();i++)
    {
        cout << "b[" << *i << ']' << endl;
    }

    for(vector<int>::const_iterator i = b.cbegin(); i!=b.cend();i++) ///const iterator. Cant change data from iterator.
    {

    }
    for(vector<int>::const_reverse_iterator i = b.crbegin(); i!= b.crend();i++)
    {}
    advance(it,3); /// == iterator it = it + 3







	return 0;
}
