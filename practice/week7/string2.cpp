#include <iostream>
#include <string>
using namespace std;

int main(){
    // 문자열 객체 생성
    string s = "Hello, World!";

    // 문자열에서 문자열 제거
    s.erase(7, 2);
    cout << "index 7부터 2글자 문자열 제거: " << s << endl;

    // 문자열에서 문자열 찾기
    int found = s.find("Hello");
    if (found >= 0){
        cout << "찾은 위치: " << found << endl;
    }  

    // 특정 위치부터 문자열 찾기
    found = s.find(",", 4);
    if (found >= 0){
        cout << "특정 위치 이후로 찾은 위치: " << found << endl;
    } 
    
    found = s.find("World");
    if(found >= 0){
        cout << "찾은 위치: " << found << endl;
    } else{
        cout << "찾을 수 없습니다" << endl;
    }

    return 0;
}