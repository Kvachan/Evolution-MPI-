#ifndef PREDATOR
#define PREDATOR

#include "basicagent.h"

class Predator : public basigAgent
{
    double x, y;
    double angle;
    double speed;

public:
    Predator(double x, double y, double angle);
    void move();

    double getSpeed();
    void setSpeed(double speed);

    double getAngle();
    void setAngle(double angle);

    double getRangeToX();
    double getRangeToY();

    double getX();
    void setX(double x);

    double getY();
    void setY(double y);
};

#endif // PREDATOR

