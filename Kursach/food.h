#ifndef FOOD
#define FOOD

#include "abstractagent.h"
class AgentsEnvironment;

class Food : public AbstractAgent {
    double x;
    double y;
public:
    Food();
    Food(double x, double y);

    double getX() override;
    double getY() override;

    void setX(double x) override;
    void setY(double y) override;

    void interact(AgentsEnvironment *env) override;
};

#endif // FOOD
