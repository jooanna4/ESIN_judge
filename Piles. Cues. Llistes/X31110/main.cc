#include <sstream>

template <typename T>
cua<T>::cua() : _pri(NULL), _ult(NULL), _mida(0) {}

template <typename T>
cua<T>::~cua() {
  while (_pri != NULL) {
    node* aux = _pri;  
    _pri = _pri->seg;
    delete aux;
  }
}

template <typename T>
cua<T>::cua(const vector<int> &v) : _pri(NULL), _ult(NULL), _mida(v.size()) {
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
    if (pant == NULL)
      _pri = p;
    else
      pant->seg = p;
    pant = p;
  }
  if (v.size() > 0) { // Arreglem darrer element
    p->seg = NULL;
    _ult = p;
  }
}

template <typename T>
nat cua<T>::longitud() const {
  return _mida;
}

template <typename T>
void cua<T>::mostra() const {
  node *p = _pri;
  cout << "[";
  if (p != NULL) {
    while (p != _ult) {
      cout << p->info << " ";
      p = p->seg;
    }
    cout << p->info;
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

  cua<int> c1(v1);
  cua<int> c2(v2);
  c1.fusiona(c2);
  cout << c1.longitud() << " ";
  c1.mostra();
  cout << c2.longitud() << " ";
  c2.mostra();
  return 0;
}
