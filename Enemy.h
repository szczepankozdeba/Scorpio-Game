#pragma once
#include "Base.h"
class Enemy :public Base
{
private:

	double moveSpeed = 0.6;
	int attack = 2;
	int counter = 0;
	int counterE = 0;
	int direction = 0;
	int hp = 5;
	bool alive = true;
	bool moveup = true;
	bool movedown = true;
	bool moveleft = true;
	bool moveright = true;
public:

	int rand_number(int n);
	bool rand_bool();

  	bool get_moveup();                     //GETTERS
	bool get_movedown();
	bool get_moveleft();
	bool get_moveright();
	bool get_alive();                 
	int get_hp();
	int get_direction();
	int get_attack();
	int get_counter();
	double get_moveSpeed();
	 
	void set_hp(int n);                //SETERS
	void set_direction(int n);
	void set_alive(bool n);
	void set_attac(int n);
	void set_moveup(bool n);
	void set_movedown(bool n);
	void set_moveleft(bool n);
	void set_moveright(bool n);
	//void set_direction();
	//void set_moveSpeed();

	void update();
	void updatemove();
	Enemy();
	//~Enemy();
};

