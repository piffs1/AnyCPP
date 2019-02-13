#include <unordered_map>
#include <string>
#include <iostream>

const unsigned short TABLE_SIZE = 32768;

using namespace std;

int main()
{
    unordered_map<string,int> numbers;
    hash<string> hashfunc = numbers.hash_function();
    numbers.insert(make_pair(atoi(hashfunc("one")),1));
    for(auto it = numbers.begin(); it!=numbers.end(); ++it)
    {
        cout << it->first << ":" << it->second << " (hash = " << hashfunc(it->first) << ")" << endl;
    }
    return 0;
}
