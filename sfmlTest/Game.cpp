#include "Game.h"
#include <vector>
#include <random>




std::vector<sf::RectangleShape> zRectVector;
std::random_device rnd;





void Game::initVariables()
{
	this->window = nullptr;
	this->iteration = 100;
	this->zValue.x = 0;
	this->zValue.y = 0;
	this->z.x = 0;
	this->z.y = 0;
	this->c.x = 0.1;
	this->c.y = 0;
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
	

	for (int i = 0; i < 5000000; i++)
	{


		std::uniform_real_distribution<float> dist(-2, 1);

		this->iteration--;
		z = sf::Vector2f(z.x * z.x - z.y * z.y, (2 * z.x * z.y)) + c;

		if (z.x > 3 || z.y > 3)
		{
			c.x = dist(rnd);
			c.y = dist(rnd);
			z.x = 0;
			z.y = 0;
		}

		

		if (this->iteration == 0)
		{
			this->iteration = 1000;
		}

		if (this->iteration == 500)
		{
			sf::RectangleShape zRect;
			zRect.setSize(sf::Vector2f(1, 1));
			zRect.setFillColor(sf::Color::White);
			zRect.setPosition(1600 / 2 * c.x + 1200, 1000 / 2 * c.y + 500);
			zRectVector.push_back(zRect);
			c.x = dist(rnd);
			c.y = dist(rnd);
		}
		if (this->iteration == 50)
		{
			sf::RectangleShape zRect;
			zRect.setSize(sf::Vector2f(1, 1));
			zRect.setFillColor(sf::Color::Blue);
			zRect.setPosition(1600 / 2 * c.x + 1200, 1000 / 2 * c.y + 500);
			zRectVector.push_back(zRect);
			c.x = dist(rnd);
			c.y = dist(rnd);
		}
	
		if (this->iteration == 1000)
		{
			sf::RectangleShape zRect;
			zRect.setSize(sf::Vector2f(1, 1));
			zRect.setFillColor(sf::Color::White);
			zRect.setPosition(1600 / 2 * c.x + 1200, 1000 / 2 * c.y + 500);
			zRectVector.push_back(zRect);
			c.x = dist(rnd);
			c.y = dist(rnd);
		}
		
	}
		
		std::cout << "c.x = " << c.x << " " << "c.y = " << c.y << std::endl;
		std::cout << "z.x = " << z.x << " " << "z.y = " << z.y << std::endl;
	
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		z.x = 0;
		z.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		c.x += 1;
		c.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		c.x -= 0.1;
		c.y -= 0.1;
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


	this->window->draw(this->center);
 
	this->window->display();
}









