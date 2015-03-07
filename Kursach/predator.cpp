#include "predator.h"
#include <math.h>

Predator::Predator(double x, double y, double angle)
{
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->speed = 0;
    this->visibility = true;
}

Predator::~Predator()
{
    this->x = 0;
    this->y = 0;
    this->speed = 0;
    this->angle = 0;
}

double Predator::getAngle()
{
    return this->angle;
}

double Predator::getSpeed()
{
    return speed;
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
