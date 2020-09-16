#include "Game.h"



Game::Game()
{
	
}


void Game::play()
{
	RenderWindow window{ VideoMode(1200, 900), "GRAJ W GRE" };
	window.setFramerateLimit(10000000000);



	Clock clock1;
	Clock clock2;
	Clock clock3;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 399;
	int counter4 = 0;

	Texture texture;
	texture.loadFromFile("t³o.png");
	Font font;
	if (!font.loadFromFile("file.ttf"))
	{
		std::cout << "error0;";
		system("pause");
	};

	Texture texturePlayer;
	texturePlayer.loadFromFile("char1.png");

	//TEXTURE ENEMY 
	Texture textureEnemy;
	textureEnemy.loadFromFile("sprite_enemy_scorpion.png");
	//TEXTURE SHOOT
	Texture textureShot;
	textureShot.loadFromFile("kula.png");




	if (!font.loadFromFile("file.ttf"))
	{
		std::cout << "error0;";
		system("pause");
	};



	Sprite spriteShot(textureShot);
	spriteShot.setTextureRect(IntRect(0, 0, 32, 50));

	Event event;

	Text text;
	text.setString("Game Over");
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(Color::Yellow);
	text.setPosition(400, 350);

	Text text2;

	text2.setFont(font);
	text2.setCharacterSize(40);
	text2.setFillColor(Color::Red);
	text2.setPosition(22, 20);

	Text text3;

	text3.setFont(font);
	text3.setCharacterSize(25);
	text3.setFillColor(Color::Yellow);
	text3.setPosition(2, 2);






	Music music1;
	music1.openFromFile("Instrumental.wav");
	music1.play();


	Player player1;

	player1.sprite.setTexture(texturePlayer);

	//Shot vector

	vector<Shot>::const_iterator iter;
	vector<Shot>shotArray;
	//objekt Shot
	Shot shot1;
	shot1.sprite.setTexture(textureShot);


	vector<Enemy>::const_iterator iter4;
	vector<Enemy>enemyArray;;                               //VeCTOR ENEMY



	vector<Block>::const_iterator iter15;
	vector<Block>blockArray;;                               //VeCTOR BLOKS


	Block block_horizontal;
	block_horizontal.rect.setSize(Vector2f(300, 25));

	Block block_vertical;
	block_vertical.rect.setSize(Vector2f(25, 300));



	counter = 0;
	while (counter < 4)                            //HORIZONTAL
	{
		block_horizontal.rect.setPosition(300 * counter, 0);
		blockArray.push_back(block_horizontal);
		counter++;
	}
	counter = 0;
	while (counter < 3)                           //VERYOCAL
	{
		block_vertical.rect.setPosition(0, counter * 300);
		blockArray.push_back(block_vertical);
		counter++;
	}
	counter = 0;
	while (counter < 4)                       //HORIZONTAL
	{
		block_horizontal.rect.setPosition(300 * counter, 880);
		blockArray.push_back(block_horizontal);
		counter++;
	}
	counter = 0;
	while (counter < 3)                           //VERTICAL
	{
		block_vertical.rect.setPosition(1180, counter * 300);
		blockArray.push_back(block_vertical);
		counter++;
	}

	counter = 0;
	while (counter < 1)                           //VERTICAL
	{
		block_vertical.rect.setPosition(350, counter * 300);
		blockArray.push_back(block_vertical);
		counter++;
	}
	counter = 0;
	while (counter < 1)                           //VERTICAL
	{
		block_vertical.rect.setPosition(700, counter * 300);
		blockArray.push_back(block_vertical);
		counter++;
	}
	counter = 0;
	while (counter < 1)                           //VERTICAL
	{
		block_vertical.rect.setPosition(1050, counter * 300);
		blockArray.push_back(block_vertical);
		counter++;
	}


	counter = 1;
	while (counter < 3)                            //HORIZONTAL
	{
		block_horizontal.rect.setPosition(counter * 350, 300);
		blockArray.push_back(block_horizontal);
		counter++;
	}
	counter = 0;
	while (counter < 3)                            //HORIZONTAL
	{
		block_horizontal.rect.setPosition(300 * counter, 600);
		blockArray.push_back(block_horizontal);
		counter++;
	}

	counter = 2;
	while (counter < 3)                           //VERTICAL
	{
		block_vertical.rect.setPosition(700, counter * 350);
		blockArray.push_back(block_vertical);
		counter++;
	}
	counter = 2;
	while (counter < 3)                           //VERTICAL
	{
		block_vertical.rect.setPosition(400, counter * 350);
		blockArray.push_back(block_vertical);
		counter++;
	}



	Enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	enemy1.sprite.setTextureRect(IntRect(0, 25, 30, 38));
	enemy1.rect.setPosition(500, 300);
	enemyArray.push_back(enemy1);



	while (window.isOpen())

	{



		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		//WINDOW CLEAR
		window.clear();


		Time elapsed1 = clock1.getElapsedTime();
		Time elapsed2 = clock2.getElapsedTime();
		Time elapsed3 = clock3.getElapsedTime();


		//ZDERZENIE ZE SCIANA ENEMY
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			counter2 = 0;

			for (iter15 = blockArray.begin(); iter15 != blockArray.end(); iter15++)
			{
				if (enemyArray[counter].rect.getGlobalBounds().intersects(blockArray[counter2].rect.getGlobalBounds()))
				{
					if (enemyArray[counter].get_direction() == 1) //up
					{
						enemyArray[counter].set_moveup(false);
						enemyArray[counter].rect.move(0, 1);
					}
					else if (enemyArray[counter].get_direction() == 2) //down
					{
						enemyArray[counter].set_movedown(false);
						enemyArray[counter].rect.move(0, -1);
					}
					else if (enemyArray[counter].get_direction() == 3) //left
					{
						enemyArray[counter].set_moveleft(false);
						enemyArray[counter].rect.move(1, 0);
					}
					else if (enemyArray[counter].get_direction() == 4) //right
					{
						enemyArray[counter].set_moveright(false);
						enemyArray[counter].rect.move(-1, 0);
					}
					else {};
				}
				counter2++;
			}

			counter++;
		}

		//  ZDERZENIE ZE ŒCIANA
		counter1 = 0;

		for (iter15 = blockArray.begin(); iter15 != blockArray.end(); iter15++)
		{
			if (player1.rect.getGlobalBounds().intersects(blockArray[counter1].rect.getGlobalBounds()))
			{
				if (player1.get_direction() == 1) //up
				{
					player1.set_moveup(false);
					player1.rect.move(0, 1);
				}
				else if (player1.get_direction() == 2) //down
				{
					player1.set_movedown(false);
					player1.rect.move(0, -1);
				}
				else if (player1.get_direction() == 3) //left
				{
					player1.set_moveleft(false);
					player1.rect.move(1, 0);
				}
				else if (player1.get_direction() == 4) //right
				{
					player1.set_moveright(false);
					player1.rect.move(-1, 0);
				}
				else {};


			}
			window.draw(blockArray[counter1].rect);
			counter1++;
		}


		text2.setString("Hp :  " + to_string(player1.get_hp()));

		if (elapsed2.asSeconds() >= 0.5)
		{

			clock2.restart();
			counter = 0;

			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{
					player1.set_hp(player1.get_hp() - enemyArray[counter].get_attack());
				}

				counter++;
			}

		}



		counter = 0;
		for (iter = shotArray.begin(); iter != shotArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (shotArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))

				{

					shotArray[counter].set_destroyed(true);
					enemyArray[counter2].set_hp(enemyArray[counter2].get_hp() - 1);
					if (enemyArray[counter2].get_hp() <= 0)
					{
						enemyArray[counter2].set_alive(false);
					}
				}
				counter2++;
			}

			counter4 = 0;
			for (iter15 = blockArray.begin(); iter15 != blockArray.end(); iter15++)
			{
				if (shotArray[counter].rect.getGlobalBounds().intersects(blockArray[counter4].rect.getGlobalBounds()))

				{

					shotArray[counter].set_destroyed(true);

				}

				counter4++;
			}


			counter++;
		}


		//USUNIÊCIE MARTWEGO BOTA
		counter = 0;

		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].get_alive() == false)
			{
				player1.set_killed(player1.get_killed() + 1);
				enemyArray.erase(iter4);
				break;
			}
			counter++;
		}



		counter = 0;
		for (iter = shotArray.begin(); iter != shotArray.end(); iter++)
		{
			if (shotArray[counter].get_destroyed() == true)
			{
				shotArray.erase(iter);
				break;
			}

			counter++;
		}


		counter = 0;




		counter3++;
		if (counter3 > 500)
		{
			enemy1.rect.setPosition(rand() % 1150, rand() % 850);
			enemyArray.push_back(enemy1);
			counter3 = 0;
		}


		if (elapsed1.asSeconds() >= 0.12)
		{
			clock1.restart();

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{

				shot1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2 - shot1.rect.getSize().x / 2,
					player1.rect.getPosition().y + player1.rect.getSize().y / 2 - shot1.rect.getSize().y / 2);
				shot1.set_direction(player1.get_direction());
				shotArray.push_back(shot1);

			}
		}


		counter1 = 0;

		for (iter15 = blockArray.begin(); iter15 != blockArray.end(); iter15++)
		{
			window.draw(blockArray[counter1].rect);
			counter1++;
		}
		counter1 = 0;

		for (iter = shotArray.begin(); iter != shotArray.end(); iter++)
		{
			shotArray[counter1].update();
			window.draw(shotArray[counter1].sprite);
			counter1++;
		}
		counter1 = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter1].update();
			enemyArray[counter1].updatemove();
			window.draw(enemyArray[counter1].sprite);
			counter1++;
		}


		window.draw(text2);
		player1.update();
		player1.updatemove();
		window.draw(player1.sprite);




		if (player1.get_hp() <= 0)
		{

			string s = to_string(player1.get_killed());
			Text text1;
			text1.setString("You have killed:  " + s + " enemies");
			text1.setFont(font);
			text1.setCharacterSize(20);
			text1.setFillColor(Color::Yellow);
			text1.setPosition(900, 800);

			//music.stop();



			window.clear();
			window.draw(text);
			window.draw(text1);




		}

		window.display();


	}
}
