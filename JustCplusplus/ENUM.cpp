/* ENUM */

#include <iostream>
#include <string>

using namespace std;


class Robot
{
public:
    enum MyENUM 
{
    SLEEP=0,
    WAKE_UP,
    WAITING
};

    Robot(){}
    ~Robot(){}
    MyENUM GetStateRobot(){return robotState;}
    void SetStateRobot(MyENUM ME){this->robotState = ME;}
private:
    MyENUM robotState = SLEEP;
};

int main(){
    Robot robot;
    robot.SetStateRobot(Robot::MyENUM::SLEEP);
    switch(robot.GetStateRobot())
    {
    case Robot::MyENUM::SLEEP:
        cout << "ROBOT IS SLEEPING " << endl;
        break;
    case Robot::MyENUM::WAITING:
        cout << "ROBOT IS WAITING " << endl;
        break;
    case Robot::MyENUM::WAKE_UP:
        cout << "ROBOT WAKING UP..." << endl;
    }
    int ras = Robot::MyENUM::SLEEP;
    cout << ras;
 	return 0;
}
