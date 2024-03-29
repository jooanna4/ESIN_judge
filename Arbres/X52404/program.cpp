#include <cstdlib>
#include <iostream>
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

    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);

    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

    // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
    // nodes del seu subarbre.
    void arbre_sumes();

  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void suma(node *m);
};
 
// Aquí va la implementació del mètode arbre_sumes
template <typename T>
void Abin<T>::arbre_sumes() {
  suma (_arrel);
}

template <typename T>
void Abin<T>::suma (node *m) {
  if (m != nullptr) {
    suma (m->f_esq);
    suma (m->f_dret);

    int i = m->info;
    if (m->f_esq != nullptr) i += m->f_esq->info;
    if (m->f_dret != nullptr) i += m->f_dret->info;
    m->info = i;
  }
}