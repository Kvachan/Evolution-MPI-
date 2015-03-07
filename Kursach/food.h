#ifndef FOOD
#define FOOD

#include "basicagent.h"
#include "environment.h"

class Food : public basicAgent
{
public:
    Food();
    Food(double x, double y);
    virtual ~Food();
    virtual void interact(Environment env);
};

#endif // FOOD

