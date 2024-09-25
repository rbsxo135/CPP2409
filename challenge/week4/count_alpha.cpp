#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 숫자 0치세요" << endl;

    char ch;

    while(1){
        cin >> ch;

        if(ch == '0'){
            break;
        }

        if(ch < 97 || ch > 122){
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        switch(ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel++;
                break;
            default:
                consonant++;
                break;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}