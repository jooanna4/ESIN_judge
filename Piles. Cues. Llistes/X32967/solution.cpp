#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    // Fantasma
    _prim = new node;
    _prim->seg = _prim;
    _prim->ant = _prim;

    _long = v.size();

    if (_long != 0) {
        node *pnou, *aux = _prim;
        for (int i = 0; i < _long; i++) {
            pnou = new node;
            pnou->info = v[i];
            pnou->seg = _prim;
            pnou->ant = aux;
            aux->seg = pnou;
            _prim->ant = pnou;
            aux = aux->seg;
        }
    }
}