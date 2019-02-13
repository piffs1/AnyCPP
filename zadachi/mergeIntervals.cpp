/* Merge intervals.
 * input :[1;3][2;6][8;10][15;18]
 * output:[1;6][8;10][15;18]
 * Program can insert intervals and merge intervals
 */

#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<pair<int,int>> vr;
    int lb,rb; //lb = left border. rb = right border
    int countIntervals;
    cout << "Input count intervals ";
    cin >> countIntervals;
    for(int i = 0; i < countIntervals; i++)
    {
        cout << "Input left border ";
        cin >> lb;
        cout << "Input right border ";
        cin >> rb;
        vr.push_back(make_pair(lb,rb));
    }
    multimap<int,char> mp;
    for(int i = 0; i < vr.size(); i++)
    {
        mp.insert(make_pair(vr[i].first,'b')); // insert left border and char 'b' equals begin
        mp.insert(make_pair(vr[i].second,'e')); // insert right border and char 'e' equals end
    }
    stack<pair<int,char>> s; //stack for check
    //for(auto it = mp.begin(); it!=mp.end();++it) // debug
        //cout << it->first << ' ' << it->second << endl;
    for(auto it = mp.begin(); it!=mp.end(); ++it)
    {
        if(s.size()==1 && it->second=='e' && s.top().second=='b') // if stack size is 1. => stack.top().second ='b'
        {
            cout << '[' << s.top().first << ';' << it->first << ']';
            s.pop();
            continue;
        }
        if(s.size() > 1 && s.top().second=='b' && it->second=='e')
        {
            s.pop();
            continue;
        }
        s.push(make_pair(it->first,it->second)); // fill stack.
        //cout << it->first << '-' << it->second << endl;
    }
    return 0;
}
