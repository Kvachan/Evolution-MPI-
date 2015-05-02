#include "mapelement.h"

MapElement::MapElement() {
    this->from = 0;
    this->to = 0;
    this->weight = 0.0;
}

MapElement::MapElement(int from, int to, double weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
}
