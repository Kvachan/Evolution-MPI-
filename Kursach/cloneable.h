#ifndef CLONEABLE
#define CLONEABLE

#include <string>

class Neuron;

class Cloneable {
public:
    Cloneable() {};

    //virtual Neuron* clone();

    virtual std::string toString();
};

#endif // CLONEABLE

