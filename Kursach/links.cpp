#include "links.h"
#include <iostream>

Links::Links() {
    totalLinksCount = 0;
}

double Links::getWeight(int activatorNeuronNumber, int receiverNeuronNumber) {

    auto res1    = links.find(activatorNeuronNumber);
    if (res1 != links.end())
    {
        auto receiverNumToWeight = res1->second;
        auto res2 = receiverNumToWeight.find(receiverNeuronNumber);

        if (res2 != receiverNumToWeight.end())
        {
            return res2->second;
        }
        else
        {
            std::cout << "ERROR 2" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR 1" << std::endl;
    }

    return 0.0;
}

void Links::addWeight(int activatorNeuronNumber, int receiverNeuronNumber, double weight) {
//    if (!this.links.containsKey(activatorNeuronNumber)) {
//        this.links.put(activatorNeuronNumber, new LinkedHashMap<Integer, Double>());
//    }
//    this.links.get(activatorNeuronNumber).put(receiverNeuronNumber, weight);

    auto it = links.find(activatorNeuronNumber);
    if (it != links.end()) {
        links[activatorNeuronNumber] = *(new std::map<int, double>());
    }
    it->second.insert(std::pair<int, double>(receiverNeuronNumber, weight));

    totalLinksCount++;
}

std::vector<double> Links::getAllWeights() {
//    List<Double> weights = new ArrayList<Double>(this.totalLinksCount);

//    for (Integer activatorIndx : this.links.keySet()) {
//        Map<Integer, Double> receiverIndxToWeight = this.links.get(activatorIndx);

//        for (Integer receiverIndx : receiverIndxToWeight.keySet()) {
//            weights.add(receiverIndxToWeight.get(receiverIndx));
//        }
//    }

//    return weights;

    std::vector<double> result;

    for (auto it1 = links.begin(); it1 != links.end(); ++it1)
    {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            result.push_back(it2->second);
        }
    }

    return result;
}


void Links::setAllWeights(std::vector<double> weights) {
//    if (weights.size() != this.totalLinksCount) {
//        throw new IllegalArgumentException("Number of links is " + this.totalLinksCount
//                + ". But weights list has size " + weights.size());
//    }

//    int indx = 0;
//    for (Integer activatorIndx : this.links.keySet()) {
//        Map<Integer, Double> receiverIndxToWeight = this.links.get(activatorIndx);

//        for (Integer receiverIndx : receiverIndxToWeight.keySet()) {
//            receiverIndxToWeight.put(receiverIndx, weights.get(indx));
//            indx++;
//        }
//    }

    if (weights.size() != totalLinksCount) {
        std::cout << "ERROR 4" << std::endl;
        return;
    }
    int indx = 0;
    for (auto it = links.begin(); it != links.end(); it++) {

        for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            it->second[it1->first] = weights[indx++];
        }
    }
}

void Links::setLinksCount(int count) {
    totalLinksCount = count;
}

Links* Links::clone() {
    Links* clone = new Links();
    clone->setLinksCount(totalLinksCount);
//    for (int key : this.links.keySet()) {
//        Map<Integer, Double> val = new LinkedHashMap<Integer, Double>();
//        for (int valKey : this.links.get(key).keySet()) {
//            val.put(valKey, this.links.get(key).get(valKey));
//        }
//        clone.links.put(key, val);
//    }
    for (auto it = links.begin(); it != links.end(); it++) {

        auto new_links  = new std::map<int, double>();

        for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            new_links->at(it1->first) = it1->second;
        }
        clone->links[it->first] = *new_links;
    }
    return clone;
}

std::string Links::toString() {
    std::string retString;
    //retString = "Links [links=" + links + ", totalLinksCount=" + totalLinksCount + "]";
    return retString;
}

std::vector<int> Links::getReceivers(int activatorNeuronNumber) {
    //std::set<int> ret;
    std::vector<int> result;
    auto it = links.find(activatorNeuronNumber);
    if(it != links.end()) {
        for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            result.push_back(it1->first);
        }
    }
    return result;
}

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
