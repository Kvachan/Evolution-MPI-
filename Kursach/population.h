#ifndef POPULATION
#define POPULATION

#include <vector>

template <class C, class T>
class Population {
    static int DEFAULT_NUMBER_OF_CHROMOSOMES; //32
    std::vector<C*> *chromosomes;
public:
    void addChromosome(C* chromosome);
    int getSize();
    C *getRandomChromosome();
    C *getChromosomeByIndex(int indx);
    void sortPopulationByFitness(); //write my comprator
    void trim(int len);
    //std::iterator<C*> getIterator(); //getIterator
};



#endif // POPULATION

