#include "llista.hpp"
#include <iostream>

void Llista::fusiona_suma(Llista &l2, nat n) {
    // Suma
    int suma = 0;
    node *aux = _prim->seg;
    for (int i = 0; i < (_long); i++) {
        suma += aux->info;
        aux = aux->seg;
    }
    aux = l2._prim->seg;
    for (int i = 0; i < (l2._long); i++) {
        suma += aux->info;
        aux = aux->seg;
    }

    node *aux1 = new node, *aux2 = l2._prim->seg, *fant2 = l2._prim, *ant = _prim, *it; //aux1 i aux2 apunten al fantasma
    aux1->info = suma;
    aux1->seg = ant->seg;
    ant->seg = aux1;
    aux1 = aux1->seg;
    ant = ant->seg;
    int i;
    while(aux2 != fant2) {
        i = 0;
        while (i < n and aux1 != _prim) {
            aux1 = aux1->seg;
            ant = ant->seg;
            i++;
        }
        i = 0;
        while (i < n and aux2 != fant2) {
            ant->seg = aux2;
            it = aux2->seg;
            aux2->seg = aux1;
            aux2 = it;
            ant = ant->seg;
            i++;
        }
    }

    _long += l2._long + 1;
    l2._prim->seg = l2._prim;
    l2._long = 0;
}