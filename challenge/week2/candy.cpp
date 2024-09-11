#include <iostream>
#include <string>
using namespace std;

int main() {
    int money, candyPrice;

    cout << "현재 가지고 있는 돈 : ";
    cin >> money;
    cout << "캔디의 가격 : ";
    cin >> candyPrice;
    cout << "최대로 살 수 있는 캔디 = " << money / candyPrice << endl;
    cout << "캔디 구입 후 남는 돈 = " << money % candyPrice << endl;

    return 0;
}