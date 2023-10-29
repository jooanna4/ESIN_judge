#include <vector>
#include <cstddef>
using namespace std;
typedef unsigned int nat;

class Llista {
  // Llista simplement encadenada, amb fantasma i no circular.
  private:
    struct node {
      int info;  // Informació del node
      node *seg; // Punter al següent element
    };
    node *_prim; // Punter a l'element fantasma
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

    void inverteix();
    // Pre: True
    // Post: S'ha invertit l'ordre els elements del p.i.
    //       Exemple: [2 5 3] = > [3 5 2]
    // No es permet usar estructures auxiliars per invertir
    // els elements ni modificar el camp info,
    // només modificar els encadenaments dels nodes.
};
