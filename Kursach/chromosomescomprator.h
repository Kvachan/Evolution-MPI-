#ifndef CHROMOSOMESCOMPRATOR
#define CHROMOSOMESCOMPRATOR

#include <map>

template<class C, class T>
class ChromosomesComparator {
    std::map<C*, T*> *cache;
public:
    int comprare(C* chr1, C* chr2);
    T fit(C *chr);
    void clearCache();
};

#endif // CHROMOSOMESCOMPRATOR

