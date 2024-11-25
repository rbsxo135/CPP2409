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

	const int USER_NUM = 1; // 플레이어 수
	User* user_list[USER_NUM]; // 유저 리스트
	
	// 직업 선택을 위한 무한 반복문
	while(1)
	{
		cout << "직업을 선택하세요 1. Magican 2. Warrior" << endl;
		string selection;
		cin >> selection;
		if(selection == "1") // 마법사
		{	
			// 유저 객체 생성 후 반복문 종료
			user_list[0] = new Magician();
			break;
		} else if(selection == "2") // 전사
		{
			// 유저 객체 생성 후 반복문 종료
			user_list[0] = new Warrior();
			break;
		} else{ // 잘못된 입력의 경우 반복문 다시 실행
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
	}

	cout << "당신의 직업은 " << user_list[0]->GetName() << "입니다." << endl;
	int turn = 0; // 유저 차례
	
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		User* cur_user = user_list[turn % USER_NUM]; // 현재 유저 지정
		
		// 해당 차례의 유저의 hp가 0 이하인지 체크. 0이하일 경우 차례가 넘어감
		if(CheckUser(cur_user) == false){
			cout << "HP가 0이하입니다. " << cur_user->GetName() << "의 차례를 넘깁니다." << endl;
			turn++;
			continue;
		}

		// 플레이어 차례 문구 안내
		for(int i = 0; i < USER_NUM; i++){
			if(turn % USER_NUM == i){
				cout << user_list[i]->GetName() << " 차례입니다" << endl;
			}
		}

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << cur_user->GetHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,정보,공격,종료): ";
		cin >> user_input;
		
		if (user_input == "상" || user_input == "하" || user_input == "좌" || user_input == "우"){
			// 입력이 유효해 유저가 이동했을 경우 displayMap, checkState 메서드 호출, 아닐 경우 continue
			if(cur_user->Move(mapX, mapY, user_input) == true){
				DisplayMap(map, user_list, USER_NUM);
				CheckState(map, cur_user);
			} else{
				continue;
			}
		}
		else if (user_input == "지도") {
			DisplayMap(map, user_list, USER_NUM);
		}
		else if (user_input == "정보"){
			cout << cur_user << endl;
			continue;
		}
		else if (user_input == "공격"){
			cur_user->DoAttack();
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 동작을 마친후에 유저의 hp가 0이하일 경우 실패했다는 안내 문구 출력
		if(CheckUser(cur_user) == false){
			cout << "HP가 0이하입니다. 실패했습니다." << endl;
		}

		// 모든 유저의 hp가 0 이하인지 체크
		int failed_user = 0;
		for(User* checking_user : user_list){
			if(CheckUser(checking_user) == false){
				failed_user++;
			}
		}

		// 모든 유저의 hp가 0이하일 경우 게임 종료
		if(failed_user == USER_NUM){
			cout << "모든 유저가 실패했습니다. 게임을 종료합니다." << endl;
			break;
		}

		// 목적지에 도달했는지 체크
		// 승리한 유저 체크
		bool finish = CheckGoal(map, cur_user);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << cur_user->GetName() << "의 승리입니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		turn++;
	}
	return 0;
}