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
        cout << "������� �������� �����" << endl;
        File.open(path);
        cout << "���� ������� ������!" << endl;
        File.close();
    }
    catch(const exception& e) ///ifstream::failure
    {
        cout << e.what() << endl;
        cout << "������ �������� ����� " << endl;
    }
	return 0;
}
