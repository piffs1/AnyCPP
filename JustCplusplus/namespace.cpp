/*namespace v1 */

#include <iostream>
#include <string>

using namespace std;

namespace my_namespace
{
    void MF()
    {
        cout << "MF() IN MY_NAMESPACE " << endl;
    }

}

namespace new_my_namespace
{
    namespace my_namespace
    {
        void MF()
        {
            cout << "MF() IN MY_NAMESPACE IN NEW_MY_NAMESPACE" << endl;
        }
    }
    void MF()
    {
        cout << "MF() IN NEW_MY_NAMESPACE" << endl;
    }
}

void MF()
{
    cout << "MF() WITHOUT NAMESPACE" << endl;

}

///using namespace my_namespace; conflict MF() and my_namespace::MF()

int main(){
    MF();
    my_namespace::MF();
    new_my_namespace::MF();
    new_my_namespace::my_namespace::MF();
	return 0;
}
