#ifndef CHROMOSOME
#define CHROMOSOME

#include <vector>

template <class C, class T>
class Chromosome {
    std::vector<C> crossover(C anotherChromosome);
    C mutate();
};

#endif // CHROMOSOME

