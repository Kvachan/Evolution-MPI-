#ifndef NEURALNETWORKDRIVENAGENT
#define NEURALNETWORKDRIVENAGENT

#include "agent.h"
#include "neuralnetworks.h"

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
    bool inSight(AbstractAgent agent);
    double distanceTo(AbstractAgent agent);
    double cosTeta(double vx1, double vy1, double vx2, double vy2);
    double module(double vx1, double vy1);
    double pseudoScalarProduct(double vx1, double vy1, double vx2, double vy2);

public:
    NeuralNetworkDrivenAgent(double x, double y, double angle);
    void setBrain(NeuralNetwork brain);
    void interact(AgentsEnvironment* env) override;
    double avoidNaNAndInfinity(double x);
    void activateNeuralNetwork(std::vector<double> nnInputs);
    //static Optimi

private:
    double normalizeSpeed(double speed);
    double normalizeDeltaAngle(double angle);


};


#endif // NEURALNETWORKDRIVENAGENT

//private double normalizeSpeed(double speed) {
//        double abs = Math.abs(speed);
//        if (abs > maxSpeed) {
//            double sign = Math.signum(speed);
//            speed = sign * (abs - (Math.floor(abs / maxSpeed) * maxSpeed));
//        }
//        return speed;
//    }

//    private double normalizeDeltaAngle(double angle) {
//        double abs = Math.abs(angle);
//        if (abs > maxDeltaAngle) {
//            double sign = Math.signum(angle);
//            angle = sign * (abs - (Math.floor(abs / maxDeltaAngle) * maxDeltaAngle));
//        }
//        return angle;
//    }

//    public static OptimizableNeuralNetwork randomNeuralNetworkBrain() {
//        OptimizableNeuralNetwork nn = new OptimizableNeuralNetwork(15);
//        for (int i = 0; i < 15; i++) {
//            ThresholdFunction f = ThresholdFunction.getRandomFunction();
//            nn.setNeuronFunction(i, f, f.getDefaultParams());
//        }
//        for (int i = 0; i < 6; i++) {
//            nn.setNeuronFunction(i, ThresholdFunction.LINEAR, ThresholdFunction.LINEAR.getDefaultParams());
//        }
//        for (int i = 0; i < 6; i++) {
//            for (int j = 6; j < 15; j++) {
//                nn.addLink(i, j, Math.random());
//            }
//        }
//        for (int i = 6; i < 15; i++) {
//            for (int j = 6; j < 15; j++) {
//                if (i < j) {
//                    nn.addLink(i, j, Math.random());
//                }
//            }
//        }
//        return nn;
//    }
//}

