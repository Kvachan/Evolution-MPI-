#ifndef ENVIRONMENTOBSERVER
#define ENVIRONMENTOBSERVER

class AgentsEnvironment;

class EnvironmentObserver {
public:
    virtual ~EnvironmentObserver() { };
    virtual void notify(AgentsEnvironment *env) = 0;

};

#endif // ENVIRONMENTOBSERVER

