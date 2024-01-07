#include <vector>
#include <stack>
using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
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
    vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals
bool graf::hi_ha_cami(nat ini, nat fi) const {
  if (ini == fi) return true;
  else if (m == 0) return false;
  else {
    bool found = false;
    vector<bool> visitat (n, false);
    stack<nat> p;
    p.push(ini);
    while (not p.empty()) {
        nat v = p.top();
        p.pop();
        visitat[v] = true;
        if (v == fi) return true;
        else {
            for (nat i = 0; i < a[v].size(); i++) {
                nat w = a[v][i];
                if (not visitat[w])
                    p.push(w);
            }
        }
    }
    return false;
  }
}