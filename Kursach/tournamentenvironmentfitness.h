#ifndef TOURNAMENTENVIRONMENTFITNESS
#define TOURNAMENTENVIRONMENTFITNESS

#include "agentsenvironment.h"
#include "food.h"
#include "fitness.h"
#include "optimizableneuralnetwork.h"
#include <random>
#include <cmath>
#include "kvRandom.h"
#include "neuralnetworkdrivenagent.h"
#include "eatenfoodobserver.h"

class TournamentEnvironmentFitness {
    void addRandomPieceOfFood(AgentsEnvironment *env, int width, int height);
public:
    double calculate(OptimizableNeuralNetwork *chromosome);
protected:
    Food* newPieceOfFood(int width, int height);
};


#endif // TOURNAMENTENVIRONMENTFITNESS

