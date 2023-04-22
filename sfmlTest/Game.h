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
	int x , y;


	sf::VideoMode videoMode;
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


	float function(float x);


	void Update();


	void render();

};

