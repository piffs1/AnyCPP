// Example program
#include <iostream>
#include <string>
#include <vector>
template<class Iterator>
void double_each_element(Iterator begin, Iterator end)
{
    for (auto it = begin; it != end; ++it) {
        std::cout << *it * 2 << " ";
    }
    std::cout << std::endl;
}

template<class Iterator, class Predicate>
int my_count_if(Iterator begin, Iterator end, Predicate pred)
{
    int sum = 0;
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            sum++;
        }
    }
    return sum;
}

int main()
{
  std::vector<int> vhs = {1,2,3,4,5,6};
  double_each_element(vhs.begin(), vhs.begin()+3); /// 2 4 6
  double_each_element(vhs.begin(), vhs.end()); /// 2 4 6 8 10 12
  double_each_element(&vhs[0], &vhs[3]); /// 2 4 6
  std::cout << my_count_if(vhs.begin(), vhs.end(), 
  [](int x){ return (x % 2) == 0; }); /// 3
}
