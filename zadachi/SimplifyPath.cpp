/* Simplify path
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* path = "/../", => "/"
* path = "/home//foo/", => "/home/foo"
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    string path;
    cin >> path;
    if(path.size()==1) {cout << path[0] << endl; exit(0);} // any path first elem '/' path[0] == '/'
    if(path.size()==2){cout << path[0] << path[1] << endl; exit(0);} // example: /a /b /c etc.
    stack<char> s;
    s.push('/');
    for(int i = path.size()-1;i >=0;i--)
    {
        if(s.top() == '/' && path[i]=='/')
            continue;
        if(path[i] == '.') break;
        s.push(path[i]);
    }
    if(s.size()==1) cout << s.top() << endl;
        else
    {
        while(s.size()!=1)
        {
            cout << s.top();
            s.pop();
        }
    }
	return 0;
}
