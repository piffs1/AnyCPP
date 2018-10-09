#include <iostream>

int main(){

    std::cout << "Input size of mas ";
    int n;
    std::cin >> n;
    int a[n];
    for(int i = 0;i < n; i++){
        std::cout << "a[" << i << "]=";
        std::cin >> a[i];
    }
    std::cout << std::endl << "Sorted mas ";
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n-1; j++)
        if(a[j]>a[j+1]){
            int tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
        }
    }
    for(int i = 0;i < n; i++){
        std::cout << a[i] << ' ';
    }
    return 0;
}
