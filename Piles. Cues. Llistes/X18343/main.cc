#include <iostream>
#include <sstream>

Llista::Llista() : _long(0) {
  _ult = _prim = nullptr;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = nullptr;
  node *p(nullptr), *pant(nullptr);
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = nullptr;
    p->ant = pant;
    if (pant != nullptr)
      pant->seg = p;
    else
      _prim = p;
    pant = p;
  }
  _ult = p;
}

Llista::~Llista() {
  node *p(_prim), *pelim;
  while (p != nullptr) {
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
  if (p != nullptr) {
    cout << p->info;
    p = p->seg;
  }
  while (p != nullptr) {
    cout << " " << p->info;
    p = p->seg;
  }
  cout << "]";
}

void Llista::mostra_invertida() const {
  node *p = _ult;
  cout << "[";
  if (p != nullptr) {
    cout << p->info;
    p = p->ant;
  }
  while (p != nullptr) {
    cout << " " << p->info;
    p = p->ant;
  }
  cout << "]";
}

int main() {
  string linea;
  while (getline(cin, linea)) {
    vector<int> v;
    istringstream ss(linea);
    int n;
    while (ss >> n) {
      v.push_back(n);
    }
    Llista l(v);
    l.ordena();
    cout << l.longitud() << " ";
    l.mostra();
    cout << " ";
    l.mostra_invertida();
    cout << endl;
  }
  return 0;
}
