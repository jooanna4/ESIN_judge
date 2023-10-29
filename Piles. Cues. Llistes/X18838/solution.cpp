#include "llista.hpp"

void Llista::inverteix() {
    if (_prim->seg == nullptr) return;
    node *p1(_prim->seg), *pant(_prim), *aux;
    while (p1 != nullptr) {
        aux = p1->seg;
        p1->seg = pant;
        pant = p1;
        p1 = aux;
    }
    _prim->seg->seg = nullptr;
    _prim->seg = pant;
}