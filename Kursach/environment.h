#ifndef ENVIRONMENT
#define ENVIRONMENT

#include "basicagent.h"

class Environment
{
    int height, width;
    std::vector<basicAgent> agents;
public:
    Environment();
    Environment(int height, int width);

    int getHeight();
    int getWidth();

    bool addAgent(basicAgent Agent);
    bool removeAgent(basicAgent &Agent);

    std::vector<basicAgent> getAgents();

    void movingOutsideEnvironment(basicAgent &Agent);

};

#endif // ENVIRONMENT

