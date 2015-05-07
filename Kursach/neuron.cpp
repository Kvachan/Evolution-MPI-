//CHECK neuron::clone()?
#include "neuron.h"


void Neuron::setThresholdFunction(IThresholdFunction *function)
{
    if ( function == nullptr || function == thresholdFunction )
        return;

    if ( thresholdFunction != nullptr )
        delete thresholdFunction;

    thresholdFunction = function;
}

Neuron::Neuron() {
    inputSignal = 0;
    afterActivationSignal = 0;
    thresholdFunction = nullptr;
}

Neuron::Neuron(IThresholdFunction *function, std::vector<double> params) {
    this->setFunctionAndParams(function, params);
}

Neuron::~Neuron()
{
    if ( thresholdFunction != nullptr )
        delete thresholdFunction;
}

void Neuron::setFunctionAndParams(IThresholdFunction *function, std::vector<double> params) {
    if(params.size() != function->getDefaultParams().size()) {
        return; //EXCEPTION
        /*throw new IllegalArgumentException("Function needs " + function.getDefaultParams().size()
                + " parameters. But params count is " + params.size());*/
    }
    setThresholdFunction( function );
    this->params = params;
}

void Neuron::addSignal(double value) {
    inputSignal += value;
}

void Neuron::activate() {
    afterActivationSignal = thresholdFunction->calculate(inputSignal, params);
    inputSignal = 0;
}

double Neuron::getAfterActivationSignal() {
    return afterActivationSignal;
}

IThresholdFunction *Neuron::getFunction() {
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

///    right way
//    return new Neuron(thresholdFunction->clone(), cloneParams);

    Neuron* clone = new Neuron(thresholdFunction, cloneParams);
    return clone;

}

std::string Neuron::toString() {
    std::string retString;
    //retString = "Neuron [thresholdFunction=" + thresholdFunction + ", params=" + params + "]";
    return retString;
}

