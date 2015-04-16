#include "neuralnetworks.h"

NeuralNetwork::NeuralNetwork() {
    activationIterations = 1;
}

NeuralNetwork::NeuralNetwork(int numberOfNeurons) {
    for(int i = 0; i < numberOfNeurons; i++) {
        //this.neurons.add(new Neuron(ThresholdFunction.SIGN, ThresholdFunction.SIGN.getDefaultParams()));
    }
}

void NeuralNetwork::setNeuronFunction(int neuronNumber, ThresholdFunction function, std::vector<double> params) {
    if (neuronNumber >= neurons.size()) {
        return; //EXCEPTION
    }
    //this.neurons.get(neuronNumber).setFunctionAndParams(function, params);
    //neurons[neuronNumber]
}
void NeuralNetwork::addLink(int activatorNeuronNumber, int receiverNeuronNumber, double weight) {
    neuronsLinks->addWeight(activatorNeuronNumber, receiverNeuronNumber, weight);
}

void NeuralNetwork::putSignalToNeuron(int neuronIndex, double signalValue) {
//    if (neuronIndx < this.neurons.size()) {
//        this.neurons.get(neuronIndx).addSignal(signalValue);
//    } else {
//        throw new IllegalArgumentException();
//    }
}

double NeuralNetwork::getAfterActivationSignal(int neuronIndx) {
//    if (neuronIndx < this.neurons.size()) {
//        return this.neurons.get(neuronIndx).getAfterActivationSignal();
//    } else {
//        throw new IllegalArgumentException();
//    }
}

void NeuralNetwork::activate() {
    for (int iter = 0; iter < activationIterations; iter++) {
        for (int i = 0; i < neurons.size(); i++) {
            Neuron activator = neurons[i];//Neuron activator = this.neurons.get(i);
            activator.activate();
            double activatorSignal = activator.getAfterActivationSignal();
//            for (Integer receiverNum : this.neuronsLinks.getReceivers(i)) {
//                if (receiverNum >= this.neurons.size()) {
//                    throw new RuntimeException("Neural network has " + this.neurons.size()
//                            + " neurons. But there was trying to accsess neuron with index " + receiverNum);
//                }
//                Neuron receiver = this.neurons.get(receiverNum);
//                double weight = this.neuronsLinks.getWeight(i, receiverNum);
//                receiver.addSignal(activatorSignal * weight);
//            }

        }
    }
}

std::vector<double> NeuralNetwork::getWeightsOfLinks() {
    return neuronsLinks->getAllWeights();
}

void NeuralNetwork::setWeightsOfLinks(std::vector<double> weights) {
    neuronsLinks->setAllWeights(weights);
}

std::vector<Neuron> NeuralNetwork::getNeurons() {
    std::vector<Neuron> ret;
    for(Neuron n : neurons) {
        ret.push_back(*n.clone());
    }
    return ret;
}

int NeuralNetwork::getNeuronsCount() {
    return neurons.size();
}

void NeuralNetwork::setNeurons(std::vector<Neuron> newNeurons) {
    neurons = newNeurons;
}
int NeuralNetwork::getActivationsIterations() {
    return activationIterations;
}
void NeuralNetwork::setActivationIterations(int activationIterations) {
    this->activationIterations = activationIterations;
}

Links* NeuralNetwork::getNeuronsLinks() {
    return neuronsLinks;
}

NeuralNetwork* NeuralNetwork::clone() {
    NeuralNetwork *clone = new NeuralNetwork(neurons.size());
    clone->setNeuronalLinks(neuronsLinks->clone());
    clone->setActivationIterations(activationIterations);
    std::vector<Neuron> newNeurons;
    clone->setNeurons(newNeurons);
    for (Neuron neuron : neurons) {
        clone->neurons.push_back(*neuron.clone());
    }
    return clone;
}

std::string NeuralNetwork::toString() {
    std::string retString;
    //retString = "NeuralNetwork [neurons=" + neurons + ", links=" + neuronsLinks + ", activationIterations=" + activationIterations + "]";
    return retString;
}

