
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Retorna la segona clau.
    // Pre: El diccionari té com a mínim 2 claus.
    Clau segona();

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
      nat _n;       // Nombre de nodes del subarbre
      node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k, bool &ins);

    // Aquí va l’especificació dels mètodes privats addicionals
    void segona(node *n, Clau &k, int &i);
};

// Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
Clau dicc<Clau>::segona() {
    Clau k;
    if (_arrel != nullptr) {
        int i = 0;
        segona(_arrel, k, i);
    }
    return k;
}

template <typename Clau>
void dicc<Clau>::segona(node *n, Clau &k, int &i) {
    if (n != nullptr and i < 2) {
        segona(n->_esq, k, i);
        i++;
        if (i == 2) {
            k = n->_k;
        }
        segona(n->_dret, k, i);
    }
}
