#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {
  public:
    dicc() : _arrel(NULL) {};
    // Pre: Cert
    // Post: El resultat és un dicc sense cap element

    ~dicc();
    // Pre: Cert
    // Post: El dicc ha estat destruït

    pair<Clau, char> insereix(const Clau &k);
    // Pre: Cert
    // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
    // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
    // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
      nat _h;       // Altura del subarbre
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    bool conteclau(node *n);
    node* insereixClau(node *n, Clau k, Clau &desequilibri, int &factor);
    int factor_equilibri(node *n);
    nat altura(node *n);
};

// Aquí va la implementació dels mètodes públics i privats
pair<Clau, char> dicc<Clau>::insereix(const Clau &k) {
    Clau c;
    int fact;
    if (not conteclau(_arrel))
        insereixClau(_arrel, k, c, fact);
}

int dicc<Clau>::factor_equilibri(node *n) {
    return n->_esq->_h - n->_dret->_h;
}

nat dicc<Clau>::altura(node *n) {
    if (n != nullptr)
        return n->_h;
    else
        return 0;
}

dicc<Clau>::node* dicc<Clau>::insereixClau(node *n, Clau k, Clau &desequilibri, int &factor) {
    if (n != nullptr) {
        if (k < n->_k)
            n->_esq = insereixClau(n->_esq);
        else
            n->_dret = insereixClau(n->_dret);
        
        n->_h = max(altura(n->_dret), altura(n->_esq)) + 1;
        factor = factor_equilibri(n);
        
    }
    else {
        n = new node;
        n->_k = k;
        n->_esq = nullptr;
        n->_dret = nullptr;
        n->_h = 1;
    }
    
}