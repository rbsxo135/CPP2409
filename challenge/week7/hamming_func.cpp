#include <iostream>
#include <string>
using namespace std;


string toLowerString(string str){
    string strCpy = str;
    for(int i = 0; i < strCpy.length(); i++){
        if(strCpy[i] <= 90){
            strCpy[i] = (char)(strCpy[i] + 32);
        }
    }
    return strCpy;
}

string toUpperString(string str){
    string strCpy = str;
    for(int i = 0; i < strCpy.length(); i++){
        if(strCpy[i] >= 97){
            strCpy[i] = (char)(strCpy[i] - 32);
        }
    }
    return strCpy;
}

// 문자열 2개를 입력받아 해밍거리 리턴, 두 문자열의 길이가 다를 경우 -1 반환;
int calHammingDist(string s1, string s2){
    int count = 0;

    if(s1.length() != s2.length()){
        return -1;
    } else{
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
        }
        return count;
    }
}

int main(){
    string s1, s2;
    int count = 0;

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    string s1Lower = toLowerString(s1);
    string s2Lower = toLowerString(s2);
    cout << "해밍 거리는 " << calHammingDist(s1Lower, s2Lower) << endl;

    return 0;
}