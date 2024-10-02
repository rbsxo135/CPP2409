#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y;

    // 보드판 초기화
    // 보드의 인덱스를 예시와 반대로 [y][x]로 해 주어야 예시와 같은 오류가 안 생긴다고 판단했습니다
    for(y = 0; y < numCell; y++)
        for(x = 0; x < numCell; x++)
            board[y][x] = ' ';
    

    // 게임 진행 코드
    int k = 0; // 유저 차례 체크 위한 변수

    // 유저가 바뀔 때마다 돌모양을 지정해주는 것보다 돌을 놓을 때 k값에 맞는 돌을 놓는 것이 더 좋다고 판단했습니다
    char markers[2] = {'X', 'O'}; // 현재 유저의 돌을 저장하기 위한 변수

    while(true){
        // 1. 누구 차례인지 출력
        switch(k % 2) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        // 음수 값을 입력받은 경우의 예외처리가 되있지 않아 추가했습니다
        if((x >= numCell || x < 0) || (y >= numCell || y < 0)){
            cout << x << ", " << y << ": ";
            cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[y][x] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        // k값에 맞는 돌을 찾아 보드에 놓습니다
        board[y][x] = markers[k % 2];

        // 5. 현재 보드 판 출력
        // x, y 좌표 축에 맞게 보이게 설정했습니다
        for(int i = numCell - 1; i >= 0; i--){
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 시 승자 출력 후 종료

        // 가로줄 빙고 조건
        if((board[0][0] != ' ' ) && (board[0][0] == board[0][1]) && (board[0][1] == board[0][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }
        if((board[1][0] != ' ' ) && (board[1][0] == board[1][1]) && (board[1][1] == board[1][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }
        if((board[2][0] != ' ' ) && (board[2][0] == board[2][1]) && (board[2][1] == board[2][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }

        // 세로줄 빙고 조건
        if((board[0][0] != ' ' ) && (board[0][0] == board[1][0]) && (board[1][0] == board[2][0])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }
        if((board[0][1] != ' ' ) && (board[0][1] == board[1][1]) && (board[1][1] == board[2][1])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }
        if((board[0][2] != ' ' ) && (board[0][2] == board[1][2]) && (board[1][2] == board[2][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }

        // 대각선 빙고 조건
        if((board[0][0] != ' ' ) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }
        if((board[2][0] != ' ' ) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])){
            cout << k % 2 + 1 << "번째 유저의 승리입니다! " << endl;
            break;
        }

        bool isFull = true;

        // 7. 모든 칸이 찼으면 종료
        for(int i = 0; i < numCell; i++){
            for(int j = 0; j < numCell; j++){
                if(board[i][j] == ' ')
                    isFull = false;
            }
        }

        if(isFull == true){
            cout << "무승부입니다!" << endl;
            break;
        }

        k++;
    }

}