#ifndef ABSTRACTAGENT
#define ABSTRACTAGENT

#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>

class AgentsEnvironment;

class Food;
class Agent;

class AbstractAgent {
public:
    virtual ~AbstractAgent() {}

    virtual double getY() = 0;
    virtual double getX() = 0;

    virtual void setX(double x) = 0;
    virtual void setY(double y) = 0;

    virtual void interact(AgentsEnvironment *env) = 0;

    virtual Food* getFood() { return NULL; };
    virtual Agent* getAgent() { return NULL; };

};

#endif // ABSTRACTAGENT
