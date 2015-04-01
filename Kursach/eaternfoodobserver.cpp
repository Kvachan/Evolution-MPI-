#include "eatenfoodobserver.h"
#include "food.h"
#include "agent.h"
#include "agentsenvironment.h"
#include <math.h>

EaternFoodObserver::EaternFoodObserver() {
    this->maxFishesDistance = 5;
    this->minEatDistance = 5;
    this->score = 0;
}

void EaternFoodObserver::notify(AgentsEnvironment *env) {
    std::vector<Food*> eaternFood = this->getEaternFood(env);

}

std::vector<Food*> EaternFoodObserver::getEaternFood(AgentsEnvironment *env) {
    std::vector<Food*> eatenFood;
    F: for ( Food *food : getFood(env) ) {
        for ( Agent* fish : getAgent(env) ) {
            double distanceToFood = abs( food->getX() - fish->getX() - (food->getY() - fish->getY()) );
            if (distanceToFood < minEatDistance) {
                eatenFood.push_back(food);
                goto F;
            }
        }
    }
    return eatenFood;
}

std::vector<Agent*> EaternFoodObserver::getAgent(AgentsEnvironment *env) {
            std::vector<Agent*> fishes;
            auto abstractAgents = env->getAgents();
            for (auto abstractAgent : abstractAgents) {
                if (auto agent = dynamic_cast<Agent*>(abstractAgent)) {
                     fishes.push_back(agent);
                }
            }
            return fishes;
}

std::vector<Food*> EaternFoodObserver::getFood(AgentsEnvironment *env) {
    std::vector<Food*> temp;
    return temp;
}

double EaternFoodObserver::getScore() {
    if (score < 0) return 0;
    return score;
}

void EaternFoodObserver::addRandomPieceOfFood(AgentsEnvironment *env) {
//    int x =
//    int x = this->random.nextInt(env->getWidth());
//    int y = this->random.nextInt(env->getHeight());
//    Food newFood = new Food(x, y);
//    env->addAgent(newFood);
}

void EaternFoodObserver::removeEatenAndCreateNewFood(AgentsEnvironment *env, std::vector<Food*> eatenFood) {
    for (Food* food : eatenFood) {
        env->removeAgent(food);
        this->addRandomPieceOfFood(env);
    }
}

std::vector<Agent*> EaternFoodObserver::getCollidedFishes(AgentsEnvironment *env) {
    std::vector<Agent*> collidedFishes;
    std::vector<Agent*> allFishes = this->getFishes(env);

          int fishesCount = allFishes.size();

          for (int i = 0; i < (fishesCount - 1); i++) {
              auto firstFish = allFishes[i];
              for (int j = i + 1; j < fishesCount; j++) {
                  auto secondFish = allFishes[j];
                  double distanceToSecondFish = sqrt(
                              pow((firstFish->getX() - secondFish->getX()), 2)
                              +
                              pow((firstFish->getY() - secondFish->getY()), 2));
                  if (distanceToSecondFish < maxFishesDistance) {
                      collidedFishes.push_back(secondFish);
                  }
              }
          }
          return collidedFishes;
}

std::vector<Agent*> EaternFoodObserver::getFishes(AgentsEnvironment *env) {
}
