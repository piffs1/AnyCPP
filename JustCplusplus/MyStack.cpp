/* My realistaion stack */

#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;


template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push_back(const T data);
    int GetSize(){return Size;}
    T top() const;
    void pop();
    inline bool isEmpty();


private:
    template<typename X>
    struct Node
    {
        Node *pNext;
        T data;
        Node(T data=T(),Node *pNext = nullptr)
        {
            this->pNext = pNext;
            this->data = data;
        }
    };
    int Size;
    Node<T> *head;
};

template<typename T>
Stack<T>::Stack()
{
    head = nullptr;
    Size = 0;
}
template<typename T>
Stack<T>::~Stack()
{
    while(Size)
        this->pop();
}

template<typename T>
void Stack<T>::push_back(const T data)
{
    ///cout << "==================push_back start====================\n";
    Node<T> *current = new Node<T>(data);
    ///cout << "current = " << current << " current->pNext = " << current->pNext << " current->data = " << current->data << " this->head = " << this->head  << endl;
    current->pNext = this->head;
    head = current;
    ///cout << "current = " << current << " current->pNext = " << current->pNext << " current->data = " << current->data << endl;
    Size++;
    ///cout << "==================push_back stop====================\n";
}

template<typename T>
T Stack<T>::top() const
{
    return this->head->data;
}
template<typename T>
void Stack<T>::pop()
{
    ///cout << "==================pop start====================\n";
    Node<T> *previous = this->head->pNext;
    ///cout << "this->head = " << this->head << " previous = " << previous <<  " data = " << this->head->data << endl;
    delete this->head;
    this->head = previous;
    Size--;
    ///cout << "==================pop stop====================\n";
}
template<typename T>
inline bool Stack<T>::isEmpty()
{
    return !Size;
}

void dr()
{
    Stack<long long> c;
    for(int i = 0; i < 10000000; i++)
    {
        c.push_back(i);
    }
    system("pause");
}


int main()
{
    //system("pause");
    //dr();
    Stack<int> c;
    cout << c.isEmpty();
    /*
    cout << c.GetSize() << endl;
    for(int i = 0; i < 100; i++)
        c.pop();
    if(!c.isEmpty())
        c.pop();
    system("pause");*/
    return EXIT_SUCCESS;
}
