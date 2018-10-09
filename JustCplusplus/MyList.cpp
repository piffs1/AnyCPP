/* My realisation list */

#include <iostream>
#include <string>
#include <thread>
#include <windows.h>
using namespace std;
template<typename T>
class List
{
public:
    List();
    ~List();
    bool isEmpty(){return !Size;}
    void push_front(const T data);
    void push_back(const T data);
    void pop_front();
    void pop_back();
    T& operator[](const int index);
    int GetSize(){return Size;}
    void ShowList() const;
    void Add(T data,int position);
    void RemoveAt(const int position);
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

    int Size;
};
template<typename T>
List<T>::List()
{
    Size = 0;
    head=nullptr;
    tail=nullptr;
}
template<typename T>
List<T>::~List()
{
    if(Size==0){return;}
    while(Size!=1)
    {
        pop_back();
    }
    //this_thread::sleep_for(chrono::microseconds(1));
    delete head; ///tail == head
    tail = head = nullptr;
}
template<typename T>
void List<T>::push_front(const T data)
{
    cout << "==============start push_front==================\n";
    Node<T> *temp = new Node<T>(data);
    cout << "start:temp = " << temp << "\ttemp->pNext = " << temp->pNext << "\ttemp->pPrev = " << temp->pPrev << "\tthis->head = " << head << "\tdata = " << data << endl;
    temp->pNext = head;
    temp->pPrev = nullptr;

    if(!Size)
    {
        head = temp;
        tail = temp;
        Size++;
        return;
    }
    head->pPrev = temp;
    head = temp;
    cout << "final:temp = " << temp << "\ttemp->pNext = " << temp->pNext << "\ttemp->pPrev = " << temp->pPrev << "\tthis->head = " << head << "\tdata = " << data << endl;
	Size++;
	cout << "==============stop push_front==================\n";
}

template<typename T>
void List<T>::push_back(const T data)
{
    //cout << "==============start push_back==================\n";
    Node<T> *temp = new Node<T>(data);
    //cout << "start:temp = " << temp << "\ttemp->pNext = " << temp->pNext << "\ttemp->pPrev = " << temp->pPrev << "\tthis->head = " << head << "\tdata = " << data << endl;
    temp->pPrev = tail;
    temp->pNext = nullptr;

    if(!Size) /// Size==0
    {
        head = temp;
        tail = temp;
        Size++;
        return;
    }
    tail->pNext = temp;
    //cout << "tail[-1. Position] final:\tOldTail->pNext = " << tail->pNext << "\tOldTail->pPrev = " << tail->pPrev << "\tOldTail->data = " << tail->data << endl;
    tail = temp;
    //cout << "final:temp = " << temp << "\ttemp->pNext = " << temp->pNext << "\ttemp->pPrev = " << temp->pPrev << "\tthis->head = " << head << "\tdata = " << data << endl;
	Size++;
	//cout << "==============stop push_back==================\n";
}
template<typename T>
T& List<T>::operator[](const int index)
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
    cout << "==============================================================\n";
    while(current!=nullptr)
    {
        cout << "List Element " << index++ << ". data = " << current->data << endl;
        current = current->pNext;
    }
    cout << "==============================================================\n";
    ///if(current==nullptr) {current = head; index = 0;}
}
template<typename T>
void List<T>::Debug() const
{
    Node<T> *current = head;
    int index = 0;
    cout << "==============================================================\n";
    while(current!=nullptr)
    {
        cout << "List Element " << index++ << ". data = " << current->data << " address = " << current << " previous = " << current->pPrev << " next = " << current->pNext << endl;
        current = current->pNext;
    }
    cout << "==============================================================\n";
    ///if(current==nullptr) {current = head; index = 0;}
}
template<typename T>
void List<T>::Add(T data,int position)
{
    int SP = Size-position;
    if (position == 0)
    {
        push_front(data);
        return;
    }
    if (position == Size)
    {
        push_back(data);
        cout << "head = " << head << " tail = " << tail << endl;
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
    Size++;

}
template<typename T>
void List<T>::pop_front()
{
    Node<T> *current = head;
    head = head->pNext;
    head->pPrev = nullptr;
    delete current;
    Size--;
}

template<typename T>
void List<T>::pop_back()
{
    Node<T> *current = tail;
    tail = tail->pPrev;
    tail->pNext = nullptr;
    delete current;
    Size--;
}

template<typename T>
void List<T>::RemoveAt(const int position)
{
    if(position==0) {pop_front(); return;}
    if(position==Size-1){pop_back(); return;}
    int SP = Size-position;
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
    Size--;
}

void qwert1()
{
    List<long long> b;
    for(int i = 0; i < 32132122;i++)
        b.push_back(i);
    system("pause");
}

void qwert()
{
    List<int> b;
    for(int i = 0; i < 4; i++)
        b.Add(i,i);
    b.ShowList();
    cout << b.GetSize() << endl;
    b.Add(31,3);   ///ok
    b.ShowList();  ///ok.maybe optimised
    b.RemoveAt(b.GetSize()-1);
    b.ShowList();
    b.pop_front();
    b.pop_back();
    b.pop_back();
    cout << b.GetSize() << endl;
    b.ShowList();
    cout << b.GetSize() << endl;

}

int main(){
    //qwert();
    List<int> b;
   // b.push_back(2);
   // b.push_back(1);
    cout << b.eq();
    //system("pause");
    //qwert1();
    //system("pause");
	return 0;
}
