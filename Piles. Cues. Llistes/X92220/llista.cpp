#include <iostream>
#include "llista.hpp"

Llista::Llista() : _long(0) {
  _prim = new node;
  _prim->seg = _prim;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = new node;
  _prim->seg = _prim;
  node *p, *pant = _prim;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = _prim;
    pant->seg = p;
    pant = p;
  }
}

Llista::~Llista() {
  node *p = _prim->seg, *pelim;
  while (p != _prim) {
    pelim = p;
    p = p->seg;
    delete pelim;
  }
  delete _prim;
}

nat Llista::longitud() const {
  return _long;
}

void Llista::mostra() const {
  node *p = _prim->seg;
  cout << "[";
  if (p != _prim) {
    cout << p->info;
    p = p->seg;
  }
  while (p != _prim) {
    cout << " " << p->info;
    p = p->seg;
  }
  cout << "]" << endl;
}
