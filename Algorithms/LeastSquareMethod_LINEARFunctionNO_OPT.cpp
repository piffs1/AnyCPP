#include <iostream>
#include <utility>
#include <vector>

struct Point{
    double x;
    double y;
};

int main(){
    std::vector<Point> v1;
    Point help;
    std::cout << "For exit from input use any letters" << std::endl;
    while(std::cout << "X = " && std::cin >> help.x && std::cout << "Y = " && std::cin >> help.y){
        v1.push_back(help);
    }
    double sumSqrXi =0;
    double sumXi = 0;
    double sumYi = 0;
    double sumXiYi = 0;
    for(int i = 0; i < v1.size(); i++){
        sumSqrXi = sumSqrXi + v1[i].x * v1[i].x;
        sumXi = sumXi + v1[i].x;
        sumYi = sumYi + v1[i].y;
        sumXiYi = sumXiYi + v1[i].x * v1[i].y;
    }
    std::cout << "We have system " << std::endl;
    std::cout << sumSqrXi << "k + " << sumXi << "b = " << sumXiYi << std::endl;
    std::cout << sumXi << "k + " << v1.size() << "b = " << sumYi << std::endl;
    /*double helpMatrix[1][1];
    helpMatrix[0][1] = sumXi;
    helpMatrix[1][0] = sumXi;
    std::cout << "LINK " << &helpMatrix[0][0] << std::endl << "LINK " << &helpMatrix[0][1] << std::endl << "LINK " << &helpMatrix[1][0] << std::endl << "LINK " << &helpMatrix[1][1] << std::endl;
    helpMatrix[1][1] = v1.size();
    std::cout << helpMatrix[0][0] << ' ' << helpMatrix [0][1] << std::endl << helpMatrix[1][0] << ' ' << helpMatrix[1][1] << std::endl;
    double detA = helpMatrix[1][1]*helpMatrix[0][0] - helpMatrix[0][1]*helpMatrix[1][0];
    std::cout << helpMatrix[1][1] << '*' << helpMatrix[0][0] << '-' <<
        helpMatrix[0][1] << '*' << helpMatrix[1][0] << '=' << detA << std::endl;
    helpMatrix[0][1] = sumXiYi;
    helpMatrix[1][1] = sumYi;
    double detB = helpMatrix[1][1]*helpMatrix[0][0] - helpMatrix[0][1]*helpMatrix[1][0];
    std::cout << helpMatrix[0][0] << ' ' << helpMatrix [0][1] << std::endl << helpMatrix[1][0] << ' ' << helpMatrix[1][1] << std::endl;
    std::cout << detB / detA;*/
    double detA = sumSqrXi * v1.size() - sumXi*sumXi;
    double detB = sumSqrXi * sumYi - sumXi * sumXiYi;
    double detK = sumXiYi*v1.size() - sumYi * sumXi;
    double b = detB/detA;
    double k = detK/detA;
    std::cout << "B = " << b << std::endl << "K = " << k;
    std::cout << std::endl <<"OTKLONENIE Y-Y(LIN) Y(LIN) = KX + B" << std::endl;
    std::cout << "X\tY\tYlin\tRAZNOST\tRAZNOST^2" << std::endl;
    double raznost2;
    double sumRaznost2=0;
    for (int i = 0 ; i < v1.size(); i++){
        raznost2 = (k*v1[i].x + b - v1[i].y)*(k*v1[i].x + b - v1[i].y);
        std::cout << v1[i].x << '\t' << v1[i].y << '\t' << k*v1[i].x + b << '\t' << k*v1[i].x + b - v1[i].y
        << '\t' << raznost2 << std::endl;
        sumRaznost2 = sumRaznost2 + raznost2;
    }
    std::cout << "NEVYAZKA = " << sumRaznost2 << std::endl;
    return 0;
}
