#include <iostream>

/*
** static member variable
** 프로그램이 종료될 때 사라짐
** 클래스의 모든 객체들이 공유하는 변수, 멤버 변수와 달리 모든 객체들이 하나의 static을 사용함
** 클래스 자체에 종속되어 있다고 보면 좋을듯
**
** static member function
** 클래스 자체에서 호출할 수 있는 함수
*/
class Marine {

private:
	static int total_marine_num;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

public:
	Marine();				//default constructor
	Marine(int x, int y);	//construct marine in (x,y)
	Marine(int x, int y, int default_damage); //contruct mainre in (x, y) with default_damage

	~Marine();

	int attack() const;						//return damage
	Marine& beAttacked(int damage_earn);	//damaged by enemy
	void move(int x, int y);				//move to (x, y)

	static void showTotalMarine();

	void showStatus();	//display status
};

//기본적으로 모든 전역/static 변수들은 선언과 동시에 0으로 초기화 되지만 클래스 static 변수들은 아래와 같은 방법으로 초기화해주어야 함
int Marine::total_marine_num = 0;

/*
** same as
** Marine::Marine() {
	hp = 50;
	coord_x = 0;
	coord_y = 0;
	damage = 5;
	is_dead = false;
}
** this is initializer list
** construct and initialize a instance at the same time
** reference and const variable must be initialized by initializer list
*/
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {total_marine_num++; }

Marine::Marine(int x, int y, int default_damage) :
		coord_x(x),
		coord_y(y),
		hp(50),
		default_damage(default_damage),
		is_dead(false) { total_marine_num++; }

Marine::~Marine() { total_marine_num--; }

int Marine::attack() const { return this->default_damage; }

Marine& Marine::beAttacked(int damage_earn) { 
	this->hp -= damage_earn;
	if (hp <= 0)
		this->is_dead = true;

	return *this;
}

void Marine::move(int x, int y) {
	this->coord_x = x;
	this->coord_y = y;
}

//static 멤버 함수안에서는 오직 static 멤버 변수만 이용가능하다.
void Marine::showTotalMarine() {
	std::cout << "Total Marine Num : " << total_marine_num << std::endl;
}

void Marine::showStatus() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << this->coord_x << " , " << this->coord_y << " ) " << std::endl;
	std::cout << " HP : " << this->hp << std::endl;
	std::cout << " 현재 총 마린수 : " << total_marine_num << std::endl;
}

int main () {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.showStatus();
	marine2.showStatus();

	std::cout << std::endl << "marine1 attacked marine2!" << std::endl;
	marine2.beAttacked(marine1.attack());

	marine1.showStatus();
	marine2.showStatus();
}

