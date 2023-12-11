#include <sstream>
#include <iostream>
#include <string>
#include "dicc.cpp"
using namespace std;


template <typename Clau>
dicc<Clau>::dicc() : _arrel(NULL) {}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
dicc<Clau>::node::node (const Clau &k, node* esq, node* dret) :
	_k(k), _esq(esq), _dret(dret), _n(1) {
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
  bool ins = false;
  _arrel = insereix_bst(_arrel, k, ins);
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst (node *n, const Clau &k, bool &ins) {
  if (n == NULL) {
    ins = true;
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k, ins);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k, ins);
    }
    if (ins)
      n->_n++;
    return n;
  }
}

template <typename Clau>
nat dicc<Clau>::quants() const {
  nat n = 0;
  if (_arrel != NULL)
    n = _arrel->_n;
  return n;
}


int main() {
  string linea, comanda;
  int n;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n) {
      d.insereix(n);
    }
    cout << d.quants() << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "segona") {
        cout << d.segona() << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}
