#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    // Fantasma
    _prim = new node;
    _prim->seg = nullptr;
    _long = v.size();

    if (v.size() != 0) {
        node *pnou, *ant = _prim;
        for (int i = 0; i < _long; i++) {
            pnou = new node;
            pnou->info = v[i];
            pnou ->seg = nullptr;
            ant->seg = pnou;
            ant = ant->seg;
        }
    }
}