/* continue */
#include <iostream>

int main(){

    for(int i = 0; i < 10; i++)
        std::cout << "i = " << i << std::endl;
    std::cout << "------------------" << std::endl;
    for(int i = 0; i < 10; i++){
        if(i==5) continue; /// пропускается цикл
        std::cout << "i = " << i << std::endl;
    }
	return 0;
}
