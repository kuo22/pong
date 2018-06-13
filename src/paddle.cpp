#include "paddle.h"

Paddle::Paddle(int x, int y, int length) {
	setX(x);
	setY(y);
	setLength(length);
}

int Paddle::getX() {
	return x;
}

int Paddle::getY() {
	return y;
}

int Paddle::getLength() {
	return length;
}

void Paddle::setX(int x) {
	this->x = x;
}

void Paddle::setY(int y) {
	this->y = y;
}

void Paddle::setLength(int length) {
	this->length = length;
}