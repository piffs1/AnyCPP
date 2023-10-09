#include <iostream>
#include <bitset>

using namespace std;

uint32_t set_bit(uint32_t number, size_t index, bool bit)
{
    // Выставляет бит в индексе бинарного числа.
    // Пример:
    // set_bit(32, 31, true)
    // Выставить 31(последний) бит -> true
    // number 0000_0000 0000_0000 0000_0000 0010_0000
    // После: 0000_0000 0000_0000 0000_0000 0010_0001
    // ----------------------------------------------
    // @mention! 
    // Помни о представлении числа как сумма степеней СЛЕВА-НАПРАВО
    // bitset[LAST_INDEX] - 2^0
    // bitset[FIRST_INDEX] - 2^size
    const uint32_t container_size = sizeof(uint32_t) * 8;
    bitset<container_size> bits{ number };
    bits.set(container_size - index - 1, bit);
    return static_cast<uint32_t>(bits.to_ulong());
}

int main()
{

    cout << set_bit(32, 31, true); // 33
}