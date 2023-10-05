#include "llista.hpp"

void Llista::separa(Llista &l2) {
    if (_long == 0 or _long == 1) return;

    node *ant = _prim, *aux = _prim->seg, *segu = _prim->seg->seg, *pnou;
    for (int i = 1; i <= _long; i++) {
        // si es parell
        if (i%2 == 0) {
            
        }
        // si es imparell
        else {

        }
    }
}