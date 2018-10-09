
/* IOF stream */

#include <iostream>
#include <fstream>
#include <string>
#define ZAPIS 0
#define SYMBOL 0
#define STROKA 1
using namespace std;

int main(){

    string path = "file.txt";
#if ZAPIS == 1
    ofstream oFout;

    oFout.open(path); /// oFout.open(path,ofstream::app) - дописываем данные в конец

    if(oFout.is_open()){
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            oFout << i << ' ';
        oFout << endl;
    }
    oFout.close();
    }
#endif // ZAPIS
#if ZAPIS == 0 && SYMBOL == 1
    ifstream iFin;

    iFin.open(path);

    if(iFin.is_open())
    {
        char ch;
        while(iFin.get(ch))
        {
            cout << ch;
        }
    }
#endif
#if ZAPIS == 0 && STROKA == 1
    ifstream iFin;
    path = "stoki.txt";
    iFin.open(path);
    if(iFin.is_open())
    {
        string str;
        while(!iFin.eof())
        {
            ///str=""; ///чтоб не повторялась ласт строчка два раза
            iFin >> str;/// - пословно getline - сами понимаете///getline(iFin,str);
            cout << str << endl;
        }
    }
    iFin.close();
#endif
	return 0;
}
