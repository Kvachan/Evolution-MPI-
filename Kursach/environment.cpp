#include "environment.h"

Environment::Environment()
{
    this->height = 0;
    this->width = 0;
}

Environment::Environment(int height, int width)
{
    this->height = height;
    this->width = width;
}

int Environment::getHeight()
{
    return this->height;
}

int Environment::getWidth()
{
    return this->width;
}

bool Environment::addAgent(basicAgent Agent)
{
    if(&Agent != NULL)
    {
        agents.push_back(Agent);
        return true;
    };
    return false;
}

bool Environment::removeAgent(basicAgent Agent)
{
    std::vector<basicAgent>::iterator it;

    if(this->agents.empty())
    {
        return false;
    }

    it = std::find(this->agents.begin(), this->agents.end(), Agent);

    if(it != this->agents.end())
    {
        return true;
    }
    return false;
}

std::vector<basicAgent> Environment::getAgents()
{
    return this->agents;
}

void Environment::movingOutsideEnvironment(basicAgent &Agent)
{
    int x = Agent.getX();
    int y = Agent.getY();

    if (x < 0)
    {
        x = this->width - 1;
    }

    if (y < 0)
    {
        y = this->height - 1;
    }
    if (x > this->width)
    {
        x = 1;
    }

    if(y > this->height)
    {
        y = 1;
    }

    Agent.setX(x);
    Agent.setY(y);
}
