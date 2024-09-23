#include <iostream>
using namespace std;

int main(void){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    // 조건문의 조건이 비교하는 두 값이 같은 경우도 포함하도록 조건을 수정했습니다
    // else if문으로 이어지므로 이전 조건에서 이미 판별된 조건을 다시 판별할 필요가 없다고 생각해 등호를 필요한 부분만 삽입했습니다
    if(a >= b && a >= c){
        largest = a;
    } else if(b > a && b >= c){
        largest = b;
    } else {
        largest = c;
    }
    
    cout << "가장 큰 정수는 " << largest << endl;
}