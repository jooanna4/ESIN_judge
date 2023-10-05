#include "llista.hpp"

void Llista::separa(Llista &l2) {
    if (_long == 0 or _long == 1) return;

    node *ant =_prim, *par = _prim->seg, *segu = _prim->seg->seg, *aux, *pnou;
    while (par != nullptr) {
        ant->seg = segu;
        pnou = new node;
        pnou->info = par->info;
        pnou->seg = nullptr;
        if (l2._long == 0)
            l2._prim = pnou;
        else
            aux->seg = pnou;
        l2._long++;
    }
}