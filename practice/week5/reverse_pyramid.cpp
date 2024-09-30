#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5-100)" << endl;
    cin >> floor;

    for(int i = floor; i >= 1; i--){
        for(int j = 0; j < floor - i; j ++){
            cout << "S";
        }
        for(int j = 1; j < i * 2; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}