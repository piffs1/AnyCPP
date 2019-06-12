#include <iostream>

/// sample from book Arthur O’Dwyer

using namespace std;

namespace STL_BOOK {

struct list_node
{
    int data;
    list_node* next;
};

template<bool Const>
class list_of_ints_iterator
{
    friend class list_of_ints;
    friend class list_of_ints_iterator<!Const>;

    using node_pointer = conditional_t<Const, const list_node*, list_node*>;
    node_pointer pNode;

    explicit list_of_ints_iterator(node_pointer p) : pNode(p) {}
public:
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = conditional_t<Const, const int*, int*>;
    using reference = conditional_t<Const, const int&, int&>;
    using iterator_category = forward_iterator_tag;

    reference operator*() const {return pNode->data; }
    auto& operator++() { pNode = pNode->next; return *this; }
    auto operator++(int) { auto result = *this; ++*this; return result; }

    template<bool R>
    bool operator==(const list_of_ints_iterator<R> &rhs) const
    { return pNode == rhs.pNode; };

    template<bool R>
    bool operator!=(const list_of_ints_iterator<R> &rhs) const
    { return pNode != rhs.pNode; };

    operator list_of_ints_iterator<true>() const
    { return list_of_ints_iterator<true>{pNode}; }
};

class list_of_ints
{
    list_node *m_pHead = nullptr;
    list_node *m_pTail = nullptr;
    int m_nSize = 0;
public:
    using const_iterator = list_of_ints_iterator<true>;
    using iterator = list_of_ints_iterator<false>;

    iterator begin() {return iterator{m_pHead};}
    iterator end() {return iterator{nullptr};}
    const_iterator cbegin() const {return const_iterator{m_pHead};}
    const_iterator cend() const {return const_iterator{nullptr};}

    int size() const {return m_nSize;}
    void push_back(int value) {
        list_node *pTail = new list_node{value, nullptr};
        if (m_pTail) {
            m_pTail->next = pTail;
        }
        else {
            m_pHead = pTail;
        }
        m_pTail = pTail;
        m_nSize++;

    }
    ~list_of_ints() {
        for (list_node* next, *p = m_pHead; p!=nullptr; p = next) {
            next = p->next;
            delete p;
        }
    }

};

}

int main()
{
    using namespace STL_BOOK;
    list_of_ints lstnMy;
    lstnMy.push_back(1);
    lstnMy.push_back(2);
    lstnMy.push_back(3);
    lstnMy.push_back(4);

    for (auto it = lstnMy.begin(); it != lstnMy.end(); ++it) {
        *it = 5;
        cout << *it << endl;
    }

    for (auto it = lstnMy.cbegin(); it != lstnMy.cend(); ++it) {
        cout << *it << endl;
    }


    return 0;
}
