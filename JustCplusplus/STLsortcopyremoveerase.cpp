#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool GreaterThanZero(int a) ///predicat
{
    return a>0;
}

class Person
{
public:
    Person(int mark,string name){this->mark = mark; this->name = name;}
    ~Person(){}
public:
    int mark;
    string name;
};


/*bool MyPred(int &a,int &b)
{
    return a>b;
}*/ ///it works in sort(1,2,MyPred)!

int main(){
    setlocale(0,"");
    vector<Person> b = {Person(12,"Василий"),
    Person(180,"Антон"),
    Person(131,"Борис"),
    Person(141,"Святой"),
    Person(89,"Дуся"),
    Person(191,"Сергей"),
    Person(124,"Стас"),
    Person(121,"Василий")};
    vector<int> v = {2,8,1,2,3,4,1};
    sort(v.begin(),v.end(),[](int a,int b){return a<b;});
    int arr[] = {1,5,2,3,4,0,18,1};
    sort(arr,arr + 8);
    for(int i = 0;i < 8;i++)
        cout << arr[i] << ' ';
    cout << endl;
    for (auto &it : v)
    {
        cout << &it << endl;
        //it = 2;
    }
    for(const auto &it : v)
    {
        cout << &it << ' ';
        cout << it << ' ' << endl;
    }
    for(auto &element : b)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    cout << "=========================\n";
    sort(b.begin(),b.end(),[](const Person &a,const Person &b)
    {
        return a.name < b.name;
    });
    for(auto &element : b)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    sort(b.begin(),b.end(),[](const Person &a,const Person &b)
    {
        return a.mark > b.mark;
    });
    cout << "=========================\n";
    for(auto &element : b)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    cout << "=========================\n";
    auto result = find(v.begin(),v.end(),229);
    cout << *result;
    auto result1 = find_if(v.begin(),v.end(),[](int a)
    {
       return a>8;
    });
    cout << endl;
    if(result1 == v.end())
    {
        cout << "NET" << endl;
    }else
    {
        cout << "DA" << endl;
    }
    auto result2 = find_if(b.begin(),b.end(),[](const Person &c)
    {
        return c.name == "Василий"; //&& c.mark = 100
    });
    if(result2 == b.end())
    {
        cout << "NET" << endl;
    }else
    {
        cout << "DA" << endl;
    }
    vector<Person> rvs;
    copy(b.begin(),b.end(),back_inserter(rvs));
    /*copy_if(b.begin(),b.end(),back_inserter(rvs), [](const Person &c)
    {
        return c.mark > 10 && c.mark < 150; ///ok
    });*/


    cout << "vector<Person> rvs.SIZE() = " << rvs.size() << endl;
    for(const auto &element : rvs)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    /// vector<int> v = {9,4,1,2,3,4,1};
    cout << "SIZE OF VECTOR V = " << v.size() << endl;
    cout << "BEFORE REMOVE" << endl;
    for(const auto &element : v)
    {
        cout << element << ' ';
    }
    cout << endl;
    auto result3 = remove(v.begin(),v.end(),1); /// remove () не удаляет, а переносит ненадобные нам элементы в конец
    /// и оставляет итератор с которого начинаются эти числа.
    cout << "AFTER REMOVE" << endl;
    for(const auto &element : v)
    {
        cout << element << ' ';
    }
    cout << endl;
    cout << "SIZE OF VECTOR V = " << v.size() << endl;
    v.erase(result3,v.end()); ///ерасе очищает с начала до коннца элементы
    cout << "AFTER ERASE" << endl;
    for(const auto &element : v)
    {
        cout << element << ' ';
    }
    cout << endl;
    cout << "SIZE OF VECTOR V = " << v.size() << endl;
    cout << "SIZE OF VECTOR<PERSON> RVS = " << rvs.size() << endl;
    cout << "BEFORE REMOVE" << endl;
    for(const auto &element : rvs)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    rvs.erase(remove_if(rvs.begin(),rvs.end(),[](const Person &c)
    {
        return c.mark > 120 && c.mark < 140;
    }), rvs.end());
    cout << "=========================\n";
    for(const auto &element : rvs)
    {
        cout << element.name << '\t' << element.mark << endl;
    }
    string str = "ONE TWO THREE FOUR FIVE ";
    cout << str << endl;
    //sort(str.begin(),str.end());
    //cout << str << endl;
    str.erase(remove(str.begin(),str.end(),' '), str.end());
    cout << str << endl;

	return 0;
}
