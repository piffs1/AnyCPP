#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> b= {0,1}; /// (20,55) - 20 количество элементов, 55 значения этих 20 элементов
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
    b.clear(); ///очищение
    cout << "Capacity = " << b.capacity() << endl;
    ///в векторе память выделяется с запасом
    ///если капасити 10 а сайз 4, то есть еще 6 свободных ячеек которые находятся рядом
    b.reserve(12); /// меняем capacity
    cout << "Capacity = " << b.capacity() << endl;
    b.shrink_to_fit(); ///Если мы зарезервировали до очень высокого значения, то
    ///shrink_to_fit() урезает эти значения до уровня size
    cout << "Capacity = " << b.capacity() << endl;
    b.resize(13,66); /// аналогично с 20 55
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
    b.erase(i+1,i+3); ///Удаляет нижнюю границу, оставляет верх.
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
