#include "arbreBin.hpp"
#include <iostream>
using namespace std;

bool compleix_suma_fills (const arbreBin<int> &a){
    bool compleix = true;
    // Cas directe 1
    if (a.es_buit())
        compleix = true;
    // Cas directe 2
    else if (a.fe().es_buit() and a.fd().es_buit())
        compleix = true;
    
    // Cas normal
    else {
        int esq = 0, dret = 0;
        if (not a.fe().es_buit()) esq = a.fe().arrel();
        if (not a.fd().es_buit()) dret = a.fd().arrel();
        if (esq+dret == a.arrel()) compleix = (compleix_suma_fills(a.fe())) and (compleix_suma_fills(a.fd()));
        else compleix = false;
    }

    return compleix;
}

int main () {
    arbreBin<int>ar;
    cin >> ar;
    cout << ar << endl;

    if (compleix_suma_fills(ar))
        cout << "L'arbre compleix la propietat 'Suma dels fills'." << endl;
    else
        cout << "L'arbre no compleix la propietat 'Suma dels fills'." << endl;
}