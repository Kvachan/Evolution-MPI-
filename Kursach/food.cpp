//CHECK
#include "food.h"
#include "agentsenvironment.h"

Food::Food() {
    x = 0;
    y = 0;
}

Food::Food(double x, double y) {
    this->x = x;
    this->y = y;
}

double Food::getX() {
    return x;
}

double Food::getY() {
    return y;
}

void Food::setX(double x) {
    this->x = x;
}

void Food::setY(double y) {
    this->y = y;
}

void Food::interact(AgentsEnvironment *env) {

}

Food* Food::getFood() {
    return this;
}
