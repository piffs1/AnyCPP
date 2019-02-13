/* hashTable for int hash keys */

#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 128;

template<typename V>
struct Cell
{
    vector<V> value;
};
template<typename V>
class HashTable
{
public:
    int checkCollisionsRows() const
    {
        int result = 0;
        for(int i = 0; i < TABLE_SIZE; i++)
            if(hashTable[i].value.size()>1)
                result++;
        return result;
    }
    void put(const int &key, const V &value)
    {
        int hash = key % TABLE_SIZE;
        hashTable[hash].value.push_back(value);
    }
    V get(const int &key, const V &value)
    {
        int hash = key % TABLE_SIZE;
        if(hashTable[hash].value.size()==1)
            return hashTable[hash].value[0];
        if(hashTable[hash].value.size()> 1)
        {
            for(int i = 0; i < hashTable[hash].value.size(); i++)
                if(hashTable[hash].value[i] == value)
                    return hashTable[hash].value[i];
            return -1;
        }
    }
    void debugSizes()
    {
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            cout << "row " << i << ' ' << hashTable[i].value.size() << endl;
        }
    }
private:
    Cell<V> hashTable[TABLE_SIZE];
};

int main()
{
    HashTable<int> ht;
    for(int i = 0; i < 5000;i++)
    {
        ht.put(rand()%TABLE_SIZE,rand()%100);
    }
    ht.debugSizes();
    cout << endl;
    cout << "Count collisions rows " << ht.checkCollisionsRows() << endl;
    return 0;
}
