#include "cua.hpp"
#include <vector>

cua::cua(const vector<int> &v) : _long(v.size()) {
    if (v.size() != 0) {
        node *paux = new node, *pant;
        paux->info = v[0];
        paux->seg = nullptr;
        pant = paux;
        for (int i = 1; i < v.size(); i++) {
            paux = new node;
            paux->info = v[i];
            paux->seg = nullptr;
            _ult = paux;
            pant->seg = paux;
            pant = pant->seg;
        }
    }
}