#ifndef OPTIMIZABLENEURALNETWORK
#define OPTIMIZABLENEURALNETWORK

#include "neuralnetworks.h"
#include "kvRandom.h"

class OptimizableNeuralNetwork : public NeuralNetwork {

    static double weightsMutationInterval; //1
    static double neuronParamsMutationInterval; //1

public:
    OptimizableNeuralNetwork();
    OptimizableNeuralNetwork(int numberOfNeurons);
    OptimizableNeuralNetwork(NeuralNetwork nn);
    OptimizableNeuralNetwork* mutate();
    OptimizableNeuralNetwork* clone();
    std::vector<OptimizableNeuralNetwork> crossover(OptimizableNeuralNetwork anotherChromosome);
    std::string toString();

private:
    void twoPointsWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights);
    void uniformelyDistributedWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights);
    void twoPointsNeuronsCrossover(std::vector<Neuron*> thisNeurons, std::vector<Neuron*> anotherNeurons);
    void uniformelyDistributedNeuronsCrossover(std::vector<Neuron*> thisNeurons, std::vector<Neuron*> anotherNeurons);
    void mutateWeights(std::vector<double> weights);
    void mutateNeuronsFunctionsParams(std::vector<Neuron*> neurons);
    void mutateChangeNeuronsFunctions(std::vector<Neuron*> neurons);
    void shuffleWeightsOnSubinterval(std::vector<double> weights);
};


#endif // OPTIMIZABLENEURALNETWORK


