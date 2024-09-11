#include <iostream>
#include <string>
using namespace std;

int main() {
    double temperature;
    
    cout << "화씨온도 : ";
    cin >> temperature;
    cout << "섭씨온도 = " << (5.0 / 9.0) * (temperature - 32.0) << endl; 
    return 0;
}