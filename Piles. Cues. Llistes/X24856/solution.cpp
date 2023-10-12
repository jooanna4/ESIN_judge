#include "cua.hpp"
#include <vector>

cua::cua(const vector<int> &v) : _long(v.size()) {
    if (_long != 0) {
        node *prim(nullptr), *pnou(nullptr), *pant(nullptr);
        for (int i = 0; i < _long; i++) {
            pnou = new node;
            pnou->info = v[i];
            if (i == 0)
                prim = pnou;
            pnou->seg = prim;
            if (i != 0)
                pant->seg = pnou;
            pant = pnou;
            _ult = pnou;
        }
    }
    else
        _ult = nullptr;
}