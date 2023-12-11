
template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}


int main() {
  int n;
  dicc<int> d;
  while (cin >> n) {
    vector<int> v;
    pair<int, char> desq = d.insereix(n);
    cout << "insereix " << n << ':';
    if (desq.second != ' ') {
      cout << ' ' << desq.first << ' ' << desq.second;
    }
    cout << endl;
  }
  return 0;
}
