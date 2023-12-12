#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k) {
  long i = ((k * k * MULT) << 20) >> 4;
  if (i < 0)
    i = -i;
  return i;
}

dicc::dicc() : _quants(0) {
  _M = 13;
  _taula = new node_hash*[_M];
  for (int i=0; i < _M; ++i) {
    _taula[i] = NULL;
  }
}

void dicc::esborra_nodes(node_hash *p) {
  if (p != NULL) {
    esborra_nodes(p->_seg);
    delete p;
  }
};

dicc::~dicc() {
  for (int i=0; i < _M; ++i) {
    esborra_nodes(_taula[i]);
  }
  delete _taula;
};

nat dicc::quants() const {
  return _quants;
}

void dicc::print() const {
  for (int i=0; i < _M; ++i) {
    cout << i << ": ";
    node_hash *p = _taula[i];
    while (p != NULL) {
      cout << p->_k << " ";
      p = p->_seg;
    }
    cout << endl;
  }
  cout << "-----------\n";
}


int main() {
  string linea;
  int n;
  dicc d1, d2, dr;

  // Obtenim elements 1er diccionari
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n){
    d1.insereix(n);
  }
  cout << "Nº elem: " << d1.quants() << endl;
  d1.print();

  // Obtenim elements 2on diccionari
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n){
    d2.insereix(n);
  }
  cout << "Nº elem: " << d2.quants() << endl;
  d2.print();

  // Intersecció
  d1.interseccio(d2, dr);
  cout << "Nº elem: " << dr.quants() << endl;
  dr.print();

  return 0;
}
