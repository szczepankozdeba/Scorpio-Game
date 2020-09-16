#pragma once
#include "Base.h"

class Player :public Base

{
private:

	 double moveSpeed = 0.7;
	int attack = 4;
	int counter = 0;
	int direction = 0;
	int hp = 10;
	int killed = 0;
	bool moveup = true;
	bool movedown = true;
	bool moveleft = true;
	bool moveright = true;
public:
	 
	bool get_moveup();
	bool get_movedown();
	bool get_moveleft();
	bool get_moveright();
	int get_killed();//GETTERS
	int get_direction();
	int get_attack();
	int get_counter();
	int get_hp();
	double get_moveSpeed();
	                          //SETERS
	void set_direction(int n);
	void set_hp(int n);
	void set_killed(int n);
	void set_moveup(bool n);
	void set_movedown(bool n);
	void set_moveleft(bool n);
	void set_moveright (bool n);
	//void set_attac();
	//void set_direction();
	//void set_moveSpeed();

	void update();
	void updatemove();
	Player();
	
};

