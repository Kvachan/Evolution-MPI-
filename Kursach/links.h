#ifndef LINKS
#define LINKS

#include "cloneable.h"
#include <map>
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

    Links* clone();

    std::string toString() override;

};


#endif // LINKS


/*
 * public Collection<Integer> getReceivers(int activatorNeuronNumber) {
        Collection<Integer> ret = null;
        if (this.links.containsKey(activatorNeuronNumber)) {
            ret = Collections.unmodifiableSet(this.links.get(activatorNeuronNumber).keySet());
        } else {
            ret = Collections.emptySet();
        }
        return ret;
    }
*/
