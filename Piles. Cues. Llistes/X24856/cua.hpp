#include <vector>
using namespace std;
typedef unsigned int nat;

class cua {
  // cua simplement encadenada, sense fantasma i circular.
  private:
    struct node {
      int info;  // Informació del node
      node *seg; // Punter al següent element
    };
    node *_ult; // Punter a l'últim element
    nat _long;  // Nombre d'elements

    node* copiar(node* n, node* fi, node* ini);

  public:
    cua();
    // Pre: True
    // Post: El p.i. és una cua buida.

    cua(const vector<int> &v);
    // Pre: True
    // Post: El p.i. conté els elements de v amb el mateix ordre.

    // Tres grans: constructora per còpia, operador d'assignació i destructora.
    cua(const cua &c);
    cua& operator=(const cua &c);
    ~cua();

    void desencuar();
    // Pre: True
    // Post: Treu el primer element de la cua. Llança un error si la cua és buida.

    const int& primer() const;
    // Pre: True
    // Post: Obté el primer element de la cua. Llança un error si la cua és buida.

    bool es_buida() const;
    // Pre: True
    // Post: Consulta si la cua és buida o no.

    nat longitud() const;
    // Pre: True
    // Post: Retorna el nombre d'elements del p.i.

    static const int CuaBuida = 310;
};
