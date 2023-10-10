#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    if (v.size() != 0) {
        node *pnou = new node;
        pnou->info = v[0];
        pnou->seg = nullptr;
        _prim = pnou;
        _long = v.size();

        node *ant = _prim;

        for (nat i = 1; i < _long; i++) {
            pnou = new node;
            pnou->info = v[i];
            pnou->seg = nullptr;
            ant->seg = pnou;
            ant = ant->seg;
        }
    }
    else {
        _prim = nullptr;
        _long = 0;
    }
}