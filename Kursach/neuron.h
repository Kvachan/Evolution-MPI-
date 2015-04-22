#ifndef NEURON
#define NEURON

#include "thresholdfunction.h"
#include <string>
#include <vector>


class Neuron {

private:
    double inputSignal;
    double afterActivationSignal;
    std::vector<double> params;
    IThresholdFunction *thresholdFunction;
    void setThresholdFunction( IThresholdFunction *function );

public:
    Neuron();
    Neuron(IThresholdFunction *function, std::vector<double> params);
    virtual ~Neuron();

    void setFunctionAndParams(IThresholdFunction *function, std::vector<double> params);
    void addSignal(double value);
    void activate();
    double getAfterActivationSignal();
    IThresholdFunction *getFunction();
    std::vector<double> getParams();

    Neuron* clone();

    std::string toString();

};

#endif // NEURON
