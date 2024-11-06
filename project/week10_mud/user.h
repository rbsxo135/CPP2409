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
	bool weapon = false; // 무기 가지고 있는지 여부
	int armor = 0; // 갑옷 가지고 있는지 여부

	bool checkXY(int mapX, int mapY, string user_input);
public:
    // private 멤버 변수를 리턴하는 get 메서드
	int getX() const;
	int getY() const;
	int getHP() const;
	bool getWeapon() const;
	int getArmor() const;

    // private 멤버 변수를 조작하는 메서드
    bool move(int mapX, int mapY, string user_input);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void equip_weapon();
    void equip_armor();
    void lose_armor();

};

// 사용자 정의 함수
// checkXY 메서드는 User 클래스 내부로 이식
void displayMap(vector<vector<int>> map, User user);
bool checkGoal(vector<vector<int>> map, User user);
void checkState(vector<vector<int>> map, User& user);
bool checkUser(User user);