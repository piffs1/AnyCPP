#include <iostream>

using namespace std;

const int TABLE_SIZE = 128;

template<typename K,typename V>
class HashEntry {
public:
    HashEntry(K key, V value)
    {
        this->key = key;
        this->value = value;
    }
    K getKey() const {return key;}
    V getValue() const {return value;}
private:
    K key;
    V value;
};
template<typename K,typename V>
class HashMap {
public:
    HashMap()
    {
        table = new HashEntry<K,V>*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }
    V get(K key) const
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == nullptr)
            return -1;
        else
            return table[hash]->getValue();
    }
    void put(K key, V value)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != nullptr)
            delete table[hash];
        table[hash] = new HashEntry<K,V>(key, value);
    }
    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != nullptr)
                delete table[i];
        delete[] table;
    }
private:
      HashEntry<K,V> **table;
};

int main()
{
    HashMap<int,int> s;
    s.put(10,12);
    s.get(10);
    return 0;
}
