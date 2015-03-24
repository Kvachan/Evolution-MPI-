#ifndef MOVINGFOOD
#define MOVINGFOOD

#include "food.h"

class MovingFood : public Food {
    double angle;
    double speed;
public:
    MovingFood();
    MovingFood(double x, double y, double angle, double spped);
protected:
    void interact(AgentsEnvironment *env) override;
};

#endif // MOVINGFOOD

