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

    void separa(Llista &l2);
    // Pre: l2 és buida
    // Post: S'han separat els elements del p.i., quedant al p.i. els elements
    //       de les posicions senars i a l2 els de les posicions parells.
    //       Exemple: [2 5 3 8 1] => [2 3 1] i l2 = [5 8]
};
