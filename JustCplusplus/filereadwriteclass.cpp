/* Overload class read/write */

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Point
{
public:
    Point()
    {
        x = y = z = 0;
    }
    Point(int x,int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void Print() {cout << "X = " << x << "\tY = " << y << "\tZ = " << z << endl;}
private:
    int x;
    int y;
    int z;
};
 ///Запись/Чтение данных из файла в/из объект(а)
int main(){
    setlocale(0,"");
    string path = "stoki.txt";
    Point point(141,352,34223);
    /*ofstream File;
    File.open(path,ofstream::app);
    if(File.is_open())
        File.write((char*)&point, sizeof(Point));
    File.close();*/

    ifstream File;
    File.open(path);
    Point pnt;
    if(File.is_open())
    {
        while(File.read((char*)&pnt,sizeof(Point)))
        pnt.Print();
    }
    File.close();

	return 0;
}
