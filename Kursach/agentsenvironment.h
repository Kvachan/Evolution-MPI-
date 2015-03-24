#ifndef AGENTSENVIRONMENT
#define AGENTSENVIRONMENT

#include "vector"

class AbstractAgent;
class EnvironmentObserver;

class AgentsEnvironment {
    int width;
    int height;
    std::vector<AbstractAgent*> agents;
    std::vector<EnvironmentObserver*> listeners;
    void avoidMovingOutsideOfBounds(AbstractAgent *agent);
public:
    AgentsEnvironment();
    AgentsEnvironment(int width, int height);

    void addListener(EnvironmentObserver *listener);
    int getWidth();
    int getHeight();

    void timeStep();
    const std::vector<AbstractAgent *> &getAgents();
    void addAgent(AbstractAgent *agent);
    void removeAgent(AbstractAgent *agent);
};

//    public synchronized void removeAgent(AbstractAgent agent) {
//        this.agents.remove(agent);
//    }

#endif // AGENTSENVIRONMENT

