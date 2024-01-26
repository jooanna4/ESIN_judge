#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    node *pant(_prim), *paux(_prim->seg), *p2(l2._prim->seg), *p2aux;
    int i;
    while (p2 != l2._prim) {
        i = 0;
        while (paux != _prim && i < n) {
            pant = paux;
            paux = paux->seg;
            i++;
        }

        i = 0;
        while (p2 != l2._prim && i < n) {
            pant->seg = p2;
            p2->ant = pant;
            paux->ant = p2;
            p2aux = p2->seg;
            p2->seg = paux;
            p2 = p2aux;
            pant = pant->seg;
            i++;
        }
    }
    l2._prim = nullptr;
    _long += l2._long;
    l2._long = 0;
}