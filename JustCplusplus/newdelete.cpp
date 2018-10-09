/* newdelete */

#include <iostream>

using namespace std;

/// Если берем new обязательно пишем delete. Память выделяется извне программы.
/// Сначала удаляем указатель, потом присваиваем nullptr. Если сделать наоборот, то затрется адрес, но данные останутся.
int main(){
    int *pa = new int;
    delete pa;
    pa = nullptr; /// pa = NULL -std=+11C
	return 0;
}
