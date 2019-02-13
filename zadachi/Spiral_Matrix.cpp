/* Spiral matrix old solution */

#include <iostream>


int main()
{
    std::cout << "Spiral matrix" << std::endl;
    int n;
    std::cout << "Input size of matrix ";
    std::cin >> n;
    int m = n;
    int matrix[n][m];
    int increment = 1;
    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++)
            matrix[i][j] = 0;
    }
    int index = 1;
    int i_index = 0;
    int j_index = 0;
    int count_of = n*m;
    while(index!=count_of+1){
        std::cout << std::endl << "1. ";
        for(int j = 0 + j_index; j < m - j_index; j++){
            matrix[i_index][j] = index++;
            std::cout <<'[' << i_index << "][" << j << "] -> ";
        }
        std::cout << std::endl << "2. ";
        for(int i = 1 + i_index; i < n - i_index; i++){
            matrix[i][n-1-j_index] = index++;
            std::cout  << '[' << i << "][" << n-1-j_index << "] -> ";
        }
        std::cout << std::endl << "3. ";
        for(int j = 0 + j_index; j < m - j_index - 1; j++){
            matrix[m-1-i_index][n-2-j] = index++;
            std::cout << '[' << m-1-i_index << "][" << n-2-j << "] -> ";
        }
        std::cout << std::endl << "4. ";
        for(int i = 1 + i_index; i < n - i_index - 1; i++){
            matrix[m-i-1][j_index] = index++;
            std::cout << '[' << m-i-1 << "][" << j_index << "] -> ";
        }
        /*std::cout << std::endl << "I INDEX = " << i_index << std::endl << "J INDEX = " << j_index << std::endl
        << "INDEX = " << index;*/
        i_index++;
        j_index++;
    }
    /*for(int j = 0; j < m; j++) /// 1 Razbivka zadach na podzadachi.
        matrix[0][j] = index++;
    for(int i = 1; i < n; i++) /// 2
        matrix[i][n-1] = index++;
    for(int j = 0; j < m-1; j++) /// 3
        matrix[m-1][n-2-j] = index++;
    for(int i = 1; i < n-1; i++) /// 4
        matrix[m-i-1][0] = index++;
    for (int j = 1; j < m-1;j++) /// 1
        matrix[1][j] = index++;
    for (int i = 2; i < n-1;i++) /// 2
        matrix[i][n-2] = index++;
    for (int j = 1; j < m-2; j++) /// 3
        matrix[m-2][n-2-j] = index++;
    for(int i = 2; i < n-2; i++) /// 4
        matrix[m-i-1][1] = index++;*/

    std::cout << std::endl;
    if((n-1)%2 == 0){
    for(int i = 1; i < (n-1)/2;i++)
        std::cout << '\t';
        std::cout << "WE GOT THE MATRIX" << std::endl;
    }else{
    for(int i = 0; i < (n-1)/2;i++)
        std::cout << '\t';
        std::cout << "FINAL MATRIX" << std::endl;
    }
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++)
            std::cout << matrix[i][j] << '\t';
    std::cout << std::endl;
    }
    std::cout << std::endl;

    /*for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++)
            std::cout << '[' << i << "][" << j << "] ";
    std::cout << std::endl;
    }*/

    return 0;
}
