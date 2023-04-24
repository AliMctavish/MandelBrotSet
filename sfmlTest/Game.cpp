#include "Game.h"
#include <vector>




std::vector<sf::RectangleShape> fractels;
std::vector<sf::RectangleShape> zRectVector;





void Game::initVariables()
{
	this->window = nullptr;
	this->zValue.x = 0;
	this->zValue.y = 0;
	this->z = 0;
	this->c = 1;
}


void Game::CenterOfObjects()
{
	this->center.setPosition(sf::Vector2f(1600/2, 1000/2));
	this->center.setFillColor(sf::Color::Red);
	this->center.setSize(sf::Vector2f(1, 1));
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
	this->CenterOfObjects();
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
	this->updateFractels();
}


void Game::updateFractels()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		z = z * z + c;
		sf::RectangleShape rect;
		sf::RectangleShape zRect;
		//rect.setFillColor(sf::Color::White);
		//zRect.setFillColor(sf::Color::Red);
		rect.setSize(sf::Vector2f(2, 2));
		zRect.setSize(sf::Vector2f(2, 2));
		//rect.setPosition(1600/2  + z, 1000 / 2 + c);
		zRect.setPosition(1600/2 + c , 1000 / 2 + c);
		
		if (z >= 2)
		{
			zRect.setFillColor(sf::Color::Blue);
			z = 0;
			c = 0;
		}
		if (z < 2)
		{
			zRect.setFillColor(sf::Color::Yellow);
		}
		std::cout << "z = " << z << std::endl;
		std::cout << "c = " << c << std::endl;
		fractels.push_back(rect);
		zRectVector.push_back(zRect);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		z = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		c += 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		c -= 0.1;
	}

	



}



//float Game::function(float x)
//{
//	x = x ^ 2 + x;
//	return x;
//}



void Game::render()
{
	this->window->clear();
	
	for (auto& zrects : zRectVector)
	{
		this->window->draw(zrects);
	}
	for (auto& fract : fractels)
	{
		this->window->draw(fract);
	}


	



	this->window->draw(this->center);
 
	this->window->display();
}









