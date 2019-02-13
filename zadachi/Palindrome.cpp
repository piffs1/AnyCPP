#include <iostream>

using namespace std;

bool isPalindrome(string in)
{
    if(in.size()==1) return true;
    if(in.size()==2){
        if(in[0] == in[1])
            return true;
        else
            return false;
    }
    string helpString;
    helpString.resize(in.size()-2);
    for(int i = 1; i < in.size()-1;i++)
        helpString[i-1] = in[i];
    cout << "HelpString now " << helpString << endl;
    if(in[0] == in[in.size()-1])
        return isPalindrome(helpString);
    else
        return false;
}

int main()
{
    cout << isPalindrome("kover") << endl;
    cout << isPalindrome("kazak");
    return 0;
}
