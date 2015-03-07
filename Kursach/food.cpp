#include "food.h"

Food::Food()
{
    this->x = 0;
    this->y = 0;
    this->visibility = true;
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

void Food::interact(Environment env)
{
    //body
}
