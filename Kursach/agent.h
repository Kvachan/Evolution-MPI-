#ifndef AGENT
#define AGENT

#include "abstractagent.h"

class Agent : public AbstractAgent
{
    double x;
    double y;
    double angle;
    double speed;
public:
    Agent();
    Agent(double x, double y, double angle);

    void move();

    double getX() override;
    double getY() override;

    void setX(double x) override;
    void setY(double y) override;

    void interact(AgentsEnvironment *env) override;

    double getSpeed();
    void setSpeed(double v);

    double getAngle();
    void setAngle(double angle);

    double getRx();
    double getRy();
};

#endif // AGENT
