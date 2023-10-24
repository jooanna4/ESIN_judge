#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin {
  public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres
 
    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);
 
    // Escriu una línia amb els elements del nivell i-èssim, d’esquerra 
    // a dreta. Cada element ha de sortir precedit d’un espai.
    void nivell(nat i);

  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void nivell_arbre(nat i, node* m);
};

// Aquí va la implementació del mètode nivell
template <typename T>
void Abin<T>::nivell(nat i) {
    nivell_arbre(i, _arrel);
}

template <typename T>
void Abin<T>::nivell_arbre(nat i, node* m) {
    if (m != nullptr) {
        if (i == 0)
            cout << " " << m->info;
        else if (i > 0) {
            nivell_arbre(i-1, m->f_esq);
            nivell_arbre(i-1, m->f_dret);
        }
    }
}