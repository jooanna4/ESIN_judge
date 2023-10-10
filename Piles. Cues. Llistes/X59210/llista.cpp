#include <iostream>
#include "llista.hpp"

Llista::Llista() : _long(0) {
  _prim = new node;
  _prim->seg = NULL;
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
