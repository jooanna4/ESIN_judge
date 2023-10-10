#include <iostream>
#include <sstream>
#include "llista.hpp"

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

  while (cin >> n) {
    cout << n << endl;
    Llista l1(v1);
    Llista l2(v2);
    l1.fusiona_suma(l2, n);
    cout << l1.longitud() << " ";
    l1.mostra();
    cout << l2.longitud() << " ";
    l2.mostra();
  }
  return 0;
}
