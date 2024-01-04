#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem la matriu d'adjacència
  a = vector<vector<bool> >(n, vector<bool>(n, false));

  // Llegim les m arestes
  nat u, v;
  for(nat i = 0; i < m; i++) {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u][v] = true;
  }
}

int main() {
  graf g;
  g.llegeix();
  nat ini, fi;
  while (cin >> ini >> fi) {
    if (g.hi_ha_cami(ini, fi))
      cout << "SI hi ha camí de " << ini << " a " << fi << endl;
    else
      cout << "NO hi ha camí de " << ini << " a " << fi << endl;
  }
  return 0;
}
