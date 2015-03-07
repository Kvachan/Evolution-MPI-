#include "basicagent.h"

basicAgent::~basicAgent()
{
    this->x = 0;
    this->y = 0;
    this->visibility = false;
}

double basicAgent::getX()
{
    return this->x;
}
double basicAgent::getY()
{
    return this->y;
}
double basicAgent::getAngle()
{
    return this->angle;
}
double basicAgent::getSpeed()
{
    return speed;
}


double basicAgent::getRangeToX()
{
    return -sin(this->angle);
}
double basicAgent::getRangeToY()
{
    return cos(this->angle);
}



void basicAgent::setX(double x)
{
    this->x = x;
}
void basicAgent::setY(double y)
{
    this->y = y;
}
void basicAgent::setVisibility(bool answer)
{
    this->visibility = answer;
}
void basicAgent::setAngle(double angle)
{
    this->angle = angle;
}
void basicAgent::setSpeed(double speed)
{
    this->speed = speed;
}
