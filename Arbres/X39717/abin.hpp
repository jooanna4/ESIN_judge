#ifndef ARBRE_BIN_H 
#define ARBRE_BIN_H

#include <list>
#include <cstdlib>
using namespace std;
typedef unsigned int nat;

// La classe Abin permet definir arbres binaris enfilats d'elements de tipus T
template <typename T>
class Abin {
  public:
    Abin(): _arrel(NULL), _pri_inordre(NULL), _ult_inordre(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element x i dos subarbres ae i ad com fills esquerra i dret

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // Retorna una llista amb els elements de l'arbre en preordre
    list<T> preordre() const;

  private:
    struct node {
      bool thread_esq;  // Indica que f_esq és un fil esquerra (true) o fill esquerra (false)
      node* f_esq;      // Punter al fill esquerra o fil esquerra
      node* f_dret;     // Punter al fill dret o fil dret
      bool thread_dret; // Indica que f_dret és un fil dret (true) o fill dret (false)
      T info;
    };
    node* _arrel; // Apunta a l'arrel
    node* _pri_inordre; // Apunta al primer element en inordre
    node* _ult_inordre; // Apunta al darrer element en inordre

    static node* copia_nodes(node* m,
      node* ant_in, node* seg_in, node* &pri_in, node* &ult_in);
    static void esborra_nodes(node* m);
};

#endif