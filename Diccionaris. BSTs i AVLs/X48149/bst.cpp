#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class bst {

  public:
    // Constructora per defecte. Crea un BST buit.
    bst();

    // Destructora
    ~bst();

    // Aquí va l’especificació dels mètodes públics addicionals
    static void ordena(node *n, vector<T>& v);

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació dels mètodes públics i privats de bst
template <typename T>
void ordena(vector<T>& v) {
  ordena(_arrel, v);
}


// Aquí va la implementació del procediment ordena
template <typename T>
void ordena(node *n, vector<T>& v) {
  if (n != nullptr) {
    ordena(n->_esq, v);
    v.push_back(n->_k);
    ordena(n->_dret);
  }
}
