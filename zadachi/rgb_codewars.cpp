#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

string rgb(int r, int g, int b)
{
    stringstream ss_response;
    // Check overflow lesszero
    r = (r < 0)? 0: r;
    g = (g < 0)? 0: g;
    b = (b < 0)? 0: b;
    // Check overflow greater FF
    r = (r > 255)? 255: r;
    g = (g > 255)? 255: g;
    b = (b > 255)? 255: b;

    ss_response << std::hex << std::setw(2) << std::setfill('0') << r;
    ss_response << std::hex << std::setw(2) << std::setfill('0') << g;
    ss_response << std::hex << std::setw(2) << std::setfill('0') << b;

    string result;
    result = ss_response.str();
    for(int i = 0; i < result.size(); i++)
    {
        if (isalpha(result[i])) {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

int main()
{
    cout << rgb(-20,255,125);
    return 0;
}