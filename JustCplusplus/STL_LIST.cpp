#include <iostream>
#include <list>

using namespace std;

template<typename T>
void PrintList(const list<T> &lst)
{
    for(auto it=lst.cbegin(); it!=lst.cend();it++)
    {
        cout << "element = " << *it << endl;
    }
}
template<typename T>
void PrintList1(const list<T> &lst)
{
    for(auto it=lst.cbegin(); it!=lst.cend();++it)
    {
        cout << "element = " << *it << endl;
    }
}

int main(){
    list<int> myList = {7,1,3,5422,0,7,7,7,7,7};
    myList.push_back(4);
    myList.push_front(5);
    list<int>::iterator it = myList.begin();
    //cout << *it << endl;
    myList.unique(); /// удаляет последовательные повторения элементов 7,1,3,5422,0,7,7,7,7,7 -> 1,3,5422,0,7 ok
    myList.sort();
    myList.pop_back();
    myList.pop_front();
	myList.reverse(); ///переворачивает лист
	myList.remove(7); ///удаляет конкретное
    myList.assign(3,12); ///3 kolvo 12 znachenie udalyaet vse nahui
	list<int> myList2 = {12,11,10,68};
	myList.assign(myList2.cbegin(),myList2.cend()); ///copy lol
	list<int> myList3;
	for(int i = 0; i < 100000;i++)
        myList3.push_back(i);
	//PrintList(myList3);
	PrintList1(myList3);
	it++;
	return 0;
}
