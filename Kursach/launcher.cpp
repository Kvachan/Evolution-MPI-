#include "population.h"
#include "optimizableneuralnetwork.h"
#include "thresholdfunction.h"
#include <random>
#include "fitness.h"
#include "geneticalgorithm.h"
#include "iterationlistener.h"

static int maxWeightNum = 10;

int getRandomWeight() {
    return rand() % maxWeightNum - rand() % maxWeightNum;
}

OptimizableNeuralNetwork* initNeuralNetwork() {
    OptimizableNeuralNetwork* nn = new OptimizableNeuralNetwork(6);
    for(int i = 0; i < 6; i++) {
        ThresholdFunctionSigma *f = new ThresholdFunctionSigma();
        nn->setNeuronFunction(i, f, f->getDefaultParams());
    }
    ThresholdFunctionLinear *f = new ThresholdFunctionLinear();
    nn->setNeuronFunction(0, f, f->getDefaultParams());
    nn->setNeuronFunction(1, f, f->getDefaultParams());

    nn->addLink(0, 2, getRandomWeight());
    nn->addLink(0, 3, getRandomWeight());
    nn->addLink(0, 4, getRandomWeight());
    nn->addLink(1, 2, getRandomWeight());
    nn->addLink(1, 3, getRandomWeight());
    nn->addLink(1, 4, getRandomWeight());
    nn->addLink(2, 5, getRandomWeight());
    nn->addLink(3, 5, getRandomWeight());
    nn->addLink(4, 5, getRandomWeight());

    return nn;


}

double calculate(OptimizableNeuralNetwork* nn) {
    double delt = 0;
    for(int i = -5; i < 6; i++) {
        for(int j = -5; j < 6; j++) {
            double target;
            if(i == j) {
                target = 0;
            } else {
                target = 1;
            }

            nn->putSignalToNeuron(0, i);
            nn->putSignalToNeuron(1, j);

            nn->activate();

            double nnOutput = nn->getAfterActivationSignal(5);

            double d = nnOutput - target;
            delt += d * d;
        }
    }
    return delt;
}

void update(GeneticAlgorithm<OptimizableNeuralNetwork, double> *environment) {
    OptimizableNeuralNetwork *gene = environment->getBest();
    double *d = environment->fitness(gene);
    if (*(d) <= 0.1) {
        environment->terminate();
    }

    environment->setParentChromosomesSurviveCount(rand() % environment->getPopulation()->getSize());
}


int main()
{
    Population<OptimizableNeuralNetwork, double> *population = new Population<OptimizableNeuralNetwork, double>();
    OptimizableNeuralNetwork *nn = initNeuralNetwork();

    for(int i = 0; i < 20; i++) {
        population->addChromosome(nn->mutate());
    }

    Fitness<OptimizableNeuralNetwork, double> *fit = new Fitness<OptimizableNeuralNetwork, double>();
    GeneticAlgorithm<OptimizableNeuralNetwork, double> *env = new GeneticAlgorithm<OptimizableNeuralNetwork, double>(population, fit);

    update(env);
    IterartionListener<OptimizableNeuralNetwork, double> *buf;
    env->addIterationListener(buf);

    env->evolve(5500);

    OptimizableNeuralNetwork *evoNn = env->getBest();
    for(int i = -10; i < -6; i++) {
        for(int j = -10; j < -6; j++) {
            evoNn->putSignalToNeuron(0, i);
            evoNn->putSignalToNeuron(1, j);
            evoNn->activate();
        }
    }
}
