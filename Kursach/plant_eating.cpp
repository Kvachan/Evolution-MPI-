#include "plant_eating.h"

PlantEating::PlantEating(double x, double y, double angle, double speed)
{
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->speed = speed;
    this->visibility = true;
}

PlantEating::~PlantEating()
{
    this->x = 0;
    this->y = 0;
    this->angle = 0;
    this->speed = 0;
    this->visibility = false;
}

void PlantEating::move(Environment env)
{
    double rangeToX = -sin(this->angle);
    double rangeToY = cos(this->angle);
    this->setX(this->getX() + (rangeToX * this->speed));
    this->setX(this->getY() + (rangeToY * this->speed));
}

void PlantEating::interact(Environment env)
{
    this->move(env);
}
