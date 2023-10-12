#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    node *pi(_prim), *p2(l2._prim), *pant(_prim), *p2aux;
    int cont = 0;

    if (pi == nullptr)
        _prim = l2._prim;

    _long += l2._long;
    // Resetejar l2
    l2._prim = nullptr;
    l2._ult = nullptr;
    l2._long = 0;

    while (pi != nullptr or p2 != nullptr) {
        // Per p.i.
        for (int i = 0; i < n; i++) {
            if (pi != nullptr) {
                cont += pi->info;
                pant = pi;
                pi = pi->seg;
            }
        }
        // Per l2
        for (int i = 0; i < n; i++) {
            if (p2 != nullptr) {
                cont += p2->info;
                if (pant != nullptr) {
                    p2aux = p2->seg;
                    pant->seg = p2;
                    p2->ant = pant;
                    p2->seg = pi;
                    if (pi != nullptr)
                        pi->ant = p2;
                    p2 = p2aux;
                    pant = pant->seg;
                }
                else {
                    pant = p2;
                    p2 = p2->seg;
                }
            }
        }
    }
    _ult = pant;
    node *pcont = new node;
    pcont->info = cont;
    pcont->ant = nullptr;
    pcont->seg = _prim;
    if (_prim != nullptr)
        _prim ->ant = pcont;
    else
        _ult = pcont;
    _prim = pcont;
    _long++;
}