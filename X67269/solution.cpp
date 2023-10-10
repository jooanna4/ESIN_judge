#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    node *pi(_prim), *p2(l2._prim), *pant(nullptr), *p2aux;
    int cont = 0;

    if (pi == nullptr)
        _prim = l2._prim;
    
    l2._prim = nullptr;
    _long += l2._long;
    l2._long = 0;

    while (pi != nullptr or p2 != nullptr) {
        for (int i = 0; i < n; i++) {
            if (pi != nullptr) {
                pant = pi;
                cont += pi->info;
                pi = pi->seg;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p2 != nullptr) {
                cont += p2->info;
                if (pant != nullptr) {
                    pant->seg = p2;
                    p2aux = p2->seg;
                    p2->seg = pi;
                    p2 = p2aux;
                    pant = pant->seg;
                }
                else
                    p2 = p2->seg;
            }
        }
    }

    node *pcont = new node;
    pcont->info = cont;
    pcont->seg = _prim;
    _prim = pcont;
    _long++;
}