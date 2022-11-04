#include <iostream>
#include <queue>

using namespace std;


const int gnSecondsPerYear = 31536000;
const int gnSecondsPerDay = 86400;
const int gnSecondsPerHour = 3600;
const int gnSecondsPerMinute = 60;

string rofl(int seconds)
{
    string result;
    if (seconds == 0) {
        return "now";
    }
    int nYears = seconds/gnSecondsPerYear;
    seconds %= gnSecondsPerYear;
  
    int nDays = seconds/gnSecondsPerDay;
    seconds %= gnSecondsPerDay;
  
    int nHours = seconds/gnSecondsPerHour;
    seconds %= gnSecondsPerHour;
  
    int nMinutes = seconds/gnSecondsPerMinute;
    seconds %= gnSecondsPerMinute;
  
    
    queue<pair<int,string>> qnQueue;
    if (nYears > 0) {
        qnQueue.push({nYears, "year"});
    }

    if (nDays > 0) {
        qnQueue.push({nDays, "day"});
    }

    if (nHours > 0){
        qnQueue.push({nHours, "hour"});
    }

    if (nMinutes > 0) {
        qnQueue.push({nMinutes, "minute"});
    }
    if (seconds > 0) {
        qnQueue.push({seconds, "second"});
    }

    if (qnQueue.size()==1){
        auto pairResult = qnQueue.front();
        result = to_string(pairResult.first) + ' ' + pairResult.second;
        if (pairResult.first > 1) {
            result += 's';
        }
        return result;
    }

    while (qnQueue.size() > 2){
        auto pairResult = qnQueue.front();
        result += to_string(pairResult.first) + ' ' + pairResult.second;
        if (pairResult.first > 1) {
            result += 's';
        }
        result += ", ";
        qnQueue.pop();
    }
    auto pairResult = qnQueue.front();
    result += to_string(pairResult.first) + ' ' + pairResult.second;
    if (pairResult.first > 1) {
        result += 's';
    }

    result += " and ";

    pairResult = qnQueue.back();
    result += to_string(pairResult.first) + ' ' + pairResult.second;
    if (pairResult.first > 1) {
        result += 's';
    }

    return result;
}



int main()
{
    cout << rofl(gnSecondsPerYear+gnSecondsPerDay+gnSecondsPerHour+gnSecondsPerMinute+2);
    return 0;
}