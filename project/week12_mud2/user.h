#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

class User{
private:
    int x = 0; // 가로 번호
	int y = 0; // 세로 번호
	int hp = 20; // 유저 체력
	int weapon = 0; // 무기 가지고 있는지 여부
	int armor = 0; // 갑옷 가지고 있는지 여부
protected:	
	string name;
	char user_icon = 'U';
	bool CheckXY(int mapX, int mapY, string user_input);
public:
    // private 멤버 변수를 리턴하는 get 메서드
	int GetX() const;
	int GetY() const;
	int GetHP() const;
	int GetWeapon() const;
	int GetArmor() const;
	char GetUserIcon() const;
	string GetName() const;

    // private 멤버 변수를 조작하는 메서드
    bool Move(int mapX, int mapY, string user_input);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void EquipWeapon();
    void EquipArmor();
    void LoseArmor();

	void DoAttack(); // 공격 명령

	friend ostream& operator<<(ostream& os, const User& user);
};

class Magician : public User{
private:
	
public:
	Magician(): User(){
		this->user_icon = 'M';
		this->name = "마법사";
	}
	void DoAttack();
};

class Warrior : public User{
public:
	Warrior() : User(){
		this->user_icon = 'W';
		this->name = "전사";
	}
	void DoAttack();
};

// 사용자 정의 함수
// checkXY 메서드는 User 클래스 내부로 이식
void DisplayMap(vector<vector<int>> map, User user_list[]);
bool CheckGoal(vector<vector<int>> map, User user);
void CheckState(vector<vector<int>> map, User& user);
bool CheckUser(User user);