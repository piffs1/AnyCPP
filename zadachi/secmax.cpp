/*my realistaion second max v1 */

#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    int M;
        label:
    cin >> M;
    int a[M];

    srand(time(NULL));
    for(int i = 0; i < M; i++)
        a[i] = rand()%10;
    int max1 = a[0];
    int max2 = a[1];
    for(int i = 0;i < M;i++)
        cout << a[i] << ' ';
    cout << endl;
    if(max1<max2) swap(max1,max2);
    for(int i = 2; i < M;i++)
    {
        if(a[i]>max1) {max2 = max1; max1 = a[i];}
        if(a[i]>max2 && a[i] < max1) {max2 = a[i];}
    }
    cout << "MAX = " << max1 << endl << "MAX2 = " << max2 << endl;
    goto label;
	return 0;
}
