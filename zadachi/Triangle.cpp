/* min sum in triangle
*  example:
*         [2]
*        [1,2]
*       [1,3,4]
*      [5,2,3,4]
* output: 2 + 1 + 1 + 2 = 6
*/

#include <iostream>

using namespace std;



int main()
{
    int levelTriangle;
    cout << "Input level triangle ";
    cin >> levelTriangle;
    int data;
    cin >> data; // Выполняем первый шаг заранее.
    int minSum = data;
    size_t counter = 2; // counter - это переменная, которая увеличивает каждое новое
    //основание треугольника с каждым новым уровнем глубины треугольника
    int min;
    for(size_t i = 1; i < levelTriangle;i++) // начинаем со второго шага. Первый был выполнен вне цикла.
    {
        cin >> data;
        min = data;
        for(size_t j = 1; j < counter; j++)
        {
            cin >> data;
            if(data<min) min = data;
        }
        minSum+=min;
        counter++;
    }
    cout << "Minimum sum of triangle is " << minSum;
    return 0;
}
