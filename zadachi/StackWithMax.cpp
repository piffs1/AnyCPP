/* stack with max
*
*
*
*/

#include <iostream>
#include <stack>


using namespace std;
class Stack : public stack<int>
{
    public:
    int max(){return maxi;}
    Stack();
    void zapros(string msg)
    {
        if(msg == "top")
            cout << "this top " << this->top() << ' ' << "max top " << track.top() << endl;
        if(msg == "pop")
            {
                if(this->empty()) return; //error
                if(this->top() == maxi) // if in our stack top() is max
                    {
                        track.pop();
                        if(track.size()) maxi = track.top(); //if stack not empty now maxi = new max data
                            //else maxi = 0; // if track.size is empty maxi = 0; bad solution
                    }
                this->pop();
                return;
            }
        if(msg == "max")
        {
            if(!this->empty())
                cout << max() << endl;
            else
                cout << "Stack is empty " << endl;

        }
        if(msg == "size") // debug function
            cout << "track size = " << track.size() << ' ' << "stack size = " << this->size() << endl;
    }
    void zapros(string,const int &temp) //string not used. function for push
    {
        if(this->empty()) {maxi = temp; this->push(temp); track.push(maxi); return;} // if stack is empty => max = new data
        if(track.top() <= temp){maxi = temp; this->push(temp); track.push(maxi); return;}
        this->push(temp);
        //track.push(maxi);
    }
    private:
        int maxi; // var for track
        stack<int> track; // stack for track maximum
};
Stack::Stack()
{
    //maxi = 0;
}
int main() {
    int q;
    cout << "Input count of actions ";
    cin >> q; //count actions
    string str;
    Stack s;
    int temp;
    for(int i = 0; i < q;i++)
    {
        //getline(cin,str,'\n');
        cin >> str;
        if(str == "push") // if user input push 7 str == push only.
        {
            cin >> temp; // check number
            s.zapros(str,temp);
        }else
            s.zapros(str);
    }
    return 0;
}
