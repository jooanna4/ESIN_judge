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

    vector<nat> quants_succ_succ() const;
    // Pre: Cert
    // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
    // del graf

  private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals
vector<nat> graf::quants_succ_succ() const {
    vector<nat> result(n, 0); 
    for (nat i = 0; i < n; ++i) {
        vector<bool> visited(n, false); // inicializar todos los vértices como no visitados
        for (nat j = 0; j < n; ++j) {
            if (a[i][j]) {
                vector<bool> succ_succs = a[j]; 
                for (nat k = 0; k < n; ++k) {
                    if (succ_succs[k] && a[j][k] && !visited[k]) {
                        ++result[i]; 
                        visited[k] = true; // marcar el vértice como visitado
                    }
                }
            }
        }
    }
    return result;
}
