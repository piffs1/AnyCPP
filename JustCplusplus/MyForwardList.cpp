/* my realisation forward_list */

#include <iostream>
#include <windows.h>
using namespace std;


/*
* односвязный список
* реализация
*/


template<typename T>
class List
{
public:
	List();
	~List();

	///удаление первого элемента в списке
	void pop_front();

	///добавление элемента в конец списка
	void push_back(T data);

	///очистить список
	void clear();

	///получить количество елементов в списке
	int GetSize() { return Size; }

	///перегруженный оператор []
	T& operator[](const int index);

	///добавление элемента в начало списка
	void push_front(T data);

	///добавление элемента в список по указанному индексу
	void insert(T data, int index);

	///удаление элемента в списке по указанному индексу
	void removeAt(int index);

	///удаление последнего элемента в списке
	void pop_back();

	void debug() const;
private:


	template<typename X>
	class Node
	{
	public:
		Node * pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::debug() const
{
    if(Size==0)return;
    Node<T> *current = this->head;
    while(current->pNext!=nullptr)
    {
        cout << "this->head - " << current;
        cout << "\tdata = " << current->data;
        cout << "\tpNext = " << current->pNext << endl;
        current = current->pNext;
    }
    cout << "this->head - " << current;
    cout << "\tdata = " << current->data;
    cout << "\tpNext = " << current->pNext << endl;
    delete current;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	///cout << "head = " << head;

	head = head->pNext;

	///cout << "\tdeleting temp = " << temp;

	///cout << "\thead->pNext = " << head << endl;

	///cout << "\thead->data = " << head->data << endl;


	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;



	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

void lq()
{
    List<long long> b;
    for(int i = 0; i < 10000;i++)
        b.push_back(i);
    system("pause");
}


int main()
{

	setlocale(0, "");


	List<int> lst;
    lst.debug();
	lst.clear();
    cout << "===========================\n";
    system("pause");
    lq();
    system("pause");
	return 0;
}

