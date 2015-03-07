#ifndef PREDATOR
#define PREDATOR

#include "basicagent.h"
#include "environment.h"

class Predator : public basicAgent
{
//    double x, y;
    double angle;
    double speed;

public:
    Predator(double x, double y, double angle);
    virtual ~Predator();

    void move();

    double getSpeed();
    void setSpeed(double speed);

    double getAngle();
    void setAngle(double angle);

    double getRangeToX();
    double getRangeToY();

    void interact()
};

#endif // PREDATOR

