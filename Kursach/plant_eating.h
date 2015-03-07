#ifndef PLANTEATING
#define PLANTEATING

#include "food.h"

class PlantEating : public Food
{
    double angle;
    double speed;
public:
    PlantEating(double x, double y, double angle, double speed);
    virtual ~PlantEating();
    void move();
    void interact(Environment env);
};

#endif // PLANTEATING

