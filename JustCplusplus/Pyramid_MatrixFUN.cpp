/*Pyramid just fun */

///File was created with help_create.bat
#include <iostream>
///Check for j and for i. mojno union that
int main()
{
    int n;
    std::cout << "Input size of matrix ";
    std::cin >> n;
    int m = n;
    int matrix[n][m];
    int levelPyramid = 0;
    int i_index = 0;
    int j_index = 0;
    int maxLevelPyramid = (m/2)+1;
    while(levelPyramid!=maxLevelPyramid){
        levelPyramid++;
        for(int j = 0 + j_index; j < m - j_index; j++)
            matrix[i_index][j] = levelPyramid;
        for(int i = 1 + i_index; i < n - i_index; i++)
            matrix[i][m-1-j_index] = levelPyramid;
        for(int j = 1 + j_index; j < m - j_index; j++)
            matrix[n-1-i_index][m-j] = levelPyramid;
        for(int i = 1 + i_index; i < n - i_index; i++)
            matrix[n-i][j_index] = levelPyramid;
        i_index++;
        j_index++;
    }





    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            std::cout << matrix[i][j] << "  ";
        std::cout << std::endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            std::cout << '[' << i << "][" << j << "]\t";
        std::cout << std::endl;
    }
    return 0;
}
