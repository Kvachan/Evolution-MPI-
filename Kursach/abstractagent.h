#ifndef ABSTRACTAGENT
#define ABSTRACTAGENT

#include <math.h>
#include <vector>

class AgentsEnvironment;

class AbstractAgent {
public:
    virtual ~AbstractAgent() {};

    virtual double getY() = 0;
    virtual double getX() = 0;

    virtual void setX(double x) = 0;
    virtual void setY(double y) = 0;

    virtual void interact(AgentsEnvironment *env) = 0;
};

#endif // ABSTRACTAGENT
