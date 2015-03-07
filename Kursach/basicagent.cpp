#include "basicagent.h"

basicAgent::~basicAgent()
{
    this->x = 0;
    this->y = 0;
    this->visibility = false;
}

double basicAgent::getX()
{
    return this->x;
}

double basicAgent::getY()
{
    return this->y;
}

void basicAgent::setX(double x)
{
    this->x = x;
}

void basicAgent::setY(double y)
{
    this->y = y;
}

void basicAgent::setVisibility(bool answer)
{
    this->visibility = answer;
}

void basicAgent::interact()
{
};

//bool operator==(basicAgent const& A, basicAgent const& B)
//{
//    if(A.getX() == B.getX() && A.getY() == B.getY())
//    {
//        return true;
//    }
//    return false;
//}

