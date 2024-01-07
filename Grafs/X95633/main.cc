#include <iostream>
#include <sstream>

graf::graf(nat n) : nv(n) {
  // Creem les multillistes d'adjacència dels n vèrtexs buides
  prim_succ = vector<node *>(n, nullptr);  
  prim_pred = vector<node *>(n, nullptr);  
}

graf::~graf() {
  for (nat i = 0; i < nv; i++) {
    node *p = prim_succ[i];
    while (p != nullptr) {
      node *elim = p;
      p = p->seg_succ;
      delete elim;
    }
  }
}

vector<nat> graf::successors(nat v) const {
  vector<nat> r;
  node *p = prim_succ[v];
  while (p != nullptr) {
    r.push_back(p->dest);
    p = p->seg_succ;
  }
  return r;
}

vector<nat> graf::predecessors(nat v) const {
  vector<nat> r;
  node *p = prim_pred[v];
  while (p != nullptr) {
    r.push_back(p->orig);
    p = p->seg_pred;
  }
  return r;
}

int main() {
  string linea, comanda;
  nat n;
  cin >> n;
  graf g(n);
  getline(cin, linea);

  // Processem comandes
  while (getline(cin, linea)) {
    cout << linea << ":";
    istringstream ss(linea);
    ss >> comanda;

    if (comanda == "insereix") {
      nat orig, dest;
      ss >> orig >> dest;
      g.insereix(orig, dest);

    } else if (comanda == "successors") {
      nat v;
      ss >> v;
      vector<nat> r = g.successors(v);
      for (nat i = 0; i < r.size(); i++) {
        cout << " " << r[i];
      }

    } else if (comanda == "predecessors") {
      nat v;
      ss >> v;
      vector<nat> r = g.predecessors(v);
      for (nat i = 0; i < r.size(); i++) {
        cout << " " << r[i];
      }
    }
    cout<<endl;
  }
  return 0;
}
