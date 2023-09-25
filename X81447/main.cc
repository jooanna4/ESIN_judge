#include <sstream>

template <typename T>
pila<T>::pila() : _cim(NULL), _mida(0) {}

template <typename T>
pila<T>::~pila() {
  while (_cim != NULL) {
    node* aux = _cim;  
    _cim = _cim->seg;
    delete aux;
  }
}

template <typename T>
pila<T>::pila(const vector<int> &v) : _cim(NULL), _mida(v.size()) {
  node *p, *pant = NULL;
  for (nat i=0; i<v.size(); i++) {
    p = new node;
    try {
      p->info = v[i];
    } catch (const char* message) {
      cerr << message << endl;
      delete p;
      throw;
    }
    p->seg = NULL;
    if (pant == NULL)
      _cim = p;
    else
      pant->seg = p;
    pant = p;
  }
}

template <typename T>
nat pila<T>::longitud() const {
  return _mida;
}

template <typename T>
void pila<T>::mostra() const {
  node *p = _cim;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
    while (p != NULL) {
      cout << " " << p->info;
      p = p->seg;
    }
  }
  cout << "]" << endl;
}

int main() {
  int n;
  string linea;

  // Obtenim v1
  vector<int> v1;
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    v1.push_back(n);
  }

  // Obtenim v2
  vector<int> v2;
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    v2.push_back(n);
  }

  pila<int> p1(v1);
  pila<int> p2(v2);
  p1.fusiona(p2);
  cout << p1.longitud() << " ";
  p1.mostra();
  cout << p2.longitud() << " ";
  p2.mostra();
  return 0;
}
