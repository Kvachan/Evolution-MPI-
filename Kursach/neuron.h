#ifndef NEURON
#define NEURON

#include "thresholdfunction.h"
#include "cloneable.h"
#include <string>
#include <vector>


class Neuron : public Cloneable {

private:
    double inputSignal;
    double afterActivationSignal;
    ThresholdFunction thresholdFunction;
    std::vector<double> params;

public:
    Neuron();
    Neuron(ThresholdFunction function, std::vector<double> params);

    void setFunctionAndParams(ThresholdFunction function, std::vector<double> params);
    void addSignal(double value);
    void activate();
    double getAfterActivationSignal();
    ThresholdFunction getFunction();
    std::vector<double> getParams();

    Neuron* clone();

    std::string toString() override;

};

#endif // NEURON
