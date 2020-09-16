#pragma once
#include "Base.h"
class Shot :
	public Base
{
protected:
	double moveSpeed = 3;
	int attack = 5;
	int counter = 0;
	int direction = 0;
	bool destroyed = false;
	int  counterlifeTime = 0;
	int lifeTime = 390;
public:

	int get_direction();              //GETERS
	int get_attack();
	int get_counter();
	bool get_destroyed();
	double get_moveSpeed();
	                                  //SETERS
	void set_direction(int n);
	void set_destroyed(bool n);
	//void set_attac();
	//void set_direction();
	//void set_moveSpeed();


	void update();
	void updatemove();

	Shot();
	//~Shot();
};

