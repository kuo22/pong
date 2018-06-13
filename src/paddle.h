#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
private:
	int x, y, length;
public:
	Paddle(int x, int y, int length);
	int getX();
	int getY();
	int getLength();
	void setX(int x);
	void setY(int y);
	void setLength(int length);
};

#endif
