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

  // Imprimeix la informació dels nodes en preordre, cada element en una nova línia i
  // precedit per espais segons el nivell on està situat.
  void preordre() const;

  static const int ArbreInvalid = 400;

  // Modifica el contingut dels nodes per tal de guardar a cada node l’altura
  // del seu subarbre
  void arbre_altures();

private:
  Arbre(): _arrel(NULL) {};
  struct node {
    T info;        // Informació del node
    node* primf;   // Punter al primer fill
    node* seggerm; // Punter al següent germà
  };
  node* _arrel; // Punter a l’arrel de l’arbre
  static node* copia_arbre(node* p);
  static void destrueix_arbre(node* p) throw();
  static void preordre(node *p, string pre);

  // Aquí va l’especificació dels mètodes privats addicionals
  static void altures(node *a, nat &i);
};

// Aquí va la implementació del mètode arbre_altures i privats addicionals
template <typename T>
void Arbre<T>::arbre_altures() {
    nat i;
    altures(_arrel, i);
}

template <typename T>
void Arbre<T>::altures(node *a, nat &i) {
    i = 1;
    if (a == nullptr) return;
        int max = 0;
        node *aux = a->primf;
        while (aux != nullptr) {
            altures(aux, i);
            if (aux->info > max) max = aux->info;
            aux = aux->seggerm;
        }
        if (a->primf != nullptr) a->info = max + 1;
        else a->info = i;
}