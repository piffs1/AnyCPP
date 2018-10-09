/*ternary operator */

#include <iostream>

void amore10()
{
    std::cout << "a < 10. a = " << std::endl;
}

int main(){
    setlocale(0,"");

    int a;
    std::cout << "Input a = ";
    std::cin >> a;

    /*if(a<10)
        std::cout << "a < 10. a = " << a << std::endl;
    else
        std::cout << "a > 10. a = " << a << std::endl;*/
    /// a<10? - ? - проверка выражения (a<10)?
    ///if a<10 std::cout << "a < 10. a = " << a << std::endl else if (a==10) std::cout << "a = 10." << std::endl else std::cout << "a > 10. a = " << a << std::endl
    (a < 10) ?(std::cout << "a < 10. a = " << a << std::endl): (a==10)?(std::cout << "a = 10." << std::endl):(std::cout << "a > 10. a = " << a << std::endl);
    int b = 4;
	int max = (a<=b)? b:a;
	std::cout << "\nMax is " << max << std::endl;
	return 0;
}
