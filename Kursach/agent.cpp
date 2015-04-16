#include "agent.h"
#include "agentsenvironment.h"

Agent::Agent() {
    x = 0;
    y = 0;
    speed = 0;
    angle = 0;
}

Agent::Agent(double x, double y, double angle) {
    this->x = x;
    this->y = y;
    this->speed = 0;
    this->angle = angle;
}

void Agent::move() {
        double rx = -sin(angle);
        double ry = cos(angle);
        x += rx * speed;
        y += ry * speed;
}

double Agent::getX() {
    return x;
}

double Agent::getY() {
    return y;
}

void Agent::setX(double x) {
    this->x = x;
}

void Agent::setY(double y) {
    this->y = y;
}

double Agent::getAngle() {
    return angle;
}

double Agent::getSpeed() {
    return speed;
}

void Agent::setAngle(double angle)
{
    this->angle = angle;
}

void Agent::setSpeed(double v)
{
    this->speed = v;
}

double Agent::getRx() {
    return -sin(angle);
}

double Agent::getRy() {
    return cos(angle);
}

void Agent::interact(AgentsEnvironment *env) {

}
