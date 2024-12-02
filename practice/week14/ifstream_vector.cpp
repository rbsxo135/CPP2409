#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TempDate
{
public:
    int hour;
    double temperature;
    TempDate(int hour, double temperature)
    {
        this->hour = hour;
        this->temperature = temperature;
    }
};

int main()
{
    ifstream is{"temp.txt"};
    if(!is)
    {
        cerr << "파일 오픈에 실패했습니다" << endl;
        exit(1);
    }
    vector<TempDate> temps;
    int hour;
    double temperature;

    while(is >> hour >> temperature)
    {
        temps.push_back(TempDate(hour, temperature));
    }
    for(TempDate t : temps)
    {
        cout << t.hour << "시: 온도 " << t.temperature << endl;
    }
    return 0;
}