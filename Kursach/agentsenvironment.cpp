//CHECK (filter)
#include "agentsenvironment.h"
#include "abstractagent.h"
#include "environmentobserver.h"


AgentsEnvironment::AgentsEnvironment() {
    width = 0;
    height = 0;
}

AgentsEnvironment::AgentsEnvironment(int width, int height) {
    this->width = width;
    this->height = height;
}

void AgentsEnvironment::addListener(EnvironmentObserver *listener) {
    listeners.push_back(listener);
}

int AgentsEnvironment::getHeight() {
    return height;
}

int AgentsEnvironment::getWidth() {
    return width;
}

void AgentsEnvironment::timeStep() {    //synchronized
    for ( AbstractAgent* agent : this->getAgents()) {
        agent->interact(this);
        this->avoidMovingOutsideOfBounds(agent);
    }
    for(EnvironmentObserver *l : this->listeners) {
        l->notify(this);
    }
}

void AgentsEnvironment::avoidMovingOutsideOfBounds(AbstractAgent *agent) {

    double newX = agent->getX();
    double newY = agent->getY();
    if (newX < 0) {
        newX = width - 1;
    }
    if (newY < 0) {
        newY = height - 1;
    }
    if (newX > width) {
        newX = 1;
    }
    if (newY > height) {
        newY = 1;
    }
    agent->setX(newX);
    agent->setY(newY);
}

void AgentsEnvironment::addAgent(AbstractAgent *agent) {
    agents.push_back(agent);

}

void AgentsEnvironment::removeAgent(AbstractAgent *agent) {
    agents.erase(std::find(agents.begin(), agents.end(), agent));
}

const std::vector<AbstractAgent *> AgentsEnvironment::getAgents() {
    return agents;
}

