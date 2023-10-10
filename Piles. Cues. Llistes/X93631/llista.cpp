#include <iostream>
#include "llista.hpp"

Llista::Llista() : _long(0) {
  _prim = new node;
  _prim->seg = NULL;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = new node;
  _prim->seg = NULL;
  node *p, *pant = _prim;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = NULL;
    pant->seg = p;
    pant = p;
  }
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
  node *p = _prim->seg;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
  }
  while (p != NULL) {
    cout << " " << p->info;
    p = p->seg;
  }
  cout << "]" << endl;
}
