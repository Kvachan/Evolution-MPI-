#include "population.h"
#include "chromosome.h"
#include <math.h>
#include <cmath>

template <class C, class T>
int Population<C, T>::DEFAULT_NUMBER_OF_CHROMOSOMES = 32;

template <class C, class T>
void Population<C, T>::addChromosome(C *chromosome) {
    chromosomes->push_back(chromosome);
}

template <class C, class T>
int Population<C, T>::getSize() {
    return chromosomes->size();
}

template <class C, class T>
C* Population<C, T>::getRandomChromosome() {
    int numOfChromosomes = chromosomes->size();
    int indx = rand() % numOfChromosomes;
    return chromosomes[indx];
}

template <class C, class T>
C *Population<C, T>::getChromosomeByIndex(int indx) { //originaly find
    Chromosome<C, T> *ch;
    return chromosomes[indx];
}

template <class C, class T>
void Population<C, T>::sortPopulationByFitness() {
    std::shuffle(chromosomes->begin(), chromosomes->end(), 1);
    std::sort<C>(chromosomes->begin(), chromosomes->end());
}

template <class C, class T>
void Population<C, T>::trim(int len) {
    //this.chromosomes = this.chromosomes.subList(0, len);
}

//template <class C, class T>
//std::iterator<C> Population<C, T>::getIterator


