#include "neuralnetworks.h"
#include "neuron.h"
#include <iostream>


NeuralNetwork::NeuralNetwork() {
    activationIterations = 1;
}

NeuralNetwork::NeuralNetwork(int numberOfNeurons) {
    for(int i = 0; i < numberOfNeurons; i++) {
        IThresholdFunction *f = new ThresholdFunctionSign;
        Neuron *nNeuron = new Neuron(f, f->getDefaultParams());
        neurons.push_back(nNeuron);
    }
}

void NeuralNetwork::setNeuronFunction(int neuronNumber, IThresholdFunction *function, std::vector<double> params) {
    Q_ASSERT( neuronNumber >= neurons.size() || neuronNumber < 0 );
    neurons[ neuronNumber ]->setFunctionAndParams(function, params);
}

void NeuralNetwork::addLink(int activatorNeuronNumber, int receiverNeuronNumber, double weight) {
    neuronsLinks->addWeight(activatorNeuronNumber, receiverNeuronNumber, weight);
}

void NeuralNetwork::putSignalToNeuron(int neuronIndex, double signalValue) {
    if (neuronIndex < neurons.size()) {
        Neuron *n = neurons[neuronIndex];
        n->addSignal(signalValue);
    } else {
        std::cout << "EXCEPTION" << std::endl;
        return;
    }
}

double NeuralNetwork::getAfterActivationSignal(int neuronIndx) {
    if(neuronIndx < neurons.size()) {
        Neuron *n = neurons[neuronIndx];
        return n->getAfterActivationSignal();
    } else {
        std::cout << "EXCEPTION" << std::endl;
        return 0;
    }
}

void NeuralNetwork::activate() {
    for (int iter = 0; iter < activationIterations; iter++) {
        for (int i = 0; i < neurons.size(); i++) {
            auto activator = neurons[i];//Neuron activator = this.neurons.get(i);
            activator->activate();
            double activatorSignal = activator->getAfterActivationSignal();
            for(int receiverNum : neuronsLinks->getReceivers(i)) {
                if (receiverNum >= neurons.size()) {
                    std::cout << "EXCEPTION" << std::endl;
                }
                Neuron *receiver = neurons[receiverNum];
                double weight = neuronsLinks->getWeight(i, receiverNum);
                receiver->addSignal(activatorSignal * weight);
            }
        }
    }
}

std::vector<double> NeuralNetwork::getWeightsOfLinks() {
    return neuronsLinks->getAllWeights();
}

void NeuralNetwork::setWeightsOfLinks(std::vector<double> weights) {
    neuronsLinks->setAllWeights(weights);
}

std::vector<Neuron *> NeuralNetwork::getNeurons() {
    std::vector<Neuron *> ret;
    ret.reserve( neurons.size() );

    for(auto n : neurons) {
        ret.push_back( n->clone() );
    }

    return ret;
}

int NeuralNetwork::getNeuronsCount() {
    return neurons.size();
}

void NeuralNetwork::setNeuronalLinks(Links *newNeuronLinks) {
    this->neuronsLinks = newNeuronLinks;
}

void NeuralNetwork::setNeurons(std::vector<Neuron *> newNeurons) {
    neurons = newNeurons;
}

int NeuralNetwork::getActivationsIterations() {
    return activationIterations;
}
void NeuralNetwork::setActivationIterations(int activationIterations) {
    this->activationIterations = activationIterations;
}

Links* NeuralNetwork::getNeuronsLinks() {
    return neuronsLinks->clone();
}

NeuralNetwork* NeuralNetwork::clone() {
    NeuralNetwork *clone = new NeuralNetwork(neurons.size());
    clone->setNeuronalLinks(neuronsLinks->clone());
    clone->setActivationIterations(activationIterations);
    std::vector<Neuron *> newNeurons;
    clone->setNeurons( newNeurons );

    for (auto neuron : neurons) {
        clone->neurons.push_back( neuron->clone() );
    }

    return clone;
}

std::string NeuralNetwork::toString() {
    std::string retString;
    //retString = "NeuralNetwork [neurons=" + neurons + ", links=" + neuronsLinks + ", activationIterations=" + activationIterations + "]";
    return retString;
}

