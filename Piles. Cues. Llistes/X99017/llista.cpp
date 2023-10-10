#include <iostream>
#include "llista.hpp"

Llista::Llista() : _long(0) {
  _prim = NULL;
  _ult  = NULL;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = NULL;
  node *p, *pant = NULL;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = NULL;
    p->ant = pant;
    if (pant == NULL)
      _prim = p;
    else
      pant->seg = p;
    pant = p;
  }
  _ult = pant;
}

Llista::~Llista() {
  node *p = _prim, *pelim;
  while (p != NULL) {
    pelim = p;
    p = p->seg;
    delete pelim;
  }
}

nat Llista::longitud() const {
  return _long;
}

void Llista::mostra() const {
  node *p = _prim;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
  }
  while (p != NULL) {
    cout << " " << p->info;
    p = p->seg;
  }
  cout << "]";
}

void Llista::mostra_invertida() const {
  node *p = _ult;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->ant;
  }
  while (p != NULL) {
    cout << " " << p->info;
    p = p->ant;
  }
  cout << "]";
}
