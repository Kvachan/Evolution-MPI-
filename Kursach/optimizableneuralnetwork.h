#ifndef OPTIMIZABLENEURALNETWORK
#define OPTIMIZABLENEURALNETWORK

#include "neuralnetworks.h"
#include "cloneable.h"
#include "random.h"

class OptimizableNeuralNetwork : public NeuralNetwork, public Cloneable {

    static double weightsMutationInterval; //1
    static double neuronParamsMutationInterval; //1

public:
    OptimizableNeuralNetwork();
    OptimizableNeuralNetwork(int numberOfNeurons);
    OptimizableNeuralNetwork(NeuralNetwork nn);
    OptimizableNeuralNetwork* mutate();
    OptimizableNeuralNetwork* clone();

private:
    void twoPointsWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights);
    void uniformelyDistributedWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights);
    void twoPointsNeuronsCrossover(std::vector<Neuron> thisNeurons, std::vector<Neuron> anotherNeurons);
    void uniformelyDistributedNeuronsCrossover(std::vector<Neuron> thisNeurons, std::vector<Neuron> anotherNeurons);
    void mutateWeights(std::vector<double> weights);
    void mutateNeuronsFunctionsParams(std::vector<Neuron> neurons);
    void mutateChangeNeuronsFunctions(std::vector<Neuron> neurons);
    void shuffleWeightsOnSubinterval(std::vector<double> weights);
};


#endif // OPTIMIZABLENEURALNETWORK
/*public List<OptimizableNeuralNetwork> crossover(OptimizableNeuralNetwork anotherChromosome) {
        OptimizableNeuralNetwork anotherClone = anotherChromosome.clone();
        OptimizableNeuralNetwork thisClone = this.clone();

        switch (this.random.nextInt(4)) {
            case 0: {
                List<Double> thisWeights = thisClone.neuronsLinks.getAllWeights();
                List<Double> anotherWeights = anotherClone.neuronsLinks.getAllWeights();
                this.twoPointsWeightsCrossover(thisWeights, anotherWeights);
                thisClone.neuronsLinks.setAllWeights(thisWeights);
                anotherClone.neuronsLinks.setAllWeights(anotherWeights);
            }
                break;
            case 1: {
                List<Double> thisWeights = thisClone.neuronsLinks.getAllWeights();
                List<Double> anotherWeights = anotherClone.neuronsLinks.getAllWeights();
                this.uniformelyDistributedWeightsCrossover(thisWeights, anotherWeights);
                thisClone.neuronsLinks.setAllWeights(thisWeights);
                anotherClone.neuronsLinks.setAllWeights(anotherWeights);
            }
                break;
            case 2: {
                this.twoPointsNeuronsCrossover(thisClone.neurons, anotherClone.neurons);
            }
                break;
            case 3: {
                this.uniformelyDistributedNeuronsCrossover(thisClone.neurons, anotherClone.neurons);
            }
                break;
        // TODO
        // case 4: {
        // this.activationIterations += this.random.nextInt(2) -
        // this.random.nextInt(2);
        // this.activationIterations = (this.activationIterations < 1) ? 1 :
        // this.activationIterations;
        // }
        // break;
        }
        List<OptimizableNeuralNetwork> ret = new ArrayList<OptimizableNeuralNetwork>();
        ret.add(anotherClone);
        ret.add(thisClone);
        ret.add(anotherClone.mutate());
        ret.add(thisClone.mutate());
        return ret;
    }
*/
