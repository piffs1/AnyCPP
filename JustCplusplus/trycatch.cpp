#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    setlocale(0,"");
    ifstream File;
    string path = "br.tx";
    File.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        cout << "Попытка открытия файла" << endl;
        File.open(path);
        cout << "Файл успешно открыт!" << endl;
        File.close();
    }
    catch(const exception& e) ///ifstream::failure
    {
        cout << e.what() << endl;
        cout << "Ошибка открытия файла " << endl;
    }
	return 0;
}
