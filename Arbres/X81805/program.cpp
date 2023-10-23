#include "arbreBin.hpp"
#include <iostream>
using namespace std;

arbreBin<int> suma_fills (arbreBin<int> b) {
    arbreBin<int> suma, a_esquerra, a_dret;
    int i;
    if (not b.es_buit()) {
        if (not b.fe().es_buit())
            a_esquerra = suma_fills(b.fe());
        if (not b.fd().es_buit())
            a_dret = suma_fills(b.fd());
        i = b.arrel();
        if (not a_esquerra.es_buit()) i += a_esquerra.arrel();
        if (not a_dret.es_buit()) i += a_dret.arrel();
        suma = arbreBin<int>(i, a_esquerra, a_dret);
    }
    return suma;
}

int main () {
    arbreBin<int> a, b;
    cin >> a;
    b = suma_fills(a);
    cout << b << endl;
}