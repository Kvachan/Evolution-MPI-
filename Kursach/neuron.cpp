#include "neuron.h"


Neuron::Neuron() {
    inputSignal = 0;
    afterActivationSignal = 0;
};

Neuron::Neuron(ThresholdFunction function, std::vector<double> params) {
    this->setFunctionAndParams(function, params);
}

void Neuron::setFunctionAndParams(ThresholdFunction function, std::vector<double> params) {
    if(params.size() != function.getDefaultParams().size()) {
        return; //EXCEPTION
        /*throw new IllegalArgumentException("Function needs " + function.getDefaultParams().size()
                + " parameters. But params count is " + params.size());*/
    }
    thresholdFunction = function;
    this->params = params;
};

void Neuron::addSignal(double value) {
    inputSignal += value;
}

void Neuron::activate() {
    afterActivationSignal = thresholdFunction.calculate(inputSignal, params);
    inputSignal = 0;
}

double Neuron::getAfterActivationSignal() {
    return afterActivationSignal;
}

ThresholdFunction Neuron::getFunction() {
    return thresholdFunction;
}

std::vector<double> Neuron::getParams() {
    std::vector<double> ret;
    for (double d : params) {
        ret.push_back(d);
    }
    return ret;
}

//Override function
Neuron* Neuron::clone() {
    std::vector<double> cloneParams;

    for (double d : params) {
        cloneParams.push_back(d);
    }

    Neuron* clone = new Neuron(thresholdFunction, cloneParams);
//    clone->inputSignal = 0;
//    clone->afterActivationSignal = 0;
    return clone;

}

std::string Neuron::toString() {
    std::string retString;
    //retString = "Neuron [thresholdFunction=" + thresholdFunction + ", params=" + params + "]";
    return retString;
}

