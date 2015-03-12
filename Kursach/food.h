#ifndef FOOD
#define FOOD

#include "environment.h"

class Food : private virtual Basic
{
protected:
    virtual void interact(Environment env);
public:
    Food();
    Food(double x, double y);
    virtual ~Food();
};

#endif // FOOD

