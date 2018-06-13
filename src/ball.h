#ifndef BALL_H
#define BALL_H

class Ball {
private:
	int x, y, x_vel, y_vel;

public:
	Ball(int x, int y, int xVel = 3, int y_vel = 3);
	int getX();
	int getY();
	int getXVel();
	int getYVel();
	void setX(int x);
	void setY(int y);
	void setXVel(int x_vel);
	void setYVel(int y_vel);
};

#endif // BALL_H
