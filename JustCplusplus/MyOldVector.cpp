/* My old realistaion vector. 
Need overload operator[]
*/

#include <iostream>
#include <cstdlib>
#include <vector>


template<class T>
struct vector{
    int size = 0;
    T *data = new T[size];
    void erase(int &begin,int &end)
    {
        if(begin < 0 || end > size){std::cout << "Ошибка. Выход за границы вектора" << std::endl;return;}
        if(begin > end){std::swap(begin,end);}
        end++;
        int dSize = end - begin;

        T *newArray = new int[size-dSize];
        for(int i = 0; i <= begin; i++)
        {
            newArray[i] = data[i];
        }

        for(int i = end; i < size; i++)
        {
            newArray[i-dSize] = data[i];
        }
        size = size - dSize;
        delete[] data;
        data = newArray;
    }
    void RefillVector()
    {
        for(int i = 0; i < size;i++)
            data[i] = rand()% 10;
    }
    void ShowVector()
    {
        if(this->isEmpty()){std::cout << "Вектор пуст!";return;}
        std::cout << "Вектор = ";
        for(int i = 0;i < size;i++)
            std::cout << data[i] << ' ';
    }
    void push_back(const T &value)
    {
        T *newArray = new T[size+1];
        for(int i = 0;i < size;i++)
            newArray[i] = data[i];

        newArray[size] = value;

        delete[] data;

        data = newArray;

        size++;
    }
    void pop_back()
    {
        ///if(size==0){std::cout << "Error. Size of array is low"; return;}
        size--;
        T *newArray = new T[size];

        for(int i = 0;i < size;i++)
            newArray[i] = data[i];

        delete[] data;

        data = newArray;
    }
    bool isEmpty(){return size==0;}
    ///void killVector(){delete[] data;}
    int sizeOfVector(){return size;}
};

void FillArray(int* a,const int size)
{
    for(int i = 0; i < size;i++)
        a[i] = rand()% 10;
}

void ShowArray(const int* a, const int size)
{
    for(int i = 0;i < size;i++)
        std::cout << a[i] << ' ';
}

void push_back(int *&array,int &size,const int value)
{
    int *newArray = new int[size+1];

    for(int i = 0;i < size;i++)
        newArray[i] = array[i];

    newArray[size] = value;

    delete[] array;

    array = newArray;

    size++;
}

void pop_back(int *&array, int &size)
{
    if(size==0){std::cout << "Error. Size of array is low"; return;}
    size--;
    int *newArray = new int[size];

    for(int i = 0;i < size;i++)
        newArray[i] = array[i];

    delete[] array;

    array = newArray;
}

int main(){
    setlocale(0,"");

    vector<int> b;

    int *countOfInput = new int;
    std::cout << "Введите количество вводимых значений ";
    std::cin >> *countOfInput;
    int inputData;
    for(int i = 0; i < *countOfInput; i++)
    {
        std::cin >> inputData;
        b.push_back(inputData);
    }
    b.RefillVector();
    delete[] countOfInput;
    countOfInput = nullptr;
    b.ShowVector();
    std::cout << '\n';
    /*while(!b.isEmpty())
    {
        std::cout << "Удаляем элемент № " << b.sizeOfVector()-1 << " со значением " << b.data[b.sizeOfVector()-1] << std::endl;
        b.pop_back();
    }*/
    std::cout << "Выберите границы удаления элементов из вектора ";
    int leftB;
    int rightB;
    std::cin >> leftB >> rightB;
    b.erase(leftB,rightB);
    b.ShowVector();
    ///std::cout << "Вектор пуст!";
    /*
    int *array = new int[sizeOfArray];
    FillArray(array,sizeOfArray);

    ShowArray(array,sizeOfArray);

    std::cout << std::endl;

    push_back(array,sizeOfArray,5);

    ShowArray(array,sizeOfArray);

    pop_back(array,sizeOfArray);

    std::cout << std::endl;

    ShowArray(array,sizeOfArray);
    delete[] array;*/
	return 0;
}
