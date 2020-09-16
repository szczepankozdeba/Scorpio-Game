#include "PickUp.h"





bool PickUp::get_isCoin()
{
	return isCoin;
}
void PickUp::set_isCoin(bool n)
{
	isCoin = n;
}


PickUp::PickUp()
{
	rect.setSize(Vector2f(50, 50));
	rect.setFillColor(Color::Blue);
	rect.setPosition(400, 200);
	sprite.setTextureRect(IntRect( 50, 50, 50, 50));
}



void PickUp::update()
{
	sprite.setPosition(rect.getPosition());
}
