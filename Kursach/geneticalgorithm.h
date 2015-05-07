#ifndef GENETICALGORITHM
#define GENETICALGORITHM

#include "chromosomescomprator.h"
#include "chromosome.h"
#include "iterationlistener.h"
#include "fitness.h"
#include "population.h"

template <class C, class T>
class GeneticAlgorithm {
    static int ALL_PARENTAL_CHROMOSOMES;
    ChromosomesComparator<C, T> *chromosomesComparator;
    Fitness<C, T> fitnessFunc;
    Population<C, T> *population;
    std::vector<IterartionListener<C, T>> *IterartListener;
    bool termin;
    int parentChromosomesSurviveCount = ALL_PARENTAL_CHROMOSOMES;
    int iteration; //0
public:
    GeneticAlgorithm();
    GeneticAlgorithm(Population<C, T> population, Fitness<C, T> fitnessFunc);
    void evolve();
    void evolve(int count);
    int getIteration();
    void terminate();
    Population<C, T>* getPopulation();
    C* getBest();
    C* getWorst();
    void setParentChromosomesSurviveCount(int parentChromosomesCount);
    int getParentChromosomesSurviveCount();
    void addIterationListener(::IterartionListener<C, T> *listener);
    void removeIterationListener(::IterartionListener<C, T> *listener);
    T* fitness(C* chromosome);
    void clearCache();
};

#endif // GENETICALGORITHM

