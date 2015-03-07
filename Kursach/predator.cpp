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
    this->visibility = false;
}



void Predator::move(Environment env)
{
    double rangeToX = -sin(this->angle);
    double rangetToY = cos(this->angle);
    this->x += rangeToX;
    this->y += rangetToY;
}

void Predator::interact(Environment env)
{
    //body
}
