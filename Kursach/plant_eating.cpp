#include "plant_eating.h"

PlantEating::PlantEating(double x, double y, double angle, double speed)
{
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->speed = speed;
}

void PlantEating::move()
{
    double rangeToX = -sin(this->angle);
    double rangeToY = cos(this->angle);
    this->setX(this->getX() + (rangeToX * this->speed));
    this->setY(this->getY() + (rangeToY * this->speed));
}
