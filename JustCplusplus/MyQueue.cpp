/* My realistion queue */

#include <iostream>
#include <string>

using namespace std;
template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    bool isEmpty();
    T& back() const;
    T& front() const;
    void push(const T data);
    void pop();
    int GetSize(){return Size;}
    void Debug() const;
private:
    template<typename X>
    struct Node
    {
        Node* pNext;
        T data;
        Node(T data=T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
        //~Node(){cout << "deleting... " << this << ' ' << data << endl;}
    };
    Node<T> *pFront,*pBack;
    int Size;
};
template<typename T>
Queue<T>::Queue()
{
    Size = 0;
    pFront = nullptr;
    pBack = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
    if(Size==0){return;}
    while(Size!=1)
        pop();
    delete pFront;
    pFront = pBack = nullptr;
}

template<typename T>
void Queue<T>::push(const T data)
{
    Node<T> *newNode = new Node<T>(data,pBack);
    pBack = newNode;
    if(!Size) {pFront = newNode; Size++; return;}
    Size++;
}

template<typename T>
void Queue<T>::pop()
{
    Node<T> *toDelete = pBack;
    pBack = pBack->pNext;
    delete toDelete;
    Size--;
    //cout << "Size is " << Size << endl;
}

template<typename T>
void Queue<T>::Debug() const
{
    Node<T> *currentDebug = pBack;
    while(currentDebug!=nullptr)
    {
        cout << "address " << currentDebug << " next " << currentDebug->pNext << " data " << currentDebug->data << endl;
        currentDebug = currentDebug->pNext;
    }
}
template<typename T>
T& Queue<T>::front() const
{
    cout << &pFront->data;
    return pFront->data;
}

template<typename T>
T& Queue<T>::back() const
{
    cout << &pFront->data;
    return pBack->data;
}
template<typename T>
bool Queue<T>::isEmpty()
{
    return !Size;
}

void Debug()
{
    Queue<long long int> b;
    for(int i = 0; i < 1000000;i++)
        b.push(i);
    //cout << b.GetSize() << endl;
    //b.Debug();
    system("pause");
}

int main(){
    Queue<int> b;
    b.front();
    b.back();
	return 0;
}
