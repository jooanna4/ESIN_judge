#include <sstream>
using namespace std;


template <typename Clau>
dicc<Clau>::dicc() : _arrel(nullptr), _n(0) {}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* p) {
  if (p != nullptr) {
    esborra_nodes(p->_esq);
    esborra_nodes(p->_dret);
    delete p;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
void dicc<Clau>::print() const {
  cout << _n << ":";
  print(_arrel);
  cout << endl;
}

template <typename Clau>
void dicc<Clau>::print(node* p) {
  if (p != nullptr) {
    print(p->_esq);
    cout << " " << p->_k;
    print(p->_dret);
  }
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
    d.print();

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda >> n;

      if (comanda == "quantes") {
        cout << d.quantes(n) << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}
