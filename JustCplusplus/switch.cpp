#include <iostream>

int main(){
    int c;
    std::cout << "Input your C = ";
    std::cin >> c;
    switch(c)
    {
        case 1: std::cout << 1 << std::endl; break;
        case 2: std::cout << 2 << std::endl; break;
        case 3: std::cout << 3 << std::endl; break;
        case 4: std::cout << 4 << std::endl; break;
        default: std::cout << "Your number is not exists of range[1..4]" << std::endl;
    }
	return 0;
}
