#include <iostream>
#include "abin.cpp"
#include "solution.cpp"

// Llegeix un arbre binari des de cin i el retorna.
// De cin s'obté el seu recorregut en preordre, el qual inclou les fulles marcades amb un -1
Abin<int> llegir_arbre() {
  Abin<int> a;
  int valor;
  cin >> valor;
  if (valor != -1) {
    Abin<int> ae = llegir_arbre();
    Abin<int> ad = llegir_arbre();
    a = Abin<int>(ae, valor, ad);
  }
  return a;
}

int main() {
  Abin<int> a(llegir_arbre());
  list<int> l = a.preordre();
  for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
    if (it == l.begin())
      cout << *it;
    else
      cout << " " << *it;
  }
  return 0;
}
