/* conditional compilation */
#include <iostream>
#define begin {
#define end }
#define DEBUG
#define ndef 3
///const char begin = '{';
///const char end = '}';
///#define заменяет в коде begin на { end на }
int main(){
    setlocale(0,"");
#ifdef DEBUG
    std::cout << "Дебаг включен.\nНачало цикла." << std::endl;
#else
    std::cout << "Дебаг отключен." << std::endl;
#endif
    for(int i = 0;i < 10; i++)
    begin
        std::cout << i << ' ';
    end
#ifdef DEBUG
    std::cout << "\nконец цикла\n";
#endif
#if ndef == 5
    std::cout << "Макрос ndef равен 5";
#elif ndef < 5
    std::cout << "Макрос ndef равен менее 5. Макрос ndef = " << ndef;
#endif
	return 0;
}
