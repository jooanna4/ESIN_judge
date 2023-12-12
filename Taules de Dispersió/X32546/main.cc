#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k) {
  long i = (((k+1) * k * MULT) << 47) >> 7;
  if (i < 0)
    i = -i;
  return i;
}

dicc::dicc(nat m) : _M(m), _quants(0) {
  _taula = new node_hash[_M];
  for (nat i=0; i < _M; ++i) {
    _taula[i]._est = lliure;
  }
}

dicc::~dicc() {
  delete[] _taula;
};

nat dicc::quants() const {
  return _quants;
}

void dicc::print() const {
  for (nat i=0; i < _M; ++i) {
    cout << i << ": ";
    if (_taula[i]._est == ocupat)
      cout << _taula[i]._k;
    else if (_taula[i]._est == lliure)
      cout << "LL";
    else if (_taula[i]._est == esborrat)
      cout << "ES";
    cout << endl;
  }
  cout << "-----------\n";
}

nat dicc::busca_node(const int &k) const {
  nat i = h(k) % _M;
  // prilliure és la primera posició esborrada que
  // trobem, val -1 si no trobem cap posició esborrada.
  int prilliure = -1;
  // comptem el nombre d'elements que visitem per només fer una passada.
  nat cont = 0;
  while (((_taula[i]._est == ocupat and _taula[i]._k != k) or _taula[i]._est == esborrat)
         and cont < _M) {
    ++cont;
    if (_taula[i]._est == esborrat and prilliure == -1) {
      prilliure = i;
    }
    i = (i+1) % _M;
  }
  if (_taula[i]._est == lliure and prilliure != -1)
    i = prilliure;
  return i;
}

void dicc::insereix(const int &k) {
  nat i = busca_node(k);
  if (_taula[i]._est != ocupat) {
    ++_quants;
  }
  _taula[i]._k = k;
  _taula[i]._est = ocupat;
  if (factor_de_carrega() > 0.8) {
    redispersio();
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
