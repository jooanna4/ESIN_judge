
dicc::dicc() : _arrel(NULL) {}

dicc::~dicc() {
  esborra_nodes(_arrel);
}

void dicc::esborra_nodes(node* t) {
  if (t != NULL) {
    esborra_nodes(t->_pf);
    esborra_nodes(t->_sg);
    delete t;
  }
}

dicc::node::node(const char &c, node* pf, node* sg) :
  _c(c), _pf(pf), _sg(sg) {
}

typename dicc::node* dicc::insereix(node *t, nat i, const string &k) {
  if (t == NULL) {
    t = new node(k[i]);
    try {
      if (i < k.length()-1) {
        t->_pf = insereix(t->_pf, i+1, k);
      }
    }
    catch (...) {
      delete t;
      throw;
    }
  } else {
    if (t->_c > k[i]) {
      t = new node(k[i], NULL, t);
      try {
        if (i < k.length()-1) {
          t->_pf = insereix(t->_pf, i+1, k);
        }
      }
      catch (...) {
        delete t;
        throw;
      }
    }
    else if (t->_c < k[i]) {
      t->_sg = insereix(t->_sg, i, k);
    }
    else { // (t->_c == k[i])
      t->_pf = insereix(t->_pf, i+1, k);
    }
  }
  return t;
}

void dicc::insereix (const string &k) {
  _arrel = insereix(_arrel, 0, k + '#'); // Símbol # és la marca de fi de clau
}


int main() {
  string input;
  dicc d;
  while (getline(cin, input)) {
    d.insereix(input);
  }

  vector<nat> freq = d.freq_longituds();
  for (nat i = 0; i < freq.size(); i++) {
    cout << freq[i] << " ";
  }
  return 0;
}
