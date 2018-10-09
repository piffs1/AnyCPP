///File was created with help_create.bat
#include <iostream>

int main()
{
    std::string b;
    std::cout << "Input slovo ";
    std::cin >> b;
    int i = b.size();
    int z = 0;
    while(i!=0)
    {
        std::cout << b[z] << ' ' << b[b.size()-1-z] << std::endl;
        if(i==1) {std:: cout << "is poly"; return 0;}
        if (b[z]==b[b.size()-z-1]){
            i=i-2;
            z++;
        }else{
            std::cout << "Not poly";
            return 0;
        }
    }
    std::cout << "is poly";
    return 0;
}
