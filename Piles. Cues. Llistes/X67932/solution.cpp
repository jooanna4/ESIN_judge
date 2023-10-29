#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    if (l2._long == 0) return;
    if (_long == 0) return;

    node *p1(_prim->seg), *p2(l2._prim->seg), *pant(_prim), *p2aux;
    while (p1 != _prim or p2 != l2._prim) {
        // n elements del p.i.
        for (int i = 0; i < n; i++) {
            p1 = p1->seg;
            pant = pant->seg;
        }

        // n elements de l2
        for (int i = 0; i < n; i++) {
            if (p2 != l2._prim) {
                p2aux = p2->seg;
                pant->seg = p2;
                p2->ant = pant;
                p2->seg = p1;
                p1->ant = p2;
                p2 = p2aux;
                pant = pant->seg;
            }
        }
    }
}