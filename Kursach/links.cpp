#include "links.h"

Links::Links() {
    totalLinksCount = 0;
}

double Links::getWeight(int activatorNeuronNumber, int receiverNeuronNumber) {
    double weight = 0;

//    if(links.key_compare(activatorNeuronNumber)) {
//        std::map<int, double> receiverNumToWeight = links.find(activatorNeuronNumber);

//        if (receiverNumToWeight.key_compare(receiverNeuronNumber)) {
//            weight = receiverNumToWeight.find(receiverNeuronNumber);
//        } else {
//            return NULL; //EXCEPTION(illegal arg)
//        }
//    } else {
//        return NULL; //EXCEPTION(illegal arg)
//    }
    return weight;
}

void Links::addWeight(int activatorNeuronNumber, int receiverNeuronNumber, double weight) {
//    if (!this.links.containsKey(activatorNeuronNumber)) {
//        this.links.put(activatorNeuronNumber, new LinkedHashMap<Integer, Double>());
//    }
//    this.links.get(activatorNeuronNumber).put(receiverNeuronNumber, weight);
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
    std::vector<double> ret;
    return ret;
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
    return clone;
}

std::string Links::toString() {
    std::string retString;
    //retString = "Links [links=" + links + ", totalLinksCount=" + totalLinksCount + "]";
    return retString;
}

std::set<int> Links::getReceivers(int activatorNeuronNumber) {
    std::set<int> ret;
    return ret;
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
