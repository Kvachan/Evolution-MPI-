#ifndef BASIC
#define BASIC

#include <math.h>
#include <algorithm>
#include <vector>

class Basic
{
protected:
    double x, y;
    bool visibility;

    virtual double getX() = 0;
    virtual double getY() = 0;

    virtual void setX() = 0;
    virtual void setY() = 0;

    virtual void setVisibility() = 0;

    virtual void interact() = 0;

public:

    virtual ~Basic();

    //    friend bool operator==(const Basic &A, const Basic &B);
};

#endif // BASIC

