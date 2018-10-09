#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

static int mas[] = {1,2,41,1,23,56,1,3,32};


int main(){
    vector<int> v;
    cout << end(mas) - begin(mas) << endl;
    for(int i = 0;i < 10; i++)
        v.push_back(rand()%20);
    cout << "VECTOR V = ";
    for(const auto &element : v)
    {
        cout << element << ' ';
    }
    cout << endl;
    auto s = max_element(v.begin(),v.end());
    cout << *s << endl;
    int arr[] = {3,3,1,0,7,1,6,10};
    for(int &element : arr)
    {
        cout << element << ' ';
    }
    cout << endl;

    auto s1 = max_element(arr,arr+8);

    cout << arr[7] << ' ' << &arr[7] << endl;

    cout << *s1 << ' ' << s1 << endl;
    ///min_element() == max_element

    auto s2 = minmax_element(arr,arr+8);

    cout << "MIN ELEMENT = \t" << *s2.first << "\t MAX ELEMENT = \t" << *s2.second << endl;

    int c[] = {2,3,4};
    for(int i = 0; i < sizeof(c)/sizeof(int);i++)
        cout << &c[i] << ' ';
    cout << endl;

    //int c[] = {2,3,4}; == vector
    //begin() end() works with any container
    auto result = accumulate(begin(c),end(c),1,[](int &a, int &b) /// a = 1. ќн записывает в &a значение умножени€
    {
        cout << &a << ' ' << &b << endl;
        return a * b;
    });
    auto result1 = accumulate(begin(c),end(c),0,[](int &a, int &b)
    {
        if(b%2==0)
            return a+b;
        else
            return a;
    });
    /// next - next iterator
    /// prev - previous iterator

    auto result2 = accumulate(next(begin(v)),prev(end(v)), to_string(mas[0]),[](string a,int b)
    {
        return a+'-'+to_string(b);
    });
    cout << "result1 = " << result1 << endl;
 ///0(точка отсчета) отправна€ точка с которой будет сумироватьс€.
    /// по сути sum = 0; sum+=sum; 0 + 2 + 3 + 4 = 9 .≈сли было бы 9, то было 9 + 2 + 3 + 4 = 18
    cout << "result = " << result << endl;
    cout << "result2 = " << result2 << endl;

    return 0;
}
