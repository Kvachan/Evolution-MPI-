#include "predator.h"
#include <math.h>

Predator::Predator(double x, double y, double angle)
{
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->speed = 0;
}

double Predator::getX()
{
    return this->x;
}

double Predator::getY()
{
    return this->y;
}

double Predator::getAngle()
{
    return this->angle;
}

double Predator::getSpeed()
{
    return speed;
}

void Predator::setX(double x)
{
    this->x = x;
}

void Predator::setY(double y)
{
    this->y = y;
}

void Predator::setAngle(double angle)
{
    this->angle = angle;
}

void Predator::setSpeed(double speed)
{
    this->speed = speed;
}

double Predator::getRangeToX()
{
    return -sin(this->angle);
}

double Predator::getRangeToY()
{
    return cos(this->angle);
}

void Predator::move()
{
    double rangeToX = -sin(this->angle);
    double rangetToY = cos(this->angle);
    this->x += rangeToX;
    this->y += rangetToY;
}
