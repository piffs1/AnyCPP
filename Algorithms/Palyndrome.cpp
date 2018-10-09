///File was created with help_create.bat
#include <iostream>

int pow10(int step)
{
    if (step == 0) return 1;
    int result=10;
    for(int i = 1;i < step; i++)
        result = result*10;
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    int n1,n2,n3,i;
    i=0;
    n3 = n;
    while (n3>0)
    {
        n3 = n3/10;
        i++;
    }
    while (n>10)
    {
        n1 = n%10;
        n2 = n/pow10(i-1);
        if (i==1){std::cout << "number is polyndrome "; return 0;}
        if (n1==n2){
            n = n%pow10(i-1);
            i--;
            n = n/10;
            i--;
        }else{
        std::cout << "number is not polyndrom";
        return 0;
        }
    }
    std::cout << "number is polyndrom";
    return 0;
}
