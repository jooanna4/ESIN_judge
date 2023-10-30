#include "llista.hpp"

void Llista::duplica_positius_elimina_negatius() {
    if (_prim != nullptr) {
        node *p1(_prim), *pant(nullptr);
        if (p1->info < 0) {
            _long--;
            node *aux(p1);
            p1 = p1->seg;
            _prim = p1;
            delete(aux);
        }
        while (p1 != nullptr) {
            if (p1->info > 0) {
                _long++;
                node *pnou = new node;
                pnou->info = p1->info;
                pnou->seg = p1->seg;
                p1->seg = pnou;
                p1 = pnou->seg;
                pant = pnou;
            }
            else if (p1->info < 0) {
                _long--;
                node *aux(p1);
                p1 = p1->seg;
                if (pant != nullptr)
                    pant->seg = p1;
                if (aux == _prim)
                    _prim = p1;
                delete(aux);
            }
            else {
                pant = p1;
                p1 = p1->seg;
            }
        }
    }
}