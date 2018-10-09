/* dynamic array copy problem */

#include <iostream>
int main(){
    setlocale(0,"");
    int *mas1 = new int[5];
    int *mas2 = new int[10];
    for(int i = 0; i < 5; i++)
        std::cout << &mas1[i] << ' ';
    std::cout << "<- Утечка памяти массив mas1 " << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << &mas2[i] << ' ';
    std::cout << "<- Массив mas2 " << std::endl;
    mas1=mas2; /// mas2=mas1 операция не выполнилась
    for(int i = 0; i < 5; i++)
        std::cout << &mas1[i] << ' ';
    std::cout << "<- Теперь mas1 ссылается на mas2 и теряет свои первичные элементы " << std::endl;
    delete[] mas1;
    delete[] mas2;
	return 0;
}
