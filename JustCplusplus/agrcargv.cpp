/*
*
* CMD.
*
*/

#include <iostream>

int main(int argc, char* argv[]){
    setlocale(0,"");
    ///argc - arguments count
    ///argv - arguments value
    std::cout << "������ ��������� ����� cmd. ������ �������� ����������" << std::endl;
    for(int i = 0; i < argc;i++)
        std::cout << argv[i] << ' ' << std::endl;

    system("pause");
	return 0;
}
