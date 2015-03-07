#ifndef BASICAGENT
#define BASICAGENT

#include <math.h>
#include <algorithm>
#include <vector>

class basicAgent
{
protected:
    double x, y;
    bool visibility;
public:
    virtual ~basicAgent();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    void setVisibility(bool answer);
    virtual void interact();
//    friend bool operator==(const basicAgent &A, const basicAgent &B);
};


#endif // BASICAGENT

