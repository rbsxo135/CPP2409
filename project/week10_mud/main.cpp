#include "user.cpp"
using namespace std;

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = {

		{0, 1, 2, 0, 4},
		{1, 0, 0, 2, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 3, 0, 0},
		{3, 0, 0, 0, 2} 
	};
	/*
	int map[mapY][mapX] = { 
		{0, 1, 2, 0, 4},
		{1, 0, 0, 2, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 3, 0, 0},
		{3, 0, 0, 0, 2} 
	};
	*/
	
	// 유저 객체 생성
	User user;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << user.getHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;
		
		if (user_input == "상" || user_input == "하" || user_input == "좌" || user_input == "우"){
			// 입력이 유효해 유저가 이동했을 경우 displayMap, checkState 메서드 호출
			if(user.move(mapX, mapY, user_input) == true){
				displayMap(map, user);
				checkState(map, user);
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 유저의 hp가 0 이하인지 체크
		if(checkUser(user) == false){
			cout << "hp가 0이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}
