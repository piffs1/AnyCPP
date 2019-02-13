/* My realistaion stack
*
*
*
*/
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push_back(const T &data);
    size_t size() const {return _size;}
    T& top() const;
    void pop();
    bool empty() const {return !_size;};


private:
    template<typename X>
    struct Node
    {
        Node *pNext;
        T data;
        Node(T data=T(),Node *pNext = nullptr) // T() constructor equal = 0. maybe.
        {
            this->pNext = pNext;
            this->data = data;
        }
    };
    size_t _size;
    Node<T> *head;
};

template<typename T>
Stack<T>::Stack()
{
    head = nullptr;
    _size = 0;
}
template<typename T>
Stack<T>::~Stack()
{
    while(_size)
        this->pop();
}

template<typename T>
void Stack<T>::push_back(const T &data)
{
    Node<T> *current = new Node<T>(data, this->head);
    //current->pNext = this->head;
    head = current;
    _size++;
}

template<typename T>
T& Stack<T>::top() const
{
    return this->head->data;
}
template<typename T>
void Stack<T>::pop()
{
    Node<T> *previous = this->head->pNext;
    delete this->head;
    this->head = previous;
    _size--;
}

int main()
{
    Stack<int> c;
    return 0;
}
