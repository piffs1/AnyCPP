/* conditional compilation */
#include <iostream>
#define begin {
#define end }
#define DEBUG
#define ndef 3
///const char begin = '{';
///const char end = '}';
///#define �������� � ���� begin �� { end �� }
int main(){
    setlocale(0,"");
#ifdef DEBUG
    std::cout << "����� �������.\n������ �����." << std::endl;
#else
    std::cout << "����� ��������." << std::endl;
#endif
    for(int i = 0;i < 10; i++)
    begin
        std::cout << i << ' ';
    end
#ifdef DEBUG
    std::cout << "\n����� �����\n";
#endif
#if ndef == 5
    std::cout << "������ ndef ����� 5";
#elif ndef < 5
    std::cout << "������ ndef ����� ����� 5. ������ ndef = " << ndef;
#endif
	return 0;
}
