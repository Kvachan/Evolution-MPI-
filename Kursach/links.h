#ifndef LINKS
#define LINKS

#include "cloneable.h"
#include <map>
#include <set>
#include <vector>
#include <string>


class Links : public Cloneable {

private:
    std::map<int, std::map<int, double> > links; //pointer?
    int totalLinksCount;

public:
    Links();
    double getWeight(int activatorNeuronNumber, int receiverNeuronNumber);
    void addWeight(int activatorNeuronNumber, int receiverNeuronNumber, double weight);
    std::vector<double> getAllWeights();
    void setAllWeights(std::vector<double> weights);

    void setLinksCount(int count);

    std::set<int> getReceivers(int activatorNeuronNumber);

    Links* clone();

    std::string toString() override;

};


#endif // LINKS



