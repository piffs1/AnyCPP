#include <iostream>
#include <cstring>
#include <string>
int main(){
    char str1[255] = "Hello";

    char str2[255] = "World";

    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    strcat(str1,str2);


    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    std::string string1 = "hi";
    string1 = string1 + " everyone!";
    std::cout << "string 1 = " << string1 + " everyone!" << std::endl;

	return 0;
}
