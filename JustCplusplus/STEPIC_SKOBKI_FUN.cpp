/* STEPIC EXCERCISE */

#include <iostream>
#include <stack>

using namespace std;

int main(){
    setlocale(0,"");
    string s;
    label: // jjust for test
	
	
    cin >> s;
    //int otkriv = 0,zakriv = 0;
    stack<pair<int,char>> finalStack;
    ///[(])
    //for(int i = 0; i < s.size();i++)
    //if(s[0]==']' || s[0]=='}' || s[0] == ')') {cout << "\nBLOCK ZERO\n" << 1 << endl; goto label; exit(0);}
    for(int i = 0; i < s.size();i++)
    {
        if(finalStack.size()==0)
        {
            if(s[i] == '(' || s[i]==')' || s[i] =='{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
            {
                if(s[i]==']' || s[i]=='}' || s[i]==')')
                {
                    cout << i+1 << endl;
                    //goto label;
                    exit(0);
                }
                finalStack.push(make_pair(i,s[i]));
            }
            continue;
        }
        if((finalStack.top().second=='[' && s[i]==']') || (finalStack.top().second=='{' && s[i]=='}') || (finalStack.top().second=='(' && s[i]==')'))
        {
            finalStack.pop();
            continue;
        }else if(
               (finalStack.top().second=='[' && s[i]=='}')
            || (finalStack.top().second=='[' && s[i]==')')
            || (finalStack.top().second=='(' && s[i]==']')
            || (finalStack.top().second=='(' && s[i]=='}')
            || (finalStack.top().second=='{' && s[i]==')')
            || (finalStack.top().second=='{' && s[i]==']'))
        {
            cout  << i+1 << endl;
            //goto label;
            exit(0);
        }
        if(s[i] == '(' || s[i]==')' || s[i] =='{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
        {
            finalStack.push(make_pair(i,s[i]));
        }
    }
    if(finalStack.empty())
    {
        cout << "Success\n";
        //goto label;
        exit(0);
    }
    cout << finalStack.top().first+1 << endl;
   // goto label;
    return 0;
}
