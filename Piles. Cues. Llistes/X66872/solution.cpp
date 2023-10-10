#include "llista.hpp"

void Llista::separa(Llista &l2) {
    if (_long == 0 or _long == 1) return;

    node *p(_prim), *p2ant(nullptr);
    while (p != nullptr) {
        node *pseg (p->seg);
        if (pseg != nullptr) {
            p->seg = pseg->seg;
            if (p2ant == nullptr)
                l2._prim = pseg;
            else
                p2ant->seg = pseg;
            p = p->seg;
            p2ant = pseg;
        }
    }
    if (p2ant != nullptr)
        p2ant->seg = nullptr;
    l2._long = _long / 2;
    _long = _long - l2._long;
}