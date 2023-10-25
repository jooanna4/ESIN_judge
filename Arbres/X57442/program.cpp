#include <cstdlib>
#include <string>
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

  // Imprimeix la informació dels nodes en preodre, cada element en una nova línia i
  // precedit per espais segons el nivell on està situat.
  void preordre() const;

  static const int ArbreInvalid = 400;

  // Modifica el contingut dels nodes per tal de guardar a cada node la suma dels
  // nodes dels seus fills. Els nodes fulla (els de grau 0) no es modifiquen.
  void arbre_suma_fills();

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
  static void preordre(node *p, string pre);

  // Aquí va l’especificació dels mètodes privats addicionals
  static void sumes(node*n);
};

// Aquí va la implementació del mètode arbre_suma_fills i privats addicionals
template <typename T>
void Arbre<T>::arbre_suma_fills() {
  sumes(_arrel);
}
/*
  T(n) = O(ngerm) + O(n)
*/ 
template <typename T>
void Arbre<T>::sumes(node*n) {
  if (n != nullptr) {
    if (n->primf != nullptr) {
      sumes(n->primf);
      int i = 0;                    // O(1)
      node *aux = n->primf;         // O(1)
      while (aux != nullptr) {      // O(ngerm)
        i += aux->info;             // O(1)
        aux = aux->seggerm;         // O(1)
      }
      n->info = i;                  // O(1)
    }
    sumes(n->seggerm);
  }
}