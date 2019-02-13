#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 6;

int matrix[SIZE][SIZE];

int main(){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
        matrix[i][j] = rand()%100;
    cout << "Matrix " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
    int rows,cols;
    rows = cols = SIZE;
    for(int k = 0; k < rows * cols; ++k) {
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(j != cols - 1) {
                    if(matrix[i][j+1] < matrix[i][j]) {
                        swap(matrix[i][j],matrix[i][j+1]);
                    }
                }
                else {
                    if((matrix[i+1][0] < matrix[i][j]) && (i != rows - 1)) {
                        swap(matrix[i+1][0],matrix[i][j]);
                    }
                }
            }
        }
    }
    cout << "Sorted matrix " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
	return 0;
}
