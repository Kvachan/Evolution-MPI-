#include "neuralnetworkdrivenagent.h"
#include <cmath>
#include "thresholdfunction.h"
#include "food.h"
#include "agentsenvironment.h"

double NeuralNetworkDrivenAgent::maxSpeed = 4;
double NeuralNetworkDrivenAgent::maxDeltaAngle = 1;
double NeuralNetworkDrivenAgent::AGENTS = -10;
double NeuralNetworkDrivenAgent::EMPTY = 0;
double NeuralNetworkDrivenAgent::FOODS = 10;
double NeuralNetworkDrivenAgent::maxAgentsDistance = 1;

#define SIGNUM(Value) ((Value) < 0 ? (-1) : !!(Value))

NeuralNetworkDrivenAgent::NeuralNetworkDrivenAgent(double x, double y, double angle)
    : Agent(x, y, angle) {

}

void NeuralNetworkDrivenAgent::setBrain(NeuralNetwork* brain) {
    this->brain = brain;
}

void NeuralNetworkDrivenAgent::interact(AgentsEnvironment *env) {
    std::vector<double>* nnInputs = this->createNnInputs(env);
    this->activateNeuralNetwork(nnInputs);


    int neuronsCount = this->brain.getNeuronsCount();
    double deltaAngle = this->brain.getAfterActivationSignal(neuronsCount - 2);
    double deltaSpeed = this->brain.getAfterActivationSignal(neuronsCount - 1);

    deltaSpeed = this->avoidNaNAndInfinity(deltaSpeed);
    deltaAngle = this->avoidNaNAndInfinity(deltaAngle);

    double newSpeed = this->normalizeSpeed(this->getSpeed() + deltaSpeed);
    double newAngle = this->getAngle() + this->normalizeDeltaAngle(deltaAngle);

    this->setAngle(newAngle);
    this->setSpeed(newSpeed);

    this->move();
}

double NeuralNetworkDrivenAgent::avoidNaNAndInfinity(double x) {
    if(std::isnan(x) || std::isinf(x)) {
        x = 0;
    }
    return x;
}

void NeuralNetworkDrivenAgent::activateNeuralNetwork(std::vector<double>* nnInputs) {
    for(int i = 0; i < nnInputs->size(); i++) {
        this->brain.putSignalToNeuron(i, (*nnInputs)[i]);
    }
    this->brain.activate();
}

std::vector<double>* NeuralNetworkDrivenAgent::createNnInputs(AgentsEnvironment *environment) {
    std::vector<double>* nn;
    Food *nearestFood = nullptr;
    double nearestFoodDist = std::numeric_limits<double>::max();

    auto agents = environment->agents;
    for (auto it = agents.begin(); it != agents.end(); ++it)
    {
        if ((*it)->getFood() != NULL && inSight(*it))
        {
            double currFoodDist = distanceTo(*it);
            if (currFoodDist <= nearestFoodDist)
            {
                nearestFood = (Food*)(*it);
                nearestFoodDist = currFoodDist;
            }
        }
    }

    Agent *nearestAgent = nullptr;
    double nearestAgentDist = maxAgentsDistance;
    for (auto it = agents.begin(); it != agents.end(); it++) {
        if ((*it)->getAgent() != NULL & inSight(*it)) {
            double currAgentDist = distanceTo(*it);
            if(currAgentDist <= nearestAgentDist) {
                nearestAgent = (Agent*)(*it);
                nearestAgentDist = currAgentDist;
            }
        }
    }

    std::vector<double> *nnInputs;
    double rx = this->getRx();
    double ry = this->getRy();
    double x = this->getX();
    double y = this->getY();


    if(nearestFood != nullptr) {
        double foodDirectionVectorX = nearestFood->getX() - x;
        double foodDirectionVectorY = nearestFood->getY() - y;

        double foodDirectionCosTeta = SIGNUM(this->pseudoScalarProduct(rx, ry, foodDirectionVectorX, foodDirectionVectorY)) *
            this->cosTeta(rx, ry, foodDirectionVectorX, foodDirectionVectorY);
        //            nnInputs.add(FOOD);
        nnInputs->push_back(FOODS);
        nnInputs->push_back(nearestFoodDist);
        nnInputs->push_back(foodDirectionCosTeta);
    } else {
        nnInputs->push_back(EMPTY);
        nnInputs->push_back(0.0);
        nnInputs->push_back(0.0);
    }
    if(nearestAgent != nullptr) {
        double agentDirectionVectorX = nearestAgent->getX() - x;
        double agentDirectionVectorY = nearestAgent->getY() - y;

        double agentDirectionCosTeta = SIGNUM(this->pseudoScalarProduct(rx, ry, agentDirectionVectorX, agentDirectionVectorY))
                * this->cosTeta(rx, ry, agentDirectionVectorX, agentDirectionVectorY);

        nnInputs->push_back(AGENTS);
        nnInputs->push_back(nearestAgentDist);
        nnInputs->push_back(agentDirectionCosTeta);
    } else {
        nnInputs->push_back(EMPTY);
        nnInputs->push_back(0.0);
        nnInputs->push_back(0.0);
    }
    return nnInputs;
}

bool NeuralNetworkDrivenAgent::inSight(AbstractAgent *agent) {
    double crossProduct = this->cosTeta(this->getRx(), this->getRy(), agent->getX() - this->getX(),
                                        agent->getY() - this->getY());
    return (crossProduct > 0);
}

double NeuralNetworkDrivenAgent::distanceTo(AbstractAgent *agent) {
    return this->module(agent->getX() - this->getX(), agent->getY() - this->getY());
}
double NeuralNetworkDrivenAgent::cosTeta(double vx1, double vy1, double vx2, double vy2) {
    double v1 = this->module(vx1, vy2);
    double v2 = this->module(vx2, vy2);
    double e = exp(1);
    if(v1 == 0) {
        v1 = e - 5;
    }
    if(v2 == 0) {
        v2 = e - 5; //this is exponenta
    }

    return ((vx1 * vx2) + (vy1 * vy2)) / (v1 * v2);
}

double NeuralNetworkDrivenAgent::module(double vx1, double vy1) {
    return sqrt((vx1 * vx1) + (vy1 * vy1));
}

double NeuralNetworkDrivenAgent::pseudoScalarProduct(double vx1, double vy1, double vx2, double vy2) {
    return (vx1 * vy2) - (vy1 * vx2);
}

double NeuralNetworkDrivenAgent::normalizeSpeed(double speed) {
    double absolut = std::abs(speed);
    if(absolut > maxSpeed) {
        double sign = SIGNUM(speed);
        speed = sign * (absolut - (floor(absolut / maxSpeed) * maxSpeed));
    }
    return speed;
}

double NeuralNetworkDrivenAgent::normalizeDeltaAngle(double angle) {
    double absolut = std::abs(angle);
    if(absolut > maxDeltaAngle) {
        double sign = SIGNUM(angle);
        angle = sign * (absolut - (floor(absolut / maxDeltaAngle) * maxDeltaAngle));
    }
    return angle;
}

OptimizableNeuralNetwork* NeuralNetworkDrivenAgent::randomNeuralNetworkBrain() {
    OptimizableNeuralNetwork* nn(15);
    for(int i = 0; i < 15; i++) {
        auto f = new ThresholdFunctionSigma;
        nn->setNeuronFunction(i, f, f->getDefaultParams());
    }
    for(int i = 0; i < 6; i++) {
        auto f = new ThresholdFunctionLinear;
        nn.setNeuronFunction(i,  f, f->getDefaultParams());
    }
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 15; j++) {
            nn.addLink(i, j, rand());
        }
    }
    for(int i = 6; i < 15; i++) {
        for(int j = 6; j < 15; j++) {
            if ( i < j) {
                nn.addLink(i, j, rand());
            }
        }
    }
    return nn;
}




