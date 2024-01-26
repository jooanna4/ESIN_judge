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
    void ordena2(vector<Clau>&v);

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    static node* insereix(node *n, Clau k);
    static void metela(vector<Clau>&v, int &i, node *n);
};

// Aquí va la implementació dels mètodes públics i privats de bst
template <typename T>
void ordena(vector<T>& v) {
  bst<T>aux;
  aux.ordena2(v);
}

template <typename Clau>
typename bst<Clau>::node* bst<Clau>::insereix(node *n, Clau k) {
  if (n != nullptr) {
    if (n->_k > k)
      n->_esq = insereix(n->_esq, k);
    else
      n->_dret = insereix(n->_dret, k);
  }
  else {
    n = new node;
    n->_k = k;
    n->_esq = n->_dret = nullptr;
  }
  return n;
}

template <typename Clau>
void bst<Clau>::ordena2(vector<Clau>&v) {
  for (int i = 0; i < v.size(); i++) {
    _arrel = insereix(_arrel, v[i]);
  }
  int i = 0;
  metela(v, i, _arrel);
}

template <typename Clau>
void bst<Clau>::metela(vector<Clau>&v, int &i, node *n) {
  if (n != nullptr) {
    metela(v, i, n->_esq);
    v[i] = n->_k;
    i++;
    metela(v, i, n->_dret);
  }
}