#include "food.h"

Food::Food()
{
    this->x = 0;
    this->y = 0;
}

Food::Food(double x, double y)
{
    this->x = x;
    this->y = y;
}

Food::~Food()
{
    this->x = 0;
    this->y = 0;
}

void Food::setX(double x)
{
    this->x = x;
}

void Food::setY(double y)
{
    this->y = y;
}

double Food::getX()
{
    return this->x;
}

double Food::getY()
{
    return this->y;
}
