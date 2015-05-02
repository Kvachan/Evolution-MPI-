#ifndef ITERATIONLISTENER
#define ITERATIONLISTENER

template <class C, class T>
class GeneticAlgorithm;

template <class C, class T>
class IterartionListener {
    void update(GeneticAlgorithm<C, T> environment);
};

#endif // ITERATIONLISTENER

