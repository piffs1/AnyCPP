/// lvalue (locator value) представляет собой объект, 
/// который занимает идентифицируемое место в памяти (например, имеет адрес).
/// rvalue = !lvalue
#include <iostream>

int foo(){}

int& foo1(){}

int main(int argc, char* argv[]){
    setlocale(0,"");
	
	int var;
	var = 4;
	///4 = var; ///lvalue_rvalue.cpp:11:6: error: lvalue required as left operand of assignment
				///4 = var;
				///	   ^~~
	///(var + 1) = 4; 	///lvalue_rvalue.cpp: In function 'int main(int, char**)':
						///lvalue_rvalue.cpp:16:14: error: lvalue required as left operand of assignment
						///(var + 1) = 4;
						///            ^
						/// некуда присваивать
	/// Мюсли... lvalue представляет объект который можно заполнить,
	/// rvalue то что должно присвоиться lvalue
	/// foo() = 2; foo() error. lvalue required
	foo1() = 2; /// OK foo1() returns lvalue(&)
	/// Все lvalue, которые не являются массивом, функцией и не имеют неполный тип, 
	/// могут быть преобразованы в rvalue
	/// & ссылка на lvalue
	/// &var = 40
	
	system("pause");
	return 0;
}
