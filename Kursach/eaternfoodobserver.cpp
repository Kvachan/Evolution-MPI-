//CHECK
#include "eatenfoodobserver.h"
#include "food.h"
#include "agent.h"
#include "agentsenvironment.h"
#include <math.h>

double EaternFoodObserver::minEatDistance = 5;
double EaternFoodObserver::maxFishesDistance = 5;

EaternFoodObserver::EaternFoodObserver() {
    this->score = 0;
}

void EaternFoodObserver::notify(AgentsEnvironment *env) {
    std::vector<Food*> eaternFood = this->getEaternFood(env);
    score += eaternFood.size();
    std::vector<Agent*> collidedFishes = this->getCollidedFishes(env);
    score -= collidedFishes.size() * 0.5;
    this->removeEatenAndCreateNewFood(env, eaternFood);
}

std::vector<Food*> EaternFoodObserver::getEaternFood(AgentsEnvironment *env) {
    std::vector<Food*> eatenFood;
    F: for ( Food *food : getFood(env) ) {
        for ( Agent* fish : getAgent(env) ) {
            double distanceToFood = module(food->getX() - fish->getX(), food->getY() - fish->getY());
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

double EaternFoodObserver::getScore() {
    if (score < 0) return 0;
    return score;
}

void EaternFoodObserver::addRandomPieceOfFood(AgentsEnvironment *env) {
    int x = std::rand() % env->getWidth();
    int y = std::rand() % env->getHeight();
    Food* newFood = new Food(x, y);
    env->addAgent(newFood);
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
                  double distanceToSecondFish = module(firstFish->getX() - secondFish->getX(), firstFish->getY() - secondFish->getY());
                  if (distanceToSecondFish < maxFishesDistance) {
                      collidedFishes.push_back(secondFish);
                  }
              }
          }
          return collidedFishes;
}

std::vector<Agent*> EaternFoodObserver::getFishes(AgentsEnvironment *env) {     //FILTER
    std::vector<Agent*> fishes;
    auto abstractAgents = env->getAgents();
    for (auto abstactAgent : abstractAgents) {
        if (auto agent = dynamic_cast<Agent*>(abstactAgent)) {
            fishes.push_back(agent);
        }
    }
    return fishes;
}

std::vector<Food*> EaternFoodObserver::getFood(AgentsEnvironment *env) {        //FILTER
    std::vector<Food*> foods;
    auto abstractAgents = env->getAgents();
    for (auto abstractAgent : abstractAgents) {
        if (auto agent = dynamic_cast<Food*>(abstractAgent)) {
            foods.push_back(agent);
        }
    }
    return foods;
}

double EaternFoodObserver::module(double vx1, double vy1) {
    return sqrt(pow(vx1, 2) + pow(vy1, 2));
}
