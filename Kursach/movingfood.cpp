#include "movingfood.h"
#include "agentsenvironment.h"

MovingFood::MovingFood() {
    angle = 0;
    speed = 0;
}

MovingFood::MovingFood(double x, double y, double angle, double spped) : Food(x, y) {
    this->angle = angle;
    this->speed = speed;
}

void MovingFood::interact(AgentsEnvironment *env) {
        double rx = -sin(angle);
        double ry = cos(angle);
        this->setX(this->getX() + (rx * speed));
        this->setY(this->getY() + (ry * speed));
}

