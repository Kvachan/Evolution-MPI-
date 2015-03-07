#ifndef PLANTEATING
#define PLANTEATING

#include "food.h"
#include "basicagent.h"

class PlantEating : private basicAgent, private Food
{
public:
    PlantEating(double x, double y, double angle, double speed);
    ~PlantEating();

    void move(Environment env);

    void interact(Environment env);
};

#endif // PLANTEATING

