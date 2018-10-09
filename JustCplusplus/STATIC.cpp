/* STATIC TEST */
#include <iostream>
/// поле статическое одно на все классы. Т.е. Если создадим экземпляры класса static_test1,2,3. То переменная
/// static будет одна и та же во всех классах
class static_test
{
public:
    static int a;
    int getB(){return b;}
    void setB(int b){this->b = b;}
private:
    int b;
};



int static_test::a = 0; ///Инициализация обязательна!!! Иначе не будет работать.

class new_class
{
public:
    new_class()
    {
        count++;
    }
    ~new_class()
    {

    } ///Функции static не могут обращаться к this. Т.к. лежат в отдельной ячейке памяти.
    /// Именно поэтому мы можем обращаться к этим методам без создания класса.
    /// Также мы не можем ссылаться на переменные не типа статик из статик функции
    static int GetCount(){return count;} /// static int GetCount() необходим, если мы хотим обратиться к функции не обращаясь к классу
    void ShowAddress(){std::cout << &this->count;}
    static void ChangeData(new_class &nc,int data);
    int getData(){return dataTemp;}
private:
    static int count;
    int dataTemp;
};

void new_class::ChangeData(new_class &nc,int data) ///Не смущаться. Если убрать модификатор static в описании класса
{                                                  ///то функция работать не будет через new_class::ChangeData()
    nc.dataTemp = data;
}

int new_class::count = 0;

int main(){
    setlocale(0,"");
    static_test::a = 5; ///Можно обращаться даже из экземпляра класса не создавая сам класс
    std::cout << static_test::a;
    static_test st;
    std::cout << std::endl << st.a << std::endl;
    std::cout << "==========================";
    new_class nc;
    new_class nc1;
    new_class nc2;
    std::cout << "\nБыло создано " << nc.GetCount() << " экземпляра класса new_class\n";
    std::cout << "&nc.count = ";
    nc.ShowAddress();
    std::cout << "\n&nc1.count = ";
    nc1.ShowAddress();
    std::cout << "\n&nc2.count = ";
    nc2.ShowAddress();
    std::cout << '\n' << "Количество экземпляров класса new_class = " << new_class::GetCount() << '\n';
    std::cout << "old data = " << nc.getData() << '\n';
    new_class::ChangeData(nc,5);
    std::cout << "new data = " << nc.getData() << '\n';
    std::cout << "old data = " << nc1.getData() << '\n';
    new_class::ChangeData(nc1,3);
    std::cout << "new data = " << nc1.getData() << '\n'; /// ok

	return 0;
}
