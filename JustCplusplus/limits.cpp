/*limits of vars*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){
    cout << "Int range [" << numeric_limits<int>::min() << "..." << numeric_limits<int>::max() << ']' << endl;
    cout << "Unsigned int range [" << numeric_limits<unsigned int>::min() << "..." << numeric_limits<unsigned int>::max() << ']' << endl;
    cout << "Short int range [" << numeric_limits<short int>::min() << "..." << numeric_limits<short int>::max() << ']' << endl;
    cout << "Unsigned short int range [" << numeric_limits<unsigned short int>::min() << "..." << numeric_limits<unsigned short int>::max() << ']' << endl;
    cout << "long int range [" << numeric_limits<long int>::min() << "..." << numeric_limits<long int>::max() << ']' << endl;
    cout << "Unsigned long int range [" << numeric_limits<unsigned long int>::min() << "..." << numeric_limits<unsigned long int>::max() << ']' << endl;
    cout << "Long long int range [" << numeric_limits<long long int>::min() << "..." << numeric_limits<long long int>::max() << ']' << endl;
    cout << "Unsigned long long int range [" << numeric_limits<unsigned long long int>::min() << "..." << numeric_limits<unsigned long long int>::max() << ']' << endl;
    cout << "char range [" << numeric_limits<char>::min() << "..." << numeric_limits<char>::max() << ']' << "in ["  << int(numeric_limits<char>::min()) << "..." << int(numeric_limits<char>::max()) << ']' << endl;
    cout << "Unsigned char range [" << numeric_limits<unsigned char>::min() << "..." << numeric_limits<unsigned char>::max() << ']' << "in ["  << int(numeric_limits<unsigned char>::min()) << "..." << int(numeric_limits<unsigned char>::max()) << ']' << endl;
    cout << "Double range [" << numeric_limits<double>::min() << "..." << numeric_limits<double>::max() << ']' << endl;
    cout << "Long double range [" << numeric_limits<long double>::min() << "..." << numeric_limits<long double>::max() << ']' << endl;
    return 0;
}
