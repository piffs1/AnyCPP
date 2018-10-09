#include <iostream>
int strlen(const char* a)
{
    int i = 0;
    while(a[i]!='\0'){i++;}
    return i;
}

int main(){

    char str[] = " ";

    char *string = str;

    std::cout << strlen(string) << std::endl;

    delete[] string;

    char *string1[] = {"Hello","World","1"};

    for(int i = 0 ; i < 3; i++)
        std::cout << string1[i] << std::endl;

    delete[] string1;
	return 0;
}
