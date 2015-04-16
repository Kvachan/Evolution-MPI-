#ifndef ABSTRACTAGENT
#define ABSTRACTAGENT

#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>

class AgentsEnvironment;

class AbstractAgent {
public:
    virtual ~AbstractAgent() {};

    virtual double getY();
    virtual double getX();

    virtual void setX(double x);
    virtual void setY(double y);

    virtual void interact(AgentsEnvironment *env);
};

#endif // ABSTRACTAGENT
