#include <iostream>
#include <map>
#include <stack>


/// https://stepik.org/media/attachments/lesson/41233/statements.pdf
/// Алгоритмы: теория и практика. Структуры данных
/*
    Скобки в коде
    Проверить, правильно ли расставлены скобки в данном коде.
    Вход. Исходный код программы.
    Выход. Проверить, верно ли расставлены скобки. Если нет,
    выдать индекс первой ошибки.

                        Формат входа. 
    Строка s[1 . . . n], состоящая из заглавных и пропис-
    ных букв латинского алфавита, цифр, знаков препинания и ско-
    бок из множества []{}().

                        Формат выхода. 
    Если скобки в s расставлены правильно, выведите
    строку “Success". В противном случае выведите индекс (исполь-
    зуя индексацию с единицы) первой закрывающей скобки, для
    которой нет соответствующей открывающей. Если такой нет,
    выведите индекс первой открывающей скобки, для которой нет
    соответствующей закрывающей.

    Test cases:
    #1 : [] -> Success
    #2 : {}[] -> Success
    #3 : ]() -> 1
         ^
    #4 : ()[} -> 4
            ^
    #5 : {}([] -> 3
           ^
    #6 : {{{} -> 2
          ^ 
    #7 : foo(bar[i); -> 10
                  ^
    #8 : {{ -> 2
          ^

*/

using namespace std;

map<char, char> _map =
{
    {')','('},
    {']','['},
    {'}','{'}
};

int check_brackets(const std::string& a_str) {

    if (a_str.empty()) {
        return 0;
    }

    stack<pair<char,int>> _stck;

    for (int i = 0; i < a_str.size();i++){
        if (a_str[i]=='[' || a_str[i]=='{' || a_str[i]=='('){
            _stck.push({a_str[i], i});
            continue;
        }

        if (a_str[i]==']' || a_str[i]=='}' || a_str[i]==')') {
            if (_stck.empty()) {
                return i+1; /// case ]()
            } else {
                if (_stck.top().first == _map[a_str[i]]) { /// case () ) - a_str[i] 
                                                     ///         ( - _stck.top()
                                                     /// case delete brackets
                    _stck.pop();
                } else {
                    return i+1;
                }
            }
        }

    }

    if (!_stck.empty()) {
        int index = _stck.top().second;
        return index+1;
    }
    return 0;

}

int main()
{
    string str;
    
    cin >> str;
            
    int nResult = check_brackets(str);

    if(nResult) {
        cout << nResult << '\n';
    } else {
        cout << "Success\n";
    }
    
    return 0;
}