#include <iostream>

int main(){

    int a = 0;
    while(a!=0)
    {
        std::cout << "while running (usual while)" << std::endl;
    }
    do
    {
        std::cout << "while running (do while) " << std::endl;
    }while(a!=0);
	return 0;
}
