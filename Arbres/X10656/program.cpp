#include <cstdlib>
using namespace std;
typedef unsigned int nat;
 
template <typename T>
class Arbre {

public:
  // Construeix un Arbre format per un únic node que conté a x.
  Arbre(const T &x);

  // Tres grans.
  Arbre(const Arbre<T> &a);
  Arbre& operator=(const Arbre<T> &a);
  ~Arbre() throw();

  // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_fill(Arbre<T> &a);

  static const int ArbreInvalid = 400;

  // Indica quants nodes de grau n té.
  nat quants_grau(nat n);

private:
  Arbre(): _arrel(NULL) {};
  struct node {
    T info;
    node* primf;
    node* seggerm;
  };
  node* _arrel;
  static node* copia_arbre(node* p);
  static void destrueix_arbre(node* p) throw();

  // Aquí va l’especificació dels mètodes privats addicionals
  static nat quants(nat n, node* m);
};

// Aquí va la implementació del mètode quants_grau
template <typename T>
nat Arbre<T>::quants_grau(nat n) {
    return quants(n, _arrel);
}

template <typename T>
nat Arbre<T>::quants(nat n, node* m) {
    nat nod(0);
    if (m != nullptr) {
        int i = 0;
        node *aux = m->primf;
        while (aux != nullptr) {
            i++;
            aux = aux->seggerm;
        }
        if (i == n) nod++;
        
        nod += quants(n, m->primf);
        nod += quants(n, m->seggerm);
    }
    return nod;
}