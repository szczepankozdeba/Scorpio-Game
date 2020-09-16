#include "Enemy.h"
#include <random>
#include <random>
#include <Windows.h>
using namespace sf;
Enemy::Enemy()
{
	rect.setSize(Vector2f(32, 50));
	rect.setFillColor(Color::Blue);
	rect.setPosition(400, 200);
	sprite.setTextureRect(IntRect(counter * 0, 0, 32, 50));
}


bool Enemy::get_moveup()
{
	return  moveup;
}

bool Enemy::get_movedown()
{
	return  movedown;
}

bool Enemy::get_moveleft()
{
	return  moveleft;
}

bool Enemy::get_moveright()
{
	return  moveright;
}

void Enemy::set_moveup(bool n)
{
	moveup = n;
}

void Enemy::set_movedown(bool n)
{
	movedown = n;
}

void Enemy::set_moveleft(bool n)
{
	moveleft = n;
}

void Enemy::set_moveright(bool n)
{
	moveright = n;
}


int Enemy::get_attack()
{
	return attack;
}
void Enemy::set_attac(int n)
{
	attack = n;
}

int Enemy::rand_number(int n )

{
	
		int a = rand() % n + 1;
		return a;
}

bool Enemy::rand_bool()
{
	int a = 0;

	a = rand() % 2;

	if (a == 1)
		return true;
	else
		return false;
}

void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void Enemy::set_direction(int n)
{
	direction = n;
}
void Enemy::set_hp(int n)
{
	hp = n;
}
void Enemy::set_alive(bool n)
{
	alive = n;
}

bool Enemy::get_alive()
{
	return alive;
}

int Enemy::get_direction()
{
	return direction;
}

double Enemy::get_moveSpeed()
{
	return moveSpeed;
}

int Enemy::get_counter()
{
	return counter;
}


int Enemy::get_hp()
{
	return hp;
}


void Enemy::updatemove()
{
	

	if (direction == 1)
	{
		if(moveup==true)
		{
		rect.move(0, -moveSpeed);
		sprite.setTextureRect(IntRect(0, 105, 30, 38));
		movedown = true;
		moveleft = true;
		moveright = true;
		moveup = true;
		}
	}
	else if (direction ==  2)
	{
		if (movedown == true)
		{
			rect.move(0, moveSpeed);
			sprite.setTextureRect(IntRect(0, 25, 30, 38));
			moveup = true;
			moveleft = true;
			moveright = true;
			movedown = true;
		}
	}
	else  if (direction == 3)
	{
		if (moveleft == true)
		{
			rect.move(-moveSpeed, 0);
			sprite.setTextureRect(IntRect(0, 160, 30, 38));
			movedown = true;
			moveup = true;
			moveright = true;
			moveleft = true;
		}
	}
	 else if (direction == 4)
	{
		if (moveright == true)
		{
			rect.move(moveSpeed, 0);
			sprite.setTextureRect(IntRect(0, 220, 30, 38));
			movedown = true;
			moveleft = true;
			moveup = true;
			moveright = true;
		}
	}
	else
	{

	}

	counter++;
		if (counter > 500)
		{
			direction = rand_number(8);
			counter = 0;
		}
	
	
}



//Enemy::~Enemy()
//{
//}
