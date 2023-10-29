#include <iostream>
#include "llista.hpp"

Llista::Llista() : _long(0) {
  _prim = new node;
  _prim->seg = _prim;
  _prim->ant = _prim;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = new node;
  _prim->seg = _prim;
  _prim->ant = _prim;
  node *p, *pant = _prim;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = _prim;
    p->ant = pant;
    pant->seg = p;
    _prim->ant = p;
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
  cout << "]";
}

void Llista::mostra_invertida() const {
  node *p = _prim->ant;
  cout << "[";
  if (p != _prim) {
    cout << p->info;
    p = p->ant;
  }
  while (p != _prim) {
    cout << " " << p->info;
    p = p->ant;
  }
  cout << "]";
}
