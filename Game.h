#pragma once
#pragma warning(disable : 4996).
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Player.h"
#include "Base.h"
#include<vector>
#include "Shot.h"
#include "Enemy.h"
#include <random>
#include<cstdlib>
#include<sstream>
#include"PickUp.h"
#include "Block.h"

using namespace std;
using namespace sf;



class Game
{
public:

	Game();
	void play();
};

