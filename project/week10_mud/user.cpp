#include "user.h"

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
// User 객체를 참조자 매개변수로 받는다
bool User::checkXY(int mapX, int mapY, string user_input) {
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

int User::getX() const{
		return this->x;
}
int User::getY() const{
	return this->y;
}
int User::getHP() const{
	return this->hp;
}
bool User::getWeapon() const{
	return this->weapon;
}
int User::getArmor() const{
	return this->armor;
}

// 유저의 위치를 이동시키는 메서드
// 이동이 유효할 경우 true 그러지 않을 경우 false 반환
bool User::move(int mapX, int mapY, string user_input){
    if (user_input == "상") {
		// 위로 한 칸 올라가기
		this->y--;
		bool inMap = this->checkXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "위로 한 칸 올라갑니다." << endl;
			return true;
		}
	}
	else if (user_input == "하") {
		// 아래로 한 칸 내려가기
		this->y++;
		bool inMap = this->checkXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "아래로 한 칸 내려갑니다." << endl;
			return true;
			}
	}
	else if (user_input == "좌") {
		// 왼쪽으로 한 칸 이동하기
		this->x--;
		bool inMap = this->checkXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "왼쪽으로 이동합니다." << endl;
			return true;
		}
	}
	else if (user_input == "우") {
		// 오른쪽으로 한 칸 이동하기
		this->x++;
		bool inMap = this->checkXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "오른쪽으로 이동합니다." << endl;
			return true;
		}
	}  
    return false;
}
void User::DecreaseHP(int dec_hp){
    this->hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp){
    this->hp += inc_hp;
}
void User::equip_weapon()
{
    this->weapon = true;
}
void User::equip_armor(){
    this->armor++;
}
void User::lose_armor(){
    this->armor--;
}

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
			user.DecreaseHP(1);
		} else{
			// 갑옷과 무기 둘 다 없을 경우 HP가 2 줄어든다
			cout << "HP가 2 줄어듭니다." << endl;
			user.DecreaseHP(2);
		}
	} else if(map[user.getY()][user.getX()] == 3){
		cout << "포션이 있습니다. HP가 2 회복됩니다." << endl;
		user.IncreaseHP(2);
	}
}

bool checkUser(User user){
    if(user.getHP() > 0){
        return true;
    } else{
        return false;
    }
}

