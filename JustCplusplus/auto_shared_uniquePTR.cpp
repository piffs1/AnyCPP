#include <iostream>
#include <string>
#include <memory>

/*
*
* smart pointers
*
*/

using namespace std;



int main(){

    auto_ptr<int> ap1(new int(10));
    cout << ap1.get() << endl; // OK. ADDRESS EXISTS
    // auto_ptr::get taking pointer
    //cout << ap1.release() << endl; // returns address and ap1=0
    //cout << ap1.get();
    // ap1.reset(); delete ap1
    auto_ptr<int> ap2(ap1);  ///когда объявляется второй указатель на ту же область памяти
    /// то указатель который прежде указывал на ту область памяти затирается.

    unique_ptr<int> up1(new int(20));
    /// unique_ptr<int> up2(up1); Уникальный указатель.
    ///up2 = move(up1); /// Перекидывает указатель up1 в up2 и первый указатель обнуляется. Схожа с аутоптр
    ///up2.swap(p1);

    int *p = new int(5);
    unique_ptr<int> up2(p);
    ///up2.reset - стирает данные
    ///up2.release - очищает сам себя
    shared_ptr<int> sp1(new int(3));
    shared_ptr<int> sp2(sp1);
    /// shared_ptr - в деструкторе имеет статический счетчик указателей. И если осталось указателей >1 то он
    /// проверяет значение(сколько указателей на данную область памяти) и сначала удаляет их.
    /// Пока не останется 1 указатель на область памяти. После чего он затирает область памяти. А потом указатель
	return 0;
}
