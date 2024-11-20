#include "user.h"

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
// User 객체를 참조자 매개변수로 받는다
bool User::CheckXY(int mapX, int mapY, string user_input) {
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

int User::GetX() const{
		return this->x;
}
int User::GetY() const{
	return this->y;
}
int User::GetHP() const{
	return this->hp;
}
int User::GetWeapon() const{
	return this->weapon;
}
int User::GetArmor() const{
	return this->armor;
}
char User::GetUserIcon() const{
	return this->user_icon;
}
string User::GetName() const{
	return this->name;
}

// 유저의 위치를 이동시키는 메서드
// 이동이 유효할 경우 true 그러지 않을 경우 false 반환
bool User::Move(int mapX, int mapY, string user_input){
    if (user_input == "상") {
		// 위로 한 칸 올라가기
		this->y--;
		bool inMap = this->CheckXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "위로 한 칸 올라갑니다." << endl;
			return true;
		}
	}
	else if (user_input == "하") {
		// 아래로 한 칸 내려가기
		this->y++;
		bool inMap = this->CheckXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "아래로 한 칸 내려갑니다." << endl;
			return true;
			}
	}
	else if (user_input == "좌") {
		// 왼쪽으로 한 칸 이동하기
		this->x--;
		bool inMap = this->CheckXY(mapX, mapY, user_input);
		if (inMap == true) {
			this->DecreaseHP(1);
			cout << "왼쪽으로 이동합니다." << endl;
			return true;
		}
	}
	else if (user_input == "우") {
		// 오른쪽으로 한 칸 이동하기
		this->x++;
		bool inMap = this->CheckXY(mapX, mapY, user_input);
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
void User::EquipWeapon()
{
    this->weapon = true;
}
void User::EquipArmor(){
    this->armor++;
}
void User::LoseArmor(){
    this->armor--;
}

// 공격 명령
void User::DoAttack(){
	cout << "공격합니다" << endl;
}

void DisplayMap(vector<vector<int>> map, User user_list[]) {
	bool user_on = false;

	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			// 유저 리스트안의 유저를 전부 탐색
			user_on = false;
			for(int k = 0; k < 2; k++)
				// 맵의 한 위치에 유저가 있을 때 이전에 유저가 탐색되지 않았고 유저가 생존해 있을 경우 유저를 맵에 표시
				if (i == user_list[k].GetY() && j == user_list[k].GetX() && user_on == false && user_list[k].GetHP() > 0) {
					// 두 명의 유저가 같이 있을 경우 표시
					// 두 명보다 많은 유저가 참가해도 표시할 수 있도록 확장하는 부분은 구현하지 못했습니다.
					if(user_list[0].GetX() == user_list[1].GetX() && user_list[0].GetY() == user_list[1].GetY()){
						cout << " M  W |"; // 양 옆 1칸 공백, 가운데 2칸 공백
						user_on = true;
					}
					// 한 명의 유저만 있을 경우 표시
					else{
						cout << "  " << user_list[k].GetUserIcon() << "   |"; // 왼쪽 공백 2칸, 오른쪽 공백 3칸
						user_on = true;
					}
				}
			// 맵의 한 위치에 유저가 없을 경우 오브젝트 표시
			if(user_on == false) {
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
bool CheckGoal(vector<vector<int>> map, User user) {
	// 목적지 도착하면 true 아닐 경우 false 반환
	if (map[user.GetY()][user.GetX()] == 4) {
		return true;
	}
	return false;
}

// 아이템, 포션, 적을 만났을 때 메시지 출력
// User 객체를 참조자 매개변수로 받는다
void CheckState(vector<vector<int>> map, User& user){
	if(map[user.GetY()][user.GetX()] == 1){
		// 아이템 중 무기와 갑옷을 랜덤하게 얻는다
		int item = rand() % 2;
		if(item == 0){
			user.EquipWeapon();
			cout << "무기를 얻었습니다. 현재 무기 개수: " << user.GetWeapon() << endl;
		} else{
			user.EquipArmor();
			cout << "갑옷을 얻었습니다. 현재 갑옷 개수: " << user.GetArmor() << endl;
		}
	} else if(map[user.GetY()][user.GetX()] == 2){
		cout << "적이 있습니다. ";
		if(user.GetArmor() > 0){
			// 갑옷이 있을 경우 HP가 줄어들지 않고 갑옷의 개수가 하나 줄어든다
			// 갑옷과 무기가 둘 다 있을 경우 갑옷을 먼저 소모하도록 설계
			user.LoseArmor();
			cout << "갑옷으로 막아내 피해를 막았습니다. 갑옷이 파괴됩니다. 현재 갑옷 개수: " << user.GetArmor() << endl;
		} else if(user.GetWeapon() >= 1){
			// 무기가 있을 경우 HP가 1만 줄어든다
			cout << "무기가 있습니다. HP가 1 줄어듭니다." << endl;
			user.DecreaseHP(1);
		} else{
			// 갑옷과 무기 둘 다 없을 경우 HP가 2 줄어든다
			cout << "HP가 2 줄어듭니다." << endl;
			user.DecreaseHP(2);
		}
	} else if(map[user.GetY()][user.GetX()] == 3){
		cout << "포션이 있습니다. HP가 2 회복됩니다." << endl;
		user.IncreaseHP(2);
	}
}

bool CheckUser(User user){
    if(user.GetHP() > 0){
        return true;
    } else{
        return false;
    }
}

void Magician::DoAttack(){
	cout << "마법 사용" << endl;
}

void Warrior::DoAttack(){
	cout << "베기 사용" << endl;
}

ostream &operator<<(ostream &os, const User &user)
{
    cout << "현재 HP는 " << user.GetHP() << " 이고, 무기 " << user.GetWeapon() 
			<< "개, 갑옷 " << user.GetArmor() << "개 입니다";
	return os;
}