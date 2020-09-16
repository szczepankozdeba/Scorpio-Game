#pragma once
#include "Base.h"
class PickUp :
	public Base
{
private:
	bool isCoin = false;


public:
    
	void update();
	bool get_isCoin();
	void set_isCoin(bool n);
	PickUp();
	
};

