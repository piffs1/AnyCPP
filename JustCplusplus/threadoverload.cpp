#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Point
{
public:
    Point(int x,int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
private:
    friend ostream& operator<<(ostream& os,const Point &point);
    friend istream& operator>>(istream& is,Point &point);
    int x;
    int y;
    int z;
};

ostream& operator<<(ostream& os,const Point &point)
{
    os << point.x << ' ' << point.y << ' ' << point.z << endl;
    return os;
}

istream& operator>>(istream& is,Point &point)
{
    is >> point.x >> point.y >> point.z;
    return is;
}

int main(){
    Point point(11,22,33);
    string path = "stoki.txt";
    fstream File;
    File.open(path,fstream::in | fstream::out | fstream::app);
    if(File.is_open())
    {
        cout << "File is opened\n";
        while(true)
        {
            File >> point;
            cout << point;
            if(File.eof()) break;
        }
    }
    File.close();
	return 0;
}
