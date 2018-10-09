/* EUCLID ALGORITHM */

#include <iostream>

using namespace std;

int AlgorithmEuclidNaibOD(int a,int b)
{
    int max,min;
    if(a>b) {max = a;min = b;}else{max = b;min=a;}
    if(max%min==0) return min;
    return AlgorithmEuclidNaibOD(min, max%min);
}
int NaimOD(int a,int b)
{
    int delA = 2;
    while(a%delA!=0 || b%delA!=0)
    {
        if(a==delA || b==delA)
        {
            delA=1;
            break;
        }
        delA++;
    }
    return delA;
}
int main(){
    cout << AlgorithmEuclidNaibOD(30,13) << endl;
    cout << NaimOD(19,18);
    cout << endl;
    return 0;
}
