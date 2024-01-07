#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en una matriu d’adjacència.
  public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();
 
    bool hi_ha_cami(nat ini, nat fi) const;
    // Pre: ini i fi són vèrtexs del graf (són menors que n)
    // Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi

  private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals
bool graf::hi_ha_cami(nat ini, nat fi) const {
    if (ini == fi) return true;
    else if (a[ini][fi]) return true;
    else {
        int i = ini, j = 0;
        bool found = false;
        while (i < n && j < n && not found) {
            if (i == ini && j == fi) found = true;
            else if (i != j && a[i][j]) {
                i = j;
                j++;
            }
            else {
                j++;
            }
        }
    }
}