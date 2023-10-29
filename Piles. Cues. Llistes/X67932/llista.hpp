#include <vector>
#include <cstddef>
using namespace std;
typedef unsigned int nat;

class Llista {
  // Llista doblement encadenada, circular i amb fantasma.
  private:
    struct node {
      int info;  // Informació del node
      node *seg; // Punter al següent element
      node *ant; // Punter a l'anterior element
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

    void mostra_invertida() const;
    // Pre: True
    // Post: Mostra el p.i. en ordre invers pel canal estàndard de sortida.

    void fusiona_suma(Llista &l2, nat n);
    // Pre: n > 0
    // Post: Al p.i. s'han fusionat els elements del p.i. i de l2 agafant n elements del p.i.
    //       i n elements de l2 alternativament (o els que quedin si n'hi ha menys de n).
    //       Al principi del p.i. s'afegeix un nou element que conté la suma de tots els elements del p.i i l2
    //       La llista l2 queda buida.
    // Exemple amb n=2:
    // p.i. [2 5 3 8 4] => [38 2 5 1 6 3 8 9 4]
    // l2   [1 6 9]     => []
};
