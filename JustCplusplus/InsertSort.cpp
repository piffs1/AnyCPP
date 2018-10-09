/* insertion sort */

#include <iostream>

int main()
{
    std::cout << "input size of mas ";
    int n;
    std::cin >> n;
    int a[n];
    for(int i = 0;i < n; i++){
        a[i] = i;
    }
    int counter = 0;
    for(int i = 1; i < n; i++)
        for(int j = i; j>0 && a[j-1]>a[j];j--){
            counter++;
            std::swap(a[j-1],a[j]);
        }
    std::cout << "SLOZHNOST of " << counter << " of massiv[" << n << ']';
    std::cout << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    /// = 5 a[0] = 1 a[1] = 2 a[2] = - 4 a[3] = 228 a[4] = 16
    /// 1. i = 1 / j = 1 a[0] > a[1] false
    /// 2. i = 2 / j = 2 a[1] > a[2] true; swap a[1],a[2](a[1] = -4 a[2] = 2) i = 2 / j = 1 a[0] > a[1] true; swap a[0],a[1]; a[0] = -4
    return 0;
}
