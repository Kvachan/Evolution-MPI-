#include "geneticalgorithm.h"

template <class C, class T>
int GeneticAlgorithm<C, T>::ALL_PARENTAL_CHROMOSOMES = std::numeric_limits<int>::max();

template <class C, class T>
GeneticAlgorithm<C, T>::GeneticAlgorithm()
{
    iteration = 0;
};

template <class C, class T>
GeneticAlgorithm<C, T>::GeneticAlgorithm(Population<C, T> population, Fitness<C, T> fitnessFunc) {
    this->population = population;
    this->fitnessFunc = fitnessFunc;
    //this->ChromosomesComparator = new chromosomesComparator<C, T>();
    this->chromosomesComparator = new ChromosomesComparator<C, T>();
    this->population->sortPopulationByFitness();
}

template <class C, class T>
void GeneticAlgorithm<C, T>::evolve() {
    int parentPopulationSize = this->population->getSize();
    Population<C, T>* newPopulation = new Population<C, T>();
    for (int i = 0; (i < parentPopulationSize) && (i < this->parentChromosomesSurviveCount); i++) {
        newPopulation->addChromosome(this->population->getChromosomeByIndex(i));
    }

    for (int i = 0; i < parentPopulationSize; i++) {
        C* chromosome = population->getChromosomeByIndex(i);
        C* mutated = chromosome->mutate();
        C* otherChromosome = population->getRandomChromosome();
        std::vector<C*> *crossovered = chromosome->crossover(otherChromosome);
        for(int i = 0; i < parentPopulationSize; i++) {
            C* chromosome = population->getChromosomeByIndex(i);
            C* mutated = chromosome->mutate();

            C* otherChromosome = population->getRandomChromosome();
            std::vector<C*> crossovered = chromosome->crossover(otherChromosome);

            newPopulation->addChromosome(mutated);
            for(C* c : crossovered) {
                newPopulation->addChromosome(c);
            }
            newPopulation->sortPopulationByFitness();
            newPopulation->trim(parentPopulationSize);
            this->population = newPopulation;
        }
}
}

template <class C, class T>
void GeneticAlgorithm<C, T>::evolve(int count) {
    this->terminate = false;

    for(int i = 0; i < count; i++) {
        if (this->terminate) {
            break;
        }
        this->evolve();
        this->iteration = i;
        for (IterartionListener<C, T> *l : this->IterartionListener) {
            l->update(*this);
        }
    }
}

template <class C, class T>
int GeneticAlgorithm<C, T>::getIteration() {
    return this->iteration;
}

template <class C, class T>
void GeneticAlgorithm<C, T>::terminate() {
    this->termin = true;
}

template <class C, class T>
Population<C, T>* GeneticAlgorithm<C, T>::getPopulation() {
    return this->population;
}

template <class C, class T>
C* GeneticAlgorithm<C, T>::getBest() {
    return this->population->getChromosomeByIndex(0);
}

template <class C, class T>
C* GeneticAlgorithm<C, T>::getWorst() {
    return this->population->getChromosomeByIndex(this->population->getSize() - 1);
}

template <class C, class T>
void GeneticAlgorithm<C, T>::setParentChromosomesSurviveCount(int parentChromosomesCount) {
    this->parentChromosomesSurviveCount = parentChromosomesCount;
}
template <class C, class T>
int GeneticAlgorithm<C, T>::getParentChromosomesSurviveCount() {
    return this->parentChromosomesSurviveCount;
}

template <class C, class T>
void GeneticAlgorithm<C, T>::addIterationListener(IterartionListener<C, T> *listener) {
    this->IterartionListener->push_back(listener);
}

template <class C, class T>
void GeneticAlgorithm<C, T>::removeIterationListener(IterartionListener<C, T> *listener) {
    this->IterartionListener->erase(std::find(IterartListener->begin(), IterartListener->end(), listener));
}

template <class C, class T>
T* GeneticAlgorithm<C, T>::fitness(C* chromosome) {
    return this->chromosomesComparator->fit(chromosome);
}

template <class C, class T>
void GeneticAlgorithm<C, T>::clearCache() {
    this->chromosomesComparator->clearCache();
}
