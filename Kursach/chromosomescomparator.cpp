#include "chromosomescomprator.h"

template<class C, class T>
int ChromosomesComparator<C, T>::comprare(C* chr1, C* chr2) {
    T* fit1 = this->fit(chr1);
    T* fit2 = this->fit(chr2);
    if (chr1 > chr2) {
        return 1;
    } else  if (chr2 > chr1) {
       return 0;
    } else {
        return NULL;
    }
}

//public int compare(C chr1, C chr2) {
//    T fit1 = this.fit(chr1);
//    T fit2 = this.fit(chr2);
//    int ret = fit1.compareTo(fit2);
//    return ret;
//}


template <class C, class T>
T ChromosomesComparator<C, T>::fit(C* chr) {
    T* fit = cache->find(chr);
    if(fit == cache->end()) {
        //fit = GeneticAlgorithm.this.fitnessFunc.calculate(chr);
        cache->insert(chr, fit);
    }
    return fit;
}

template <class C, class T>
void ChromosomesComparator<C, T>::clearCache() {
    cache->clear();
}

