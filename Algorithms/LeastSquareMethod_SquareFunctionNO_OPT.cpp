#include <iostream>
#include <utility>
#include <vector>
/// Поправить неточность вывода + и -. Оптимизировать.
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
    double sumXi3 = 0;
    double sumXi4 = 0;
    double sumXi2Yi = 0;
    for(int i = 0; i < v1.size(); i++){
        sumSqrXi = sumSqrXi + v1[i].x * v1[i].x;
        sumXi = sumXi + v1[i].x;
        sumYi = sumYi + v1[i].y;
        sumXiYi = sumXiYi + v1[i].x * v1[i].y;
        sumXi3 = sumXi3 + v1[i].x * v1[i].x * v1[i].x;
        sumXi4 = sumXi4 + v1[i].x * v1[i].x * v1[i].x * v1[i].x;
        sumXi2Yi = sumXi2Yi + v1[i].x * v1[i].x * v1[i].y;
    }
    std::cout << "We have system " << std::endl;
    std::cout << sumXi4 << "a + " << sumXi3 << "b + " << sumSqrXi << "c = " << sumXi2Yi << std::endl;
    std::cout << sumXi3 << "a + " << sumSqrXi << "b + " << sumXi << "c = " << sumXiYi << std::endl;
    std::cout << sumSqrXi << "a + " << sumXi << "b + " << v1.size() << "c = " << sumYi << std::endl;
    ///--------------------------------------------------------------------------
    std::cout << sumXi4 << "a + " << sumXi3 << "c = " << sumXi2Yi << std::endl;
    std::cout << sumXi3 << "a + " << sumSqrXi <<  "c = " << sumXiYi << std::endl;
    std::cout << sumSqrXi << "a + " << sumXi << "c = " << sumYi << std::endl;
    double detM = (sumXi4 * sumSqrXi * v1.size() + sumXi3 * sumXi * sumSqrXi + sumXi3 *sumXi * sumSqrXi) -
    (sumSqrXi * sumSqrXi * sumSqrXi + sumXi*sumXi *sumXi4 + sumXi3 * sumXi3 * v1.size());
    double detA = (sumXi2Yi * sumSqrXi * v1.size() + sumXiYi * sumXi * sumSqrXi + sumXi3 *sumXi * sumYi) -
    (sumSqrXi * sumYi * sumSqrXi + sumXi*sumXi *sumXi2Yi + sumXiYi * sumXi3 * v1.size());
    double detB = (sumXi4 * sumXiYi * v1.size() + sumXi3 * sumYi * sumSqrXi + sumXi2Yi *sumXi * sumSqrXi) -
    (sumSqrXi * sumXiYi * sumSqrXi + sumYi*sumXi *sumXi4 + sumXi2Yi * sumXi3 * v1.size());
    double detC = (sumXi4 * sumSqrXi * sumYi + sumXi3 * sumXiYi * sumSqrXi + sumXi3 *sumXi * sumXi2Yi) -
    (sumXi2Yi * sumSqrXi * sumSqrXi + sumXi*sumXiYi *sumXi4 + sumXi3 * sumXi3 * sumYi);
    double a = detA/detM;
    double b = detB/detM;
    double c = detC/detM;
    std::cout << a << "x^2 +" << b << "x +" << c << std::endl;
    return 0;
}
