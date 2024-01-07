#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k) {
  long i = (((k+1) * k * MULT) << 47) >> 7;
  if (i < 0)
    i = -i;
  return i;
}

dicc::dicc(nat m) : _quants(0) {
  _M = m;
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

void dicc::insereix(const int &k) {
  long i = h(k) % _M;
  node_hash *p = _taula[i], *ant = NULL;
  while (p != NULL and p->_k < k) {
    ant = p;
    p = p->_seg;
  }
  if (p == NULL or p->_k > k) {
    node_hash *n = new node_hash;
    n->_k = k;
    n->_seg = p;
    if (ant == NULL)
      _taula[i] = n;
    else
      ant->_seg = n;
    ++_quants;
    if (factor_de_carrega() > 0.8) {
      redispersio();
    }
  }
}

int main() {
  string linea;
  int n;
  cin >> n; getline(cin, linea);
  dicc d(n);

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n){
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n){
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

 
  return 0;
}
