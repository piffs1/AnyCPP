/* My realisation vector
* capacity permanently 4. rework later.
* Notice:
* need rework pop_back()
* need rework push_back()
* need rework clear
* need rework _capacity
* need rework at()
*/

#include <iostream>

using namespace std;

template<typename T>
class Vector
{
public:
    Vector();
    Vector(const int &size);
    ~Vector();
    T& at(const size_t index) const;
    void push_back(T data);
    void pop_back();
    size_t capacity() const { return _capacity; }
    size_t size() const {return _size; }
    T& front() const {return data[0];}
    T& back() const {return data[_size-1];}
    bool empty() const {return !_size;}
    void assign(T _fill);
    // void insert();
    // void emplace();
    T& operator[](const int index);
    void clear() { _size = 0; }
private:
    size_t _capacity;
    size_t _size;
    T *data;
};

template<typename T>
T& Vector<T>::at(const size_t index) const
{
    if (index < 0 || index >= _size)
        throw; // need exception
}
template<typename T>
void Vector<T>::assign(T _fill)
{
    for(size_t i = 0; i < _size; i++)
        data[i] = _fill;
}
template<typename T>
Vector<T>::~Vector()
{
    delete[] data;
}
template<typename T>
void Vector<T>::push_back(T data)
{
    if(_capacity!=0)
    {
        this->data[_size] = data;
        _size++;
        _capacity--;
    }else
    {
        _capacity = 4;
        T *newArray = new T[_size+_capacity]; // creating new array
        for(size_t i = 0;i < _size;i++)
            newArray[i] = this->data[i]; // copy of old array
        delete[] this->data;
        this->data = newArray;
        this->data[_size] = data;
        _size++;
    }
}
template<typename T>
void Vector<T>::pop_back()
{
    _size--; // up later
}
template<typename T>
T& Vector<T>::operator[](const int index)
{
    return data[index];
}

template<typename T>
Vector<T>::Vector()
{
    _size = 0;
    _capacity = 4;
    data = new T[_capacity];
}

template<typename T>
Vector<T>::Vector(const int &size)
{
    _size = 0;
    _capacity = size;
    data = new T[_size+_capacity];
}

int main()
{
    Vector<int> b;
    vector<int> c;

    return 0;
}
