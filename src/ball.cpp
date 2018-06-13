#include "ball.h"

Ball::Ball(int x, int y, int x_vel, int y_vel) {
	setX(x);
	setY(y);
	this->x_vel = x_vel;
	this->y_vel = y_vel;
}

int Ball::getX() { return x; }
int Ball::getY() { return y; }
int Ball::getXVel() { return x_vel; }
int Ball::getYVel() { return y_vel; }

void Ball::setX(int x) {
	this->x = x;
}

void Ball::setY(int y) {
	this->y = y;
}

void Ball::setXVel(int x_vel) {
	this->x_vel = x_vel;
}

void Ball::setYVel(int y_vel) {
	this->y_vel = y_vel;
}