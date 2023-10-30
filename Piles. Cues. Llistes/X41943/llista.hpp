#include <vector>
#include <cstddef>
using namespace std;
typedef unsigned int nat;

class Llista {
  // Llista simplement encadenada, sense fantasma i no circular.
  private:
    struct node {
      int info;  // Informació del node
      node *seg; // Punter al següent element
    };
    node *_prim; // Punter al primer element
    nat _long;   // Nombre d'elements

  public:
    Llista();
    // Pre: True
    // Post: El p.i. és una llista buida.

    Llista(const vector<int> &v);
    // Pre: True
    // Post: El p.i. conté els elements de v amb el mateix ordre.

    ~Llista();
    // Post: Destrueix els elements del p.i.

    nat longitud() const;
    // Pre: True
    // Post: Retorna el nombre d'elements del p.i.

    void mostra() const;
    // Pre: True
    // Post: Mostra el p.i. pel canal estàndard de sortida.

    void duplica_positius_elimina_negatius();
    // Pre: True
    // Post: S'han duplicat els elements positius i
    //       s'han eliminat els elements negatius del p.i.
    //       Exemple: [0 3 -6 8 0 4 -2 0] => [0 3 3 8 8 0 4 4 0]
};
