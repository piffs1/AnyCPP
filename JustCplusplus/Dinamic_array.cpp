/* dynamic matrix */

#include <iostream>

int main(){
    int rows = 5;
    int cols = 6;
    int **mas = new int*[rows]; /// ������� ������ ����������.

    for(int i = 0;i < rows;i++)
        mas[i] = new int[cols]; ///������� ��������� �� ����� ������ �������� cols �.�. mas[rows][cols]
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
	///delete[] mas - ���� �� ������ ������ ���������� �� ���������, �� ������ ��������, �� ��������� ���������.
    for(int i = 0;i < rows;i++)
        delete[] mas[i];    /// ������� ������� �������� cols
    delete[] mas; /// ������� ������ ���������� �� ���������
	return 0;
}
