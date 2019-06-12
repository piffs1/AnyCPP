#include <iostream>
#include <cassert>

#define BEGIN_NAMESPACE(VALUE) VALUE {
#define END_NAMESPACE } /// Это просто шалости
/// sample from book Arthur O’Dwyer

using namespace std;

namespace BEGIN_NAMESPACE(STL_BOOK)

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
    auto& operator++() { pNode = pNode->next; return *this; } /// in this example auto is list_of_ints_iterator
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



template<typename Iterator, typename Predicate>
auto count_if(Iterator begin, Iterator end, Predicate pred)
{
    using Traits = iterator_traits<Iterator>;
    auto sum = typename Traits::difference_type{};
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            ++sum;
        }
    }
    return sum;
}
/*
template<typename Iterator>
auto distance(Iterator begin, Iterator end)
{
    using Traits = iterator_traits<Iterator>;
    if constexpr
    (
        is_base_of<random_access_iterator_tag,
        typename Traits::iterator_category>
    )
    {
        return (end - begin);
    }
    else
    {
        auto result = typename Traits::difference_type{};
        for (auto it = begin; it != end; ++it) {
            ++result;
        }
        return result;
    }
}
*/

END_NAMESPACE

int main()
{
    using namespace STL_BOOK;
    list_of_ints lstnMy;
    lstnMy.push_back(1);
    lstnMy.push_back(2);
    lstnMy.push_back(3);
    lstnMy.push_back(4);

    for (auto it = lstnMy.cbegin(); it != lstnMy.cend(); ++it) {
        cout << *it << endl;
    }

    int nCountIfTest = STL_BOOK::count_if(lstnMy.cbegin(), lstnMy.cend(),[](int a_value){
        return a_value >= 2;
    });
    assert(nCountIfTest == 3);

    //int nDistanceTest = STL_BOOK::distance(lstnMy.cbegin(), lstnMy.cend());
    //assert(nDistanceTest == 4);

    for (auto it = lstnMy.begin(); it != lstnMy.end(); ++it) {
        *it = 5;
        cout << *it << endl;
    }

    return 0;
}
