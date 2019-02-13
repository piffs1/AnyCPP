/* my realisation forward_list */

#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(const T &data);
	void clear();
	size_t size() const { return _size; }
	T& operator[](const int &index);
	void push_front(const T &data);
	void insert(const T &data,const size_t &index);
	void removeAt(const size_t &index);
	void pop_back();
    bool empty() const {return !_size;}

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
	size_t _size;
	Node<T> *head;
};


template<typename T>
List<T>::List()
{
	_size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
    head = head->pNext;
	delete temp;
	_size--;

}

template<typename T>
void List<T>::push_back(const T &data)
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

	_size++;
}

template<typename T>
void List<T>::clear()
{
	while (_size)
	{
		pop_front();
	}
}


template<typename T>
T & List<T>::operator[](const int &index)
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
void List<T>::push_front(const T &data)
{
	head = new Node<T>(data, head);
	_size++;
}

template<typename T>
void List<T>::insert(const T &data,const size_t &index)
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

		_size++;
	}
}

template<typename T>
void List<T>::removeAt(const size_t &index)
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

		_size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(_size - 1);
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
    List<int> s;
	return 0;
}

