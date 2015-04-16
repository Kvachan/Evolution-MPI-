#ifndef THRESHOLDFUNCTION
#define THRESHOLDFUNCTION

#include <vector>
#include <QSharedPointer>
#include <math.h>

class ThresholdFunction;

typedef QSharedPointer<ThresholdFunction> ThresholdFunctionPtr;

class ThresholdFunction {
public:
    virtual double calculate(double value, const std::vector<double> &params);
    virtual std::vector<double> getDefaultParams();
    virtual ~ThresholdFunction(){}
};

class ThresholdFunctionLinear : public ThresholdFunction
{
public:
    double calculate(double value, const std::vector<double> &params) override {
        double a = ( params.size() > 0 )? params[0] : 0;
        double b = ( params.size() > 1 )? params[1] : 0;
        return (a * value) + b;
    }

    std::vector<double> getDefaultParams() override {
        std::vector<double> ret;
        ret.push_back( 1.0 );
        ret.push_back( 0.0 );
        return ret;
    }
};

class ThresholdFunctionSign : public ThresholdFunction
{
public:
    double calculate(double value, const std::vector<double> &params) override {
        double threshold = ( params.size() > 0 ) ? params[0] : 0;
        if ( value > threshold ) {
            return 1;
        } else {
            return 0;
        }
    }

    std::vector<double> getDefaultParams() override {
        std::vector<double> ret;
        ret.push_back( 0.0 );
        return ret;
    }
};

class ThresholdFunctionSigma : public ThresholdFunction
{
public:
    double calculate(double value, const std::vector<double> &params) override {
    double a = params[0];
    double b = params[1];
    double c = params[2];

    return a / (b + exp(-value * c));
    }

    std::vector<double> getDefaultParams() override {
    double a = 1;
    double b = 1;
    double c = 1;
    std::vector<double> ret;
    ret.push_back(a);
    ret.push_back(b);
    ret.push_back(c);
    return ret;
    }
};

#endif // THRESHOLDFUNCTION
