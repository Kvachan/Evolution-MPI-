#ifndef BASICAGENT
#define BASICAGENT

#include "basic.h"

class basicAgent : public Basic
{
protected:
    double angle, speed;
public:
    virtual ~basicAgent();

    double getX();
    double getY();
    double getSpeed();
    double getAngle();
    double getRangeToX();
    double getRangeToY();

    void setX(double x);
    void setY(double y);
    void setSpeed(double speed);
    void setAngle(double angle);

    void setVisibility(bool answer);

    virtual void move();

    virtual void interact();
};


#endif // BASICAGENT

