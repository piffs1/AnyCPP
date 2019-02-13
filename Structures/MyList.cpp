/* My realisation list */

#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();
    bool empty() const {return !_size;}
    void push_front(const T &data);
    void push_back(const T &data);
    void pop_front();
    void pop_back();
    T& operator[](const size_t &index);
    size_t size(){return _size;}
    void ShowList() const;
    void Add(T &data,int &position);
    void RemoveAt(const int &position);
    void Debug() const;
    ///bool eq() {return head==tail;} operator==worked
private:
    template<typename X>
    struct Node
    {
        Node *pNext,*pPrev;
        T data;
        Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
		/*bool operator==(const Node& node1)
		{
		    if(this->data == node1.data) return true;
		    else false; /// operator worked.
		}*/
    };
    Node<T> *head;
    Node<T> *tail;

    size_t _size;
};
template<typename T>
List<T>::List()
{
    _size = 0;
    head=nullptr;
    tail=nullptr;
}
template<typename T>
List<T>::~List()
{
    if(_size==0){return;}
    while(_size!=1)
    {
        pop_back();
    }
    delete head; ///tail == head
    tail = head = nullptr;
}
template<typename T>
void List<T>::push_front(const T &data)
{
    Node<T> *temp = new Node<T>(data);
    temp->pNext = head;
    temp->pPrev = nullptr;

    if(!_size)
    {
        head = temp;
        tail = temp;
        _size++;
        return;
    }
    head->pPrev = temp;
    head = temp;
    _size++;
}

template<typename T>
void List<T>::push_back(const T &data)
{
    Node<T> *temp = new Node<T>(data);
    temp->pPrev = tail;
    temp->pNext = nullptr;

    if(!_size) /// Size==0
    {
        head = temp;
        tail = temp;
        _size++;
        return;
    }
    tail->pNext = temp;
    tail = temp;
	_size++;
}
template<typename T>
T& List<T>::operator[](const size_t &index)
{
    int counter = 0;
    Node<T> *current = head;
    while(current!=nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    /*else
    {
        Node<T> *current = this->tail;
        while(current!=nullptr)
        {
            if(counter == index)
            {
                ///cout << "current->pNext " << current->pNext << " current->pPrev " << current->pPrev << endl;
                return current->data;
            }
            current = current->pPrev;
            counter++;
        }
    }*/

}
template<typename T>
void List<T>::ShowList() const
{
    Node<T> *current = head;
    int index = 0;
    while(current!=nullptr)
    {
        current = current->pNext;
    }
    ///if(current==nullptr) {current = head; index = 0;}
}
template<typename T>
void List<T>::Debug() const
{
    Node<T> *current = head;
    int index = 0;
    while(current!=nullptr)
    {
        current = current->pNext;
    }
    ///if(current==nullptr) {current = head; index = 0;}
}
template<typename T>
void List<T>::Add(T &data,int &position)
{
    int SP = _size-position;
    if (position == 0)
    {
        push_front(data);
        return;
    }
    if (position == _size)
    {
        push_back(data);
        return;
    }
    if(SP>position)
    {
        Node<T> *current = head;
        for(int i = 0;i < position - 1;i++)
        {
            current = current->pNext;
        }
        Node<T> *temp = new Node<T>(data,current->pNext,current->pNext->pPrev);
        current->pNext = temp;
        temp->pPrev = current;
        temp->pPrev = current;
        temp->pNext->pPrev = temp;
        ///left
    }
    else
    {
        Node<T> *current = tail;
        for(int i = 0;i < SP; i++)
        {
            current = current->pPrev;
        }
        Node<T> *temp = new Node<T>(data,current->pNext,current->pNext->pPrev);
        current->pNext = temp;
        temp->pPrev = current;
        temp->pNext->pPrev = temp;
        ///right
    }
    _size++;

}
template<typename T>
void List<T>::pop_front()
{
    Node<T> *current = head;
    head = head->pNext;
    head->pPrev = nullptr;
    delete current;
    _size--;
}

template<typename T>
void List<T>::pop_back()
{
    Node<T> *current = tail;
    tail = tail->pPrev;
    tail->pNext = nullptr;
    delete current;
    _size--;
}

template<typename T>
void List<T>::RemoveAt(const int &position)
{
    if(position==0) {pop_front(); return;}
    if(position==_size-1){pop_back(); return;}
    int SP = _size-position;
    if(SP>position)
    {
        Node<T> *current = head;
        for(int i = 0;i < position - 1;i++)
        {
            current = current->pNext;
        }
        Node<T> *toDelete = current->pNext;
        current->pNext = toDelete->pNext;
        current->pNext->pPrev = current;
        delete toDelete;
        ///left
    }
    else
    {
        Node<T> *current = tail;
        for(int i = 0;i < SP-1; i++)
        {
            current = current->pPrev;
        }
        Node<T> *toDelete = current->pNext;
        current->pNext = toDelete->pNext;
        current->pNext->pPrev = current;
        delete toDelete;
        ///right
    }
    _size--;
}

int main(){
    List<int> b;
	return 0;
}
