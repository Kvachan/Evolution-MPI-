#ifndef MOVINGFOOD
#define MOVINGFOOD

#include "food.h"

class MovingFood : public Food {
    double angle;
    double speed;
public:
    MovingFood();
    MovingFood(double x, double y, double angle, double spped);
    void interact(AgentsEnvironment *env) override;
protected:
    void move(AgentsEnvironment *env);

};

#endif // MOVINGFOOD

