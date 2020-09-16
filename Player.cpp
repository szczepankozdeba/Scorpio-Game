#include "Player.h"


using namespace sf;
Player::Player()
{
	rect.setSize(Vector2f(32, 50));
	rect.setFillColor(Color::Blue);
	rect.setPosition(100, 100);
	sprite.setTextureRect(IntRect(counter * 0, 0, 32, 50));
}



int Player::get_killed()
{
  return  killed;
}

bool Player::get_moveup()
{
	return  moveup;
}

bool Player::get_movedown()
{
	return  movedown;
}

bool Player::get_moveleft()
{
	return  moveleft;
}

bool Player::get_moveright()
{
	return  moveright;
}

void Player::set_moveup(bool n)
{
	moveup = n;
}

void Player::set_movedown(bool n)
{
	movedown = n;
}

void Player::set_moveleft(bool n)
{
	moveleft = n;
}

void Player::set_moveright(bool n)
{
	moveright = n;
}
void Player::set_killed(int n)
{
	killed = n;
}

void Player::set_direction(int n)
{
	direction = n;
}

int Player::get_direction()
{
	return direction;
}

double Player::get_moveSpeed()
{
	return moveSpeed;
}

int Player::get_counter()
{
	return counter;
}

int Player::get_attack()
{
	return attack;
}

int Player::get_hp()
{
	return hp;
}
void Player::set_hp(int n)
{
	hp = n;
}


void Player::update()
{
	sprite.setPosition(rect.getPosition());
}
void Player::updatemove()
{
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (moveup == true)
		{
			rect.move(0, -moveSpeed);
			sprite.setTextureRect(IntRect(counter * 0, 350, 32, 50));
			direction = 1;
			movedown = true;
			moveleft = true;
			moveright = true;
			moveup = true;
		} 
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (movedown == true)
		{
			rect.move(0, moveSpeed);
			sprite.setTextureRect(IntRect(counter * 0, 0, 32, 50));
			direction = 2;
			moveup = true;
			moveleft = true;
			moveright = true;
			movedown = true;
		}
	}
	 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (moveleft == true)
		{
			rect.move(-moveSpeed, 0);
			sprite.setTextureRect(IntRect(counter * 64, 150, 32, 50));
			direction = 3;
			movedown = true;
			moveright = true;
			moveup = true;
			moveleft = true;
		}
	}
	 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (moveright == true)
		{
			rect.move(moveSpeed, 0);
			sprite.setTextureRect(IntRect(counter * 64, 250, 32, 50));
			direction = 4;
			movedown = true;
			moveleft = true;
			moveup = true;
			moveright = true;
		}	
	}
	else {};

	counter++;
	if (counter == 2)
	{
		counter = 0;
	}
}