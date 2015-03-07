#ifndef PREDATOR
#define PREDATOR

#include "basicagent.h"
#include "environment.h"

class Predator : private basicAgent
{

public:
    Predator(double x, double y, double angle);
    ~Predator();

    void move(Environment env);

    void interact(Environment env);
};

#endif // PREDATOR

