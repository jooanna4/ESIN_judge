#include <iostream>
#include <sstream>

template <typename T>
deque<T>::deque() : _long(0) {
  _prim = NULL;
  _ult  = NULL;
}

template <typename T>
deque<T>::deque(const deque &dq) : _long(dq._long) {
  _prim = NULL;
  node *p, *pant = NULL, *p2 = dq._prim;
  while (p2 != NULL) {
    p = new node;
    p->info = p2->info;
    p->seg = NULL;
    p->ant = pant;
    if (pant == NULL)
      _prim = p;
    else
      pant->seg = p;
    pant = p;
    p2 = p2->seg;
  }
  _ult = pant;
}

template <typename T>
deque<T>::~deque() {
  node *p = _prim, *pelim;
  while (p != NULL) {
    pelim = p;
    p = p->seg;
    delete pelim;
  }
}

template <typename T>
nat deque<T>::size() const {
  return _long;
}

template <typename T>
bool deque<T>::empty() const {
  return _prim == NULL;
}

template <typename T>
T deque<T>::front() const {
  return _prim->info;
}

template <typename T>
T deque<T>::rear() const {
  return _ult->info;
}

template <typename T>
void mostra(deque<T> dq) {
// Pre: True
// Post: Mostra els elements de dq pel cout entre claudàtors i separats per espais.
  cout << "[";
  if (not dq.empty()) {
    cout << dq.front();
    dq.pop();
  }
  while (not dq.empty()) {
    cout << " " << dq.front();
    dq.pop();
  }
  cout << "]";
}

template <typename T>
void mostra_invertida(deque<T> dq) {
// Pre: True
// Post: Mostra en ordre invers els elements de dq pel cout entre claudàtors i separats per espais.
  cout << "[";
  if (not dq.empty()) {
    cout << dq.rear();
    dq.eject();
  }
  while (not dq.empty()) {
    cout << " " << dq.rear();
    dq.eject();
  }
  cout << "]";
}


int main() {
  string linea, comanda;
  int n;
  deque<int> dq;

  // Processem comandes
  while (getline(cin, linea)) {
    cout << linea << ": ";
    istringstream ss(linea);
    ss >> comanda;

    if (comanda == "size") {
      cout << dq.size();

    } else if (comanda == "empty") {
      cout << boolalpha << dq.empty();

    } else if (comanda == "front") {
      cout << dq.front();

    } else if (comanda == "rear") {
      cout << dq.rear();

    } else if (comanda == "push") {
      ss >> n;
      cout << n;
      dq.push(n);

    } else if (comanda == "inject") {
      ss >> n;
      cout << n;
      dq.inject(n);

    } else if (comanda == "pop") {
      cout << dq.front();
      dq.pop();

    } else if (comanda == "eject") {
      cout << dq.rear();
      dq.eject();

    } else if (comanda == "mostra") {
      mostra(dq);

    } else if (comanda == "mostra_invertida") {
      mostra_invertida(dq);
    }
    cout<<endl;
  }
  return 0;
}
