#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

class User{
private:
	int x = 0; // 가로 번호
	int y = 0; // 세로 번호
	int hp = 20; // 유저 체력
	bool weapon = false; // 무기 가지고 있는지 여부
	int armor = 0; // 갑옷 가지고 있는지 여부

	// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
	// User 객체를 참조자 매개변수로 받는다
	bool checkXY(int mapX, int mapY, string user_input) {
		if (this->x >= 0 && this->x < mapX && this->y >= 0 && this->y < mapY) {
			return true;
		} else{
			// 맵을 벗어났을 경우 오류 메시지를 출력하고 원래 좌표로 돌아간다
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			if(user_input == "상"){
				this->y++;
			} else if(user_input == "하"){
				this->y--;
			} else if(user_input == "좌"){
				this->x++;
			} else if(user_input == "우"){
				this->x--;
			}
		}
		return false;
	}
public:
	// private 멤버 변수를 리턴하는 get 메서드
	int getX(){
		return this->x;
	}
	int getY(){
		return this->y;
	}
	int getHp(){
		return this->hp;
	}
	bool getWeapon(){
		return this->weapon;
	}
	int getArmor(){
		return this->armor;
	}

	// private 멤버 변수롤 조작하는 메서드

	// 유저의 위치를 이동시키는 메서드
	// 이동이 유효할 경우 true 그러지 않을 경우 false 반환
	bool move(int mapX, int mapY, string user_input){
		if (user_input == "상") {
			// 위로 한 칸 올라가기
			this->y--;
			bool inMap = this->checkXY(mapX, mapY, user_input);
			if (inMap == true) {
				this->setHp(-1);
				cout << "위로 한 칸 올라갑니다." << endl;
				return true;
			}
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			this->y++;
			bool inMap = this->checkXY(mapX, mapY, user_input);
			if (inMap == true) {
				this->setHp(-1);
				cout << "아래로 한 칸 내려갑니다." << endl;
				return true;
			}
		}
		else if (user_input == "좌") {
			// 왼쪽으로 한 칸 이동하기
			this->x--;
			bool inMap = this->checkXY(mapX, mapY, user_input);
			if (inMap == true) {
				this->setHp(-1);
				cout << "왼쪽으로 이동합니다." << endl;
				return true;
			}
		}
		else if (user_input == "우") {
			// 오른쪽으로 한 칸 이동하기
			this->x++;
			bool inMap = this->checkXY(mapX, mapY, user_input);
			if (inMap == true) {
				this->setHp(-1);
				cout << "오른쪽으로 이동합니다." << endl;
				return true;
			}
		} 
		return false;
	}
	void setHp(int hpDiff){
		// HP 변경 전/후 차이를 매개변수로 받는다
		this->hp += hpDiff;
	}
	void equip_weapon(){
		this->weapon = true;
	}
	void equip_armor(){
		this->armor++;
	}
	void lose_armor(){
		this->armor--;
	}
};

// 사용자 정의 함수
// checkXY 메서드는 User 클래스 내부로 이식
void displayMap(int map[][mapX], User user);
bool checkGoal(int map[][mapX], User user);
void checkState(int map[][mapX], User& user);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { 
		{0, 1, 2, 0, 4},
		{1, 0, 0, 2, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 3, 0, 0},
		{3, 0, 0, 0, 2} 
	};
	
	// 유저 객체 생성
	User user;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << user.getHp() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
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
		if(user.getHp() <= 0){
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

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], User user) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user.getY() && j == user.getX()) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 유저의 위치가 목적지인지 체크하는 함수
// User 객체를 매개변수로 받아 x, y좌표를 구한다
bool checkGoal(int map[][mapX], User user) {
	// 목적지 도착하면
	if (map[user.getY()][user.getX()] == 4) {
		return true;
	}
	return false;
}

// 아이템, 포션, 적을 만났을 때 메시지 출력
// User 객체를 참조자 매개변수로 받는다
void checkState(int map[][mapX], User& user){
	if(map[user.getY()][user.getX()] == 1){
		// 아이템 중 무기와 갑옷을 랜덤하게 얻는다
		int item = rand() % 2;
		if(item == 0){
			user.equip_weapon();
			cout << "무기를 얻었습니다." << endl;
		} else{
			user.equip_armor();
			cout << "갑옷을 얻었습니다. 현재 갑옷 개수: " << user.getArmor() << endl;
		}
	} else if(map[user.getY()][user.getX()] == 2){
		cout << "적이 있습니다. ";
		if(user.getArmor() > 0){
			// 갑옷이 있을 경우 HP가 줄어들지 않고 갑옷의 개수가 하나 줄어든다
			// 갑옷과 무기가 둘 다 있을 경우 갑옷을 먼저 소모하도록 설계
			user.lose_armor();
			cout << "갑옷으로 막아내 피해를 막았습니다. 갑옷이 파괴됩니다. 현재 갑옷 개수: " << user.getArmor() << endl;
		} else if(user.getWeapon() == true){
			// 무기가 있을 경우 HP가 1만 줄어든다
			cout << "무기가 있습니다. HP가 1 줄어듭니다." << endl;
			user.setHp(-1);
		} else{
			// 갑옷과 무기 둘 다 없을 경우 HP가 2 줄어든다
			cout << "HP가 2 줄어듭니다." << endl;
			user.setHp(-2);
		}
	} else if(map[user.getY()][user.getX()] == 3){
		cout << "포션이 있습니다. HP가 2 회복됩니다." << endl;
		user.setHp(2);
	}
}
