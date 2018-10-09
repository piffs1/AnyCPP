/*changing systems*/

#include <iostream>
#include <windows.h>
#include <stack>
const char NEWLINE = '\n';

int main(){
    setlocale(0,"");
    std::cout << "Введите систему в которую необходимо перевести десятичное число(<10) ";
    int sos;
    std::cin >> sos;
    if(sos > 10)
    {
        std::cout << "Ошибка. Система счисления больше 10";
        exit(-1);
    }
    std::cout << "Введите число ";
    int number;
    std::cin >> number;
    std::stack<int>final_number;
    while(number>=sos)
    {
        final_number.push(number%sos);
        number = number / sos;
    }
    final_number.push(number);
    while(!final_number.empty())
    {
        std::cout << final_number.top();
        final_number.pop();
    }
	return 0;
}
