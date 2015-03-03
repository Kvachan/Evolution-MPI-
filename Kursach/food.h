#ifndef FOOD
#define FOOD

#include "basicagent.h"

class Food : public basicAgent
{
protected:
    double x, y;
public:
    Food();
    Food(double x, double y);
    virtual ~Food();

    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
};

#endif // FOOD

