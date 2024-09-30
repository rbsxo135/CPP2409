#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5-100)" << endl;
    cin >> floor;

    for(int i = 0; i <= floor - 1; i++){
        for(int j = 0; j < floor - i - 1; j ++){
            cout << "S";
        }
        for(int j = 1; j <= i * 2 + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}