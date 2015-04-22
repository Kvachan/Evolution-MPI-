#ifndef NEURALNETWORKDRIVENAGENT
#define NEURALNETWORKDRIVENAGENT

#include "agent.h"
#include "neuralnetworks.h"
#include "optimizableneuralnetwork.h"

//init static members!!!
class NeuralNetworkDrivenAgent : public Agent {

private:
    static double maxSpeed; //4
    static double maxDeltaAngle; //1
    static double AGENTS; // -10?
    static double EMPTY; //0
    static double FOOD; //10
    NeuralNetwork brain; //NeuralNetwork brain;

protected:
    static double maxAgentsDistance; //5
    std::vector<double> createNnInputs(AgentsEnvironment* environment);
    bool inSight(AbstractAgent *agent);
    double distanceTo(AbstractAgent *agent);
    double cosTeta(double vx1, double vy1, double vx2, double vy2);
    double module(double vx1, double vy1);
    double pseudoScalarProduct(double vx1, double vy1, double vx2, double vy2);

public:
    NeuralNetworkDrivenAgent(double x, double y, double angle);
    void setBrain(NeuralNetwork brain);
    void interact(AgentsEnvironment* env) override;
    double avoidNaNAndInfinity(double x);
    void activateNeuralNetwork(std::vector<double> nnInputs);
    static OptimizableNeuralNetwork randomNeuralNetworkBrain();

private:
    double normalizeSpeed(double speed);
    double normalizeDeltaAngle(double angle);


};


#endif // NEURALNETWORKDRIVENAGENT

