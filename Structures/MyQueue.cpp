/* My realistion queue
*
* Problem with destructor. Review later.
*
*/

#include <iostream>
#include <string>

using namespace std;
template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty() const {return !_size;};
    T& back() const {return pBack->data;}
    T& front() const {return pFront->data;}
    void push(const T &data);
    void pop();
    size_t size() const {return _size;}
private:
    template<typename X>
    struct Node
    {
        Node* pNext;
        Node* pPrev;
        T data;
        Node(T data=T(), Node* pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node<T> *pFront,*pBack;
    size_t _size;
};
template<typename T>
Queue<T>::Queue()
{
    _size = 0;
    pFront = nullptr;
    pBack = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
    if(_size==0){return;}
    while(!_size) // maybe wrong.
        pop();
   // delete pFront;
    //pFront = pBack = nullptr;
}

template<typename T>
void Queue<T>::push(const T &data)
{
    Node<T> *newNode = new Node<T>(data); //maybe Node<T>(data,pBack);
    if(!_size){pFront = pBack = newNode; _size++; return;}
    newNode->pNext = pBack; // linking new node. (NewNode)->(pBack).
    pBack->pPrev = newNode; // linking old back node. (NewNode)<-(pBack).
    pBack = newNode; //updating back pointer.
    _size++;
}

template<typename T>
void Queue<T>::pop()
{
    Node<T> *current = pFront->pPrev; // taking post front element
    delete pFront; //deleting front element of queue
    current->pNext = nullptr; // front next element is nullptr
    pFront = current; // new front element = previous old front element
    _size--;
}

int main(){
    Queue<int> b;
	return 0;
}
