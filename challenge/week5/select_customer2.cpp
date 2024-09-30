#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int menu;
    bool run = true;
    while(run)
    {
        cout << "1. 가장 나이가 많은 사람 출력 2. 가장 나이가 적은 사람 출력 3. 종료" << endl;
        cin >> menu;

        switch (menu){
        case 1:
        {
            int maxAge = 0;
            int maxAgeIdx = 0;
            for (int i = 0; i < maxPeople; i++){
                if (maxAge < ages[i]){
                    maxAge = ages[i];
                    maxAgeIdx = i;
                }
            }
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == maxAge){
                    cout << "가장 나이가 많은사람 : " << names[i] << ", 나이: " << maxAge << endl;
                }
            }
            break;
        }
        case 2:
        {
            int minAge = INT_MAX;
            int minAgeIdx = 0;
            for (int i = 0; i < maxPeople; i++){
                if (minAge > ages[i]){
                    minAge = ages[i];
                    minAgeIdx = i;
                }
            }
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == minAge){
                    cout << "가장 나이가 많은사람 : " << names[i] << ", 나이: " << minAge << endl;
                }
            }            break;
        }
        case 3:
        {
            run = false;
            break;
        }
        default:
        {
            cout << "그 외의 숫자를 입력하세요" << endl;
            break;
        }
        }
    }

    return 0;
}