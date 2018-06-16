#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "paddle.h"

void ballLogic(sf::FloatRect paddleBound, sf::FloatRect paddleBound2, sf::FloatRect ballBound);
void paddleLogic();

int width = 600;
int height = 400;
int paddle_len = 80;
int paddle_x = 100;
Paddle p1(paddle_x, height / 2, paddle_len);
Paddle p2(width - paddle_x, height / 2, paddle_len);
Ball ball(width / 2, height / 2, 3, 3);
sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
sf::CircleShape shape(10.f);
sf::RectangleShape rect(sf::Vector2f(5, p1.getLength()));
sf::RectangleShape rect2(sf::Vector2f(5, p2.getLength()));

int main()
{
	shape.setPosition(ball.getX(), ball.getY());
	rect.setPosition(p1.getX(), p1.getY());
	rect2.setPosition(p2.getX(), p2.getY());

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
		sf::FloatRect paddleBound2 = rect2.getGlobalBounds();
		sf::FloatRect ballBound = shape.getGlobalBounds();


		paddleLogic();
		ballLogic(paddleBound, paddleBound2, ballBound);
		window.clear();
		window.draw(rect);
		window.draw(rect2);
		window.draw(shape);
		window.display();
	}

	return 0;
}

void ballLogic(sf::FloatRect paddleBound, sf::FloatRect paddleBound2, sf::FloatRect ballBound) {
	if (ball.getX() == 0 || ball.getX() == width || paddleBound.intersects(ballBound) || paddleBound2.intersects(ballBound)) {
		ball.setXVel(ball.getXVel() * -1);
	}
	if (ball.getY() <= 3 || ball.getY() >= (height - 20)) {
		ball.setYVel(ball.getYVel() * -1);
	}
	ball.setX(ball.getX() + ball.getXVel());
	ball.setY(ball.getY() + ball.getYVel());
	shape.setPosition(ball.getX(), ball.getY());
}

void paddleLogic() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		p1.setY(p1.getY() - 3);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		p1.setY(p1.getY() + 3);
	}
	rect.setPosition(p1.getX(), p1.getY());
}