#include "tournamentenvironmentfitness.h"

void TournamentEnvironmentFitness::addRandomPieceOfFood(AgentsEnvironment *env, int width, int height) {
    Food *newFood = this->newPieceOfFood(width, height);
    env->addAgent(newFood);
}

double TournamentEnvironmentFitness::calculate(OptimizableNeuralNetwork *chromosome) {

    int width = 200;
    int height = 200;
    int agentsCount = 10;
    int foodCount = 5;
    int environmentIterations = 50;

    AgentsEnvironment *env = new AgentsEnvironment(width, height);

    for (int i = 0; i < agentsCount; i++) {
        int x = rand() % width;
        int y = rand() % height;
        double direction = 2 * M_PI * ffRand(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
        NeuralNetworkDrivenAgent* agent = new NeuralNetworkDrivenAgent(x, y, direction);
        agent->setBrain(chromosome->clone());

        env->addAgent(agent);
    }

    for (int i = 0; i < foodCount; i++) {
        Food *food = this->newPieceOfFood(width, height);
        env->addAgent(food);
    }

    EaternFoodObserver *tournamentListener = new EatenFoodObserver();
    this->addRandomPieceOfFood(env, width, height);
    env->addListener(tournamentListener);

    for (int i = 0; i < environmentIterations; i++) {
        env->timeStep();
    }

    double score = tournamentListener->getScore();
    return 1.0 / score;
}

Food* TournamentEnvironmentFitness::newPieceOfFood(int width, int height) {
    Food food = new Food(random.nextInt(width), random.nextInt(height));
    return food;
}
