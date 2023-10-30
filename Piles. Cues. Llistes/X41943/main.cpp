#include <iostream>
#include <sstream>
#include "llista.hpp"

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
    l.duplica_positius_elimina_negatius();
    cout << l.longitud() << " ";
    l.mostra();
  }
  return 0;
}
