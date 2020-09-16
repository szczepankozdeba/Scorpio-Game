#include "Shot.h"



Shot::Shot()
{
	rect.setSize(Vector2f(32, 32));
	rect.setFillColor(Color::Magenta);
	rect.setPosition(0,0);
	sprite.setTextureRect(IntRect( 252, 1, 34, 34));
}



void Shot::set_direction(int n)
{
	direction = n;
}

int Shot::get_direction()
{
	return direction;
}

double Shot::get_moveSpeed()
{
	return moveSpeed;
}

int Shot::get_counter()
{
	return counter;
}

int Shot::get_attack()
{
	return attack;
}


void Shot::update()
{
	if (direction == 1)  //up
	{
		rect.move(0, -moveSpeed);
	}
	if (direction == 2)  //down
	{
		rect.move(0, moveSpeed);
	}
	if (direction == 3)   // left
	{
		rect.move(-moveSpeed, 0);   
	}
	if (direction == 4)   //right
	{
		rect.move(moveSpeed, 0);
	}

	counterlifeTime++;
	if (counterlifeTime >= lifeTime)
	{
		set_destroyed(true);
	}
	sprite.setPosition(rect.getPosition());

}

bool Shot::get_destroyed()
{
	return destroyed;
}

void Shot::set_destroyed(bool n)
{
	destroyed = n;
}


	
