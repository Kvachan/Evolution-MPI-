#ifndef MAPELEMENT
#define MAPELEMENT

class MapElement {
public:
    int from;
    int to;
    double weight;

    MapElement();
    MapElement(int from, int to, double weight);

};

#endif // MAPELEMENT

