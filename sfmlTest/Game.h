#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

class Game
{
public:
	sf::RenderWindow* window;

	void initVariables();
	void initWindow();
	void renderCube();
	void updateFractels();
	int y;
	float c , z;


	sf::VideoMode videoMode;
	sf::RectangleShape center;
	sf::Vector2f zValue;
	sf::Event ev; 

public :
	//construct
	Game();
	//destruct
	virtual ~Game();
	//Accessors

	const bool running() const {
		return this->window->isOpen();
	};


	//functions
	void pollEvents();


	void CenterOfObjects();




	void Update();


	void render();

};

