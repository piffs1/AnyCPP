#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){

    srand(time(NULL));
    std::cout << rand()%100;
	return 0;
}
