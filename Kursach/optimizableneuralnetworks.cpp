#include "optimizableneuralnetwork.h"
#include <set>
#include <tr1/functional>
using std::tr1::hash;

double OptimizableNeuralNetwork::weightsMutationInterval = 1;
double OptimizableNeuralNetwork::neuronParamsMutationInterval = 1;

OptimizableNeuralNetwork::OptimizableNeuralNetwork() {};

OptimizableNeuralNetwork::OptimizableNeuralNetwork(int numberOfNeurons)
    : NeuralNetwork(numberOfNeurons)
{

}

OptimizableNeuralNetwork::OptimizableNeuralNetwork(NeuralNetwork nn) {
    activationIterations == nn.getActivationsIterations();
    neurons = nn.getNeurons();
    neuronsLinks = nn.getNeuronsLinks();
}

void OptimizableNeuralNetwork::twoPointsWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights) {
    int left = rand() % thisWeights.size();
    int right = rand() % thisWeights.size();
    if (left > right) {
        int tmp = right;
        right = left;
        left = tmp;
    }
    for(int i = left; i < right; i++) {
        double thisWeight = anotherWeights[i];
        thisWeights[i] = anotherWeights[i];
        anotherWeights[i] = thisWeight;
    }
}

void OptimizableNeuralNetwork::uniformelyDistributedWeightsCrossover(std::vector<double> thisWeights, std::vector<double> anotherWeights) {

    int weightSize = thisWeights.size();
    int itersCount = rand() % weightSize;
    if(itersCount == 0) {
        itersCount = 1;
    }

    std::set<int> used;
    for(int iter = 0; iter < itersCount; iter++) {
        int i = rand() % weightSize;
        if(weightSize > 1) {
            while(!used.empty()) { //while (used.contains(i)) {
                i = rand() % weightSize;
            }
        }

        double thisWeight = thisWeights[i];
        double anotherWeight = anotherWeights[i];

        anotherWeights[i] = thisWeight;
        thisWeights[i] = anotherWeight;
        used.insert(i);
    }
}

void OptimizableNeuralNetwork::twoPointsNeuronsCrossover(std::vector<Neuron> thisNeurons, std::vector<Neuron> anotherNeurons) {
    int left = rand() % thisNeurons.size();
    int right = rand() % thisNeurons.size();
    if(left > right) {
        int tmp = right;
        right = left;
        left = tmp;
    }
    for(int i = left; i < right; i++) {
        Neuron thisNeuron = thisNeurons[i];
        thisNeurons[i] = anotherNeurons[i];
        anotherNeurons[i] = thisNeuron;
    }
}

void OptimizableNeuralNetwork::uniformelyDistributedNeuronsCrossover(std::vector<Neuron> thisNeurons, std::vector<Neuron> anotherNeurons) {
    int neuronSize = thisNeurons.size();
    int itersCount = rand() % neuronSize;
    if(itersCount == 0) {
        itersCount = 1;
    }
    std::set<int> used;
    for(int iter = 0; iter < itersCount; iter++) {
        int i = rand() % neuronSize;
        if(neuronSize > 1) {
            while(!used.empty()) {
                i = rand() % neuronSize;
            }
        }
        Neuron thisNeuron = thisNeurons[i];
        Neuron anotherNeuron = anotherNeurons[i];

        anotherNeurons[i] = thisNeuron;
        thisNeurons[i] = anotherNeuron;
        used.insert(i);
    }
}



OptimizableNeuralNetwork* OptimizableNeuralNetwork::mutate() {
    OptimizableNeuralNetwork *mutated = this->clone();
    switch (rand() % 4) {
            case 0: {
                std::vector<double> weights = mutated->neuronsLinks->getAllWeights();
                this->mutateWeights(weights);
                mutated->neuronsLinks->setAllWeights(weights);
            } break;
            case 1: {
                this->mutateNeuronsFunctionsParams(mutated->neurons);
            } break;
            case 2: {
                this->mutateChangeNeuronsFunctions(mutated->neurons);
            } break;
            case 3: {
                std::vector<double> weights = mutated->neuronsLinks->getAllWeights();
                this->shuffleWeightsOnSubinterval(weights);
                mutated->neuronsLinks->setAllWeights(weights);
            } break;
    }
    return mutated;
}

void OptimizableNeuralNetwork::mutateWeights(std::vector<double> weights) {
    int weightSize = weights.size();
    int itersCount = rand() % weightSize;
    if(itersCount == 0) {
        itersCount = 1;
    }
    std::set<int> used;
    for (int iter = 0; iter < itersCount; iter++) {
        int i = rand() % weightSize;
        if (weightSize > 1) {
            while (!used.empty())
            {
                i = rand() % weightSize;
            }
        }
        double w = weights[i];
        w += (nextGaussian() - nextGaussian()) * weightsMutationInterval;
        weights[i] = w;
        used.insert(i);
    }
}

void OptimizableNeuralNetwork::mutateNeuronsFunctionsParams(std::vector<Neuron> neurons) {
    int neuronSize = neurons.size();
    int itersCount = rand() % neuronSize;
    if (itersCount == 0) {
        itersCount = 1;
    }
    std::set<int> used;
    for(int iter = 0; iter < itersCount; iter++) {
        int i = rand() % neuronSize;
        if(neuronSize > 1) {
            while (!used.empty()) {
                i = rand() % neuronSize;
            }
        }
        Neuron n = neurons[i];

        std::vector<double> params = n.getParams();
        for(int j = 0; j < params.size(); j++) {
            double param = params[j];
            param += (nextGaussian() - nextGaussian()) * neuronParamsMutationInterval;
            params[j] = param;
        }
        n.setFunctionAndParams(n.getFunction(), params);
        used.insert(i);
    }
}

void OptimizableNeuralNetwork::mutateChangeNeuronsFunctions(std::vector<Neuron> neurons) {
    int neuronSize = neurons.size();
    int itersCount = rand() % neuronSize;
    if(itersCount == 0) {
        itersCount = 1;
    }
    std::set<int> used;
    for(int iter = 0; iter < itersCount; iter++) {
        int i = rand() % neuronSize;
        if (neuronSize > 1) {
            while(!used.empty()) {
                i = rand() % neuronSize;
            }
        }
        Neuron n = neurons[i];
        ThresholdFunctionSigma f; //like need random function
        n.setFunctionAndParams(f, f.getDefaultParams());
        used.insert(i);
    }
}

void OptimizableNeuralNetwork::shuffleWeightsOnSubinterval(std::vector<double> weights) {
    int left = rand() % weights.size();
    int right = rand() % weights.size();
    if(left > right) {
        int tmp = right;
        right = left;
        left = tmp;
    }
    std::vector<double> subListOfWeights;
    for(int i = 0; i < ((right - left) + 1); i++) {
        subListOfWeights.push_back(weights[left + i]);
    }
    std::random_shuffle(subListOfWeights.begin(), subListOfWeights.end());
    for(int i = 0; i < ((right - left) + 1); i++) {
        weights[left + i] = subListOfWeights[i];
    }

}

OptimizableNeuralNetwork* OptimizableNeuralNetwork::clone() {
    OptimizableNeuralNetwork *clone = new OptimizableNeuralNetwork(this->neurons.size());
    clone->neuronsLinks = this->neuronsLinks->clone();
    clone->activationIterations = this->activationIterations;
    for(Neuron neuron : this->neurons) {
        clone->neurons.push_back(*neuron.clone());
    }
    return clone;
}

std::vector<OptimizableNeuralNetwork> OptimizableNeuralNetwork::crossover(OptimizableNeuralNetwork anotherChromosome) {

    OptimizableNeuralNetwork *anotherClone = anotherChromosome.clone();
    OptimizableNeuralNetwork *thisClone = this->clone();

    switch (rand() % 4) { //like 5
    case 0: {
        std::vector<double> thisWeights = thisClone->neuronsLinks->getAllWeights();
        std::vector<double> anotherWeights = anotherClone->neuronsLinks->getAllWeights();
        this->twoPointsWeightsCrossover(thisWeights, anotherWeights);
        thisClone->neuronsLinks->setAllWeights(thisWeights);
        anotherClone->neuronsLinks->setAllWeights(anotherWeights);
    } break;
    case 1: {
        std::vector<double> thisWeights = thisClone->neuronsLinks->getAllWeights();
        std::vector<double> anotherWeights = anotherClone->neuronsLinks->getAllWeights();
        this->uniformelyDistributedWeightsCrossover(thisWeights, anotherWeights);
        thisClone->neuronsLinks->setAllWeights(thisWeights);
        anotherClone->neuronsLinks->setAllWeights(anotherWeights);
    } break;

    case 2: {
        this->twoPointsNeuronsCrossover(thisClone->neurons, anotherClone->neurons);
    } break;

    case 3: {
        this->uniformelyDistributedNeuronsCrossover(thisClone->neurons, anotherClone->neurons);
    } break;

    case 4: {
        this->activationIterations += rand() % 2 - rand() % 2;
        this->activationIterations = (this->activationIterations < 1) ? 1 : this->activationIterations;
    } break;
    default:
        break;
    }
    std::vector<OptimizableNeuralNetwork> ret;
    ret.push_back(*anotherClone);
    ret.push_back(*thisClone);
    ret.push_back(*anotherClone->mutate());
    ret.push_back(*thisClone->mutate());
    return ret;
}
