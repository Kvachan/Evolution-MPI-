//don't have implementation, because it's abstract class (implements in EaternFoodObserver)
#ifndef ENVIRONMENTOBSERVER
#define ENVIRONMENTOBSERVER

class AgentsEnvironment;

class EnvironmentObserver {
public:
    virtual ~EnvironmentObserver() { };
    virtual void notify(AgentsEnvironment *env) = 0;

};

#endif // ENVIRONMENTOBSERVER

