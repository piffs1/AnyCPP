#include <iostream>

int while_not_sum(int n)
{
    if(n==1) return 1; /// Точка возврата
    return while_not_sum(n-1)+n; /// Углубление
}

int main(){
    std::cout << while_not_sum(4);
	return 0;
}
