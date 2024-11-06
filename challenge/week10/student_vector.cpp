#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int input = 0;
    while(1){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> input;
        if(input == -1)
            break;
        v.push_back(input);
    }

    int sum = 0;
    int size = 0;
    for(int i : v){
        sum += i;
        size++;
    }

    cout << "성적 평균=" << sum / size << endl;

    return 0;
}