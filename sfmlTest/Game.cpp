#include "Game.h"
#include <vector>




std::vector<sf::RectangleShape> fractels;





void Game::initVariables()
{
	this->window = nullptr;
	this->x = 200;
}



void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1600;
	this->window = new sf::RenderWindow(this->videoMode, "mandelbrot set", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}


//void Game::renderCube(sf::RenderWindow* target) 
//{
//
//
//}



Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->pollEvents();
}



//float Game::function(float x)
//{
//	x = x ^ 2 + x;
//	return x;
//}



void Game::render()
{
	this->window->clear();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sf::RectangleShape rect;
		rect.setFillColor(sf::Color::White);
		rect.setSize(sf::Vector2f(2,2));
		rect.setPosition(x/2,(x = x^2 + x)/2);
		fractels.push_back(rect);
	}

	for (auto& fract : fractels)
	{
		this->window->draw(fract);
	}


	this->window->display();
}








