#ifndef EATENFOODOBSERVER
#define EATENFOODOBSERVER

#include "environmentobserver.h"
#include "vector"
#include "AgentsEnvironment.h"

class Agent;
class Food;
class AgentsEnvironment;

class EaternFoodObserver : public EnvironmentObserver {
    double score;
protected:
    static double minEatDistance;
    static double maxFishesDistance;
    void notify(AgentsEnvironment *env) override;
    void addRandomPieceOfFood(AgentsEnvironment* env);
    void removeEatenAndCreateNewFood(AgentsEnvironment* env, std::vector<Food*> eatenFood);
private:
    std::vector<Agent*> getCollidedFishes(AgentsEnvironment *env);
    std::vector<Food *> getEaternFood(AgentsEnvironment *env);
    std::vector<Agent *> getAgent(AgentsEnvironment *env);
    std::vector<Food *> getFood(AgentsEnvironment *env);
    std::vector<Agent*> getFishes(AgentsEnvironment *env);

public:
    EaternFoodObserver();
    double getScore();
};

#endif // EATENFOODOBSERVER
