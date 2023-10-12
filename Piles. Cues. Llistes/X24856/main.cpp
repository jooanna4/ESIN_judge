#include <iostream>
#include <sstream>
#include "cua.hpp"

int main() {
  string linea;
  while (getline(cin, linea)) {
    vector<int> v;
    istringstream ss(linea);
    int n;
    while (ss >> n) {
      v.push_back(n);
    }
    cua c1(v);
    cua c2(c1);

    cout << c2.longitud() << " [";
    while (not c2.es_buida()) {
      if(c2.longitud() == 1)
        cout << c2.primer();
      else
        cout << c2.primer() << " ";
      c2.desencuar();
    }
    cout << "]" << endl;
  }
}
