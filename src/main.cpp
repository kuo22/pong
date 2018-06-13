#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "paddle.h"

void ballLogic(sf::FloatRect paddleBound, sf::FloatRect ballBound);

int width = 600;
int height = 400;
int paddle_len = 80;
int paddle_x = 100;
Paddle paddle(paddle_x, height / 2, paddle_len);
Ball ball(width / 2, height / 2, 3, 3);
sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
sf::CircleShape shape(10.f);
sf::RectangleShape rect(sf::Vector2f(10, paddle.getLength()));

int main()
{
	shape.setPosition(ball.getX(), ball.getY());
	rect.setPosition(paddle.getX(), paddle.getY());
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::FloatRect paddleBound = rect.getGlobalBounds();
		sf::FloatRect ballBound = shape.getGlobalBounds();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			paddle.setY(paddle.getY() - 3);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			paddle.setY(paddle.getY() + 3);
		}
		rect.setPosition(paddle.getX(), paddle.getY());
		ballLogic(paddleBound, ballBound);
		window.clear();
		window.draw(rect);
		window.draw(shape);
		window.display();
	}

	return 0;
}

void ballLogic(sf::FloatRect paddleBound, sf::FloatRect ballBound) {
	if (ball.getX() == 0 || ball.getX() == width || paddleBound.intersects(ballBound)) {
		ball.setXVel(ball.getXVel() * -1);
	}
	if (ball.getY() <= 3 || ball.getY() >= (height - 20)) {
		ball.setYVel(ball.getYVel() * -1);
	}
	ball.setX(ball.getX() + ball.getXVel());
	ball.setY(ball.getY() + ball.getYVel());
	shape.setPosition(ball.getX(), ball.getY());
}