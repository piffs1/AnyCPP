/* dynamic matrix */

#include <iostream>

int main(){
    int rows = 5;
    int cols = 6;
    int **mas = new int*[rows]; /// Создаем массив указателей.

    for(int i = 0;i < rows;i++)
        mas[i] = new int[cols]; ///создаем указатель на новый массив размером cols т.е. mas[rows][cols]
	for(int i = 0; i < rows;i++)
    {
        for(int j = 0; j < cols;j++)
            mas[i][j] = j+i;
    }
    for(int i = 0; i < rows;i++)
    {
        for(int j = 0; j < cols;j++)
            std::cout << mas[i][j] << ' ';
        std::cout << std::endl;
    }
	///delete[] mas - если мы удалим массив указателей на указатели, то массив удалится, но указатели останутся.
    for(int i = 0;i < rows;i++)
        delete[] mas[i];    /// Очищаем массивы размером cols
    delete[] mas; /// Удаляем массив указателей на указатели
	return 0;
}
